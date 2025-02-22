// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * xpand3/expression/Literal.cpp
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

#include "Literal.hpp"
#include <xpand3/expression/AbstractExpression.hpp>
#include <xpand3/Identifier.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "xpand3/expression/ExpressionPackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

/*PROTECTED REGION ID(Literal.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

using namespace ::xpand3::expression;

// Default constructor
Literal::Literal()
{
    /*PROTECTED REGION ID(LiteralImpl__LiteralImpl) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

#ifdef ECORECPP_NOTIFICATION_API
    m_eDeliver = false;
#endif
}

Literal::~Literal()
{
    if (m_literalValue)
    {
        m_literalValue.reset();
    }
}

// Attributes

// References

::xpand3::Identifier_ptr Literal::getLiteralValue() const
{
    return m_literalValue;
}

void Literal::setLiteralValue(::xpand3::Identifier_ptr _literalValue)
{
    if (m_literalValue)
        m_literalValue->_setEContainer(Literal_ptr(),
                ::xpand3::expression::ExpressionPackage::_instance()->getLiteral__literalValue());
    if (_literalValue)
        _literalValue->_setEContainer(_this(),
                ::xpand3::expression::ExpressionPackage::_instance()->getLiteral__literalValue());

#ifdef ECORECPP_NOTIFICATION_API
    ::xpand3::Identifier_ptr _old_literalValue = m_literalValue;
#endif
    m_literalValue = _literalValue;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                _this(),
                ::xpand3::expression::ExpressionPackage::_instance()->getLiteral__literalValue(),
                _old_literalValue,
                m_literalValue
            );
        eNotify(&notification);
    }
#endif
}

