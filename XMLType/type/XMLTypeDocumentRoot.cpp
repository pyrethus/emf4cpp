// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * type/XMLTypeDocumentRoot.cpp
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

#include "XMLTypeDocumentRoot.hpp"
#include <ecore/EStringToStringMapEntry.hpp>
#include <type/ProcessingInstruction.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "type/TypePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

/*PROTECTED REGION ID(XMLTypeDocumentRoot.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::type;

// Default constructor
XMLTypeDocumentRoot::XMLTypeDocumentRoot()
{

    m_xMLNSPrefixMap.reset(
            new ::ecorecpp::mapping::ReferenceEListImpl<
                    ::ecore::EStringToStringMapEntry_ptr, -1, true, false >(
                    this,
                    ::type::TypePackage::_instance()->getXMLTypeDocumentRoot__xMLNSPrefixMap()));
    m_xSISchemaLocation.reset(
            new ::ecorecpp::mapping::ReferenceEListImpl<
                    ::ecore::EStringToStringMapEntry_ptr, -1, true, false >(
                    this,
                    ::type::TypePackage::_instance()->getXMLTypeDocumentRoot__xSISchemaLocation()));
    m_processingInstruction.reset(
            new ::ecorecpp::mapping::ReferenceEListImpl<
                    ::type::ProcessingInstruction_ptr, -2, true, false >(this,
                    ::type::TypePackage::_instance()->getXMLTypeDocumentRoot__processingInstruction()));

    /*PROTECTED REGION ID(XMLTypeDocumentRootImpl__XMLTypeDocumentRootImpl) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API
    m_eDeliver = false;
#endif
}

XMLTypeDocumentRoot::~XMLTypeDocumentRoot()
{
}

// Attributes

std::vector< ::ecore::EFeatureMapEntry > const& XMLTypeDocumentRoot::getMixed() const
{
    return m_mixed;
}

void XMLTypeDocumentRoot::setMixed(
        std::vector< ::ecore::EFeatureMapEntry > _mixed)
{
#ifdef ECORECPP_NOTIFICATION_API
    std::vector< ::ecore::EFeatureMapEntry > _old_mixed = m_mixed;
#endif
    m_mixed = _mixed;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::type::TypePackage::_instance()->getXMLTypeDocumentRoot__mixed(),
                _old_mixed,
                m_mixed
        );
        eNotify(&notification);
    }
#endif
}

void XMLTypeDocumentRoot::addMixed(
        ::ecore::EFeatureMapEntry const& _new_element_in_mixed)
{
    m_mixed.push_back(_new_element_in_mixed);
}

void XMLTypeDocumentRoot::setMixedAt(size_t _position,
        ::ecore::EFeatureMapEntry const& _new_element_in_mixed)
{
    if (_position >= m_mixed.size())
        m_mixed.resize(_position + 1, ::ecore::EFeatureMapEntry());

    m_mixed[_position] = _new_element_in_mixed;
}

void XMLTypeDocumentRoot::deleteMixedAt(size_t _position)
{
    if (_position >= m_mixed.size())
        throw "Attribute counter out of bounds!";

    // TODO: This is not actually quite true
    if (_position == m_mixed.size() - 1)
        m_mixed.resize(_position);
}

std::vector< ::type::String > const& XMLTypeDocumentRoot::getCDATA() const
{
    return m_cDATA;
}

void XMLTypeDocumentRoot::setCDATA(std::vector< ::type::String > _cDATA)
{
#ifdef ECORECPP_NOTIFICATION_API
    std::vector< ::type::String > _old_cDATA = m_cDATA;
#endif
    m_cDATA = _cDATA;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::type::TypePackage::_instance()->getXMLTypeDocumentRoot__cDATA(),
                _old_cDATA,
                m_cDATA
        );
        eNotify(&notification);
    }
#endif
}

void XMLTypeDocumentRoot::addCDATA(::type::String const& _new_element_in_cDATA)
{
    m_cDATA.push_back(_new_element_in_cDATA);
}

void XMLTypeDocumentRoot::setCDATAAt(size_t _position,
        ::type::String const& _new_element_in_cDATA)
{
    if (_position >= m_cDATA.size())
        m_cDATA.resize(_position + 1, ::type::String());

    m_cDATA[_position] = _new_element_in_cDATA;
}

void XMLTypeDocumentRoot::deleteCDATAAt(size_t _position)
{
    if (_position >= m_cDATA.size())
        throw "Attribute counter out of bounds!";

    // TODO: This is not actually quite true
    if (_position == m_cDATA.size() - 1)
        m_cDATA.resize(_position);
}

std::vector< ::type::String > const& XMLTypeDocumentRoot::getComment() const
{
    return m_comment;
}

void XMLTypeDocumentRoot::setComment(std::vector< ::type::String > _comment)
{
#ifdef ECORECPP_NOTIFICATION_API
    std::vector< ::type::String > _old_comment = m_comment;
#endif
    m_comment = _comment;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::type::TypePackage::_instance()->getXMLTypeDocumentRoot__comment(),
                _old_comment,
                m_comment
        );
        eNotify(&notification);
    }
#endif
}

void XMLTypeDocumentRoot::addComment(
        ::type::String const& _new_element_in_comment)
{
    m_comment.push_back(_new_element_in_comment);
}

void XMLTypeDocumentRoot::setCommentAt(size_t _position,
        ::type::String const& _new_element_in_comment)
{
    if (_position >= m_comment.size())
        m_comment.resize(_position + 1, ::type::String());

    m_comment[_position] = _new_element_in_comment;
}

void XMLTypeDocumentRoot::deleteCommentAt(size_t _position)
{
    if (_position >= m_comment.size())
        throw "Attribute counter out of bounds!";

    // TODO: This is not actually quite true
    if (_position == m_comment.size() - 1)
        m_comment.resize(_position);
}

std::vector< ::type::String > const& XMLTypeDocumentRoot::getText() const
{
    return m_text;
}

void XMLTypeDocumentRoot::setText(std::vector< ::type::String > _text)
{
#ifdef ECORECPP_NOTIFICATION_API
    std::vector< ::type::String > _old_text = m_text;
#endif
    m_text = _text;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::type::TypePackage::_instance()->getXMLTypeDocumentRoot__text(),
                _old_text,
                m_text
        );
        eNotify(&notification);
    }
#endif
}

void XMLTypeDocumentRoot::addText(::type::String const& _new_element_in_text)
{
    m_text.push_back(_new_element_in_text);
}

void XMLTypeDocumentRoot::setTextAt(size_t _position,
        ::type::String const& _new_element_in_text)
{
    if (_position >= m_text.size())
        m_text.resize(_position + 1, ::type::String());

    m_text[_position] = _new_element_in_text;
}

void XMLTypeDocumentRoot::deleteTextAt(size_t _position)
{
    if (_position >= m_text.size())
        throw "Attribute counter out of bounds!";

    // TODO: This is not actually quite true
    if (_position == m_text.size() - 1)
        m_text.resize(_position);
}

// References

const ::ecorecpp::mapping::EList< ::ecore::EStringToStringMapEntry_ptr >& XMLTypeDocumentRoot::getXMLNSPrefixMap() const
{
    return *m_xMLNSPrefixMap;
}

::ecorecpp::mapping::EList< ::ecore::EStringToStringMapEntry_ptr >& XMLTypeDocumentRoot::getXMLNSPrefixMap()
{
    return *m_xMLNSPrefixMap;
}

const ::ecorecpp::mapping::EList< ::ecore::EStringToStringMapEntry_ptr >& XMLTypeDocumentRoot::getXSISchemaLocation() const
{
    return *m_xSISchemaLocation;
}

::ecorecpp::mapping::EList< ::ecore::EStringToStringMapEntry_ptr >& XMLTypeDocumentRoot::getXSISchemaLocation()
{
    return *m_xSISchemaLocation;
}

const ::ecorecpp::mapping::EList< ::type::ProcessingInstruction_ptr >& XMLTypeDocumentRoot::getProcessingInstruction() const
{
    return *m_processingInstruction;
}

::ecorecpp::mapping::EList< ::type::ProcessingInstruction_ptr >& XMLTypeDocumentRoot::getProcessingInstruction()
{
    return *m_processingInstruction;
}

