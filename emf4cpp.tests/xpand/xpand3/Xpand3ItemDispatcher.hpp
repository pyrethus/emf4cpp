// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * xpand3/Xpand3ItemDispatcher.hpp
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

#ifndef XPAND3_ITEMDISPATCHER_HPP
#define XPAND3_ITEMDISPATCHER_HPP
#include <cassert>

#include <ecore_forward.hpp>
#include <ecore/EClass.hpp>

#include <xpand3.hpp>
#include <xpand3/dllXpand3.hpp>

namespace xpand3
{

    template<class T>
    class EXPORT_XPAND3_DLL
Xpand3ItemDispatcher
{
public:
    Xpand3ItemDispatcher() = default;
    ~Xpand3ItemDispatcher() = default;

    /** Clients need to overload and reimplement this work() method for every
     * class they want to handle. The second argument is a dummy argument to
     * disambiguate work methods in case of an inheritance hirarchy and
     * always contains a nullptr.
     * Note that in a class hierarchy classes may be shadowed by derived classes. */
    void work(const ::ecore::EObject_ptr&, ::ecore::EObject*)
    {}

    /** Entry function for the dispatch mechanism. */
    void enter(const ::ecore::EObject_ptr& obj)
    {
        auto eClass = obj->eClass();
        if (eClass->getEPackage() != Xpand3Package::_instance())
        {
            assert(!"The package of the eclass does not match the package of the dispatcher!");
            return;
        }

        switch (eClass->getClassifierID())
        {
            case Xpand3Package::DECLAREDPARAMETER:
            {
                auto derived = ::ecore::as< DeclaredParameter >(obj);
                _this()->T::work(derived, (DeclaredParameter*)nullptr);
            }break;
            case Xpand3Package::FILE:
            {
                auto derived = ::ecore::as< File >(obj);
                _this()->T::work(derived, (File*)nullptr);
            }break;
            case Xpand3Package::IDENTIFIER:
            {
                auto derived = ::ecore::as< Identifier >(obj);
                _this()->T::work(derived, (Identifier*)nullptr);
            }break;
            case Xpand3Package::IMPORTSTATEMENT:
            {
                auto derived = ::ecore::as< ImportStatement >(obj);
                _this()->T::work(derived, (ImportStatement*)nullptr);
            }break;
            case Xpand3Package::SYNTAXELEMENT:
            {
                auto derived = ::ecore::as< SyntaxElement >(obj);
                _this()->T::work(derived, (SyntaxElement*)nullptr);
            }break;
            default:
            break;
        }
    }

private:
    /** Inline helper, should compile to simple offset adjustment. */
    T* _this()
    {   return static_cast<T*>(this);}

    /** Inline helper, should compile to simple offset adjustment. */
    const T* _this() const
    {   return static_cast<const T*>(this);}
};

}
 // xpand3

#endif // XPAND3_ITEMDISPATCHER_HPP
