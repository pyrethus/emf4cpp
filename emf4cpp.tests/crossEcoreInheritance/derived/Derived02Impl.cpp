// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * derived/Derived02Impl.cpp
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

#include "Derived02.hpp"
#include <derived/DerivedPackage.hpp>
#include <derived/Derived01.hpp>
#include <derived/Derived02.hpp>
#include <base/Base01.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

/*PROTECTED REGION ID(Derived02Impl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::derived;

void Derived02::_initialize()
{
    // Supertypes
    ::derived::Derived01::_initialize();

    // References

    /*PROTECTED REGION ID(Derived02Impl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations

// EObject
::ecore::EJavaObject Derived02::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean /*_resolve*/)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::derived::DerivedPackage::DERIVED02__VALBASE01:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::toAny(_any, getValBase01());
    }
        return _any;
    case ::derived::DerivedPackage::DERIVED02__DERIVED02REF:
    {
        _any = ::ecore::as < ::ecore::EObject > (getDerived02ref());
    }
        return _any;
    case ::derived::DerivedPackage::DERIVED02__VALBASE10:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::toAny(_any, getValBase10());
    }
        return _any;
    case ::derived::DerivedPackage::DERIVED02__VALBASE02:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::toAny(_any, getValBase02());
    }
        return _any;
    case ::derived::DerivedPackage::DERIVED02__VALBASE03:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::toAny(_any, getValBase03());
    }
        return _any;
    case ::derived::DerivedPackage::DERIVED02__VALBASE11:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::toAny(_any, getValBase11());
    }
        return _any;
    case ::derived::DerivedPackage::DERIVED02__VALBASE20:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::toAny(_any, getValBase20());
    }
        return _any;
    case ::derived::DerivedPackage::DERIVED02__VALDERIVED01:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::toAny(_any, getValDerived01());
    }
        return _any;
    case ::derived::DerivedPackage::DERIVED02__VALDERIVED02:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::toAny(_any, getValDerived02());
    }
        return _any;
    case ::derived::DerivedPackage::DERIVED02__BASE01REF:
    {
        _any = ::ecore::as < ::ecore::EObject > (getBase01ref());
    }
        return _any;

    }
    throw "Error: eGet() does not handle this featureID";
}

void Derived02::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::derived::DerivedPackage::DERIVED02__VALBASE01:
    {
        ::ecore::EInt _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::fromAny(_newValue, _t0);
        setValBase01(_t0);
    }
        return;
    case ::derived::DerivedPackage::DERIVED02__DERIVED02REF:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::derived::Derived02 > (_t0);
        setDerived02ref(_t1);
    }
        return;
    case ::derived::DerivedPackage::DERIVED02__VALBASE10:
    {
        ::ecore::EInt _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::fromAny(_newValue, _t0);
        setValBase10(_t0);
    }
        return;
    case ::derived::DerivedPackage::DERIVED02__VALBASE02:
    {
        ::ecore::EInt _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::fromAny(_newValue, _t0);
        setValBase02(_t0);
    }
        return;
    case ::derived::DerivedPackage::DERIVED02__VALBASE03:
    {
        ::ecore::EInt _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::fromAny(_newValue, _t0);
        setValBase03(_t0);
    }
        return;
    case ::derived::DerivedPackage::DERIVED02__VALBASE11:
    {
        ::ecore::EInt _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::fromAny(_newValue, _t0);
        setValBase11(_t0);
    }
        return;
    case ::derived::DerivedPackage::DERIVED02__VALBASE20:
    {
        ::ecore::EInt _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::fromAny(_newValue, _t0);
        setValBase20(_t0);
    }
        return;
    case ::derived::DerivedPackage::DERIVED02__VALDERIVED01:
    {
        ::ecore::EInt _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::fromAny(_newValue, _t0);
        setValDerived01(_t0);
    }
        return;
    case ::derived::DerivedPackage::DERIVED02__VALDERIVED02:
    {
        ::ecore::EInt _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::fromAny(_newValue, _t0);
        setValDerived02(_t0);
    }
        return;
    case ::derived::DerivedPackage::DERIVED02__BASE01REF:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::base::Base01 > (_t0);
        setBase01ref(_t1);
    }
        return;

    }
    throw "Error: eSet() does not handle this featureID";
}

