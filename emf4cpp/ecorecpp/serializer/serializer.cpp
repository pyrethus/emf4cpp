// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * serializer/serializer.cpp
 * Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
 * Copyright (C) INCHRON GmbH 2016 <soeren.henning@inchron.com>
 *
 * EMF4CPP is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EMF4CPP is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "serializer.hpp"
#include <ecore.hpp>
#include "../util/debug.hpp"
#include "../mapping.hpp"

using namespace ::ecorecpp::serializer;
using namespace ::ecore;

serializer::serializer(std::ostream& _ostream, XmiIndentMode mode) :
	m_out(_ostream),
	m_mode(mode),
	m_internalBuffer(),
	m_level(0),
	m_ser(m_internalBuffer, m_mode == XmiIndentMode::Indentation),
	m_usedPackages()
{
}

serializer::~serializer()
{
}

void
serializer::create_node(::ecore::EObject_ptr parent_obj,
                        EObject_ptr child_obj, EStructuralFeature_ptr ef)
{
    m_ser.open_object(ef->getName());

    EClass_ptr child_cl = child_obj->eClass();

    // May be a subtype
    if (child_cl != ef->getEType()) {
        m_ser.add_attribute("xsi:type", get_type(child_obj));
		m_usedPackages.push_back(child_cl->getEPackage());
	}

    serialize_node(child_obj);

    m_ser.close_object(ef->getName());
}

