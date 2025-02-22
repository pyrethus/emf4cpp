// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kdm/core/KDMEntityImpl.cpp
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

#include "KDMEntity.hpp"
#include <kdm/core/CorePackage.hpp>
#include <kdm/core/ModelElement.hpp>
#include <kdm/kdm/Attribute.hpp>
#include <kdm/kdm/Annotation.hpp>
#include <kdm/kdm/Stereotype.hpp>
#include <kdm/kdm/ExtendedValue.hpp>
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

/*PROTECTED REGION ID(KDMEntityImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::kdm::core;

void KDMEntity::_initialize()
{
    // Supertypes
    ::kdm::core::ModelElement::_initialize();

    // References

    /*PROTECTED REGION ID(KDMEntityImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations

void KDMEntity::createAggregation(::kdm::core::KDMEntity_ptr _otherEntity)
{
    /*PROTECTED REGION ID(KDMEntityImpl_createAggregation) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    throw "UnsupportedOperationException: kdm::core::KDMEntity::createAggregation";
    /*PROTECTED REGION END*/
}

void KDMEntity::deleteAggregation(
        ::kdm::core::AggregatedRelationship_ptr _aggregation)
{
    /*PROTECTED REGION ID(KDMEntityImpl_deleteAggregation) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    throw "UnsupportedOperationException: kdm::core::KDMEntity::deleteAggregation";
    /*PROTECTED REGION END*/
}

::kdm::core::KDMRelationship_ptr KDMEntity::getInbound()
{
    /*PROTECTED REGION ID(KDMEntityImpl_getInbound) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    throw "UnsupportedOperationException: kdm::core::KDMEntity::getInbound";
    /*PROTECTED REGION END*/
}

::kdm::core::KDMRelationship_ptr KDMEntity::getOutbound()
{
    /*PROTECTED REGION ID(KDMEntityImpl_getOutbound) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    throw "UnsupportedOperationException: kdm::core::KDMEntity::getOutbound";
    /*PROTECTED REGION END*/
}

::kdm::core::KDMRelationship_ptr KDMEntity::getOwnedRelation()
{
    /*PROTECTED REGION ID(KDMEntityImpl_getOwnedRelation) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    throw "UnsupportedOperationException: kdm::core::KDMEntity::getOwnedRelation";
    /*PROTECTED REGION END*/
}

::kdm::core::AggregatedRelationship_ptr KDMEntity::getInAggregated()
{
    /*PROTECTED REGION ID(KDMEntityImpl_getInAggregated) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    throw "UnsupportedOperationException: kdm::core::KDMEntity::getInAggregated";
    /*PROTECTED REGION END*/
}

::kdm::core::AggregatedRelationship_ptr KDMEntity::getOutAggregated()
{
    /*PROTECTED REGION ID(KDMEntityImpl_getOutAggregated) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    throw "UnsupportedOperationException: kdm::core::KDMEntity::getOutAggregated";
    /*PROTECTED REGION END*/
}

::kdm::core::KDMEntity_ptr KDMEntity::getOwner()
{
    /*PROTECTED REGION ID(KDMEntityImpl_getOwner) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    throw "UnsupportedOperationException: kdm::core::KDMEntity::getOwner";
    /*PROTECTED REGION END*/
}

::kdm::core::KDMEntity_ptr KDMEntity::getOwnedElement()
{
    /*PROTECTED REGION ID(KDMEntityImpl_getOwnedElement) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    throw "UnsupportedOperationException: kdm::core::KDMEntity::getOwnedElement";
    /*PROTECTED REGION END*/
}

::kdm::core::KDMEntity_ptr KDMEntity::getGroup()
{
    /*PROTECTED REGION ID(KDMEntityImpl_getGroup) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    throw "UnsupportedOperationException: kdm::core::KDMEntity::getGroup";
    /*PROTECTED REGION END*/
}

::kdm::core::KDMEntity_ptr KDMEntity::getGroupedElement()
{
    /*PROTECTED REGION ID(KDMEntityImpl_getGroupedElement) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    throw "UnsupportedOperationException: kdm::core::KDMEntity::getGroupedElement";
    /*PROTECTED REGION END*/
}

::kdm::kdm::KDMModel_ptr KDMEntity::getModel()
{
    /*PROTECTED REGION ID(KDMEntityImpl_getModel) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    throw "UnsupportedOperationException: kdm::core::KDMEntity::getModel";
    /*PROTECTED REGION END*/
}

