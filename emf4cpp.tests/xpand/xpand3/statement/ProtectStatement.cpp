// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * xpand3/statement/ProtectStatement.cpp
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

#include "ProtectStatement.hpp"
#include <xpand3/statement/AbstractStatementWithBody.hpp>
#include <xpand3/statement/AbstractStatement.hpp>
#include <xpand3/expression/AbstractExpression.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "xpand3/statement/StatementPackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

/*PROTECTED REGION ID(ProtectStatement.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::xpand3::statement;

// Default constructor
ProtectStatement::ProtectStatement()
{
    /*PROTECTED REGION ID(ProtectStatementImpl__ProtectStatementImpl) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API
    m_eDeliver = false;
#endif
}

ProtectStatement::~ProtectStatement()
{
    if (m_commentStart)
    {
        m_commentStart.reset();
    }
    if (m_commentEnd)
    {
        m_commentEnd.reset();
    }
    if (m_id)
    {
        m_id.reset();
    }
}

// Attributes

::ecore::EBoolean ProtectStatement::isDisable() const
{
    return m_disable;
}

void ProtectStatement::setDisable(::ecore::EBoolean _disable)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EBoolean _old_disable = m_disable;
#endif
    m_disable = _disable;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::xpand3::statement::StatementPackage::_instance()->getProtectStatement__disable(),
                _old_disable,
                m_disable
            );
        eNotify(&notification);
    }
#endif
}

// References

::xpand3::expression::AbstractExpression_ptr ProtectStatement::getCommentStart() const
{
    return m_commentStart;
}

void ProtectStatement::setCommentStart(
        ::xpand3::expression::AbstractExpression_ptr _commentStart)
{
    if (m_commentStart)
        m_commentStart->_setEContainer(ProtectStatement_ptr(),
                ::xpand3::statement::StatementPackage::_instance()->getProtectStatement__commentStart());
    if (_commentStart)
        _commentStart->_setEContainer(_this(),
                ::xpand3::statement::StatementPackage::_instance()->getProtectStatement__commentStart());

#ifdef ECORECPP_NOTIFICATION_API
    ::xpand3::expression::AbstractExpression_ptr _old_commentStart = m_commentStart;
#endif
    m_commentStart = _commentStart;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::xpand3::statement::StatementPackage::_instance()->getProtectStatement__commentStart(),
                _old_commentStart,
                m_commentStart
            );
        eNotify(&notification);
    }
#endif
}

::xpand3::expression::AbstractExpression_ptr ProtectStatement::getCommentEnd() const
{
    return m_commentEnd;
}

void ProtectStatement::setCommentEnd(
        ::xpand3::expression::AbstractExpression_ptr _commentEnd)
{
    if (m_commentEnd)
        m_commentEnd->_setEContainer(ProtectStatement_ptr(),
                ::xpand3::statement::StatementPackage::_instance()->getProtectStatement__commentEnd());
    if (_commentEnd)
        _commentEnd->_setEContainer(_this(),
                ::xpand3::statement::StatementPackage::_instance()->getProtectStatement__commentEnd());

#ifdef ECORECPP_NOTIFICATION_API
    ::xpand3::expression::AbstractExpression_ptr _old_commentEnd = m_commentEnd;
#endif
    m_commentEnd = _commentEnd;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::xpand3::statement::StatementPackage::_instance()->getProtectStatement__commentEnd(),
                _old_commentEnd,
                m_commentEnd
            );
        eNotify(&notification);
    }
#endif
}

::xpand3::expression::AbstractExpression_ptr ProtectStatement::getId() const
{
    return m_id;
}

void ProtectStatement::setId(::xpand3::expression::AbstractExpression_ptr _id)
{
    if (m_id)
        m_id->_setEContainer(ProtectStatement_ptr(),
                ::xpand3::statement::StatementPackage::_instance()->getProtectStatement__id());
    if (_id)
        _id->_setEContainer(_this(),
                ::xpand3::statement::StatementPackage::_instance()->getProtectStatement__id());

#ifdef ECORECPP_NOTIFICATION_API
    ::xpand3::expression::AbstractExpression_ptr _old_id = m_id;
#endif
    m_id = _id;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::xpand3::statement::StatementPackage::_instance()->getProtectStatement__id(),
                _old_id,
                m_id
            );
        eNotify(&notification);
    }
#endif
}

