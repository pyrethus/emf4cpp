// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * mapping/elist_traits.hpp
 * Copyright (C) INCHRON GmbH 2019 <soeren.henning@inchron.com>
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

#ifndef ECORECPP_MAPPING_ELISTTRAITS_HPP
#define ECORECPP_MAPPING_ELISTTRAITS_HPP

#include <algorithm>
#include <memory>
#include <vector>

#include <ecore_forward.hpp>

namespace ecorecpp
{
namespace mapping
{

template<typename T> struct is_shared_ptr : std::false_type {};
template<typename T> struct is_shared_ptr<std::shared_ptr<T>> : std::true_type {};

template< typename T, bool Containment = false >
struct ContainmentPolicy {
	using value_type = T;
	using ptr_type = std::weak_ptr<typename value_type::element_type>;
	using container_type = std::vector<ptr_type>;

	static void free_all(container_type&) {
	}

	static void free(value_type&) {
	}

	static void set(value_type&, ::ecore::EObject_ptr, ::ecore::EReference_ptr&) {
	}

	static void unset(value_type&, ::ecore::EReference_ptr&) {
	}

	static void cleanup(container_type& cont) {
		cont.erase( std::remove_if( cont.begin(), cont.end(),
					[](const ptr_type& ptr) {return ptr.expired();} )
				, cont.end() );

	}

	static value_type to_value_type(const ptr_type& ptr) {
		return ptr.lock();
	}
};

template< typename T >
struct ContainmentPolicy< T, true > {
	using value_type = T;
	using ptr_type = value_type;
	using container_type = std::vector<ptr_type>;

	static void free_all(container_type& vec) {
		std::for_each(vec.begin(), vec.end(), [](ptr_type& ptr) { ptr.reset(); });
	}

	static void free(value_type& ptr) {
		ptr.reset();
	}

	static void set(value_type& obj, ::ecore::EObject_ptr parent, ::ecore::EReference_ptr& ref) {
		if (obj)
			obj->_setEContainer(parent, ref);
	}

	static void unset(value_type& obj, ::ecore::EReference_ptr& ref) {
		if (obj)
			obj->_setEContainer(::ecore::EObject_ptr(), ref);
	}

	static void cleanup(container_type&) {
	}

	static value_type to_value_type(const ptr_type& ptr) {
		return ptr;
	}
};

template< typename T, bool Opposite = false >
struct OppositePolicy
{
	using value_type = T;

	static void set(value_type&, ::ecore::EObject_ptr, int) {
	}

	static void unset(value_type&, ::ecore::EObject_ptr, int) {
	}
};

template< typename T >
struct OppositePolicy< T, true >
{
	using value_type = T;

	static void set(value_type& obj, ::ecore::EObject_ptr parent, int oppRef) {
		if (oppRef == -1)
			return;

		if (obj)
			obj->_inverseAdd(oppRef, parent);
	}

	static void unset(value_type& obj, ::ecore::EObject_ptr parent, int oppRef) {
		if (oppRef == -1)
			return;

		if (obj)
			obj->_inverseRemove(oppRef, parent);
	}
};

} // mapping
} // ecorecpp

#endif // ECORECPP_MAPPING_ELISTTRAITS_HPP
