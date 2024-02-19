// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * ecore/EPackage.hpp
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

#ifndef ECORE_EPACKAGE_HPP
#define ECORE_EPACKAGE_HPP

#include <ecore/dllEcore.hpp>
#include <ecore_forward.hpp>

#include <ecore/ENamedElement.hpp>

#include <unordered_map>
#include <memory>
#include <ecorecpp/ItemProvider.hpp>

/*PROTECTED REGION END*/

namespace ecore
{

class EXPORT_ECORE_DLL EPackage : public virtual ::ecore::ENamedElement
{
public:
    EPackage();

    virtual ~EPackage();

    virtual void _initialize();

    // Operations

    virtual ::ecore::EClassifier_ptr getEClassifier ( ::ecore::EString const& _name);

    // Attributes
    virtual ::ecore::EString const& getNsURI () const;
    virtual void setNsURI (::ecore::EString const& _nsURI);

    virtual ::ecore::EString const& getNsPrefix () const;
    virtual void setNsPrefix (::ecore::EString const& _nsPrefix);

    // References
    virtual ::ecore::EFactory_ptr getEFactoryInstance () const;
    virtual void setEFactoryInstance (::ecore::EFactory_ptr _eFactoryInstance);
    virtual ::ecore::EFactory_ptr basicgetEFactoryInstance ();
    virtual void basicsetEFactoryInstance (::ecore::EFactory_ptr _eFactoryInstance);

    virtual const ::ecorecpp::mapping::EList< ::ecore::EClassifier_ptr >& getEClassifiers () const;
    virtual ::ecorecpp::mapping::EList< ::ecore::EClassifier_ptr >& getEClassifiers ();

    virtual const ::ecorecpp::mapping::EList< ::ecore::EPackage_ptr >& getESubpackages () const;
    virtual ::ecorecpp::mapping::EList< ::ecore::EPackage_ptr >& getESubpackages ();

    virtual ::ecore::EPackage_ptr getESuperPackage () const;
    virtual void setESuperPackage (::ecore::EPackage_ptr _eSuperPackage);
    virtual ::ecore::EPackage_ptr basicgetESuperPackage ();
    virtual void basicsetESuperPackage (::ecore::EPackage_ptr _eSuperPackage);

    /*PROTECTED REGION ID(EPackage) ENABLED START*/

    static constexpr uint64_t makeUniqueFeatureID( uint32_t classID, uint32_t featureID )
    {
        return (static_cast<uint64_t>(classID) << 32) | featureID;
    }

protected:
    // Hardcoded map to speed up getEClassifier operation
    typedef std::unordered_map< ::ecore::EString , ::ecore::EClassifier_ptr > EClassifierMapType;

    EClassifierMapType m_eClassifiersMap;

public:
    const std::shared_ptr<::ecorecpp::ItemProvider>& getItemProviderInstance () const;
    void setItemProviderInstance (const std::shared_ptr<::ecorecpp::ItemProvider>&);

protected:
    std::shared_ptr<::ecorecpp::ItemProvider> m_itemProviderInstance;

public:
    /*PROTECTED REGION END*/

    // EObjectImpl
    virtual ::ecore::EJavaObject eGet ( ::ecore::EInt _featureID, ::ecore::EBoolean _resolve);
    virtual void eSet ( ::ecore::EInt _featureID, ::ecore::EJavaObject const& _newValue);
    virtual ::ecore::EBoolean eIsSet ( ::ecore::EInt _featureID);
    virtual void eUnset ( ::ecore::EInt _featureID);
    virtual ::ecore::EClass_ptr _eClass ();
    virtual void _inverseAdd ( ::ecore::EInt _featureID, ::ecore::EJavaObject const& _newValue);
    virtual void _inverseRemove ( ::ecore::EInt _featureID, ::ecore::EJavaObject const& _oldValue);

    /*PROTECTED REGION ID(EPackageImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/

protected:
    EPackage_ptr _this()
    {   return std::dynamic_pointer_cast<EPackage>(shared_from_this());}

    // Attributes

    ::ecore::EString m_nsURI
    {};

    ::ecore::EString m_nsPrefix
    {};

    // References

    std::weak_ptr< ::ecore::EFactory > m_eFactoryInstance;

    ::ecore::EList_ptr< ::ecore::EClassifier_ptr > m_eClassifiers;

    ::ecore::EList_ptr< ::ecore::EPackage_ptr > m_eSubpackages;

    std::weak_ptr< ::ecore::EPackage > m_eSuperPackage;

};

}
 // ecore

#endif // ECORE_EPACKAGE_HPP

