// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * SVG/EllipseImpl.cpp
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

#include "Ellipse.hpp"
#include <SVG/SVGPackage.hpp>
#include <SVG/Shape.hpp>
#include <SVG/SvgFile.hpp>
#include <SVG/Use.hpp>
#include <SVG/Attribute.hpp>
#include <SVG/Coordinates.hpp>
#include <SVG/Dimension.hpp>
#include <SVG/Svg.hpp>
#include <SVG/GroupingElement.hpp>
#include <SVG/Marker.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

/*PROTECTED REGION ID(EllipseImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::SVG;

void Ellipse::_initialize()
{
    // Supertypes
    ::SVG::Shape::_initialize();

    // References

    /*PROTECTED REGION ID(EllipseImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations

// EObject
::ecore::EJavaObject Ellipse::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean /*_resolve*/)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::SVG::SVGPackage::ELLIPSE__OWNER:
    {
        _any = getOwner().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::SVG::SVGPackage::ELLIPSE__TARGET:
    {
        _any = getTarget().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::SVG::SVGPackage::ELLIPSE__ATTRIBUTE:
    {
        _any = getAttribute().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::SVG::SVGPackage::ELLIPSE__POSITION:
    {
        _any = ::ecore::as < ::ecore::EObject > (getPosition());
    }
        return _any;
    case ::SVG::SVGPackage::ELLIPSE__SIZE:
    {
        _any = ::ecore::as < ::ecore::EObject > (getSize());
    }
        return _any;
    case ::SVG::SVGPackage::ELLIPSE__ROOT:
    {
        _any = ::ecore::as < ::ecore::EObject > (getRoot());
    }
        return _any;
    case ::SVG::SVGPackage::ELLIPSE__FILL:
    {
        ::ecorecpp::mapping::any_traits < ::PrimitiveTypes::String
                > ::toAny(_any, getFill());
    }
        return _any;
    case ::SVG::SVGPackage::ELLIPSE__VIEWBOX:
    {
        ::ecorecpp::mapping::any_traits < ::PrimitiveTypes::String
                > ::toAny(_any, getViewBox());
    }
        return _any;
    case ::SVG::SVGPackage::ELLIPSE__GROUP:
    {
        _any = ::ecore::as < ::ecore::EObject > (getGroup());
    }
        return _any;
    case ::SVG::SVGPackage::ELLIPSE__IDENTIFIER:
    {
        ::ecorecpp::mapping::any_traits < ::PrimitiveTypes::String
                > ::toAny(_any, getIdentifier());
    }
        return _any;
    case ::SVG::SVGPackage::ELLIPSE__DRAWSMARKER:
    {
        _any = ::ecore::as < ::ecore::EObject > (getDrawsMarker());
    }
        return _any;
    case ::SVG::SVGPackage::ELLIPSE__STROKE:
    {
        ::ecorecpp::mapping::any_traits < ::PrimitiveTypes::String
                > ::toAny(_any, getStroke());
    }
        return _any;

    }
    throw "Error: eGet() does not handle this featureID";
}

void Ellipse::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::SVG::SVGPackage::ELLIPSE__OWNER:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getOwner().clear();
        getOwner().insert_all(*_t0);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__TARGET:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getTarget().clear();
        getTarget().insert_all(*_t0);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__ATTRIBUTE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getAttribute().clear();
        getAttribute().insert_all(*_t0);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__POSITION:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::SVG::Coordinates > (_t0);
        setPosition(_t1);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__SIZE:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::SVG::Dimension > (_t0);
        setSize(_t1);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__ROOT:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::SVG::Svg > (_t0);
        setRoot(_t1);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__FILL:
    {
        ::PrimitiveTypes::String _t0;
        ::ecorecpp::mapping::any_traits < ::PrimitiveTypes::String
                > ::fromAny(_newValue, _t0);
        setFill(_t0);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__VIEWBOX:
    {
        ::PrimitiveTypes::String _t0;
        ::ecorecpp::mapping::any_traits < ::PrimitiveTypes::String
                > ::fromAny(_newValue, _t0);
        setViewBox(_t0);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__GROUP:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::SVG::GroupingElement > (_t0);
        setGroup(_t1);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__IDENTIFIER:
    {
        ::PrimitiveTypes::String _t0;
        ::ecorecpp::mapping::any_traits < ::PrimitiveTypes::String
                > ::fromAny(_newValue, _t0);
        setIdentifier(_t0);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__DRAWSMARKER:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::SVG::Marker > (_t0);
        setDrawsMarker(_t1);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__STROKE:
    {
        ::PrimitiveTypes::String _t0;
        ::ecorecpp::mapping::any_traits < ::PrimitiveTypes::String
                > ::fromAny(_newValue, _t0);
        setStroke(_t0);
    }
        return;

    }
    throw "Error: eSet() does not handle this featureID";
}

::ecore::EBoolean Ellipse::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::SVG::SVGPackage::ELLIPSE__OWNER:
        return getOwner().size() > 0;
    case ::SVG::SVGPackage::ELLIPSE__TARGET:
        return getTarget().size() > 0;
    case ::SVG::SVGPackage::ELLIPSE__ATTRIBUTE:
        return getAttribute().size() > 0;
    case ::SVG::SVGPackage::ELLIPSE__POSITION:
        return getPosition().get() != nullptr;
    case ::SVG::SVGPackage::ELLIPSE__SIZE:
        return getSize().get() != nullptr;
    case ::SVG::SVGPackage::ELLIPSE__ROOT:
        return getRoot().get() != nullptr;
    case ::SVG::SVGPackage::ELLIPSE__FILL:
        return ::ecorecpp::mapping::set_traits < ::PrimitiveTypes::String
                > ::is_set(getFill());
    case ::SVG::SVGPackage::ELLIPSE__VIEWBOX:
        return ::ecorecpp::mapping::set_traits < ::PrimitiveTypes::String
                > ::is_set(getViewBox());
    case ::SVG::SVGPackage::ELLIPSE__GROUP:
        return getGroup().get() != nullptr;
    case ::SVG::SVGPackage::ELLIPSE__IDENTIFIER:
        return ::ecorecpp::mapping::set_traits < ::PrimitiveTypes::String
                > ::is_set(getIdentifier());
    case ::SVG::SVGPackage::ELLIPSE__DRAWSMARKER:
        return getDrawsMarker().get() != nullptr;
    case ::SVG::SVGPackage::ELLIPSE__STROKE:
        return ::ecorecpp::mapping::set_traits < ::PrimitiveTypes::String
                > ::is_set(getStroke());

    }
    throw "Error: eIsSet() does not handle this featureID";
}

