// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kdm/data/SimpleContentType.cpp
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

#include "SimpleContentType.hpp"
#include <kdm/data/ComplexContentType.hpp>
#include <kdm/kdm/Attribute.hpp>
#include <kdm/kdm/Annotation.hpp>
#include <kdm/kdm/Stereotype.hpp>
#include <kdm/kdm/ExtendedValue.hpp>
#include <kdm/source/SourceRef.hpp>
#include <kdm/data/AbstractDataRelationship.hpp>
#include <kdm/action/ActionElement.hpp>
#include <kdm/data/AbstractContentElement.hpp>
#include <kdm/core/KDMRelationship.hpp>
#include <kdm/core/AggregatedRelationship.hpp>
#include <kdm/core/KDMEntity.hpp>
#include <kdm/kdm/KDMModel.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kdm/data/DataPackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

/*PROTECTED REGION ID(SimpleContentType.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::kdm::data;

// Default constructor
SimpleContentType::SimpleContentType()
{
    /*PROTECTED REGION ID(SimpleContentTypeImpl__SimpleContentTypeImpl) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API
    m_eDeliver = false;
#endif
}

SimpleContentType::~SimpleContentType()
{
}

// Attributes

::kdm::core::String SimpleContentType::getKind() const
{
    return m_kind;
}

void SimpleContentType::setKind(::kdm::core::String _kind)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::kdm::core::String _old_kind = m_kind;
#endif
    m_kind = _kind;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::kdm::data::DataPackage::_instance()->getSimpleContentType__kind(),
                _old_kind,
                m_kind
            );
        eNotify(&notification);
    }
#endif
}

// References

const ::ecorecpp::mapping::EList< ::kdm::data::ComplexContentType_ptr >& SimpleContentType::getType() const
{
    if (!m_type)
        return const_cast< SimpleContentType* >(this)->getType();

    return *m_type;
}

::ecorecpp::mapping::EList< ::kdm::data::ComplexContentType_ptr >& SimpleContentType::getType()
{
    /*PROTECTED REGION ID(SimpleContentType__getType) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    if (!m_type)
        m_type.reset(
                new ::ecorecpp::mapping::ReferenceEListImpl<
                        ::kdm::data::ComplexContentType_ptr, -1, false, false >(
                        this,
                        ::kdm::data::DataPackage::_instance()->getSimpleContentType__type()));
    /*PROTECTED REGION END*/
    return *m_type;
}

