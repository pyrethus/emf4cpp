// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * ecore/ETypeParameter.cpp
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

#include "ETypeParameter.hpp"
#include <ecore/ENamedElement.hpp>
#include <ecore/EAnnotation.hpp>
#include <ecore/EGenericType.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "ecore/EcorePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

/*PROTECTED REGION ID(ETypeParameter.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::ecore;

// Default constructor
ETypeParameter::ETypeParameter()
{
    /*PROTECTED REGION ID(ETypeParameterImpl__ETypeParameterImpl) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API
    m_eDeliver = false;
#endif
}

ETypeParameter::~ETypeParameter()
{
}

// Attributes

// References

const ::ecorecpp::mapping::EList< ::ecore::EGenericType_ptr >& ETypeParameter::getEBounds() const
{
    if (!m_eBounds)
        return const_cast< ETypeParameter* >(this)->getEBounds();

    return *m_eBounds;
}

::ecorecpp::mapping::EList< ::ecore::EGenericType_ptr >& ETypeParameter::getEBounds()
{
    /*PROTECTED REGION ID(ETypeParameter__getEBounds) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    if (!m_eBounds)
        m_eBounds.reset(
                new ::ecorecpp::mapping::ReferenceEListImpl<
                        ::ecore::EGenericType_ptr, -1, true, false >(this,
                        ::ecore::EcorePackage::_instance()->getETypeParameter__eBounds()));
    /*PROTECTED REGION END*/
    return *m_eBounds;
}