void Ellipse::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error: eUnset() does not handle this featureID";
}

::ecore::EClass_ptr Ellipse::_eClass()
{
    static ::ecore::EClass_ptr _eclass =
            ::SVG::SVGPackage::_instance()->getEllipse();
    return _eclass;
}

/** Set the local end of a reference with an EOpposite property.
 */
void Ellipse::_inverseAdd(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::SVG::SVGPackage::ELLIPSE__OWNER:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_newValue);
        ::SVG::SvgFile_ptr _t1 = std::dynamic_pointer_cast < ::SVG::SvgFile
                > (_t0);

        // add to a list
        auto &container =
                (::ecorecpp::mapping::ReferenceEListImpl< ::SVG::SvgFile_ptr,
                        -1, false, true >&) ::SVG::Element::getOwner();
        container.basicAdd(_t1);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__TARGET:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_newValue);
        ::SVG::Use_ptr _t1 = std::dynamic_pointer_cast < ::SVG::Use > (_t0);

        // add to a list
        auto &container = (::ecorecpp::mapping::ReferenceEListImpl<
                ::SVG::Use_ptr, -1, false, true >&) ::SVG::Element::getTarget();
        container.basicAdd(_t1);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__ATTRIBUTE:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_newValue);
        ::SVG::Attribute_ptr _t1 = std::dynamic_pointer_cast < ::SVG::Attribute
                > (_t0);

        // add to a list
        auto &container =
                (::ecorecpp::mapping::ReferenceEListImpl< ::SVG::Attribute_ptr,
                        -1, false, true >&) ::SVG::Element::getAttribute();
        container.basicAdd(_t1);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__POSITION:
    {
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__SIZE:
    {
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__ROOT:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_newValue);
        ::SVG::Svg_ptr _t1 = std::dynamic_pointer_cast < ::SVG::Svg > (_t0);

        ::SVG::Svg_ptr _old_root = getRoot();
        if (_old_root && _old_root != _t0)
        {
            ::ecore::EJavaObject _this = ::ecore::EObject::_this();
            _old_root->::ecore::EObject::_inverseRemove(
                    ::SVG::SVGPackage::_instance()->getSvg__children(), _this);
        }

        // set reference
        basicsetRoot(_t1);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__GROUP:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_newValue);
        ::SVG::GroupingElement_ptr _t1 = std::dynamic_pointer_cast
                < ::SVG::GroupingElement > (_t0);

        ::SVG::GroupingElement_ptr _old_group = getGroup();
        if (_old_group && _old_group != _t0)
        {
            ::ecore::EJavaObject _this = ::ecore::EObject::_this();
            _old_group->::ecore::EObject::_inverseRemove(
                    ::SVG::SVGPackage::_instance()->getGroupingElement__groupContent(),
                    _this);
        }

        // set reference
        basicsetGroup(_t1);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__DRAWSMARKER:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_newValue);
        ::SVG::Marker_ptr _t1 = std::dynamic_pointer_cast < ::SVG::Marker
                > (_t0);

        ::SVG::Marker_ptr _old_drawsMarker = getDrawsMarker();
        if (_old_drawsMarker && _old_drawsMarker != _t0)
        {
            ::ecore::EJavaObject _this = ::ecore::EObject::_this();
            _old_drawsMarker->::ecore::EObject::_inverseRemove(
                    ::SVG::SVGPackage::_instance()->getMarker__drawing(),
                    _this);
        }

        // set reference
        basicsetDrawsMarker(_t1);
    }
        return;

    }
    throw "Error: _inverseAdd() does not handle this featureID";
}