::ecore::EBoolean Derived02::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::derived::DerivedPackage::DERIVED02__VALBASE01:
        return ::ecorecpp::mapping::set_traits < ::ecore::EInt
                > ::is_set(getValBase01());
    case ::derived::DerivedPackage::DERIVED02__DERIVED02REF:
        return getDerived02ref().get() != nullptr;
    case ::derived::DerivedPackage::DERIVED02__VALBASE10:
        return ::ecorecpp::mapping::set_traits < ::ecore::EInt
                > ::is_set(getValBase10());
    case ::derived::DerivedPackage::DERIVED02__VALBASE02:
        return ::ecorecpp::mapping::set_traits < ::ecore::EInt
                > ::is_set(getValBase02());
    case ::derived::DerivedPackage::DERIVED02__VALBASE03:
        return ::ecorecpp::mapping::set_traits < ::ecore::EInt
                > ::is_set(getValBase03());
    case ::derived::DerivedPackage::DERIVED02__VALBASE11:
        return ::ecorecpp::mapping::set_traits < ::ecore::EInt
                > ::is_set(getValBase11());
    case ::derived::DerivedPackage::DERIVED02__VALBASE20:
        return ::ecorecpp::mapping::set_traits < ::ecore::EInt
                > ::is_set(getValBase20());
    case ::derived::DerivedPackage::DERIVED02__VALDERIVED01:
        return ::ecorecpp::mapping::set_traits < ::ecore::EInt
                > ::is_set(getValDerived01());
    case ::derived::DerivedPackage::DERIVED02__VALDERIVED02:
        return ::ecorecpp::mapping::set_traits < ::ecore::EInt
                > ::is_set(getValDerived02());
    case ::derived::DerivedPackage::DERIVED02__BASE01REF:
        return getBase01ref().get() != nullptr;

    }
    throw "Error: eIsSet() does not handle this featureID";
}

void Derived02::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error: eUnset() does not handle this featureID";
}

::ecore::EClass_ptr Derived02::_eClass()
{
    static ::ecore::EClass_ptr _eclass =
            ::derived::DerivedPackage::_instance()->getDerived02();
    return _eclass;
}

/** Set the local end of a reference with an EOpposite property.
 */
void Derived02::_inverseAdd(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::derived::DerivedPackage::DERIVED02__DERIVED02REF:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_newValue);
        ::derived::Derived02_ptr _t1 = std::dynamic_pointer_cast
                < ::derived::Derived02 > (_t0);

        ::derived::Derived02_ptr _old_derived02ref = getDerived02ref();
        if (_old_derived02ref && _old_derived02ref != _t0)
        {
            ::ecore::EJavaObject _this = ::ecore::EObject::_this();
            _old_derived02ref->::ecore::EObject::_inverseRemove(
                    ::derived::DerivedPackage::_instance()->getDerived02__base01ref(),
                    _this);
        }

        // set reference
        basicsetDerived02ref(_t1);
    }
        return;
    case ::derived::DerivedPackage::DERIVED02__BASE01REF:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_newValue);
        ::base::Base01_ptr _t1 = std::dynamic_pointer_cast < ::base::Base01
                > (_t0);

        ::base::Base01_ptr _old_base01ref = getBase01ref();
        if (_old_base01ref && _old_base01ref != _t0)
        {
            ::ecore::EJavaObject _this = ::ecore::EObject::_this();
            _old_base01ref->::ecore::EObject::_inverseRemove(
                    ::base::BasePackage::_instance()->getBase01__derived02ref(),
                    _this);
        }

        // set reference
        basicsetBase01ref(_t1);
    }
        return;

    }
    throw "Error: _inverseAdd() does not handle this featureID";
}

/** Unset the local end of a reference with an EOpposite property.
 */
void Derived02::_inverseRemove(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_oldValue)
{
    switch (_featureID)
    {
    case ::derived::DerivedPackage::DERIVED02__DERIVED02REF:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_oldValue);
        ::derived::Derived02_ptr _t1 = std::dynamic_pointer_cast
                < ::derived::Derived02 > (_t0);

        // set reference
        if (basicgetDerived02ref() == _t1)
            basicsetDerived02ref(nullptr);
    }
        return;
    case ::derived::DerivedPackage::DERIVED02__BASE01REF:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_oldValue);
        ::base::Base01_ptr _t1 = std::dynamic_pointer_cast < ::base::Base01
                > (_t0);

        // set reference
        if (basicgetBase01ref() == _t1)
            basicsetBase01ref(nullptr);
    }
        return;

    }
    throw "Error: _inverseRemove() does not handle this featureID";
}

