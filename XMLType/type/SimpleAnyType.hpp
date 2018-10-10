// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * type/SimpleAnyType.hpp
 * Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
 * Copyright (C) INCHRON GmbH 2016-2018 <emf4cpp@inchron.com>
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

#ifndef TYPE_SIMPLEANYTYPE_HPP
#define TYPE_SIMPLEANYTYPE_HPP

#include <ecorecpp/mapping_forward.hpp>

#include <type/dllType.hpp>
#include <type_forward.hpp>

#include <ecore_forward.hpp>
#include <type/AnyType.hpp>

#include "TypePackage.hpp"

/*PROTECTED REGION ID(SimpleAnyType_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace type
{

class EXPORT_TYPE_DLL SimpleAnyType : public virtual ::type::AnyType
{
public:
    SimpleAnyType();

    virtual ~SimpleAnyType();

    virtual void _initialize();

    // Operations

    // Attributes
    virtual ::type::String getRawValue () const;
    virtual void setRawValue (::type::String _rawValue);

    virtual ::type::AnySimpleType getValue () const;
    virtual void setValue (::type::AnySimpleType _value);

    // References
    virtual ::ecore::EDataType_ptr getInstanceType () const;
    virtual void setInstanceType (::ecore::EDataType_ptr _instanceType);

    /* This is the same value as getClassifierId() returns, but as a static
     * value it can be used in template expansions. */
    static const int classifierId = TypePackage::SIMPLEANYTYPE;

    /*PROTECTED REGION ID(SimpleAnyType) START*/
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

    /*PROTECTED REGION ID(SimpleAnyTypeImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

protected:
    SimpleAnyType_ptr _this()
    {   return SimpleAnyType_ptr(this);}

    // Attributes

    ::type::String m_rawValue
    {};

    ::type::AnySimpleType m_value
    {};

    // References

    ::ecore::EDataType_ptr m_instanceType;

};

}
 // type

#endif // TYPE_SIMPLEANYTYPE_HPP