/** Unset the local end of a reference with an EOpposite property.
 */
void Ellipse::_inverseRemove(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_oldValue)
{
    switch (_featureID)
    {
    case ::SVG::SVGPackage::ELLIPSE__OWNER:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_oldValue);
        ::SVG::SvgFile_ptr _t1 = std::dynamic_pointer_cast < ::SVG::SvgFile
                > (_t0);

        // add to a list
        auto &container =
                (::ecorecpp::mapping::ReferenceEListImpl< ::SVG::SvgFile_ptr,
                        -1, false, true >&) ::SVG::Element::getOwner();
        container.basicRemove(_t1);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__TARGET:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_oldValue);
        ::SVG::Use_ptr _t1 = std::dynamic_pointer_cast < ::SVG::Use > (_t0);

        // add to a list
        auto &container = (::ecorecpp::mapping::ReferenceEListImpl<
                ::SVG::Use_ptr, -1, false, true >&) ::SVG::Element::getTarget();
        container.basicRemove(_t1);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__ATTRIBUTE:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_oldValue);
        ::SVG::Attribute_ptr _t1 = std::dynamic_pointer_cast < ::SVG::Attribute
                > (_t0);

        // add to a list
        auto &container =
                (::ecorecpp::mapping::ReferenceEListImpl< ::SVG::Attribute_ptr,
                        -1, false, true >&) ::SVG::Element::getAttribute();
        container.basicRemove(_t1);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__POSITION:
    {
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__SIZE:
    {
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__ROOT:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_oldValue);
        ::SVG::Svg_ptr _t1 = std::dynamic_pointer_cast < ::SVG::Svg > (_t0);

        // set reference
        if (basicgetRoot() == _t1)
            basicsetRoot(nullptr);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__GROUP:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_oldValue);
        ::SVG::GroupingElement_ptr _t1 = std::dynamic_pointer_cast
                < ::SVG::GroupingElement > (_t0);

        // set reference
        if (basicgetGroup() == _t1)
            basicsetGroup(nullptr);
    }
        return;
    case ::SVG::SVGPackage::ELLIPSE__DRAWSMARKER:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EObject_ptr > (_oldValue);
        ::SVG::Marker_ptr _t1 = std::dynamic_pointer_cast < ::SVG::Marker
                > (_t0);

        // set reference
        if (basicgetDrawsMarker() == _t1)
            basicsetDrawsMarker(nullptr);
    }
        return;

    }
    throw "Error: _inverseRemove() does not handle this featureID";
}

