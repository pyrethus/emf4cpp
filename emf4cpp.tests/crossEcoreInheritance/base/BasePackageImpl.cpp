// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * base/BasePackageImpl.cpp
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

#include <base/BasePackage.hpp>
#include <base/BaseFactory.hpp>
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

using namespace ::base;

BasePackage::BasePackage()
{

    // Feature definitions of Base01
    m_Base01__valBase01 = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_Base01__derived02ref = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

    // Feature definitions of Base02
    m_Base02__valBase02 = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of Base03
    m_Base03__valBase03 = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

}

void BasePackage::_initPackage()
{
    // Factory
    ::ecore::EFactory_ptr _fa = BaseFactory::_instance();
    basicsetEFactoryInstance(_fa);
    _fa->basicsetEPackage(_this());

// Create classes and their features
    auto &classifiers = (::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EClassifier_ptr, -1, true, true >&) getEClassifiers();

    { // Base01
        m_Base01EClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
        m_Base01EClass->setClassifierID(BASE01);
        m_Base01EClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_Base01EClass);
        // m_Base01__valBase01 has already been allocated above
        m_Base01__valBase01->setFeatureID(
                ::base::BasePackage::BASE01__VALBASE01);
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_Base01EClass->getEStructuralFeatures()).basicAdd(
                m_Base01__valBase01);
        m_Base01__valBase01->basicsetEContainingClass(m_Base01EClass);
        // m_Base01__derived02ref has already been allocated above
        m_Base01__derived02ref->setFeatureID(
                ::base::BasePackage::BASE01__DERIVED02REF);
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_Base01EClass->getEStructuralFeatures()).basicAdd(
                m_Base01__derived02ref);
        m_Base01__derived02ref->basicsetEContainingClass(m_Base01EClass);
    }

    { // Base02
        m_Base02EClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
        m_Base02EClass->setClassifierID(BASE02);
        m_Base02EClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_Base02EClass);
        // m_Base02__valBase02 has already been allocated above
        m_Base02__valBase02->setFeatureID(
                ::base::BasePackage::BASE02__VALBASE02);
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_Base02EClass->getEStructuralFeatures()).basicAdd(
                m_Base02__valBase02);
        m_Base02__valBase02->basicsetEContainingClass(m_Base02EClass);
    }

    { // Base03
        m_Base03EClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
        m_Base03EClass->setClassifierID(BASE03);
        m_Base03EClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_Base03EClass);
        // m_Base03__valBase03 has already been allocated above
        m_Base03__valBase03->setFeatureID(
                ::base::BasePackage::BASE03__VALBASE03);
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_Base03EClass->getEStructuralFeatures()).basicAdd(
                m_Base03__valBase03);
        m_Base03__valBase03->basicsetEContainingClass(m_Base03EClass);
    }

    // Create enums

    // Create data types

    getESubpackages().push_back(
            ::base::base1::Base1Package::_getInstanceAndRemoveOwnership());

    // Initialize package
    setName("base");
    setNsPrefix("base");
    setNsURI("http:///com.example.base.ecore/base");

    // TODO: bounds for type parameters

    // Add supertypes to classes

    // TODO: Initialize classes and features; add operations and parameters
    // TODO: GenericTypes
    { // Base01
        m_Base01EClass->setName("Base01");
        m_Base01EClass->setAbstract(false);
        m_Base01EClass->setInterface(false);
        m_Base01__valBase01->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEInt());
        m_Base01__valBase01->setName("valBase01");
        m_Base01__valBase01->setDefaultValueLiteral("");
        m_Base01__valBase01->setLowerBound(0);
        m_Base01__valBase01->setUpperBound(1);
        m_Base01__valBase01->setTransient(false);
        m_Base01__valBase01->setVolatile(false);
        m_Base01__valBase01->setChangeable(true);
        m_Base01__valBase01->setUnsettable(false);
        m_Base01__valBase01->setID(false);
        m_Base01__valBase01->setUnique(true);
        m_Base01__valBase01->setDerived(false);
        m_Base01__valBase01->setOrdered(true);

        m_Base01__derived02ref->setEType(
                dynamic_cast< ::derived::DerivedPackage* >(::derived::DerivedPackage::_instance().get())->getDerived02());
        m_Base01__derived02ref->setName("derived02ref");
        m_Base01__derived02ref->setDefaultValueLiteral("");
        m_Base01__derived02ref->setLowerBound(0);
        m_Base01__derived02ref->setUpperBound(1);
        m_Base01__derived02ref->setTransient(false);
        m_Base01__derived02ref->setVolatile(false);
        m_Base01__derived02ref->setChangeable(true);
        m_Base01__derived02ref->setContainment(false);
        m_Base01__derived02ref->setResolveProxies(true);
        m_Base01__derived02ref->setUnique(true);
        m_Base01__derived02ref->setDerived(false);
        m_Base01__derived02ref->setOrdered(true);
        m_Base01__derived02ref->setEOpposite(
                ::ecore::as < ::ecore::EReference
                        > (dynamic_cast< ::derived::DerivedPackage* >(::derived::DerivedPackage::_instance().get())->getDerived02()->getEStructuralFeatures()[1]));

    }

    { // Base02
        m_Base02EClass->setName("Base02");
        m_Base02EClass->setAbstract(false);
        m_Base02EClass->setInterface(false);
        m_Base02__valBase02->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEInt());
        m_Base02__valBase02->setName("valBase02");
        m_Base02__valBase02->setDefaultValueLiteral("");
        m_Base02__valBase02->setLowerBound(0);
        m_Base02__valBase02->setUpperBound(1);
        m_Base02__valBase02->setTransient(false);
        m_Base02__valBase02->setVolatile(false);
        m_Base02__valBase02->setChangeable(true);
        m_Base02__valBase02->setUnsettable(false);
        m_Base02__valBase02->setID(false);
        m_Base02__valBase02->setUnique(true);
        m_Base02__valBase02->setDerived(false);
        m_Base02__valBase02->setOrdered(true);

    }

    { // Base03
        m_Base03EClass->setName("Base03");
        m_Base03EClass->setAbstract(false);
        m_Base03EClass->setInterface(false);
        m_Base03__valBase03->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEInt());
        m_Base03__valBase03->setName("valBase03");
        m_Base03__valBase03->setDefaultValueLiteral("");
        m_Base03__valBase03->setLowerBound(0);
        m_Base03__valBase03->setUpperBound(1);
        m_Base03__valBase03->setTransient(false);
        m_Base03__valBase03->setVolatile(false);
        m_Base03__valBase03->setChangeable(true);
        m_Base03__valBase03->setUnsettable(false);
        m_Base03__valBase03->setID(false);
        m_Base03__valBase03->setUnique(true);
        m_Base03__valBase03->setDerived(false);
        m_Base03__valBase03->setOrdered(true);

    }

    // TODO: Initialize data types

    /* EAnnotations for EPackage, the EClasses and their EStructuralFeatures */
    ::ecore::EAnnotation_ptr _annotation;

    _initialize();
}

::ecore::EClass_ptr BasePackage::getBase01()
{
    return m_Base01EClass;
}
::ecore::EClass_ptr BasePackage::getBase02()
{
    return m_Base02EClass;
}
::ecore::EClass_ptr BasePackage::getBase03()
{
    return m_Base03EClass;
}

::ecore::EAttribute_ptr BasePackage::getBase01__valBase01()
{
    return m_Base01__valBase01;
}
::ecore::EReference_ptr BasePackage::getBase01__derived02ref()
{
    return m_Base01__derived02ref;
}
::ecore::EAttribute_ptr BasePackage::getBase02__valBase02()
{
    return m_Base02__valBase02;
}
::ecore::EAttribute_ptr BasePackage::getBase03__valBase03()
{
    return m_Base03__valBase03;
}

