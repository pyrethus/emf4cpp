// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * parser/References.hpp
 * Copyright (C) INCHRON AG 2020 <soeren.henning@inchron.com>
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

#pragma once

#include <ecore/EObject.hpp>
#include "../mapping/type_definitions.hpp"

namespace ecorecpp {
namespace parser {

struct Reference {
	::ecore::EObject_ptr _obj;
	::ecorecpp::mapping::type_definitions::string_t _featureName;
	::ecorecpp::mapping::type_definitions::string_t _refType;
	::ecorecpp::mapping::type_definitions::string_t _href;
};

} //end namespace parser
} //end namespace ecorecpp
