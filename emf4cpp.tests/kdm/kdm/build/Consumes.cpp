// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kdm/build/Consumes.cpp
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

#include "Consumes.hpp"
#include <kdm/build/AbstractBuildRelationship.hpp>
#include <kdm/kdm/Attribute.hpp>
#include <kdm/kdm/Annotation.hpp>
#include <kdm/kdm/Stereotype.hpp>
#include <kdm/kdm/ExtendedValue.hpp>
#include <kdm/build/AbstractBuildElement.hpp>
#include <kdm/build/BuildStep.hpp>
#include <kdm/core/KDMEntity.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kdm/build/BuildPackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

/*PROTECTED REGION ID(Consumes.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::kdm::build;

// Default constructor
Consumes::Consumes()
{
    /*PROTECTED REGION ID(ConsumesImpl__ConsumesImpl) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API
    m_eDeliver = false;
#endif
}

Consumes::~Consumes()
{
}

// Attributes

// References

::kdm::build::AbstractBuildElement_ptr Consumes::getTo() const
{
    return m_to.lock();
}

void Consumes::setTo(::kdm::build::AbstractBuildElement_ptr _to)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::kdm::build::AbstractBuildElement_ptr _old_to = m_to.lock();
#endif
    m_to = _to;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::kdm::build::BuildPackage::_instance()->getConsumes__to(),
                _old_to,
                m_to.lock()
            );
        eNotify(&notification);
    }
#endif
}

::kdm::build::BuildStep_ptr Consumes::getFrom() const
{
    return m_from.lock();
}

void Consumes::setFrom(::kdm::build::BuildStep_ptr _from)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::kdm::build::BuildStep_ptr _old_from = m_from.lock();
#endif
    m_from = _from;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::kdm::build::BuildPackage::_instance()->getConsumes__from(),
                _old_from,
                m_from.lock()
            );
        eNotify(&notification);
    }
#endif
}

