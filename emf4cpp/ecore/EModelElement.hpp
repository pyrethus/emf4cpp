// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * ecore/EModelElement.hpp
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

#ifndef ECORE_EMODELELEMENT_HPP
#define ECORE_EMODELELEMENT_HPP

#include <ecore/EObject.hpp>

#include <ecore/dllEcore.hpp>
#include <ecore_forward.hpp>

/*PROTECTED REGION ID(EModelElement_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace ecore
{

class EXPORT_ECORE_DLL EModelElement : public virtual ::ecore::EObject
{
public:
    EModelElement();

    virtual ~EModelElement();

    virtual void _initialize();

    // Operations

    virtual ::ecore::EAnnotation_ptr getEAnnotation ( ::ecore::EString const& _source);

    // Attributes

    // References
    virtual const ::ecorecpp::mapping::EList< ::ecore::EAnnotation_ptr >& getEAnnotations () const;
    virtual ::ecorecpp::mapping::EList< ::ecore::EAnnotation_ptr >& getEAnnotations ();

    /*PROTECTED REGION ID(EModelElement) START*/
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

    /*PROTECTED REGION ID(EModelElementImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

protected:
    EModelElement_ptr _this()
    {   return std::dynamic_pointer_cast<EModelElement>(shared_from_this());}

    // Attributes

    // References

    ::ecore::EList_ptr< ::ecore::EAnnotation_ptr > m_eAnnotations;

};

}
 // ecore

#endif // ECORE_EMODELELEMENT_HPP

