// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * ResourceTests/RootImpl.cpp
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

#include "Root.hpp"
#include <ResourceTests/ResourceTestsPackage.hpp>
#include <ResourceTests/ReferenceTarget.hpp>
#include <ResourceTests/Referrer.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

/*PROTECTED REGION ID(RootImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::ResourceTests;

void Root::_initialize()
{
    // Supertypes

    // References
    if (m_target)
    {
        m_target->_initialize();
    }
    for (const auto &ref : getReferrers())
    {
        ref->_initialize();
    }

    /*PROTECTED REGION ID(RootImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations

// EObject
::ecore::EJavaObject Root::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean /*_resolve*/)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::ResourceTests::ResourceTestsPackage::ROOT__TARGET:
    {
        _any = ::ecore::as < ::ecore::EObject > (getTarget());
    }
        return _any;
    case ::ResourceTests::ResourceTestsPackage::ROOT__REFERRERS:
    {
        _any = getReferrers().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;

    }
    throw "Error: eGet() does not handle this featureID";
}

void Root::eSet(::ecore::EInt _featureID, ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::ResourceTests::ResourceTestsPackage::ROOT__TARGET:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::ResourceTests::ReferenceTarget > (_t0);
        setTarget(_t1);
    }
        return;
    case ::ResourceTests::ResourceTestsPackage::ROOT__REFERRERS:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getReferrers().clear();
        getReferrers().insert_all(*_t0);
    }
        return;

    }
    throw "Error: eSet() does not handle this featureID";
}

::ecore::EBoolean Root::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::ResourceTests::ResourceTestsPackage::ROOT__TARGET:
        return getTarget().get() != nullptr;
    case ::ResourceTests::ResourceTestsPackage::ROOT__REFERRERS:
        return getReferrers().size() > 0;

    }
    throw "Error: eIsSet() does not handle this featureID";
}

void Root::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error: eUnset() does not handle this featureID";
}

::ecore::EClass_ptr Root::_eClass()
{
    static ::ecore::EClass_ptr _eclass =
            ::ResourceTests::ResourceTestsPackage::_instance()->getRoot();
    return _eclass;
}

/** Set the local end of a reference with an EOpposite property.
 */
void Root::_inverseAdd(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::ResourceTests::ResourceTestsPackage::ROOT__TARGET:
    {
    }
        return;
    case ::ResourceTests::ResourceTestsPackage::ROOT__REFERRERS:
    {
    }
        return;

    }
    throw "Error: _inverseAdd() does not handle this featureID";
}

/** Unset the local end of a reference with an EOpposite property.
 */
void Root::_inverseRemove(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_oldValue)
{
    switch (_featureID)
    {
    case ::ResourceTests::ResourceTestsPackage::ROOT__TARGET:
    {
    }
        return;
    case ::ResourceTests::ResourceTestsPackage::ROOT__REFERRERS:
    {
    }
        return;

    }
    throw "Error: _inverseRemove() does not handle this featureID";
}

