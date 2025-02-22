// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * myDsl/Entity.hpp
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

#ifndef MYDSL_ENTITY_HPP
#define MYDSL_ENTITY_HPP

#include <myDsl/dllMyDsl.hpp>
#include <myDsl_forward.hpp>

#include <ecore_forward.hpp>
#include <myDsl/Type.hpp>

#include "MyDslPackage.hpp"

/*PROTECTED REGION ID(Entity_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace myDsl
{

class EXPORT_MYDSL_DLL Entity : public virtual ::myDsl::Type
{
public:
    Entity();

    virtual ~Entity();

    virtual void _initialize();

    // Operations

    // Attributes

    // References
    virtual ::myDsl::Entity_ptr getExtends () const;
    virtual void setExtends (::myDsl::Entity_ptr _extends);

    virtual const ::ecorecpp::mapping::EList< ::myDsl::Property_ptr >& getProperties () const;
    virtual ::ecorecpp::mapping::EList< ::myDsl::Property_ptr >& getProperties ();

    /* This is the same value as getClassifierId() returns, but as a static
     * value it can be used in template expansions. */
    static const int classifierId = MyDslPackage::ENTITY;

    /*PROTECTED REGION ID(Entity) START*/
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

    /*PROTECTED REGION ID(EntityImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

protected:
    Entity_ptr _this()
    {   return std::dynamic_pointer_cast<Entity>(shared_from_this());}

    // Attributes

    // References

    std::weak_ptr< ::myDsl::Entity > m_extends;

    ::ecore::EList_ptr< ::myDsl::Property_ptr > m_properties;

};

}
 // myDsl

#endif // MYDSL_ENTITY_HPP

