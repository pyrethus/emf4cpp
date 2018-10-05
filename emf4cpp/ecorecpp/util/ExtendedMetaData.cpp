// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * util/ExtendedMetaData.hpp
 * Copyright (C) INCHRON GmbH 2018 <matthias.doerfel@inchron.com>
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

#include "ExtendedMetaData.hpp"

#include "BasicExtendedMetaData.hpp"

namespace ecorecpp {
namespace util {

::ecore::Ptr<ExtendedMetaData> ExtendedMetaData::s_instance;

ExtendedMetaData::~ExtendedMetaData() = default;

::ecore::Ptr<ExtendedMetaData> ExtendedMetaData::_instance() {
	if (!s_instance.get())
		s_instance = ::ecore::Ptr<ExtendedMetaData>( new BasicExtendedMetaData );
	return s_instance;
}

const ::ecore::EString ExtendedMetaData::ANNOTATION_URI = "http:///org/eclipse/emf/ecore/util/ExtendedMetaData";
const ::ecore::EString ExtendedMetaData::XMLNS_URI = "http://www.w3.org/2000/xmlns/";
const ::ecore::EString ExtendedMetaData::XML_URI = "http://www.w3.org/XML/1998/namespace";
const ::ecore::EString ExtendedMetaData::XSI_URI = "http://www.w3.org/2001/XMLSchema-instance";
const ::ecore::EString ExtendedMetaData::XML_SCHEMA_URI = "http://www.w3.org/2001/XMLSchema";
const ::ecore::EString ExtendedMetaData::XMI_URI = "http://www.omg.org/XMI";
const ::ecore::EString ExtendedMetaData::XMLNS_PREFIX = "xmlns";
const ::ecore::EString ExtendedMetaData::XSI_PREFIX = "xsi";

const ::ecore::EString ExtendedMetaData::FEATURE_KINDS[] = {
	"unspecified", "simple", "attribute", "attributeWildcard",
	"element", "elementWildcard", "group" };

const ::ecore::EString ExtendedMetaData::CONTENT_KINDS[] = {
	"unspecified", "empty", "simple", "mixed", "elementOnly" };

const ::ecore::EString ExtendedMetaData::DERIVATION_KINDS[] = {
	"unspecified", "restriction", "list", "union" };

const ::ecore::EString ExtendedMetaData::PROCESSING_KINDS[] = {
	"unspecified", "strict", "lax", "skip" };

const ::ecore::EString ExtendedMetaData::WHITE_SPACE_KINDS[] = {
	"unspecified", "preserve", "replace", "collapse" };

} // util
} // ecorecpp
