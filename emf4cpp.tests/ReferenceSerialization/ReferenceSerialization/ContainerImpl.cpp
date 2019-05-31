// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * ReferenceSerialization/ContainerImpl.cpp
 * Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
 * Copyright (C) INCHRON GmbH 2016-2018 <emf4cpp@inchron.com>
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

#include "Container.hpp"
#include <ReferenceSerialization/ReferenceSerializationPackage.hpp>
#include <ReferenceSerialization/Content.hpp>
#include <ReferenceSerialization/Child.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

/*PROTECTED REGION ID(ContainerImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::ReferenceSerialization;

void Container::_initialize()
{
    // Supertypes

    // References
    for (size_t i = 0; i < m_contents->size(); i++)
    {
        (*m_contents)[i]->_initialize();
    }
    if (m_child)
    {
        m_child->_initialize();
    }

    /*PROTECTED REGION ID(ContainerImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations

// EObject
::ecore::EJavaObject Container::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CONTENTS:
    {
        _any = m_contents->asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__REFERENCES:
    {
        _any = m_references->asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CHILD:
    {
        _any = ::ecore::as < ::ecore::EObject > (m_child);
    }
        return _any;
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CHILDREF:
    {
        _any = ::ecore::as < ::ecore::EObject > (m_childRef.lock());
    }
        return _any;

    }
    throw "Error";
}

void Container::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CONTENTS:
    {
        ::ecore::EList_ptr < ::ecore::EObject_ptr > _t0 =
                ::ecorecpp::mapping::any::any_cast
                        < ::ecore::EList_ptr< ::ecore::EObject_ptr >
                        > (_newValue);
        ::ReferenceSerialization::Container::getContents().clear();
        ::ReferenceSerialization::Container::getContents().insert_all(*_t0);
    }
        return;
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__REFERENCES:
    {
        ::ecore::EList_ptr < ::ecore::EObject_ptr > _t0 =
                ::ecorecpp::mapping::any::any_cast
                        < ::ecore::EList_ptr< ::ecore::EObject_ptr >
                        > (_newValue);
        ::ReferenceSerialization::Container::getReferences().clear();
        ::ReferenceSerialization::Container::getReferences().insert_all(*_t0);
    }
        return;
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CHILD:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_newValue);
        ::ReferenceSerialization::Child_ptr _t1 = std::dynamic_pointer_cast
                < ::ReferenceSerialization::Child > (_t0);
        ::ReferenceSerialization::Container::setChild(_t1);
    }
        return;
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CHILDREF:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_newValue);
        ::ReferenceSerialization::Child_ptr _t1 = std::dynamic_pointer_cast
                < ::ReferenceSerialization::Child > (_t0);
        ::ReferenceSerialization::Container::setChildRef(_t1);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean Container::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CONTENTS:
        return m_contents && m_contents->size();
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__REFERENCES:
        return m_references && m_references->size();
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CHILD:
        return !(m_child == nullptr);
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CHILDREF:
        return !m_childRef.expired();

    }
    throw "Error";
}

void Container::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr Container::_eClass()
{
    static ::ecore::EClass_ptr _eclass =
            dynamic_cast< ::ReferenceSerialization::ReferenceSerializationPackage* >(::ReferenceSerialization::ReferenceSerializationPackage::_instance().get())->getContainer();
    return _eclass;
}

/** Set the local end of a reference with an EOpposite property.
 */
void Container::_inverseAdd(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CONTENTS:
    {
    }
        return;
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__REFERENCES:
    {
    }
        return;
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CHILD:
    {
    }
        return;
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CHILDREF:
    {
    }
        return;

    }
    throw "Error: _inverseAdd() does not handle this featureID";
}

/** Unset the local end of a reference with an EOpposite property.
 */
void Container::_inverseRemove(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _oldValue)
{
    switch (_featureID)
    {
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CONTENTS:
    {
    }
        return;
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__REFERENCES:
    {
    }
        return;
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CHILD:
    {
    }
        return;
    case ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CHILDREF:
    {
    }
        return;

    }
    throw "Error: _inverseRemove() does not handle this featureID";
}

