// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * xpand3/statement/AbstractStatementWithBody.hpp
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

#ifndef XPAND3_STATEMENT_ABSTRACTSTATEMENTWITHBODY_HPP
#define XPAND3_STATEMENT_ABSTRACTSTATEMENTWITHBODY_HPP

#include <xpand3/dllXpand3.hpp>
#include <xpand3/statement_forward.hpp>

#include <ecore_forward.hpp>
#include <xpand3/statement/AbstractStatement.hpp>

#include "StatementPackage.hpp"

/*PROTECTED REGION ID(AbstractStatementWithBody_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace xpand3
{
    namespace statement
    {

    class EXPORT_XPAND3_DLL AbstractStatementWithBody : public virtual ::xpand3::statement::AbstractStatement
    {
    public:
        AbstractStatementWithBody();

        virtual ~AbstractStatementWithBody();

        virtual void _initialize();

        // Operations

        // Attributes

        // References
        virtual const ::ecorecpp::mapping::EList< ::xpand3::statement::AbstractStatement_ptr >& getBody () const;
        virtual ::ecorecpp::mapping::EList< ::xpand3::statement::AbstractStatement_ptr >& getBody ();

        /* This is the same value as getClassifierId() returns, but as a static
         * value it can be used in template expansions. */
        static const int classifierId = StatementPackage::ABSTRACTSTATEMENTWITHBODY;

        /*PROTECTED REGION ID(AbstractStatementWithBody) START*/
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

        /*PROTECTED REGION ID(AbstractStatementWithBodyImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        AbstractStatementWithBody_ptr _this()
        {   return std::dynamic_pointer_cast<AbstractStatementWithBody>(shared_from_this());}

        // Attributes

        // References

        ::ecore::EList_ptr< ::xpand3::statement::AbstractStatement_ptr > m_body;

    };

}
 // statement
}// xpand3

#endif // XPAND3_STATEMENT_ABSTRACTSTATEMENTWITHBODY_HPP

