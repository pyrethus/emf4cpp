// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kdm/platform/NamingResourceImpl.cpp
 * Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
 * Copyright (C) INCHRON GmbH 2016-2019 <emf4cpp@inchron.com>
 * Copyright (C) INCHRON AG 2019-2021 <emf4cpp@inchron.com>
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

#include "NamingResource.hpp"
#include <kdm/platform/PlatformPackage.hpp>
#include <kdm/platform/ResourceType.hpp>
#include <kdm/kdm/Attribute.hpp>
#include <kdm/kdm/Annotation.hpp>
#include <kdm/kdm/Stereotype.hpp>
#include <kdm/kdm/ExtendedValue.hpp>
#include <kdm/source/SourceRef.hpp>
#include <kdm/platform/AbstractPlatformRelationship.hpp>
#include <kdm/action/ActionElement.hpp>
#include <kdm/code/AbstractCodeElement.hpp>
#include <kdm/platform/AbstractPlatformElement.hpp>
#include <kdm/core/KDMRelationship.hpp>
#include <kdm/core/AggregatedRelationship.hpp>
#include <kdm/core/KDMEntity.hpp>
#include <kdm/kdm/KDMModel.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

/*PROTECTED REGION ID(NamingResourceImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::kdm::platform;

void NamingResource::_initialize()
{
    // Supertypes
    ::kdm::platform::ResourceType::_initialize();

    // References

    /*PROTECTED REGION ID(NamingResourceImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations

// EObject
::ecore::EJavaObject NamingResource::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean /*_resolve*/)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ATTRIBUTE:
    {
        _any = getAttribute().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ANNOTATION:
    {
        _any = getAnnotation().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__STEREOTYPE:
    {
        _any = getStereotype().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__TAGGEDVALUE:
    {
        _any = getTaggedValue().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__NAME:
    {
        ::ecorecpp::mapping::any_traits < ::kdm::core::String
                > ::toAny(_any, getName());
    }
        return _any;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__SOURCE:
    {
        _any = getSource().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__RELATION:
    {
        _any = getRelation().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ABSTRACTION:
    {
        _any = getAbstraction().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__IMPLEMENTATION:
    {
        _any = getImplementation().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__PLATFORMELEMENT:
    {
        _any = getPlatformElement().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;

    }
    throw "Error: eGet() does not handle this featureID";
}

void NamingResource::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ATTRIBUTE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getAttribute().clear();
        getAttribute().insert_all(*_t0);
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ANNOTATION:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getAnnotation().clear();
        getAnnotation().insert_all(*_t0);
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__STEREOTYPE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getStereotype().clear();
        getStereotype().insert_all(*_t0);
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__TAGGEDVALUE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getTaggedValue().clear();
        getTaggedValue().insert_all(*_t0);
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__NAME:
    {
        ::kdm::core::String _t0;
        ::ecorecpp::mapping::any_traits < ::kdm::core::String
                > ::fromAny(_newValue, _t0);
        setName(_t0);
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__SOURCE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getSource().clear();
        getSource().insert_all(*_t0);
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__RELATION:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getRelation().clear();
        getRelation().insert_all(*_t0);
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ABSTRACTION:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getAbstraction().clear();
        getAbstraction().insert_all(*_t0);
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__IMPLEMENTATION:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getImplementation().clear();
        getImplementation().insert_all(*_t0);
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__PLATFORMELEMENT:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getPlatformElement().clear();
        getPlatformElement().insert_all(*_t0);
    }
        return;

    }
    throw "Error: eSet() does not handle this featureID";
}

::ecore::EBoolean NamingResource::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ATTRIBUTE:
        return getAttribute().size() > 0;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ANNOTATION:
        return getAnnotation().size() > 0;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__STEREOTYPE:
        return getStereotype().size() > 0;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__TAGGEDVALUE:
        return getTaggedValue().size() > 0;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__NAME:
        return ::ecorecpp::mapping::set_traits < ::kdm::core::String
                > ::is_set(getName());
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__SOURCE:
        return getSource().size() > 0;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__RELATION:
        return getRelation().size() > 0;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ABSTRACTION:
        return getAbstraction().size() > 0;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__IMPLEMENTATION:
        return getImplementation().size() > 0;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__PLATFORMELEMENT:
        return getPlatformElement().size() > 0;

    }
    throw "Error: eIsSet() does not handle this featureID";
}

void NamingResource::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error: eUnset() does not handle this featureID";
}

::ecore::EClass_ptr NamingResource::_eClass()
{
    static ::ecore::EClass_ptr _eclass =
            ::kdm::platform::PlatformPackage::_instance()->getNamingResource();
    return _eclass;
}

/** Set the local end of a reference with an EOpposite property.
 */
void NamingResource::_inverseAdd(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ATTRIBUTE:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ANNOTATION:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__STEREOTYPE:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__TAGGEDVALUE:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__SOURCE:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__RELATION:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ABSTRACTION:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__IMPLEMENTATION:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__PLATFORMELEMENT:
    {
    }
        return;

    }
    throw "Error: _inverseAdd() does not handle this featureID";
}

/** Unset the local end of a reference with an EOpposite property.
 */
void NamingResource::_inverseRemove(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_oldValue)
{
    switch (_featureID)
    {
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ATTRIBUTE:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ANNOTATION:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__STEREOTYPE:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__TAGGEDVALUE:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__SOURCE:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__RELATION:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__ABSTRACTION:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__IMPLEMENTATION:
    {
    }
        return;
    case ::kdm::platform::PlatformPackage::NAMINGRESOURCE__PLATFORMELEMENT:
    {
    }
        return;

    }
    throw "Error: _inverseRemove() does not handle this featureID";
}

