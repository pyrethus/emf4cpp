// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * xpand3/statement/ForEachStatement.hpp
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

#ifndef XPAND3_STATEMENT_FOREACHSTATEMENT_HPP
#define XPAND3_STATEMENT_FOREACHSTATEMENT_HPP

#include <xpand3/dllXpand3.hpp>
#include <xpand3/statement_forward.hpp>

#include <ecore_forward.hpp>
#include <xpand3/expression_forward.hpp>
#include <xpand3_forward.hpp>
#include <xpand3/statement/AbstractStatementWithBody.hpp>

#include "StatementPackage.hpp"

/*PROTECTED REGION ID(ForEachStatement_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace xpand3
{
    namespace statement
    {

    class EXPORT_XPAND3_DLL ForEachStatement : public virtual ::xpand3::statement::AbstractStatementWithBody
    {
    public:
        ForEachStatement();

        virtual ~ForEachStatement();

        virtual void _initialize();

        // Operations

        // Attributes

        // References
        virtual ::xpand3::expression::AbstractExpression_ptr getTarget () const;
        virtual void setTarget (::xpand3::expression::AbstractExpression_ptr _target);

        virtual ::xpand3::expression::AbstractExpression_ptr getSeparator () const;
        virtual void setSeparator (::xpand3::expression::AbstractExpression_ptr _separator);

        virtual ::xpand3::Identifier_ptr getVariable () const;
        virtual void setVariable (::xpand3::Identifier_ptr _variable);

        virtual ::xpand3::Identifier_ptr getIteratorName () const;
        virtual void setIteratorName (::xpand3::Identifier_ptr _iteratorName);

        /* This is the same value as getClassifierId() returns, but as a static
         * value it can be used in template expansions. */
        static const int classifierId = StatementPackage::FOREACHSTATEMENT;

        /*PROTECTED REGION ID(ForEachStatement) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        virtual ::ecore::EJavaObject eGet ( ::ecore::EInt _featureID, ::ecore::EBoolean _resolve);
        virtual void eSet ( ::ecore::EInt _featureID, ::ecore::EJavaObject const& _newValue);
        virtual ::ecore::EBoolean eIsSet ( ::ecore::EInt _featureID);
        virtual void eUnset ( ::ecore::EInt _featureID);
        virtual ::ecore::EClass_ptr _eClass ();
        virtual void _inverseAdd ( ::ecore::EInt _featureID, ::ecore::EJavaObject const& _newValue);
        virtual void _inverseRemove ( ::ecore::EInt _featureID, ::ecore::EJavaObject const& _oldValue);

        /*PROTECTED REGION ID(ForEachStatementImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        ForEachStatement_ptr _this()
        {   return std::dynamic_pointer_cast<ForEachStatement>(shared_from_this());}

        // Attributes

        // References

        ::xpand3::expression::AbstractExpression_ptr m_target;

        ::xpand3::expression::AbstractExpression_ptr m_separator;

        ::xpand3::Identifier_ptr m_variable;

        ::xpand3::Identifier_ptr m_iteratorName;

    };

}
 // statement
}// xpand3

#endif // XPAND3_STATEMENT_FOREACHSTATEMENT_HPP

