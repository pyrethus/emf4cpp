// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * derived/DerivedPackageImpl.cpp
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

#include <derived/DerivedPackage.hpp>
#include <derived/DerivedFactory.hpp>
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
#include <base/BasePackage.hpp>
#include <base/Base01.hpp>

using namespace ::derived;

DerivedPackage::DerivedPackage()
{

    // Feature definitions of Derived01
    m_Derived01__valDerived01 = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of Derived02
    m_Derived02__valDerived02 = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_Derived02__base01ref = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

}

void DerivedPackage::_initPackage()
{
    // Factory
    ::ecore::EFactory_ptr _fa = DerivedFactory::_instance();
    basicsetEFactoryInstance(_fa);
    _fa->basicsetEPackage(_this());

// Create classes and their features
    auto &classifiers = (::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EClassifier_ptr, -1, true, true >&) getEClassifiers();

    { // Derived01
        m_Derived01EClass = ::ecore::Ptr < ::ecore::EClass
                > (new ::ecore::EClass);
        m_Derived01EClass->setClassifierID(DERIVED01);
        m_Derived01EClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_Derived01EClass);
        // m_Derived01__valDerived01 has already been allocated above
        m_Derived01__valDerived01->setFeatureID(
                ::derived::DerivedPackage::DERIVED01__VALDERIVED01);
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_Derived01EClass->getEStructuralFeatures()).basicAdd(
                m_Derived01__valDerived01);
        m_Derived01__valDerived01->basicsetEContainingClass(m_Derived01EClass);
    }

    { // Derived02
        m_Derived02EClass = ::ecore::Ptr < ::ecore::EClass
                > (new ::ecore::EClass);
        m_Derived02EClass->setClassifierID(DERIVED02);
        m_Derived02EClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_Derived02EClass);
        // m_Derived02__valDerived02 has already been allocated above
        m_Derived02__valDerived02->setFeatureID(
                ::derived::DerivedPackage::DERIVED02__VALDERIVED02);
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_Derived02EClass->getEStructuralFeatures()).basicAdd(
                m_Derived02__valDerived02);
        m_Derived02__valDerived02->basicsetEContainingClass(m_Derived02EClass);
        // m_Derived02__base01ref has already been allocated above
        m_Derived02__base01ref->setFeatureID(
                ::derived::DerivedPackage::DERIVED02__BASE01REF);
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_Derived02EClass->getEStructuralFeatures()).basicAdd(
                m_Derived02__base01ref);
        m_Derived02__base01ref->basicsetEContainingClass(m_Derived02EClass);
    }

    // Create enums

    // Create data types

    // Initialize package
    setName("derived");
    setNsPrefix("derived");
    setNsURI("http:///com.example.derived.ecore");

    // TODO: bounds for type parameters

    // Add supertypes to classes
    m_Derived01EClass->getESuperTypes().push_back(
            dynamic_cast< ::base::base1::base2::Base2Package* >(::base::base1::base2::Base2Package::_instance().get())->getBase20());
    m_Derived02EClass->getESuperTypes().push_back(m_Derived01EClass);

    // TODO: Initialize classes and features; add operations and parameters
    // TODO: GenericTypes
    { // Derived01
        m_Derived01EClass->setName("Derived01");
        m_Derived01EClass->setAbstract(false);
        m_Derived01EClass->setInterface(false);
        m_Derived01__valDerived01->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEInt());
        m_Derived01__valDerived01->setName("valDerived01");
        m_Derived01__valDerived01->setDefaultValueLiteral("");
        m_Derived01__valDerived01->setLowerBound(0);
        m_Derived01__valDerived01->setUpperBound(1);
        m_Derived01__valDerived01->setTransient(false);
        m_Derived01__valDerived01->setVolatile(false);
        m_Derived01__valDerived01->setChangeable(true);
        m_Derived01__valDerived01->setUnsettable(false);
        m_Derived01__valDerived01->setID(false);
        m_Derived01__valDerived01->setUnique(true);
        m_Derived01__valDerived01->setDerived(false);
        m_Derived01__valDerived01->setOrdered(true);

    }

    { // Derived02
        m_Derived02EClass->setName("Derived02");
        m_Derived02EClass->setAbstract(false);
        m_Derived02EClass->setInterface(false);
        m_Derived02__valDerived02->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEInt());
        m_Derived02__valDerived02->setName("valDerived02");
        m_Derived02__valDerived02->setDefaultValueLiteral("");
        m_Derived02__valDerived02->setLowerBound(0);
        m_Derived02__valDerived02->setUpperBound(1);
        m_Derived02__valDerived02->setTransient(false);
        m_Derived02__valDerived02->setVolatile(false);
        m_Derived02__valDerived02->setChangeable(true);
        m_Derived02__valDerived02->setUnsettable(false);
        m_Derived02__valDerived02->setID(false);
        m_Derived02__valDerived02->setUnique(true);
        m_Derived02__valDerived02->setDerived(false);
        m_Derived02__valDerived02->setOrdered(true);

        m_Derived02__base01ref->setEType(
                dynamic_cast< ::base::BasePackage* >(::base::BasePackage::_instance().get())->getBase01());
        m_Derived02__base01ref->setName("base01ref");
        m_Derived02__base01ref->setDefaultValueLiteral("");
        m_Derived02__base01ref->setLowerBound(0);
        m_Derived02__base01ref->setUpperBound(1);
        m_Derived02__base01ref->setTransient(false);
        m_Derived02__base01ref->setVolatile(false);
        m_Derived02__base01ref->setChangeable(true);
        m_Derived02__base01ref->setContainment(false);
        m_Derived02__base01ref->setResolveProxies(true);
        m_Derived02__base01ref->setUnique(true);
        m_Derived02__base01ref->setDerived(false);
        m_Derived02__base01ref->setOrdered(true);
        m_Derived02__base01ref->setEOpposite(
                ::ecore::as < ::ecore::EReference
                        > (dynamic_cast< ::base::BasePackage* >(::base::BasePackage::_instance().get())->getBase01()->getEStructuralFeatures()[1]));

    }

    // TODO: Initialize data types

    /* EAnnotations for EPackage, the EClasses and their EStructuralFeatures */
    ::ecore::EAnnotation_ptr _annotation;

    _initialize();
}

::ecore::EClass_ptr DerivedPackage::getDerived01()
{
    return m_Derived01EClass;
}
::ecore::EClass_ptr DerivedPackage::getDerived02()
{
    return m_Derived02EClass;
}

::ecore::EAttribute_ptr DerivedPackage::getDerived01__valDerived01()
{
    return m_Derived01__valDerived01;
}
::ecore::EAttribute_ptr DerivedPackage::getDerived02__valDerived02()
{
    return m_Derived02__valDerived02;
}
::ecore::EReference_ptr DerivedPackage::getDerived02__base01ref()
{
    return m_Derived02__base01ref;
}

