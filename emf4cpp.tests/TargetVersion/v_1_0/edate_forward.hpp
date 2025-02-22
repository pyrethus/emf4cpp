// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * v_1_0/edate_forward.hpp
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

#ifndef _V_1_0_EDATE_FORWARD_HPP
#define _V_1_0_EDATE_FORWARD_HPP

#include <ecore_forward.hpp> // for EDataTypes

/*PROTECTED REGION ID(v_1_0_edate_forward) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
// Additional headers here
/*PROTECTED REGION END*/

// EPackage

namespace v_1_0
{
    namespace edate
    {

// EDataType

// EClass

// Person
        class Person;
        using Person_ptr = ::ecore::Ptr<Person>;

// Apollo11
        class Apollo11;
        using Apollo11_ptr = ::ecore::Ptr<Apollo11>;

// EEnum

// Package & Factory
        class EdateFactory;
        using EdateFactory_ptr = ::ecore::Ptr<EdateFactory>;
        class EdatePackage;
        using EdatePackage_ptr = ::ecore::Ptr<EdatePackage>;

    } // edate
} // v_1_0

#endif // _V_1_0_EDATE_FORWARD_HPP

