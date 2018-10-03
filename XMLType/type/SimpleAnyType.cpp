// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * type/SimpleAnyType.cpp
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
#include <type/AnyType.hpp>
#include <ecore/EDataType.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "type/TypePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

/*PROTECTED REGION ID(SimpleAnyType.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::type;

// Default constructor
SimpleAnyType::SimpleAnyType() :
        m_instanceType(0)
{

    /*PROTECTED REGION ID(SimpleAnyTypeImpl__SimpleAnyTypeImpl) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API
    m_eDeliver = false;
#endif
}

SimpleAnyType::~SimpleAnyType()
{
}

// Attributes

::type::String SimpleAnyType::getRawValue() const
{
    return m_rawValue;
}

void SimpleAnyType::setRawValue(::type::String _rawValue)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::type::String _old_rawValue = m_rawValue;
#endif
    m_rawValue = _rawValue;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::type::TypePackage::_instance()->getSimpleAnyType__rawValue(),
                _old_rawValue,
                m_rawValue
        );
        eNotify(&notification);
    }
#endif
}

::type::AnySimpleType SimpleAnyType::getValue() const
{
    return m_value;
}

void SimpleAnyType::setValue(::type::AnySimpleType _value)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::type::AnySimpleType _old_value = m_value;
#endif
    m_value = _value;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::type::TypePackage::_instance()->getSimpleAnyType__value(),
                _old_value,
                m_value
        );
        eNotify(&notification);
    }
#endif
}

// References

::ecore::EDataType_ptr SimpleAnyType::getInstanceType() const
{
    return m_instanceType;
}

void SimpleAnyType::setInstanceType(::ecore::EDataType_ptr _instanceType)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EDataType_ptr _old_instanceType = m_instanceType;
#endif
    m_instanceType = _instanceType;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::type::TypePackage::_instance()->getSimpleAnyType__instanceType(),
                _old_instanceType,
                m_instanceType
        );
        eNotify(&notification);
    }
#endif
}

