// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * ecore/EAttribute.cpp
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

#include "EAttribute.hpp"
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EAnnotation.hpp>
#include <ecore/EClassifier.hpp>
#include <ecore/EGenericType.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EDataType.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "ecore/EcorePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

/*PROTECTED REGION ID(EAttribute.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::ecore;

// Default constructor
EAttribute::EAttribute()
{
    /*PROTECTED REGION ID(EAttributeImpl__EAttributeImpl) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API
    m_eDeliver = false;
#endif
}

EAttribute::~EAttribute()
{
}

// Attributes

::ecore::EBoolean EAttribute::isID() const
{
    return m_iD;
}

void EAttribute::setID(::ecore::EBoolean _iD)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EBoolean _old_iD = m_iD;
#endif
    m_iD = _iD;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::ecore::EcorePackage::_instance()->getEAttribute__iD(),
                _old_iD,
                m_iD
            );
        eNotify(&notification);
    }
#endif
}

// References

::ecore::EDataType_ptr EAttribute::getEAttributeType() const
{
    return m_eAttributeType.lock();
}

void EAttribute::setEAttributeType(::ecore::EDataType_ptr _eAttributeType)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EDataType_ptr _old_eAttributeType = m_eAttributeType.lock();
#endif
    m_eAttributeType = _eAttributeType;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::ecore::EcorePackage::_instance()->getEAttribute__eAttributeType(),
                _old_eAttributeType,
                m_eAttributeType.lock()
            );
        eNotify(&notification);
    }
#endif
}

