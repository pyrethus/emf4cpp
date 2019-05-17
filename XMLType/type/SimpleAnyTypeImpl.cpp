// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * type/SimpleAnyTypeImpl.cpp
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

#include "SimpleAnyType.hpp"
#include <type/TypePackage.hpp>
#include <type/AnyType.hpp>
#include <ecore/EDataType.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

/*PROTECTED REGION ID(SimpleAnyTypeImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::type;

void SimpleAnyType::_initialize()
{
    // Supertypes
    ::type::AnyType::_initialize();

    // References

    /*PROTECTED REGION ID(SimpleAnyTypeImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations

// EObject
::ecore::EJavaObject SimpleAnyType::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::type::TypePackage::ANYTYPE__MIXED:
    {
        std::vector < ::ecorecpp::mapping::any > _anys(m_mixed.size());
        for (size_t _i = 0; _i < m_mixed.size(); _i++)
            ::ecorecpp::mapping::any_traits < ::ecore::EFeatureMapEntry
                    > ::toAny(_anys[_i], m_mixed[_i]);
        _any = _anys;
    }
        return _any;
    case ::type::TypePackage::ANYTYPE__ANYATTRIBUTE:
    {
        std::vector < ::ecorecpp::mapping::any > _anys(m_anyAttribute.size());
        for (size_t _i = 0; _i < m_anyAttribute.size(); _i++)
            ::ecorecpp::mapping::any_traits < ::ecore::EFeatureMapEntry
                    > ::toAny(_anys[_i], m_anyAttribute[_i]);
        _any = _anys;
    }
        return _any;
    case ::type::TypePackage::SIMPLEANYTYPE__INSTANCETYPE:
    {
        if (m_instanceType)
            _any = ::ecore::as < ::ecore::EObject > (m_instanceType);
    }
        return _any;

    }
    throw "Error";
}

void SimpleAnyType::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::type::TypePackage::ANYTYPE__MIXED:
    {
        ::ecore::EFeatureMapEntry _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EFeatureMapEntry
                > ::fromAny(_newValue, _t0);
        ::type::AnyType::addMixed(_t0);
    }
        return;
    case ::type::TypePackage::ANYTYPE__ANYATTRIBUTE:
    {
        ::ecore::EFeatureMapEntry _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EFeatureMapEntry
                > ::fromAny(_newValue, _t0);
        ::type::AnyType::addAnyAttribute(_t0);
    }
        return;
    case ::type::TypePackage::SIMPLEANYTYPE__INSTANCETYPE:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_newValue);
        ::ecore::EDataType_ptr _t1 = std::dynamic_pointer_cast
                < ::ecore::EDataType > (_t0);
        ::type::SimpleAnyType::setInstanceType(_t1);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean SimpleAnyType::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::type::TypePackage::ANYTYPE__MIXED:
        return m_mixed.size();
    case ::type::TypePackage::ANYTYPE__ANY:
        return m_any.size();
    case ::type::TypePackage::ANYTYPE__ANYATTRIBUTE:
        return m_anyAttribute.size();
    case ::type::TypePackage::SIMPLEANYTYPE__RAWVALUE:
        return ::ecorecpp::mapping::set_traits < ::type::String
                > ::is_set(m_rawValue);
    case ::type::TypePackage::SIMPLEANYTYPE__VALUE:
        return ::ecorecpp::mapping::set_traits < ::type::AnySimpleType
                > ::is_set(m_value);
    case ::type::TypePackage::SIMPLEANYTYPE__INSTANCETYPE:
        return (bool) m_instanceType;

    }
    throw "Error";
}

void SimpleAnyType::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr SimpleAnyType::_eClass()
{
    static ::ecore::EClass_ptr _eclass =
            dynamic_cast< ::type::TypePackage* >(::type::TypePackage::_instance().get())->getSimpleAnyType();
    return _eclass;
}

/** Set the local end of a reference with an EOpposite property.
 */
void SimpleAnyType::_inverseAdd(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::type::TypePackage::SIMPLEANYTYPE__INSTANCETYPE:
    {
    }
        return;

    }
    throw "Error: _inverseAdd() does not handle this featureID";
}

/** Unset the local end of a reference with an EOpposite property.
 */
void SimpleAnyType::_inverseRemove(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _oldValue)
{
    switch (_featureID)
    {
    case ::type::TypePackage::SIMPLEANYTYPE__INSTANCETYPE:
    {
    }
        return;

    }
    throw "Error: _inverseRemove() does not handle this featureID";
}

