// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kdm/build/BuildModel.cpp
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

#include "BuildModel.hpp"
#include <kdm/kdm/KDMModel.hpp>
#include <kdm/kdm/Attribute.hpp>
#include <kdm/kdm/Annotation.hpp>
#include <kdm/kdm/Stereotype.hpp>
#include <kdm/kdm/ExtendedValue.hpp>
#include <kdm/kdm/Audit.hpp>
#include <kdm/kdm/ExtensionFamily.hpp>
#include <kdm/build/AbstractBuildElement.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kdm/build/BuildPackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

/*PROTECTED REGION ID(BuildModel.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::kdm::build;

// Default constructor
BuildModel::BuildModel()
{
    /*PROTECTED REGION ID(BuildModelImpl__BuildModelImpl) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API
    m_eDeliver = false;
#endif
}

BuildModel::~BuildModel()
{
}

// Attributes

// References

const ::ecorecpp::mapping::EList< ::kdm::build::AbstractBuildElement_ptr >& BuildModel::getBuildElement() const
{
    if (!m_buildElement)
        return const_cast< BuildModel* >(this)->getBuildElement();

    return *m_buildElement;
}

::ecorecpp::mapping::EList< ::kdm::build::AbstractBuildElement_ptr >& BuildModel::getBuildElement()
{
    /*PROTECTED REGION ID(BuildModel__getBuildElement) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    if (!m_buildElement)
        m_buildElement.reset(
                new ::ecorecpp::mapping::ReferenceEListImpl<
                        ::kdm::build::AbstractBuildElement_ptr, -1, true, false >(
                        this,
                        ::kdm::build::BuildPackage::_instance()->getBuildModel__buildElement()));
    /*PROTECTED REGION END*/
    return *m_buildElement;
}

