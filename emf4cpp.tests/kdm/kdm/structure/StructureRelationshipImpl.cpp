// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kdm/structure/StructureRelationshipImpl.cpp
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

#include "StructureRelationship.hpp"
#include <kdm/structure/StructurePackage.hpp>
#include <kdm/structure/AbstractStructureRelationship.hpp>
#include <kdm/kdm/Attribute.hpp>
#include <kdm/kdm/Annotation.hpp>
#include <kdm/kdm/Stereotype.hpp>
#include <kdm/kdm/ExtendedValue.hpp>
#include <kdm/core/KDMEntity.hpp>
#include <kdm/structure/AbstractStructureElement.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

/*PROTECTED REGION ID(StructureRelationshipImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::kdm::structure;

void StructureRelationship::_initialize()
{
    // Supertypes
    ::kdm::structure::AbstractStructureRelationship::_initialize();

    // References

    /*PROTECTED REGION ID(StructureRelationshipImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations

// EObject
::ecore::EJavaObject StructureRelationship::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean /*_resolve*/)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__ATTRIBUTE:
    {
        _any = getAttribute().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__ANNOTATION:
    {
        _any = getAnnotation().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__STEREOTYPE:
    {
        _any = getStereotype().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__TAGGEDVALUE:
    {
        _any = getTaggedValue().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__TO:
    {
        _any = ::ecore::as < ::ecore::EObject > (getTo());
    }
        return _any;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__FROM:
    {
        _any = ::ecore::as < ::ecore::EObject > (getFrom());
    }
        return _any;

    }
    throw "Error: eGet() does not handle this featureID";
}

void StructureRelationship::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__ATTRIBUTE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getAttribute().clear();
        getAttribute().insert_all(*_t0);
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__ANNOTATION:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getAnnotation().clear();
        getAnnotation().insert_all(*_t0);
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__STEREOTYPE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getStereotype().clear();
        getStereotype().insert_all(*_t0);
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__TAGGEDVALUE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getTaggedValue().clear();
        getTaggedValue().insert_all(*_t0);
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__TO:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::kdm::core::KDMEntity > (_t0);
        setTo(_t1);
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__FROM:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::kdm::structure::AbstractStructureElement
                > (_t0);
        setFrom(_t1);
    }
        return;

    }
    throw "Error: eSet() does not handle this featureID";
}

::ecore::EBoolean StructureRelationship::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__ATTRIBUTE:
        return getAttribute().size() > 0;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__ANNOTATION:
        return getAnnotation().size() > 0;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__STEREOTYPE:
        return getStereotype().size() > 0;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__TAGGEDVALUE:
        return getTaggedValue().size() > 0;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__TO:
        return getTo().get() != nullptr;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__FROM:
        return getFrom().get() != nullptr;

    }
    throw "Error: eIsSet() does not handle this featureID";
}

void StructureRelationship::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error: eUnset() does not handle this featureID";
}

::ecore::EClass_ptr StructureRelationship::_eClass()
{
    static ::ecore::EClass_ptr _eclass =
            ::kdm::structure::StructurePackage::_instance()->getStructureRelationship();
    return _eclass;
}

/** Set the local end of a reference with an EOpposite property.
 */
void StructureRelationship::_inverseAdd(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__ATTRIBUTE:
    {
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__ANNOTATION:
    {
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__STEREOTYPE:
    {
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__TAGGEDVALUE:
    {
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__TO:
    {
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__FROM:
    {
    }
        return;

    }
    throw "Error: _inverseAdd() does not handle this featureID";
}

/** Unset the local end of a reference with an EOpposite property.
 */
void StructureRelationship::_inverseRemove(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_oldValue)
{
    switch (_featureID)
    {
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__ATTRIBUTE:
    {
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__ANNOTATION:
    {
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__STEREOTYPE:
    {
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__TAGGEDVALUE:
    {
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__TO:
    {
    }
        return;
    case ::kdm::structure::StructurePackage::STRUCTURERELATIONSHIP__FROM:
    {
    }
        return;

    }
    throw "Error: _inverseRemove() does not handle this featureID";
}

