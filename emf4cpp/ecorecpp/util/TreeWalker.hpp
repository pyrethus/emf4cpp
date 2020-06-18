// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * TreeWalker.hpp
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

#ifndef TreeWalker_HPP
#define TreeWalker_HPP

#include "../dllEcorecpp.hpp"

#include <functional>
#include <ecore_forward.hpp>

namespace ecorecpp {
namespace util {

class EXPORT_ECORECPP_DLL TreeWalker {
public:
	enum class Status { Continue, SkipChildren, Stop };

	using ObjectHandler = std::function<Status (const ::ecore::EObject_ptr&)>;

	/** Create a pre- and post-order TreeWalker for an EMF instance
	 *
	 * @param preOrder  any function like object accepting an EObject_ptr and
	 *                  returning bool (required argument, nullptr allowed)
	 * @param postOrder any function like object accepting an EObject_ptr and
	 *                  returning bool (optional argument)
	 *
	 * The TreeWalker traverses the EMF instance along the containment
	 * relations. For every EObject visited it calls the pre-order functor,
	 * descends to the contained children, and calls the post-order
	 * functor. If any functor returns Status::Stop, the tree traversal stops
	 * and the current EObject is returned. This can be used for a find
	 * functionality.
	 *
	 * If the functor returns Status::Continue, the tree traversal is
	 * continued and a nullptr is returned. Likewise Status::SkipChildren
	 * continues, but does not iterate over the children of the current item.
	 *
	 * \note You can call methods of object instances by using
	 * std::bind(&Foo::method, &foo, std::placeholders::_1).
	 *
	 * \note TreeWalker(nullptr, PostOrderFunctor) is a valid post-order
	 * tree traversal.
	 */
	TreeWalker(ObjectHandler preOrder, ObjectHandler postOrder = nullptr);
	~TreeWalker();

	::ecore::EObject_ptr traverse(const ::ecore::EObject_ptr& obj);

private:
	ObjectHandler _preOrder, _postOrder;
};

} // utils
} // ecorecpp

#endif /* TreeWalker_HPP */