// EObject
::ecore::EJavaObject KDMEntity::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean /*_resolve*/)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::kdm::core::CorePackage::KDMENTITY__ATTRIBUTE:
    {
        _any = getAttribute().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::core::CorePackage::KDMENTITY__ANNOTATION:
    {
        _any = getAnnotation().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::core::CorePackage::KDMENTITY__STEREOTYPE:
    {
        _any = getStereotype().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::core::CorePackage::KDMENTITY__TAGGEDVALUE:
    {
        _any = getTaggedValue().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::core::CorePackage::KDMENTITY__NAME:
    {
        ::ecorecpp::mapping::any_traits < ::kdm::core::String
                > ::toAny(_any, getName());
    }
        return _any;

    }
    throw "Error: eGet() does not handle this featureID";
}

void KDMEntity::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::kdm::core::CorePackage::KDMENTITY__ATTRIBUTE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getAttribute().clear();
        getAttribute().insert_all(*_t0);
    }
        return;
    case ::kdm::core::CorePackage::KDMENTITY__ANNOTATION:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getAnnotation().clear();
        getAnnotation().insert_all(*_t0);
    }
        return;
    case ::kdm::core::CorePackage::KDMENTITY__STEREOTYPE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getStereotype().clear();
        getStereotype().insert_all(*_t0);
    }
        return;
    case ::kdm::core::CorePackage::KDMENTITY__TAGGEDVALUE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getTaggedValue().clear();
        getTaggedValue().insert_all(*_t0);
    }
        return;
    case ::kdm::core::CorePackage::KDMENTITY__NAME:
    {
        ::kdm::core::String _t0;
        ::ecorecpp::mapping::any_traits < ::kdm::core::String
                > ::fromAny(_newValue, _t0);
        setName(_t0);
    }
        return;

    }
    throw "Error: eSet() does not handle this featureID";
}

::ecore::EBoolean KDMEntity::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kdm::core::CorePackage::KDMENTITY__ATTRIBUTE:
        return getAttribute().size() > 0;
    case ::kdm::core::CorePackage::KDMENTITY__ANNOTATION:
        return getAnnotation().size() > 0;
    case ::kdm::core::CorePackage::KDMENTITY__STEREOTYPE:
        return getStereotype().size() > 0;
    case ::kdm::core::CorePackage::KDMENTITY__TAGGEDVALUE:
        return getTaggedValue().size() > 0;
    case ::kdm::core::CorePackage::KDMENTITY__NAME:
        return ::ecorecpp::mapping::set_traits < ::kdm::core::String
                > ::is_set(getName());

    }
    throw "Error: eIsSet() does not handle this featureID";
}

void KDMEntity::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error: eUnset() does not handle this featureID";
}

::ecore::EClass_ptr KDMEntity::_eClass()
{
    static ::ecore::EClass_ptr _eclass =
            ::kdm::core::CorePackage::_instance()->getKDMEntity();
    return _eclass;
}

/** Set the local end of a reference with an EOpposite property.
 */
void KDMEntity::_inverseAdd(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::kdm::core::CorePackage::KDMENTITY__ATTRIBUTE:
    {
    }
        return;
    case ::kdm::core::CorePackage::KDMENTITY__ANNOTATION:
    {
    }
        return;
    case ::kdm::core::CorePackage::KDMENTITY__STEREOTYPE:
    {
    }
        return;
    case ::kdm::core::CorePackage::KDMENTITY__TAGGEDVALUE:
    {
    }
        return;

    }
    throw "Error: _inverseAdd() does not handle this featureID";
}

/** Unset the local end of a reference with an EOpposite property.
 */
void KDMEntity::_inverseRemove(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_oldValue)
{
    switch (_featureID)
    {
    case ::kdm::core::CorePackage::KDMENTITY__ATTRIBUTE:
    {
    }
        return;
    case ::kdm::core::CorePackage::KDMENTITY__ANNOTATION:
    {
    }
        return;
    case ::kdm::core::CorePackage::KDMENTITY__STEREOTYPE:
    {
    }
        return;
    case ::kdm::core::CorePackage::KDMENTITY__TAGGEDVALUE:
    {
    }
        return;

    }
    throw "Error: _inverseRemove() does not handle this featureID";
}

