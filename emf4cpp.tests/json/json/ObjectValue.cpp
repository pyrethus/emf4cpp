// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * json/ObjectValue.cpp
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

#include "ObjectValue.hpp"
#include <json/Value.hpp>
#include <json/NVPair.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "json/JsonPackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

/*PROTECTED REGION ID(ObjectValue.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::json;

// Default constructor
ObjectValue::ObjectValue()
{
    /*PROTECTED REGION ID(ObjectValueImpl__ObjectValueImpl) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API
    m_eDeliver = false;
#endif
}

ObjectValue::~ObjectValue()
{
}

// Attributes

// References

const ::ecorecpp::mapping::EList< ::json::NVPair_ptr >& ObjectValue::getMembers() const
{
    if (!m_members)
        return const_cast< ObjectValue* >(this)->getMembers();

    return *m_members;
}

::ecorecpp::mapping::EList< ::json::NVPair_ptr >& ObjectValue::getMembers()
{
    /*PROTECTED REGION ID(ObjectValue__getMembers) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    if (!m_members)
        m_members.reset(
                new ::ecorecpp::mapping::ReferenceEListImpl< ::json::NVPair_ptr,
                        -1, true, false >(this,
                        ::json::JsonPackage::_instance()->getObjectValue__members()));
    /*PROTECTED REGION END*/
    return *m_members;
}

