// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * xpand3/statement/FileStatementImpl.cpp
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

#include "FileStatement.hpp"
#include <xpand3/statement/StatementPackage.hpp>
#include <xpand3/statement/AbstractStatementWithBody.hpp>
#include <xpand3/statement/AbstractStatement.hpp>
#include <xpand3/expression/AbstractExpression.hpp>
#include <xpand3/Identifier.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

/*PROTECTED REGION ID(FileStatementImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::xpand3::statement;

void FileStatement::_initialize()
{
    // Supertypes
    ::xpand3::statement::AbstractStatementWithBody::_initialize();

    // References
    if (m_fileNameExpression)
    {
        m_fileNameExpression->_initialize();
    }
    if (m_outletNameIdentifier)
    {
        m_outletNameIdentifier->_initialize();
    }

    /*PROTECTED REGION ID(FileStatementImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations

// EObject
::ecore::EJavaObject FileStatement::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean /*_resolve*/)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__LINE:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::toAny(_any, getLine());
    }
        return _any;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__START:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::toAny(_any, getStart());
    }
        return _any;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__END:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::toAny(_any, getEnd());
    }
        return _any;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__FILENAME:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EString
                > ::toAny(_any, getFileName());
    }
        return _any;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__BODY:
    {
        _any = getBody().asEListOf< ::ecore::EObject_ptr >();
    }
        return _any;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__FILENAMEEXPRESSION:
    {
        _any = ::ecore::as < ::ecore::EObject > (getFileNameExpression());
    }
        return _any;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__OUTLETNAMEIDENTIFIER:
    {
        _any = ::ecore::as < ::ecore::EObject > (getOutletNameIdentifier());
    }
        return _any;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__ONCE:
    {
        ::ecorecpp::mapping::any_traits < ::ecore::EBoolean
                > ::toAny(_any, isOnce());
    }
        return _any;

    }
    throw "Error: eGet() does not handle this featureID";
}

void FileStatement::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__LINE:
    {
        ::ecore::EInt _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::fromAny(_newValue, _t0);
        setLine(_t0);
    }
        return;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__START:
    {
        ::ecore::EInt _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::fromAny(_newValue, _t0);
        setStart(_t0);
    }
        return;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__END:
    {
        ::ecore::EInt _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EInt
                > ::fromAny(_newValue, _t0);
        setEnd(_t0);
    }
        return;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__FILENAME:
    {
        ::ecore::EString _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EString
                > ::fromAny(_newValue, _t0);
        setFileName(_t0);
    }
        return;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__BODY:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast
                < ::ecore::EList_ptr< ::ecore::EObject_ptr > > (_newValue);
        getBody().clear();
        getBody().insert_all(*_t0);
    }
        return;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__FILENAMEEXPRESSION:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::xpand3::expression::AbstractExpression
                > (_t0);
        setFileNameExpression(_t1);
    }
        return;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__OUTLETNAMEIDENTIFIER:
    {
        auto _t0 = ::ecorecpp::mapping::any::any_cast < ::ecore::EObject_ptr
                > (_newValue);
        auto _t1 = ::ecore::as < ::xpand3::Identifier > (_t0);
        setOutletNameIdentifier(_t1);
    }
        return;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__ONCE:
    {
        ::ecore::EBoolean _t0;
        ::ecorecpp::mapping::any_traits < ::ecore::EBoolean
                > ::fromAny(_newValue, _t0);
        setOnce(_t0);
    }
        return;

    }
    throw "Error: eSet() does not handle this featureID";
}

::ecore::EBoolean FileStatement::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__LINE:
        return ::ecorecpp::mapping::set_traits < ::ecore::EInt
                > ::is_set(getLine());
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__START:
        return ::ecorecpp::mapping::set_traits < ::ecore::EInt
                > ::is_set(getStart());
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__END:
        return ::ecorecpp::mapping::set_traits < ::ecore::EInt
                > ::is_set(getEnd());
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__FILENAME:
        return ::ecorecpp::mapping::set_traits < ::ecore::EString
                > ::is_set(getFileName());
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__BODY:
        return getBody().size() > 0;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__FILENAMEEXPRESSION:
        return getFileNameExpression().get() != nullptr;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__OUTLETNAMEIDENTIFIER:
        return getOutletNameIdentifier().get() != nullptr;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__ONCE:
        return ::ecorecpp::mapping::set_traits < ::ecore::EBoolean
                > ::is_set(isOnce());

    }
    throw "Error: eIsSet() does not handle this featureID";
}

void FileStatement::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error: eUnset() does not handle this featureID";
}

::ecore::EClass_ptr FileStatement::_eClass()
{
    static ::ecore::EClass_ptr _eclass =
            ::xpand3::statement::StatementPackage::_instance()->getFileStatement();
    return _eclass;
}

/** Set the local end of a reference with an EOpposite property.
 */
void FileStatement::_inverseAdd(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_newValue)
{
    switch (_featureID)
    {
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__BODY:
    {
    }
        return;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__FILENAMEEXPRESSION:
    {
    }
        return;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__OUTLETNAMEIDENTIFIER:
    {
    }
        return;

    }
    throw "Error: _inverseAdd() does not handle this featureID";
}

/** Unset the local end of a reference with an EOpposite property.
 */
void FileStatement::_inverseRemove(::ecore::EInt _featureID,
        ::ecore::EJavaObject const &_oldValue)
{
    switch (_featureID)
    {
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__BODY:
    {
    }
        return;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__FILENAMEEXPRESSION:
    {
    }
        return;
    case ::xpand3::statement::StatementPackage::FILESTATEMENT__OUTLETNAMEIDENTIFIER:
    {
    }
        return;

    }
    throw "Error: _inverseRemove() does not handle this featureID";
}

