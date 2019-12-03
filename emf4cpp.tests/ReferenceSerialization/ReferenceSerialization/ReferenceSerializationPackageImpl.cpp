// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * ReferenceSerialization/ReferenceSerializationPackageImpl.cpp
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

#include <ReferenceSerialization/ReferenceSerializationPackage.hpp>
#include <ReferenceSerialization/ReferenceSerializationFactory.hpp>
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

using namespace ::ReferenceSerialization;

ReferenceSerializationPackage::ReferenceSerializationPackage()
{

    // Feature definitions of Container
    m_Container__contents = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);
    m_Container__references = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);
    m_Container__child = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);
    m_Container__childRef = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

    // Feature definitions of Content
    m_Content__name = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of Child

}

void ReferenceSerializationPackage::_initPackage()
{
    // Factory
    ::ecore::EFactory_ptr _fa = ReferenceSerializationFactory::_instance();
    basicsetEFactoryInstance(_fa);
    _fa->basicsetEPackage(_this());

// Create classes and their features
    auto &classifiers = (::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EClassifier_ptr, -1, true, true >&) getEClassifiers();

    // Container
    m_ContainerEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_ContainerEClass->setClassifierID(CONTAINER);
    m_ContainerEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_ContainerEClass);
    // m_Container__contents has already been allocated above
    m_Container__contents->setFeatureID(
            ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CONTENTS);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ContainerEClass->getEStructuralFeatures()).basicAdd(
            m_Container__contents);
    m_Container__contents->basicsetEContainingClass(m_ContainerEClass);
    // m_Container__references has already been allocated above
    m_Container__references->setFeatureID(
            ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__REFERENCES);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ContainerEClass->getEStructuralFeatures()).basicAdd(
            m_Container__references);
    m_Container__references->basicsetEContainingClass(m_ContainerEClass);
    // m_Container__child has already been allocated above
    m_Container__child->setFeatureID(
            ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CHILD);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ContainerEClass->getEStructuralFeatures()).basicAdd(
            m_Container__child);
    m_Container__child->basicsetEContainingClass(m_ContainerEClass);
    // m_Container__childRef has already been allocated above
    m_Container__childRef->setFeatureID(
            ::ReferenceSerialization::ReferenceSerializationPackage::CONTAINER__CHILDREF);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ContainerEClass->getEStructuralFeatures()).basicAdd(
            m_Container__childRef);
    m_Container__childRef->basicsetEContainingClass(m_ContainerEClass);

    // Content
    m_ContentEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_ContentEClass->setClassifierID(CONTENT);
    m_ContentEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_ContentEClass);
    // m_Content__name has already been allocated above
    m_Content__name->setFeatureID(
            ::ReferenceSerialization::ReferenceSerializationPackage::CONTENT__NAME);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ContentEClass->getEStructuralFeatures()).basicAdd(
            m_Content__name);
    m_Content__name->basicsetEContainingClass(m_ContentEClass);

    // Child
    m_ChildEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_ChildEClass->setClassifierID(CHILD);
    m_ChildEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_ChildEClass);

    // Create enums

    // Create data types

    // Initialize package
    setName("ReferenceSerialization");
    setNsPrefix("ReferenceSerialization");
    setNsURI("http://www.example.org/ReferenceSerialization");

    // TODO: bounds for type parameters

    // Add supertypes to classes

    // TODO: Initialize classes and features; add operations and parameters
    // TODO: GenericTypes
    // Container
    m_ContainerEClass->setName("Container");
    m_ContainerEClass->setAbstract(false);
    m_ContainerEClass->setInterface(false);
    m_Container__contents->setEType(m_ContentEClass);
    m_Container__contents->setName("contents");
    m_Container__contents->setDefaultValueLiteral("");
    m_Container__contents->setLowerBound(0);
    m_Container__contents->setUpperBound(-1);
    m_Container__contents->setTransient(false);
    m_Container__contents->setVolatile(false);
    m_Container__contents->setChangeable(true);
    m_Container__contents->setContainment(true);
    m_Container__contents->setResolveProxies(true);
    m_Container__contents->setUnique(true);
    m_Container__contents->setDerived(false);
    m_Container__contents->setOrdered(true);
    m_Container__references->setEType(m_ContentEClass);
    m_Container__references->setName("references");
    m_Container__references->setDefaultValueLiteral("");
    m_Container__references->setLowerBound(0);
    m_Container__references->setUpperBound(-1);
    m_Container__references->setTransient(false);
    m_Container__references->setVolatile(false);
    m_Container__references->setChangeable(true);
    m_Container__references->setContainment(false);
    m_Container__references->setResolveProxies(true);
    m_Container__references->setUnique(true);
    m_Container__references->setDerived(false);
    m_Container__references->setOrdered(true);
    m_Container__child->setEType(m_ChildEClass);
    m_Container__child->setName("child");
    m_Container__child->setDefaultValueLiteral("");
    m_Container__child->setLowerBound(0);
    m_Container__child->setUpperBound(1);
    m_Container__child->setTransient(false);
    m_Container__child->setVolatile(false);
    m_Container__child->setChangeable(true);
    m_Container__child->setContainment(true);
    m_Container__child->setResolveProxies(true);
    m_Container__child->setUnique(true);
    m_Container__child->setDerived(false);
    m_Container__child->setOrdered(true);
    m_Container__childRef->setEType(m_ChildEClass);
    m_Container__childRef->setName("childRef");
    m_Container__childRef->setDefaultValueLiteral("");
    m_Container__childRef->setLowerBound(0);
    m_Container__childRef->setUpperBound(1);
    m_Container__childRef->setTransient(false);
    m_Container__childRef->setVolatile(false);
    m_Container__childRef->setChangeable(true);
    m_Container__childRef->setContainment(false);
    m_Container__childRef->setResolveProxies(true);
    m_Container__childRef->setUnique(true);
    m_Container__childRef->setDerived(false);
    m_Container__childRef->setOrdered(true);
    // Content
    m_ContentEClass->setName("Content");
    m_ContentEClass->setAbstract(false);
    m_ContentEClass->setInterface(false);
    m_Content__name->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_Content__name->setName("name");
    m_Content__name->setDefaultValueLiteral("");
    m_Content__name->setLowerBound(0);
    m_Content__name->setUpperBound(1);
    m_Content__name->setTransient(false);
    m_Content__name->setVolatile(false);
    m_Content__name->setChangeable(true);
    m_Content__name->setUnsettable(false);
    m_Content__name->setID(false);
    m_Content__name->setUnique(true);
    m_Content__name->setDerived(false);
    m_Content__name->setOrdered(true);
    // Child
    m_ChildEClass->setName("Child");
    m_ChildEClass->setAbstract(false);
    m_ChildEClass->setInterface(false);

    // TODO: Initialize data types

    /* EAnnotations for EPackage, the EClasses and their EStructuralFeatures */
    ::ecore::EAnnotation_ptr _annotation;

    _initialize();
}

::ecore::EClass_ptr ReferenceSerializationPackage::getContainer()
{
    return m_ContainerEClass;
}
::ecore::EClass_ptr ReferenceSerializationPackage::getContent()
{
    return m_ContentEClass;
}
::ecore::EClass_ptr ReferenceSerializationPackage::getChild()
{
    return m_ChildEClass;
}

::ecore::EReference_ptr ReferenceSerializationPackage::getContainer__contents()
{
    return m_Container__contents;
}
::ecore::EReference_ptr ReferenceSerializationPackage::getContainer__references()
{
    return m_Container__references;
}
::ecore::EReference_ptr ReferenceSerializationPackage::getContainer__child()
{
    return m_Container__child;
}
::ecore::EReference_ptr ReferenceSerializationPackage::getContainer__childRef()
{
    return m_Container__childRef;
}
::ecore::EAttribute_ptr ReferenceSerializationPackage::getContent__name()
{
    return m_Content__name;
}

