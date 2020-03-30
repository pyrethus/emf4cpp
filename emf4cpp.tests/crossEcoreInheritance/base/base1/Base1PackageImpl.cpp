// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * base/base1/Base1PackageImpl.cpp
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

#include <base/base1/Base1Package.hpp>
#include <base/base1/Base1Factory.hpp>
#include <ecore.hpp>
#include <ecore/EcorePackage.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EAttribute.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EOperation.hpp>
#include <ecore/EParameter.hpp>
#include <ecore/EEnum.hpp>
#include <ecore/EEnumLiteral.hpp>
#include <ecore/EDataType.hpp>
#include <ecore/EGenericType.hpp>
#include <ecore/ETypeParameter.hpp>
#include <ecore/EcorePackage.hpp>
#include <derived/DerivedPackage.hpp>
#include <derived/Derived02.hpp>

using namespace ::base::base1;

Base1Package::Base1Package()
{

    // Feature definitions of Base10
    m_Base10__valBase10 = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of Base11
    m_Base11__valBase11 = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

}

void Base1Package::_initPackage()
{
    // Factory
    ::ecore::EFactory_ptr _fa = Base1Factory::_instance();
    basicsetEFactoryInstance(_fa);
    _fa->basicsetEPackage(_this());

// Create classes and their features
    auto &classifiers = (::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EClassifier_ptr, -1, true, true >&) getEClassifiers();

    { // Base10
        m_Base10EClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
        m_Base10EClass->setClassifierID(BASE10);
        m_Base10EClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_Base10EClass);
        // m_Base10__valBase10 has already been allocated above
        m_Base10__valBase10->setFeatureID(
                ::base::base1::Base1Package::BASE10__VALBASE10);
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_Base10EClass->getEStructuralFeatures()).basicAdd(
                m_Base10__valBase10);
        m_Base10__valBase10->basicsetEContainingClass(m_Base10EClass);
    }

    { // Base11
        m_Base11EClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
        m_Base11EClass->setClassifierID(BASE11);
        m_Base11EClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_Base11EClass);
        // m_Base11__valBase11 has already been allocated above
        m_Base11__valBase11->setFeatureID(
                ::base::base1::Base1Package::BASE11__VALBASE11);
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_Base11EClass->getEStructuralFeatures()).basicAdd(
                m_Base11__valBase11);
        m_Base11__valBase11->basicsetEContainingClass(m_Base11EClass);
    }

    // Create enums

    // Create data types

    getESubpackages().push_back(
            ::base::base1::base2::Base2Package::_getInstanceAndRemoveOwnership());

    // Initialize package
    setName("base1");
    setNsPrefix("base1");
    setNsURI("http:///com.example.base.ecore/base/base1");

    // TODO: bounds for type parameters

    // Add supertypes to classes
    m_Base10EClass->getESuperTypes().push_back(
            dynamic_cast< ::base::BasePackage* >(::base::BasePackage::_instance().get())->getBase01());
    m_Base11EClass->getESuperTypes().push_back(m_Base10EClass);
    m_Base11EClass->getESuperTypes().push_back(
            dynamic_cast< ::base::BasePackage* >(::base::BasePackage::_instance().get())->getBase02());
    m_Base11EClass->getESuperTypes().push_back(
            dynamic_cast< ::base::BasePackage* >(::base::BasePackage::_instance().get())->getBase03());

    // TODO: Initialize classes and features; add operations and parameters
    // TODO: GenericTypes
    { // Base10
        m_Base10EClass->setName("Base10");
        m_Base10EClass->setAbstract(false);
        m_Base10EClass->setInterface(false);
        m_Base10__valBase10->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEInt());
        m_Base10__valBase10->setName("valBase10");
        m_Base10__valBase10->setDefaultValueLiteral("");
        m_Base10__valBase10->setLowerBound(0);
        m_Base10__valBase10->setUpperBound(1);
        m_Base10__valBase10->setTransient(false);
        m_Base10__valBase10->setVolatile(false);
        m_Base10__valBase10->setChangeable(true);
        m_Base10__valBase10->setUnsettable(false);
        m_Base10__valBase10->setID(false);
        m_Base10__valBase10->setUnique(true);
        m_Base10__valBase10->setDerived(false);
        m_Base10__valBase10->setOrdered(true);

    }

    { // Base11
        m_Base11EClass->setName("Base11");
        m_Base11EClass->setAbstract(false);
        m_Base11EClass->setInterface(false);
        m_Base11__valBase11->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEInt());
        m_Base11__valBase11->setName("valBase11");
        m_Base11__valBase11->setDefaultValueLiteral("");
        m_Base11__valBase11->setLowerBound(0);
        m_Base11__valBase11->setUpperBound(1);
        m_Base11__valBase11->setTransient(false);
        m_Base11__valBase11->setVolatile(false);
        m_Base11__valBase11->setChangeable(true);
        m_Base11__valBase11->setUnsettable(false);
        m_Base11__valBase11->setID(false);
        m_Base11__valBase11->setUnique(true);
        m_Base11__valBase11->setDerived(false);
        m_Base11__valBase11->setOrdered(true);

    }

    // TODO: Initialize data types

    /* EAnnotations for EPackage, the EClasses and their EStructuralFeatures */
    ::ecore::EAnnotation_ptr _annotation;

    _initialize();
}

::ecore::EClass_ptr Base1Package::getBase10()
{
    return m_Base10EClass;
}
::ecore::EClass_ptr Base1Package::getBase11()
{
    return m_Base11EClass;
}

::ecore::EAttribute_ptr Base1Package::getBase10__valBase10()
{
    return m_Base10__valBase10;
}
::ecore::EAttribute_ptr Base1Package::getBase11__valBase11()
{
    return m_Base11__valBase11;
}

