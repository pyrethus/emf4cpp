// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * SVG/Element.cpp
 * Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
 * Copyright (C) INCHRON GmbH 2016-2018 <emf4cpp@inchron.com>
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

#include "Element.hpp"
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
#include "SVG/SVGPackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

/*PROTECTED REGION ID(Element.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::SVG;

// Default constructor
Element::Element()
{

    m_owner.reset(
            new ::ecorecpp::mapping::ReferenceEListImpl< ::SVG::SvgFile_ptr, -1,
                    false, true >(this,
                    ::SVG::SVGPackage::_instance()->getElement__owner(),
                    ::SVG::SVGPackage::SVGFILE__ELEMENTS));
    m_target.reset(
            new ::ecorecpp::mapping::ReferenceEListImpl< ::SVG::Use_ptr, -1,
                    false, true >(this,
                    ::SVG::SVGPackage::_instance()->getElement__target(),
                    ::SVG::SVGPackage::USE__USE));
    m_attribute.reset(
            new ::ecorecpp::mapping::ReferenceEListImpl< ::SVG::Attribute_ptr,
                    -1, false, true >(this,
                    ::SVG::SVGPackage::_instance()->getElement__attribute(),
                    ::SVG::SVGPackage::ATTRIBUTE__ATTOWNER));

    /*PROTECTED REGION ID(ElementImpl__ElementImpl) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API
    m_eDeliver = false;
#endif
}

Element::~Element()
{
    if (m_position)
    {
        m_position.reset();
    }
    if (m_size)
    {
        m_size.reset();
    }
}

// Attributes

::PrimitiveTypes::String Element::getFill() const
{
    return m_fill;
}

void Element::setFill(::PrimitiveTypes::String _fill)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::PrimitiveTypes::String _old_fill = m_fill;
#endif
    m_fill = _fill;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::SVG::SVGPackage::_instance()->getElement__fill(),
                _old_fill,
                m_fill
        );
        eNotify(&notification);
    }
#endif
}

::PrimitiveTypes::String Element::getViewBox() const
{
    return m_viewBox;
}

void Element::setViewBox(::PrimitiveTypes::String _viewBox)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::PrimitiveTypes::String _old_viewBox = m_viewBox;
#endif
    m_viewBox = _viewBox;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::SVG::SVGPackage::_instance()->getElement__viewBox(),
                _old_viewBox,
                m_viewBox
        );
        eNotify(&notification);
    }
#endif
}

::PrimitiveTypes::String Element::getIdentifier() const
{
    return m_identifier;
}

void Element::setIdentifier(::PrimitiveTypes::String _identifier)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::PrimitiveTypes::String _old_identifier = m_identifier;
#endif
    m_identifier = _identifier;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::SVG::SVGPackage::_instance()->getElement__identifier(),
                _old_identifier,
                m_identifier
        );
        eNotify(&notification);
    }
#endif
}

// References

const ::ecorecpp::mapping::EList< ::SVG::SvgFile_ptr >& Element::getOwner() const
{
    return *m_owner;
}

::ecorecpp::mapping::EList< ::SVG::SvgFile_ptr >& Element::getOwner()
{
    return *m_owner;
}

const ::ecorecpp::mapping::EList< ::SVG::Use_ptr >& Element::getTarget() const
{
    return *m_target;
}

::ecorecpp::mapping::EList< ::SVG::Use_ptr >& Element::getTarget()
{
    return *m_target;
}

const ::ecorecpp::mapping::EList< ::SVG::Attribute_ptr >& Element::getAttribute() const
{
    return *m_attribute;
}

::ecorecpp::mapping::EList< ::SVG::Attribute_ptr >& Element::getAttribute()
{
    return *m_attribute;
}

::SVG::Coordinates_ptr Element::getPosition() const
{
    return m_position;
}

void Element::setPosition(::SVG::Coordinates_ptr _position)
{
    if (m_position)
        m_position->_setEContainer(Element_ptr(),
                ::SVG::SVGPackage::_instance()->getElement__position());
    if (_position)
        _position->_setEContainer(_this(),
                ::SVG::SVGPackage::_instance()->getElement__position());

#ifdef ECORECPP_NOTIFICATION_API
    ::SVG::Coordinates_ptr _old_position = m_position;
#endif
    m_position = _position;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::SVG::SVGPackage::_instance()->getElement__position(),
                _old_position,
                m_position
        );
        eNotify(&notification);
    }
#endif
}

::SVG::Dimension_ptr Element::getSize() const
{
    return m_size;
}

void Element::setSize(::SVG::Dimension_ptr _size)
{
    if (m_size)
        m_size->_setEContainer(Element_ptr(),
                ::SVG::SVGPackage::_instance()->getElement__size());
    if (_size)
        _size->_setEContainer(_this(),
                ::SVG::SVGPackage::_instance()->getElement__size());

#ifdef ECORECPP_NOTIFICATION_API
    ::SVG::Dimension_ptr _old_size = m_size;
#endif
    m_size = _size;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::SVG::SVGPackage::_instance()->getElement__size(),
                _old_size,
                m_size
        );
        eNotify(&notification);
    }
#endif
}

::SVG::Svg_ptr Element::getRoot() const
{
    return m_root.lock();
}

::SVG::Svg_ptr Element::basicgetRoot()
{
    return m_root.lock();
}

void Element::basicsetRoot(::SVG::Svg_ptr _root)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::SVG::Svg_ptr _old_root = m_root.lock();
#endif
    m_root = _root;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::SVG::SVGPackage::_instance()->getElement__root(),
                _old_root,
                m_root.lock()
        );
        eNotify(&notification);
    }
#endif
}

void Element::setRoot(::SVG::Svg_ptr _root)
{
    ::SVG::Svg_ptr _old_root = m_root.lock();
    if (_root != _old_root)
    {
        ::ecore::EJavaObject _this = ::ecore::EObject::_this();
        if (_old_root)
        {
            _old_root->_inverseRemove(::SVG::SVGPackage::SVG__CHILDREN, _this);
        }
        if (_root)
        {
            _root->_inverseAdd(::SVG::SVGPackage::SVG__CHILDREN, _this);
        }
        basicsetRoot(_root);
    }
}

::SVG::GroupingElement_ptr Element::getGroup() const
{
    return m_group.lock();
}

::SVG::GroupingElement_ptr Element::basicgetGroup()
{
    return m_group.lock();
}

void Element::basicsetGroup(::SVG::GroupingElement_ptr _group)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::SVG::GroupingElement_ptr _old_group = m_group.lock();
#endif
    m_group = _group;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::SVG::SVGPackage::_instance()->getElement__group(),
                _old_group,
                m_group.lock()
        );
        eNotify(&notification);
    }
#endif
}

void Element::setGroup(::SVG::GroupingElement_ptr _group)
{
    ::SVG::GroupingElement_ptr _old_group = m_group.lock();
    if (_group != _old_group)
    {
        ::ecore::EJavaObject _this = ::ecore::EObject::_this();
        if (_old_group)
        {
            _old_group->_inverseRemove(
                    ::SVG::SVGPackage::GROUPINGELEMENT__GROUPCONTENT, _this);
        }
        if (_group)
        {
            _group->_inverseAdd(
                    ::SVG::SVGPackage::GROUPINGELEMENT__GROUPCONTENT, _this);
        }
        basicsetGroup(_group);
    }
}

::SVG::Marker_ptr Element::getDrawsMarker() const
{
    return m_drawsMarker.lock();
}

::SVG::Marker_ptr Element::basicgetDrawsMarker()
{
    return m_drawsMarker.lock();
}

void Element::basicsetDrawsMarker(::SVG::Marker_ptr _drawsMarker)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::SVG::Marker_ptr _old_drawsMarker = m_drawsMarker.lock();
#endif
    m_drawsMarker = _drawsMarker;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::SVG::SVGPackage::_instance()->getElement__drawsMarker(),
                _old_drawsMarker,
                m_drawsMarker.lock()
        );
        eNotify(&notification);
    }
#endif
}

void Element::setDrawsMarker(::SVG::Marker_ptr _drawsMarker)
{
    ::SVG::Marker_ptr _old_drawsMarker = m_drawsMarker.lock();
    if (_drawsMarker != _old_drawsMarker)
    {
        ::ecore::EJavaObject _this = ::ecore::EObject::_this();
        if (_old_drawsMarker)
        {
            _old_drawsMarker->_inverseRemove(::SVG::SVGPackage::MARKER__DRAWING,
                    _this);
        }
        if (_drawsMarker)
        {
            _drawsMarker->_inverseAdd(::SVG::SVGPackage::MARKER__DRAWING,
                    _this);
        }
        basicsetDrawsMarker(_drawsMarker);
    }
}

