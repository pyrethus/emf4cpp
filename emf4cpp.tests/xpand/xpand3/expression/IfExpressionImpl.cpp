// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * xpand3/expression/IfExpressionImpl.cpp
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

#include "IfExpression.hpp"
#include <xpand3/expression/ExpressionPackage.hpp>
#include <xpand3/expression/AbstractExpression.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

/*PROTECTED REGION ID(IfExpressionImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::xpand3::expression;

void IfExpression::_initialize()
{
    // Supertypes
    ::xpand3::expression::AbstractExpression::_initialize();

    // References
    if (m_condition)
    {
        m_condition->_initialize();
    }
    if (m_thenPart)
    {
        m_thenPart->_initialize();
    }
    if (m_elsePart)
    {
        m_elsePart->_initialize();
    }

    /*PROTECTED REGION ID(IfExpressionImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations

// EObject
::ecore::EJavaObject IfExpression::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean /*_resolve*/)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__LINE:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::toAny(_any, getLine());
    }
        return _any;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__START:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::toAny(_any, getStart());
    }
        return _any;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__END:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::toAny(_any, getEnd());
    }
        return _any;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__FILENAME:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EString
                > ::toAny(_any, getFileName());
    }
        return _any;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__CONDITION:
    {
        _any = ::ecore::as < ::ecore::EObject > (getCondition());
    }
        return _any;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__THENPART:
    {
        _any = ::ecore::as < ::ecore::EObject > (getThenPart());
    }
        return _any;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__ELSEPART:
    {
        _any = ::ecore::as < ::ecore::EObject > (getElsePart());
    }
        return _any;

    }
    throw "Error: eGet() does not handle this featureID";
}

void IfExpression::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__LINE:
    {
        ::ecore::EInt _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::fromAny(_newValue, _t0);
        setLine(_t0);
    }
        return;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__START:
    {
        ::ecore::EInt _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::fromAny(_newValue, _t0);
        setStart(_t0);
    }
        return;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__END:
    {
        ::ecore::EInt _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::fromAny(_newValue, _t0);
        setEnd(_t0);
    }
        return;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__FILENAME:
    {
        ::ecore::EString _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EString
                > ::fromAny(_newValue, _t0);
        setFileName(_t0);
    }
        return;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__CONDITION:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::xpand3::expression::AbstractExpression
                > (_t0);
        setCondition(_t1);
    }
        return;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__THENPART:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::xpand3::expression::AbstractExpression
                > (_t0);
        setThenPart(_t1);
    }
        return;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__ELSEPART:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::xpand3::expression::AbstractExpression
                > (_t0);
        setElsePart(_t1);
    }
        return;

    }
    throw "Error: eSet() does not handle this featureID";
}

::ecore::EBoolean IfExpression::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__LINE:
        return ::ecorecpp::mapping::set_traits < ::ecore::EInt
                > ::is_set(getLine());
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__START:
        return ::ecorecpp::mapping::set_traits < ::ecore::EInt
                > ::is_set(getStart());
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__END:
        return ::ecorecpp::mapping::set_traits < ::ecore::EInt
                > ::is_set(getEnd());
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__FILENAME:
        return ::ecorecpp::mapping::set_traits < ::ecore::EString
                > ::is_set(getFileName());
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__CONDITION:
        return getCondition().get() != nullptr;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__THENPART:
        return getThenPart().get() != nullptr;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__ELSEPART:
        return getElsePart().get() != nullptr;

    }
    throw "Error: eIsSet() does not handle this featureID";
}

void IfExpression::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error: eUnset() does not handle this featureID";
}

::ecore::EClass_ptr IfExpression::_eClass()
{
    static ::ecore::EClass_ptr _eclass =
            ::xpand3::expression::ExpressionPackage::_instance()->getIfExpression();
    return _eclass;
}

/** Set the local end of a reference with an EOpposite property.
 */
void IfExpression::_inverseAdd(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__CONDITION:
    {
    }
        return;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__THENPART:
    {
    }
        return;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__ELSEPART:
    {
    }
        return;

    }
    throw "Error: _inverseAdd() does not handle this featureID";
}

/** Unset the local end of a reference with an EOpposite property.
 */
void IfExpression::_inverseRemove(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_oldValue)
{
    switch (_featureID)
    {
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__CONDITION:
    {
    }
        return;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__THENPART:
    {
    }
        return;
    case ::xpand3::expression::ExpressionPackage::IFEXPRESSION__ELSEPART:
    {
    }
        return;

    }
    throw "Error: _inverseRemove() does not handle this featureID";
}

