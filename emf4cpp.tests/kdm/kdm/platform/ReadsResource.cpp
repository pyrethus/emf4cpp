// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kdm/platform/ReadsResource.cpp
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

#include "ReadsResource.hpp"
#include <kdm/action/AbstractActionRelationship.hpp>
#include <kdm/kdm/Attribute.hpp>
#include <kdm/kdm/Annotation.hpp>
#include <kdm/kdm/Stereotype.hpp>
#include <kdm/kdm/ExtendedValue.hpp>
#include <kdm/platform/ResourceType.hpp>
#include <kdm/action/ActionElement.hpp>
#include <kdm/core/KDMEntity.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kdm/platform/PlatformPackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

/*PROTECTED REGION ID(ReadsResource.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::kdm::platform;

// Default constructor
ReadsResource::ReadsResource()
{
    /*PROTECTED REGION ID(ReadsResourceImpl__ReadsResourceImpl) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API
    m_eDeliver = false;
#endif
}

ReadsResource::~ReadsResource()
{
}

// Attributes

// References

::kdm::platform::ResourceType_ptr ReadsResource::getTo() const
{
    return m_to.lock();
}

void ReadsResource::setTo(::kdm::platform::ResourceType_ptr _to)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::kdm::platform::ResourceType_ptr _old_to = m_to.lock();
#endif
    m_to = _to;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::kdm::platform::PlatformPackage::_instance()->getReadsResource__to(),
                _old_to,
                m_to.lock()
            );
        eNotify(&notification);
    }
#endif
}

::kdm::action::ActionElement_ptr ReadsResource::getFrom() const
{
    return m_from.lock();
}

void ReadsResource::setFrom(::kdm::action::ActionElement_ptr _from)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::kdm::action::ActionElement_ptr _old_from = m_from.lock();
#endif
    m_from = _from;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::kdm::platform::PlatformPackage::_instance()->getReadsResource__from(),
                _old_from,
                m_from.lock()
            );
        eNotify(&notification);
    }
#endif
}

