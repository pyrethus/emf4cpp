// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * parser/XMLHandler.hpp
 * Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
 * Copyright (C) INCHRON GmbH 2016 <soeren.henning@inchron.com>
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

#ifndef XMLHandler_HPP
#define XMLHandler_HPP

#include <list>
#include <string>
#include <unordered_map>

#include <ecore/EClass.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EPackage.hpp>

#include "../dllEcorecpp.hpp"
#include "../util/ExtendedMetaData.hpp"
#include "simple_xml_parser.hpp"

namespace ecorecpp {
namespace parser {

class EXPORT_ECORECPP_DLL XMLHandler {
public:

	XMLHandler();
	~XMLHandler() = default;

	void setExtendedMetaData(bool);
	bool getExtendedMetaData() const;

	void processing_tag(xml_parser::match_pair const& tag,
			xml_parser::attr_list_t const& attr_list);

	void start_tag(xml_parser::match_pair const& tag,
			xml_parser::attr_list_t const& attr_list);

	void end_tag(xml_parser::match_pair const& tag);

	void characters(xml_parser::match_pair const& chars);

	::ecore::EObject_ptr getRootElement();

	using XmiIdMap = std::unordered_map<::ecorecpp::mapping::type_definitions::string_t, ::ecore::EObject_ptr>;
	XmiIdMap& getXmiIds();
	void resolveReferences();
	void resolveCrossDocumentReferences();

private:

	int m_level;
	bool m_expected_literal;
	::ecorecpp::mapping::type_definitions::string_t m_expected_literal_name;
	std::list<::ecore::EObject_ptr> m_objects;

	::ecore::EPackage_ptr m_current_metamodel;
	::ecorecpp::mapping::type_definitions::string_t m_current_namespace;

	struct Reference {
		::ecore::EObject_ptr _obj;
		::ecorecpp::mapping::type_definitions::string_t _featureName;
		::ecorecpp::mapping::type_definitions::string_t _refType;
		::ecorecpp::mapping::type_definitions::string_t _href;
	};

	std::list<Reference> m_unresolved_references;
	std::list<Reference> m_unresolved_cross_references;

	inline bool isAtCurrentNamespace(
			const ::ecorecpp::mapping::type_definitions::string_t& _name) const {
		return _name.find(':') == ::ecorecpp::mapping::type_definitions::string_t::npos;
	}

	XmiIdMap _xmiIds;
	::ecore::Ptr<util::ExtendedMetaData> m_extendedMetaData;
	::ecore::EStructuralFeature_ptr getEStructuralFeature(::ecore::EClass_ptr, ::ecore::EString);

	std::unordered_map<
		::ecorecpp::mapping::type_definitions::string_t,
		::ecorecpp::mapping::type_definitions::string_t > _nsUriMap;
};

} // parser
} // ecorecpp

#endif    /*XMLHandler_HPP */
