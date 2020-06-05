// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * v_3_0/edate/EdatePackageImpl.cpp
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

#include <v_3_0/edate/EdatePackage.hpp>
#include <v_3_0/edate/EdateFactory.hpp>
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

using namespace ::v_3_0::edate;

EdatePackage::EdatePackage()
{

    // Feature definitions of Person
    m_Person__Birthday = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_Person__Name = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of Apollo11
    m_Apollo11__FirstManOnMoonDate = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_Apollo11__Member = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

}

void EdatePackage::_initPackage()
{
    // Factory
    ::ecore::EFactory_ptr _fa = EdateFactory::_instance();
    basicsetEFactoryInstance(_fa);
    _fa->basicsetEPackage(_this());

// Create classes and their features
    auto &classifiers = (::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EClassifier_ptr, -1, true, true >&) getEClassifiers();

    { // Person
        m_PersonEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
        m_PersonEClass->setClassifierID(PERSON);
        m_PersonEClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_PersonEClass);
        // m_Person__Birthday has already been allocated above
        m_Person__Birthday->setFeatureID(
                ::v_3_0::edate::EdatePackage::PERSON__BIRTHDAY);
        m_Person__Birthday->setName("Birthday");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_PersonEClass->getEStructuralFeatures()).basicAdd(
                m_Person__Birthday);
        m_Person__Birthday->basicsetEContainingClass(m_PersonEClass);
        // m_Person__Name has already been allocated above
        m_Person__Name->setFeatureID(
                ::v_3_0::edate::EdatePackage::PERSON__NAME);
        m_Person__Name->setName("Name");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_PersonEClass->getEStructuralFeatures()).basicAdd(
                m_Person__Name);
        m_Person__Name->basicsetEContainingClass(m_PersonEClass);
    }

    { // Apollo11
        m_Apollo11EClass = ::ecore::Ptr < ::ecore::EClass
                > (new ::ecore::EClass);
        m_Apollo11EClass->setClassifierID(APOLLO11);
        m_Apollo11EClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_Apollo11EClass);
        // m_Apollo11__FirstManOnMoonDate has already been allocated above
        m_Apollo11__FirstManOnMoonDate->setFeatureID(
                ::v_3_0::edate::EdatePackage::APOLLO11__FIRSTMANONMOONDATE);
        m_Apollo11__FirstManOnMoonDate->setName("FirstManOnMoonDate");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_Apollo11EClass->getEStructuralFeatures()).basicAdd(
                m_Apollo11__FirstManOnMoonDate);
        m_Apollo11__FirstManOnMoonDate->basicsetEContainingClass(
                m_Apollo11EClass);
        // m_Apollo11__Member has already been allocated above
        m_Apollo11__Member->setFeatureID(
                ::v_3_0::edate::EdatePackage::APOLLO11__MEMBER);
        m_Apollo11__Member->setName("Member");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_Apollo11EClass->getEStructuralFeatures()).basicAdd(
                m_Apollo11__Member);
        m_Apollo11__Member->basicsetEContainingClass(m_Apollo11EClass);
    }

    // Create enums

    // Create data types

    // Initialize package
    setName("edate");
    setNsPrefix("edate");
    setNsURI("http://www.example.org/edate/3.0");

    // TODO: bounds for type parameters

    // Add supertypes to classes

    // TODO: Initialize classes and features; add operations and parameters
    // TODO: GenericTypes
    { // Person
        m_PersonEClass->setName("Person");
        m_PersonEClass->setAbstract(false);
        m_PersonEClass->setInterface(false);
        m_Person__Birthday->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEDate());
        m_Person__Birthday->setDefaultValueLiteral("");
        m_Person__Birthday->setLowerBound(0);
        m_Person__Birthday->setUpperBound(1);
        m_Person__Birthday->setTransient(false);
        m_Person__Birthday->setVolatile(false);
        m_Person__Birthday->setChangeable(true);
        m_Person__Birthday->setUnsettable(false);
        m_Person__Birthday->setID(false);
        m_Person__Birthday->setUnique(true);
        m_Person__Birthday->setDerived(false);
        m_Person__Birthday->setOrdered(true);
        m_Person__Name->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
        m_Person__Name->setDefaultValueLiteral("");
        m_Person__Name->setLowerBound(0);
        m_Person__Name->setUpperBound(1);
        m_Person__Name->setTransient(false);
        m_Person__Name->setVolatile(false);
        m_Person__Name->setChangeable(true);
        m_Person__Name->setUnsettable(false);
        m_Person__Name->setID(false);
        m_Person__Name->setUnique(true);
        m_Person__Name->setDerived(false);
        m_Person__Name->setOrdered(true);

    }

    { // Apollo11
        m_Apollo11EClass->setName("Apollo11");
        m_Apollo11EClass->setAbstract(false);
        m_Apollo11EClass->setInterface(false);
        m_Apollo11__FirstManOnMoonDate->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEDate());
        m_Apollo11__FirstManOnMoonDate->setDefaultValueLiteral(
                "1969-07-20T20:18:00.000+0000");
        m_Apollo11__FirstManOnMoonDate->setLowerBound(0);
        m_Apollo11__FirstManOnMoonDate->setUpperBound(1);
        m_Apollo11__FirstManOnMoonDate->setTransient(false);
        m_Apollo11__FirstManOnMoonDate->setVolatile(false);
        m_Apollo11__FirstManOnMoonDate->setChangeable(true);
        m_Apollo11__FirstManOnMoonDate->setUnsettable(false);
        m_Apollo11__FirstManOnMoonDate->setID(false);
        m_Apollo11__FirstManOnMoonDate->setUnique(true);
        m_Apollo11__FirstManOnMoonDate->setDerived(false);
        m_Apollo11__FirstManOnMoonDate->setOrdered(true);

        m_Apollo11__Member->setEType(m_PersonEClass);
        m_Apollo11__Member->setDefaultValueLiteral("");
        m_Apollo11__Member->setLowerBound(0);
        m_Apollo11__Member->setUpperBound(1);
        m_Apollo11__Member->setTransient(false);
        m_Apollo11__Member->setVolatile(false);
        m_Apollo11__Member->setChangeable(true);
        m_Apollo11__Member->setContainment(true);
        m_Apollo11__Member->setResolveProxies(true);
        m_Apollo11__Member->setUnique(true);
        m_Apollo11__Member->setDerived(false);
        m_Apollo11__Member->setOrdered(true);

    }

    // TODO: Initialize data types

    /* EAnnotations for EPackage, the EClasses and their EStructuralFeatures */
    ::ecore::EAnnotation_ptr _annotation;

    _initialize();
}

::ecore::EClass_ptr EdatePackage::getPerson()
{
    return m_PersonEClass;
}
::ecore::EClass_ptr EdatePackage::getApollo11()
{
    return m_Apollo11EClass;
}

::ecore::EAttribute_ptr EdatePackage::getPerson__Birthday()
{
    return m_Person__Birthday;
}
::ecore::EAttribute_ptr EdatePackage::getPerson__Name()
{
    return m_Person__Name;
}
::ecore::EAttribute_ptr EdatePackage::getApollo11__FirstManOnMoonDate()
{
    return m_Apollo11__FirstManOnMoonDate;
}
::ecore::EReference_ptr EdatePackage::getApollo11__Member()
{
    return m_Apollo11__Member;
}

