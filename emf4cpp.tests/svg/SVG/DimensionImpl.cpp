// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * SVG/DimensionImpl.cpp
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

#include "Dimension.hpp"
#include <SVG/SVGPackage.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

/*PROTECTED REGION ID(DimensionImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::SVG;

void Dimension::_initialize()
{
    // Supertypes

    // References

    /*PROTECTED REGION ID(DimensionImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations

// EObject
::ecore::EJavaObject Dimension::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean /*_resolve*/)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::SVG::SVGPackage::DIMENSION__WIDTH:
    {
        ::ecorecpp::mapping::any_traits < ::PrimitiveTypes::Double
                > ::toAny(_any, getWidth());
    }
        return _any;
    case ::SVG::SVGPackage::DIMENSION__HEIGHT:
    {
        ::ecorecpp::mapping::any_traits < ::PrimitiveTypes::Double
                > ::toAny(_any, getHeight());
    }
        return _any;

    }
    throw "Error: eGet() does not handle this featureID";
}

void Dimension::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::SVG::SVGPackage::DIMENSION__WIDTH:
    {
        ::PrimitiveTypes::Double _t0;
        ::ecorecpp::mapping::any_traits < ::PrimitiveTypes::Double
                > ::fromAny(_newValue, _t0);
        setWidth(_t0);
    }
        return;
    case ::SVG::SVGPackage::DIMENSION__HEIGHT:
    {
        ::PrimitiveTypes::Double _t0;
        ::ecorecpp::mapping::any_traits < ::PrimitiveTypes::Double
                > ::fromAny(_newValue, _t0);
        setHeight(_t0);
    }
        return;

    }
    throw "Error: eSet() does not handle this featureID";
}

::ecore::EBoolean Dimension::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::SVG::SVGPackage::DIMENSION__WIDTH:
        return ::ecorecpp::mapping::set_traits < ::PrimitiveTypes::Double
                > ::is_set(getWidth());
    case ::SVG::SVGPackage::DIMENSION__HEIGHT:
        return ::ecorecpp::mapping::set_traits < ::PrimitiveTypes::Double
                > ::is_set(getHeight());

    }
    throw "Error: eIsSet() does not handle this featureID";
}

void Dimension::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error: eUnset() does not handle this featureID";
}

::ecore::EClass_ptr Dimension::_eClass()
{
    static ::ecore::EClass_ptr _eclass =
            ::SVG::SVGPackage::_instance()->getDimension();
    return _eclass;
}

/** Set the local end of a reference with an EOpposite property.
 */
void Dimension::_inverseAdd(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {

    }
    throw "Error: _inverseAdd() does not handle this featureID";
}

/** Unset the local end of a reference with an EOpposite property.
 */
void Dimension::_inverseRemove(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_oldValue)
{
    switch (_featureID)
    {

    }
    throw "Error: _inverseRemove() does not handle this featureID";
}