void serializer::serialize_node(EObject_ptr obj)
{
    ++m_level;

#ifdef DEBUG
    ::ecorecpp::mapping::type_definitions::string_t indent(m_level, '\t');
#endif

    EClass_ptr cl = obj->eClass();

    /**
     *
     *
     * Node attributes
     *
     *
     */
    ::ecorecpp::mapping::EList< EAttribute_ptr > const& attributes =
          cl->getEAllAttributes();

    for (size_t i = 0; i < attributes.size(); i++)
    {
        try
        {
            EAttribute_ptr const& current_at = attributes[i];
            EClassifier_ptr at_classifier = current_at->getEType();

            DEBUG_MSG(cerr, indent << current_at->getName());

            if (!current_at->isTransient() && !current_at->isDerived()
				&& obj->eIsSet(current_at))
            {
                EDataType_ptr atc = as< EDataType >(at_classifier);
                if (atc)
                {
                    EFactory_ptr fac =
                            at_classifier->getEPackage()->getEFactoryInstance();
                    ecorecpp::mapping::any any = obj->eGet(current_at);

                    if (current_at->getUpperBound() == 1)
                    {
                        ::ecorecpp::mapping::type_definitions::string_t value =
                                fac->convertToString(atc, any);

                        DEBUG_MSG(cerr, indent << current_at->getName() << " "
                                << value);

                        if (!value.empty() && value
                                != current_at->getDefaultValueLiteral())
                        {
                            m_ser.add_attribute(current_at->getName(), value);
                        }
                    }
                }
                else
                {
                    // TODO: possible?
                }
            }
        } catch (const std::exception& e)
        {
            DEBUG_MSG(cerr, e.what() );
        }
    }

    ::ecorecpp::mapping::EList< EReference_ptr > const& references =
          cl->getEAllReferences();

    for (size_t i = 0; i < references.size(); i++)
    {
        try
        {
            EReference_ptr current_ref = references[i];

            DEBUG_MSG(cerr, indent << current_ref->getName());

            if (!current_ref->isTransient() && !current_ref->isDerived()
				&& obj->eIsSet(current_ref))
            {
                ecorecpp::mapping::any any = obj->eGet(current_ref);

                if (!current_ref->isContainment())
                {
                    // TODO: create reference
                    ::ecorecpp::mapping::type_definitions::stringstream_t value;
                    DEBUG_MSG(cerr, indent << current_ref->getName());

                    if (current_ref->getUpperBound() != 1)
                    {
                        mapping::EList<::ecore::EObject_ptr>::ptr_type children =
                            ecorecpp::mapping::any::any_cast<mapping::EList<::ecore::EObject_ptr>::ptr_type >(any);
                        // Remove expired references first
                        children->cleanup();

                        for (size_t j = 0; j < children->size(); j++)
                        {
                            value << get_reference(obj, (*children)[j]);

                            if (j + 1 < children->size())
                                value << " ";
                        }
                    }
                    else
                    {
                        EObject_ptr child =
                            ecorecpp::mapping::any::any_cast< EObject_ptr >(any);
                        if (child)
                            value << get_reference(obj, child);
                    }

                    if (!value.str().empty())
                        m_ser.add_attribute(current_ref->getName(), value.str());
                }
            }
        } catch (...)
        {
            DEBUG_MSG(cerr, "exception catched! ");
        }
    }

    /**
     *
     *
     * Node children
     *
     *
     */
    for (size_t i = 0; i < attributes.size(); i++)
    {
        try
        {
            EAttribute_ptr const& current_at = attributes[i];
            EClassifier_ptr at_classifier = current_at->getEType();

            DEBUG_MSG(cerr, indent << current_at->getName());

            if (!current_at->isTransient() && !current_at->isDerived()
				&& obj->eIsSet(current_at))
            {
                EDataType_ptr atc = as< EDataType >(at_classifier);
                if (atc)
                {
                    EFactory_ptr fac =
                        at_classifier->getEPackage()->getEFactoryInstance();
                    ecorecpp::mapping::any any = obj->eGet(current_at);

                    if (current_at->getUpperBound() != 1)
                    {
                        // std::vector of what? solution: anys
                        std::vector< ecorecpp::mapping::any > anys =
                            ecorecpp::mapping::any::any_cast< std::vector< ecorecpp::mapping::any > >(any);
                        for (size_t k = 0; k < anys.size(); k++)
                        {
                            ::ecorecpp::mapping::type_definitions::string_t value =
                                    fac->convertToString(atc, anys[k]);

                            DEBUG_MSG(cerr, indent << current_at->getName()
                                    << " " << value);

                            m_ser.open_object(current_at->getName());
                            m_ser.add_value(value);
                            m_ser.close_object(current_at->getName());
                        }
                    }
                }
                else
                {
                    // TODO: possible?
                }
            }
        } catch (...)
        {
            DEBUG_MSG(cerr, "exception catched!");
        }
    }

    for (size_t i = 0; i < references.size(); i++)
    {
        try
        {
            EReference_ptr current_ref = references[i];

            DEBUG_MSG(cerr, indent << current_ref->getName());

            if (!current_ref->isTransient() && !current_ref->isDerived()
				&& obj->eIsSet(current_ref))
            {
                ecorecpp::mapping::any any = obj->eGet(current_ref);

                if (current_ref->isContainment())
                {
                    DEBUG_MSG(cerr, indent << current_ref->getName());

                    if (current_ref->getUpperBound() != 1)
                    {
                        mapping::EList<::ecore::EObject_ptr>::ptr_type children = ecorecpp::mapping::any::any_cast<
                                mapping::EList<::ecore::EObject_ptr>::ptr_type >(any);
                        for (size_t j = 0; j < children->size(); j++)
                        {
                            create_node(obj, (*children)[j], current_ref);
                        }
                    }
                    else
                    {
                        EObject_ptr child = ecorecpp::mapping::any::any_cast< EObject_ptr >(any);
						if (child)
                            create_node(obj, child, current_ref);
                    }
                }
            }
        } catch (...)
        {
            DEBUG_MSG(cerr, "exception catched! ");
        }
    }

    --m_level;
}

