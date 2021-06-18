// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * ReferenceStringCreationException.hpp
 * Copyright (C) INCHRON AG 2021 <info@inchron.com>
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

#include <stdexcept>

namespace ecore {
	class EObject;
}

namespace ecorecpp {
namespace exception {

class ReferenceStringCreationException : public std::logic_error {
public:

	ReferenceStringCreationException( const std::string& what,
			const ::ecore::EObject_ptr& from,
			const ::ecore::EObject_ptr& to,
			bool crossDocument )
		: std::logic_error(what),
		  _from(from),
		  _to(to),
		  _crossDocument(crossDocument) {
	}
	~ReferenceStringCreationException() override = default;

	const ::ecore::EObject_ptr& sourceEObject() const {return _from;}
	const ::ecore::EObject_ptr& destinationEObject() const {return _from;}
	bool isCrossDocument() const {return _crossDocument;}

private:

	::ecore::EObject_ptr _from, _to;
	bool _crossDocument{false};
};

} // exception
} // ecorecpp
