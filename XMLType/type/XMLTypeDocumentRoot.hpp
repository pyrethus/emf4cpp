// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * type/XMLTypeDocumentRoot.hpp
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

#ifndef TYPE_XMLTYPEDOCUMENTROOT_HPP
#define TYPE_XMLTYPEDOCUMENTROOT_HPP

#include <ecore/EObject.hpp>

#include <type/dllType.hpp>
#include <type_forward.hpp>

#include <ecore_forward.hpp>

#include "TypePackage.hpp"

/*PROTECTED REGION ID(XMLTypeDocumentRoot_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace type
{

class EXPORT_TYPE_DLL XMLTypeDocumentRoot : public virtual ::ecore::EObject
{
public:
    XMLTypeDocumentRoot();

    virtual ~XMLTypeDocumentRoot();

    virtual void _initialize();

    // Operations

    // Attributes
    virtual std::vector< ::ecore::EFeatureMapEntry > const& getMixed () const;
    virtual void setMixed (std::vector< ::ecore::EFeatureMapEntry > _mixed);

    virtual void addMixed (::ecore::EFeatureMapEntry const& _new_element_in_mixed);
    virtual void setMixedAt ( size_t _position, ::ecore::EFeatureMapEntry const& _new_element_in_mixed);
    virtual void deleteMixedAt ( size_t _position );

    virtual std::vector< ::type::String > const& getCDATA () const;
    virtual void setCDATA (std::vector< ::type::String > _cDATA);

    virtual void addCDATA (::type::String const& _new_element_in_cDATA);
    virtual void setCDATAAt ( size_t _position, ::type::String const& _new_element_in_cDATA);
    virtual void deleteCDATAAt ( size_t _position );

    virtual std::vector< ::type::String > const& getComment () const;
    virtual void setComment (std::vector< ::type::String > _comment);

    virtual void addComment (::type::String const& _new_element_in_comment);
    virtual void setCommentAt ( size_t _position, ::type::String const& _new_element_in_comment);
    virtual void deleteCommentAt ( size_t _position );

    virtual std::vector< ::type::String > const& getText () const;
    virtual void setText (std::vector< ::type::String > _text);

    virtual void addText (::type::String const& _new_element_in_text);
    virtual void setTextAt ( size_t _position, ::type::String const& _new_element_in_text);
    virtual void deleteTextAt ( size_t _position );

    // References
    virtual const ::ecorecpp::mapping::EList< ::ecore::EStringToStringMapEntry_ptr >& getXMLNSPrefixMap () const;
    virtual ::ecorecpp::mapping::EList< ::ecore::EStringToStringMapEntry_ptr >& getXMLNSPrefixMap ();

    virtual const ::ecorecpp::mapping::EList< ::ecore::EStringToStringMapEntry_ptr >& getXSISchemaLocation () const;
    virtual ::ecorecpp::mapping::EList< ::ecore::EStringToStringMapEntry_ptr >& getXSISchemaLocation ();

    virtual const ::ecorecpp::mapping::EList< ::type::ProcessingInstruction_ptr >& getProcessingInstruction () const;
    virtual ::ecorecpp::mapping::EList< ::type::ProcessingInstruction_ptr >& getProcessingInstruction ();

    /* This is the same value as getClassifierId() returns, but as a static
     * value it can be used in template expansions. */
    static const int classifierId = TypePackage::XMLTYPEDOCUMENTROOT;

    /*PROTECTED REGION ID(XMLTypeDocumentRoot) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

    // EObjectImpl
    virtual ::ecore::EJavaObject eGet ( ::ecore::EInt _featureID, ::ecore::EBoolean _resolve);
    virtual void eSet ( ::ecore::EInt _featureID, ::ecore::EJavaObject const& _newValue);
    virtual ::ecore::EBoolean eIsSet ( ::ecore::EInt _featureID);
    virtual void eUnset ( ::ecore::EInt _featureID);
    virtual ::ecore::EClass_ptr _eClass ();
    virtual void _inverseAdd ( ::ecore::EInt _featureID, ::ecore::EJavaObject const& _newValue);
    virtual void _inverseRemove ( ::ecore::EInt _featureID, ::ecore::EJavaObject const& _oldValue);

    /*PROTECTED REGION ID(XMLTypeDocumentRootImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

protected:
    XMLTypeDocumentRoot_ptr _this()
    {   return std::dynamic_pointer_cast<XMLTypeDocumentRoot>(shared_from_this());}

    // Attributes

    std::vector< ::ecore::EFeatureMapEntry > m_mixed
    {};

    std::vector< ::type::String > m_cDATA
    {};

    std::vector< ::type::String > m_comment
    {};

    std::vector< ::type::String > m_text
    {};

    // References

    ::ecore::EList_ptr< ::ecore::EStringToStringMapEntry_ptr > m_xMLNSPrefixMap;

    ::ecore::EList_ptr< ::ecore::EStringToStringMapEntry_ptr > m_xSISchemaLocation;

    ::ecore::EList_ptr< ::type::ProcessingInstruction_ptr > m_processingInstruction;

};

}
 // type

#endif // TYPE_XMLTYPEDOCUMENTROOT_HPP

