// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * xpand3/declaration/Extension.hpp
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

#ifndef XPAND3_DECLARATION_EXTENSION_HPP
#define XPAND3_DECLARATION_EXTENSION_HPP

#include <xpand3/dllXpand3.hpp>
#include <xpand3/declaration_forward.hpp>

#include <ecore_forward.hpp>
#include <xpand3_forward.hpp>
#include <xpand3/expression_forward.hpp>
#include <xpand3/declaration/AbstractNamedDeclaration.hpp>

#include "DeclarationPackage.hpp"

/*PROTECTED REGION ID(Extension_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace xpand3
{
    namespace declaration
    {

    class EXPORT_XPAND3_DLL Extension : public virtual ::xpand3::declaration::AbstractNamedDeclaration
    {
    public:
        Extension();

        virtual ~Extension();

        virtual void _initialize();

        // Operations

        // Attributes
        virtual ::ecore::EBoolean isCached () const;
        virtual void setCached (::ecore::EBoolean _cached);

        // References
        virtual ::xpand3::expression::AbstractExpression_ptr getBody () const;
        virtual void setBody (::xpand3::expression::AbstractExpression_ptr _body);

        virtual ::xpand3::Identifier_ptr getReturnType () const;
        virtual void setReturnType (::xpand3::Identifier_ptr _returnType);

        /* This is the same value as getClassifierId() returns, but as a static
         * value it can be used in template expansions. */
        static const int classifierId = DeclarationPackage::EXTENSION;

        /*PROTECTED REGION ID(Extension) START*/
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

        /*PROTECTED REGION ID(ExtensionImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        Extension_ptr _this()
        {   return std::dynamic_pointer_cast<Extension>(shared_from_this());}

        // Attributes

        ::ecore::EBoolean m_cached
        {};

        // References

        ::xpand3::expression::AbstractExpression_ptr m_body;

        ::xpand3::Identifier_ptr m_returnType;

    };

}
 // declaration
}// xpand3

#endif // XPAND3_DECLARATION_EXTENSION_HPP

