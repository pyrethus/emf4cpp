// -*- mode: c++; c-basic-offset: 4; -*-
/*
 * TreeWalker.cpp
 * Copyright 2020 INCHRON AG <info@inchron.com>
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

#include "TreeWalker.hpp"

#include <ecore.hpp>

namespace ecorecpp {
namespace util {

TreeWalker::TreeWalker( ObjectHandler preOrder, ObjectHandler postOrder )
	: _preOrder(preOrder),
	  _postOrder(postOrder) {
}

TreeWalker::~TreeWalker() {
}

::ecore::EObject_ptr TreeWalker::traverse(const ::ecore::EObject_ptr& obj) {
	Status status = Status::Continue;

	if (_preOrder != nullptr) {
		status = _preOrder(obj);
		if ( status == Status::Stop )
			return obj;
	}

	if (status != Status::SkipChildren) {
		auto children = obj->eContents();
		for (auto child : *children) {
			auto obj = traverse(child);
			if (obj)
				return obj;
		}
	}

	if (_postOrder != nullptr) {
		status = _postOrder(obj);
		if (status == Status::Stop)
			return obj;
	}

	return nullptr;
}

} // util
} // ecorecpp