void
serializer::serialize(EObject_ptr obj)
{
    m_root_obj = obj;

    EClass_ptr cl = obj->eClass();
    EPackage_ptr pkg = cl->getEPackage();
	m_usedPackages.push_back(pkg);

	// remove the XML processing instruction
	m_internalBuffer.str(std::string());
	// Serialize the top level object into m_internalBuffer
	m_ser.open_object("", greedy_serializer::SilentMode::Silent);
	serialize_node(obj);
	m_ser.close_object("", greedy_serializer::SilentMode::Silent);

	// Create a new serializer for the real output.
	greedy_serializer output(m_out, m_mode == XmiIndentMode::Indentation);

	::ecorecpp::mapping::type_definitions::string_t root_name(get_type(obj));
	output.open_object(root_name);

    // common attributes, following standard EMF order
    // xmi:version="2.0"
    output.add_attribute("xmi:version", "2.0");
    // xmlns:xmi="http://www.omg.org/XMI"
    output.add_attribute("xmlns:xmi", "http://www.omg.org/XMI");
    // xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    output.add_attribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");

	// sort and unify according to EPackage name
	std::sort(m_usedPackages.begin(), m_usedPackages.end(),
			  [](const EPackage_ptr& lhs, const EPackage_ptr& rhs) -> bool {
				  return lhs->getName() < rhs->getName(); });
	m_usedPackages.erase(std::unique(m_usedPackages.begin(), m_usedPackages.end()),
						  m_usedPackages.end());

	for ( auto pkg : m_usedPackages ) {

		::ecorecpp::mapping::type_definitions::string_t const& ns_uri = pkg->getNsURI();

		::ecorecpp::mapping::type_definitions::stringstream_t root_namespace;
		root_namespace << "xmlns:" << pkg->getName();

		output.add_attribute(root_namespace.str(),ns_uri); // root element namespace URI
	}

	output.append(m_internalBuffer.str());

    output.close_object(root_name);
}

::ecorecpp::mapping::type_definitions::string_t
serializer::get_type(EObject_ptr obj) const
{
    EClass_ptr cl = obj->eClass();
    EPackage_ptr pkg = cl->getEPackage();

    ::ecorecpp::mapping::type_definitions::stringstream_t ss;
    ss << pkg->getName() << ":" << cl->getName();

    return ss.str();
}

#include <list>

::ecorecpp::mapping::type_definitions::string_t
serializer::get_reference(EObject_ptr from, EObject_ptr to) const
{
    ::ecorecpp::mapping::type_definitions::stringstream_t value;

    std::list< EObject_ptr > to_antecessors;
    EObject_ptr antecessor = to;
    while (antecessor)
    {
        to_antecessors.push_back(antecessor);
        antecessor = to_antecessors.back()->eContainer();
    }

    EPackage_ptr pkg = as< EPackage > (to_antecessors.back());
    if (pkg)
    {
        if (m_root_obj != pkg)
        {
            value << get_type(to) << " " << pkg->getNsURI();
        }

        value << "#/";
        to_antecessors.pop_back();

        while (to_antecessors.size())
        {
            value << "/"
                  << as< ENamedElement >(to_antecessors.back())->getName();
            to_antecessors.pop_back();
        }
    }
    else if (to_antecessors.back() == m_root_obj)
    {
        value << "/";
        EObject_ptr prev = to_antecessors.back();
        to_antecessors.pop_back();

        while (to_antecessors.size())
        {
            EStructuralFeature_ptr esf =
                    to_antecessors.back()->eContainingFeature();
            if (esf->getUpperBound() == 1)
                value << "/@" << esf->getName();
            else
            {
                ecorecpp::mapping::any _any = prev->eGet(esf);

                mapping::EList<::ecore::EObject_ptr>::ptr_type ef = ecorecpp::mapping::any::any_cast<
                        mapping::EList<::ecore::EObject_ptr>::ptr_type >(_any);

                // calculate the index of back at father's collection
                size_t index_of = 0;
                for (; index_of < ef->size() && (*ef)[index_of]
                        != to_antecessors.back(); index_of++)
                    ;

                value << "/@" << esf->getName() << "." << index_of;
            }

            prev = to_antecessors.back();
            to_antecessors.pop_back();
        }
    }
    else
    {
        // TODO
        DEBUG_MSG(cerr, "not implemented!");
    }

    return value.str();
}
