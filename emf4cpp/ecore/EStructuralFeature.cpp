// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * ecore/EStructuralFeature.cpp
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

#include "EStructuralFeature.hpp"
#include <ecore/ETypedElement.hpp>
#include <ecore/EAnnotation.hpp>
#include <ecore/EClassifier.hpp>
#include <ecore/EGenericType.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "ecore/EcorePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

/*PROTECTED REGION ID(EStructuralFeature.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::ecore;

// Default constructor
EStructuralFeature::EStructuralFeature()
{
    /*PROTECTED REGION ID(EStructuralFeatureImpl__EStructuralFeatureImpl) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API
    m_eDeliver = false;
#endif
}

EStructuralFeature::~EStructuralFeature()
{
}

// Attributes

::ecore::EBoolean EStructuralFeature::isChangeable() const
{
    return m_changeable;
}

void EStructuralFeature::setChangeable(::ecore::EBoolean _changeable)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EBoolean _old_changeable = m_changeable;
#endif
    m_changeable = _changeable;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::ecore::EcorePackage::_instance()->getEStructuralFeature__changeable(),
                _old_changeable,
                m_changeable
            );
        eNotify(&notification);
    }
#endif
}

::ecore::EBoolean EStructuralFeature::isVolatile() const
{
    return m_volatile;
}

void EStructuralFeature::setVolatile(::ecore::EBoolean _volatile)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EBoolean _old_volatile = m_volatile;
#endif
    m_volatile = _volatile;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::ecore::EcorePackage::_instance()->getEStructuralFeature__volatile(),
                _old_volatile,
                m_volatile
            );
        eNotify(&notification);
    }
#endif
}

::ecore::EBoolean EStructuralFeature::isTransient() const
{
    return m_transient;
}

void EStructuralFeature::setTransient(::ecore::EBoolean _transient)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EBoolean _old_transient = m_transient;
#endif
    m_transient = _transient;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::ecore::EcorePackage::_instance()->getEStructuralFeature__transient(),
                _old_transient,
                m_transient
            );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& EStructuralFeature::getDefaultValueLiteral() const
{
    return m_defaultValueLiteral;
}

void EStructuralFeature::setDefaultValueLiteral(
        ::ecore::EString const &_defaultValueLiteral)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_defaultValueLiteral = m_defaultValueLiteral;
#endif
    m_defaultValueLiteral = _defaultValueLiteral;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::ecore::EcorePackage::_instance()->getEStructuralFeature__defaultValueLiteral(),
                _old_defaultValueLiteral,
                m_defaultValueLiteral
            );
        eNotify(&notification);
    }
#endif
}

::ecore::EJavaObject EStructuralFeature::getDefaultValue()
{
    /*PROTECTED REGION ID(EStructuralFeatureImpl_Getter_defaultValue) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    throw "UnsupportedOperationException: ecore::EStructuralFeature::defaultValue";
    /*PROTECTED REGION END*/
}

::ecore::EBoolean EStructuralFeature::isUnsettable() const
{
    return m_unsettable;
}

void EStructuralFeature::setUnsettable(::ecore::EBoolean _unsettable)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EBoolean _old_unsettable = m_unsettable;
#endif
    m_unsettable = _unsettable;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::ecore::EcorePackage::_instance()->getEStructuralFeature__unsettable(),
                _old_unsettable,
                m_unsettable
            );
        eNotify(&notification);
    }
#endif
}

::ecore::EBoolean EStructuralFeature::isDerived() const
{
    return m_derived;
}

void EStructuralFeature::setDerived(::ecore::EBoolean _derived)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EBoolean _old_derived = m_derived;
#endif
    m_derived = _derived;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::ecore::EcorePackage::_instance()->getEStructuralFeature__derived(),
                _old_derived,
                m_derived
            );
        eNotify(&notification);
    }
#endif
}

// References

::ecore::EClass_ptr EStructuralFeature::getEContainingClass() const
{
    return m_eContainingClass.lock();
}

::ecore::EClass_ptr EStructuralFeature::basicgetEContainingClass()
{
    return m_eContainingClass.lock();
}

void EStructuralFeature::basicsetEContainingClass(
        ::ecore::EClass_ptr _eContainingClass)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EClass_ptr _old_eContainingClass = m_eContainingClass.lock();
#endif
    m_eContainingClass = _eContainingClass;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::ecore::EcorePackage::_instance()->getEStructuralFeature__eContainingClass(),
                _old_eContainingClass,
                m_eContainingClass.lock()
            );
        eNotify(&notification);
    }
#endif
}

void EStructuralFeature::setEContainingClass(
        ::ecore::EClass_ptr _eContainingClass)
{
    ::ecore::EClass_ptr _old_eContainingClass = m_eContainingClass.lock();
    if (_eContainingClass != _old_eContainingClass)
    {
        ::ecore::EJavaObject _this = ::ecore::EObject::_this();
        if (_old_eContainingClass)
        {
            _old_eContainingClass->::ecore::EObject::_inverseRemove(
                    ::ecore::EcorePackage::_instance()->getEClass__eStructuralFeatures(),
                    _this);
        }
        if (_eContainingClass && ::ecore::EcorePackage::_instance())
        {
            _eContainingClass->::ecore::EObject::_inverseAdd(
                    ::ecore::EcorePackage::_instance()->getEClass__eStructuralFeatures(),
                    _this);
        }
        basicsetEContainingClass(_eContainingClass);
    }
}

