// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kdm/event/StateImpl.cpp
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

#include "State.hpp"
#include <kdm/event/EventPackage.hpp>
#include <kdm/event/EventResource.hpp>
#include <kdm/kdm/Attribute.hpp>
#include <kdm/kdm/Annotation.hpp>
#include <kdm/kdm/Stereotype.hpp>
#include <kdm/kdm/ExtendedValue.hpp>
#include <kdm/source/SourceRef.hpp>
#include <kdm/event/AbstractEventRelationship.hpp>
#include <kdm/action/ActionElement.hpp>
#include <kdm/code/AbstractCodeElement.hpp>
#include <kdm/event/AbstractEventElement.hpp>
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

/*PROTECTED REGION ID(StateImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::kdm::event;

void State::_initialize()
{
    // Supertypes
    ::kdm::event::EventResource::_initialize();

    // References

    /*PROTECTED REGION ID(StateImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations

// EObject
::ecore::EJavaObject State::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean /*_resolve*/)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::kdm::event::EventPackage::STATE__ATTRIBUTE:
    {
        _any = getAttribute().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::event::EventPackage::STATE__ANNOTATION:
    {
        _any = getAnnotation().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::event::EventPackage::STATE__STEREOTYPE:
    {
        _any = getStereotype().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::event::EventPackage::STATE__TAGGEDVALUE:
    {
        _any = getTaggedValue().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::event::EventPackage::STATE__NAME:
    {
        ::ecorecpp::mapping::any_traits < ::kdm::core::String
                > ::toAny(_any, getName());
    }
        return _any;
    case ::kdm::event::EventPackage::STATE__SOURCE:
    {
        _any = getSource().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::event::EventPackage::STATE__EVENTRELATION:
    {
        _any = getEventRelation().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::event::EventPackage::STATE__ABSTRACTION:
    {
        _any = getAbstraction().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::event::EventPackage::STATE__IMPLEMENTATION:
    {
        _any = getImplementation().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::kdm::event::EventPackage::STATE__EVENTELEMENT:
    {
        _any = getEventElement().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;

    }
    throw "Error: eGet() does not handle this featureID";
}

void State::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::kdm::event::EventPackage::STATE__ATTRIBUTE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getAttribute().clear();
        getAttribute().insert_all(*_t0);
    }
        return;
    case ::kdm::event::EventPackage::STATE__ANNOTATION:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getAnnotation().clear();
        getAnnotation().insert_all(*_t0);
    }
        return;
    case ::kdm::event::EventPackage::STATE__STEREOTYPE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getStereotype().clear();
        getStereotype().insert_all(*_t0);
    }
        return;
    case ::kdm::event::EventPackage::STATE__TAGGEDVALUE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getTaggedValue().clear();
        getTaggedValue().insert_all(*_t0);
    }
        return;
    case ::kdm::event::EventPackage::STATE__NAME:
    {
        ::kdm::core::String _t0;
        ::ecorecpp::mapping::any_traits < ::kdm::core::String
                > ::fromAny(_newValue, _t0);
        setName(_t0);
    }
        return;
    case ::kdm::event::EventPackage::STATE__SOURCE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getSource().clear();
        getSource().insert_all(*_t0);
    }
        return;
    case ::kdm::event::EventPackage::STATE__EVENTRELATION:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getEventRelation().clear();
        getEventRelation().insert_all(*_t0);
    }
        return;
    case ::kdm::event::EventPackage::STATE__ABSTRACTION:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getAbstraction().clear();
        getAbstraction().insert_all(*_t0);
    }
        return;
    case ::kdm::event::EventPackage::STATE__IMPLEMENTATION:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getImplementation().clear();
        getImplementation().insert_all(*_t0);
    }
        return;
    case ::kdm::event::EventPackage::STATE__EVENTELEMENT:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getEventElement().clear();
        getEventElement().insert_all(*_t0);
    }
        return;

    }
    throw "Error: eSet() does not handle this featureID";
}

::ecore::EBoolean State::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kdm::event::EventPackage::STATE__ATTRIBUTE:
        return getAttribute().size() > 0;
    case ::kdm::event::EventPackage::STATE__ANNOTATION:
        return getAnnotation().size() > 0;
    case ::kdm::event::EventPackage::STATE__STEREOTYPE:
        return getStereotype().size() > 0;
    case ::kdm::event::EventPackage::STATE__TAGGEDVALUE:
        return getTaggedValue().size() > 0;
    case ::kdm::event::EventPackage::STATE__NAME:
        return ::ecorecpp::mapping::set_traits < ::kdm::core::String
                > ::is_set(getName());
    case ::kdm::event::EventPackage::STATE__SOURCE:
        return getSource().size() > 0;
    case ::kdm::event::EventPackage::STATE__EVENTRELATION:
        return getEventRelation().size() > 0;
    case ::kdm::event::EventPackage::STATE__ABSTRACTION:
        return getAbstraction().size() > 0;
    case ::kdm::event::EventPackage::STATE__IMPLEMENTATION:
        return getImplementation().size() > 0;
    case ::kdm::event::EventPackage::STATE__EVENTELEMENT:
        return getEventElement().size() > 0;

    }
    throw "Error: eIsSet() does not handle this featureID";
}

void State::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error: eUnset() does not handle this featureID";
}

::ecore::EClass_ptr State::_eClass()
{
    static ::ecore::EClass_ptr _eclass =
            ::kdm::event::EventPackage::_instance()->getState();
    return _eclass;
}

/** Set the local end of a reference with an EOpposite property.
 */
void State::_inverseAdd(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::kdm::event::EventPackage::STATE__ATTRIBUTE:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__ANNOTATION:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__STEREOTYPE:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__TAGGEDVALUE:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__SOURCE:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__EVENTRELATION:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__ABSTRACTION:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__IMPLEMENTATION:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__EVENTELEMENT:
    {
    }
        return;

    }
    throw "Error: _inverseAdd() does not handle this featureID";
}

/** Unset the local end of a reference with an EOpposite property.
 */
void State::_inverseRemove(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_oldValue)
{
    switch (_featureID)
    {
    case ::kdm::event::EventPackage::STATE__ATTRIBUTE:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__ANNOTATION:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__STEREOTYPE:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__TAGGEDVALUE:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__SOURCE:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__EVENTRELATION:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__ABSTRACTION:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__IMPLEMENTATION:
    {
    }
        return;
    case ::kdm::event::EventPackage::STATE__EVENTELEMENT:
    {
    }
        return;

    }
    throw "Error: _inverseRemove() does not handle this featureID";
}

