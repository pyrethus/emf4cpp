// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * TopLevelPackage/TopLevelPackagePackageImpl.cpp
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

#include <TopLevelPackage/TopLevelPackagePackage.hpp>
#include <TopLevelPackage/TopLevelPackageFactory.hpp>
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
#include <ecore/EObject.hpp>

using namespace ::TopLevelPackage;

TopLevelPackagePackage::TopLevelPackagePackage()
{

    // Feature definitions of TopLevelClass
    m_TopLevelClass__reference = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

}

void TopLevelPackagePackage::_initPackage()
{
    // Factory
    ::ecore::EFactory_ptr _fa = TopLevelPackageFactory::_instance();
    basicsetEFactoryInstance(_fa);
    _fa->basicsetEPackage(_this());

// Create classes and their features
    auto &classifiers = (::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EClassifier_ptr, -1, true, true >&) getEClassifiers();

    { // TopLevelClass
        m_TopLevelClassEClass = ::ecore::Ptr < ::ecore::EClass
                > (new ::ecore::EClass);
        m_TopLevelClassEClass->setClassifierID(TOPLEVELCLASS);
        m_TopLevelClassEClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_TopLevelClassEClass);
        // m_TopLevelClass__reference has already been allocated above
        m_TopLevelClass__reference->setFeatureID(
                ::TopLevelPackage::TopLevelPackagePackage::TOPLEVELCLASS__REFERENCE);
        m_TopLevelClass__reference->setName("reference");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_TopLevelClassEClass->getEStructuralFeatures()).basicAdd(
                m_TopLevelClass__reference);
        m_TopLevelClass__reference->basicsetEContainingClass(
                m_TopLevelClassEClass);
    }

    // Create enums

    // Create data types

    getESubpackages().push_back(
            ::TopLevelPackage::Level1::Level1Package::_getInstanceAndRemoveOwnership());

    // Initialize package
    setName("TopLevelPackage");
    setNsPrefix("TopLevelPackage");
    setNsURI("http:///com.example.subpackage/TopLevelPackage");

    // TODO: bounds for type parameters

    // Add supertypes to classes

    // TODO: Initialize classes and features; add operations and parameters
    // TODO: GenericTypes
    { // TopLevelClass
        m_TopLevelClassEClass->setName("TopLevelClass");
        m_TopLevelClassEClass->setAbstract(false);
        m_TopLevelClassEClass->setInterface(false);

        m_TopLevelClass__reference->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEObject());
        m_TopLevelClass__reference->setDefaultValueLiteral("");
        m_TopLevelClass__reference->setLowerBound(0);
        m_TopLevelClass__reference->setUpperBound(1);
        m_TopLevelClass__reference->setTransient(false);
        m_TopLevelClass__reference->setVolatile(false);
        m_TopLevelClass__reference->setChangeable(true);
        m_TopLevelClass__reference->setContainment(false);
        m_TopLevelClass__reference->setResolveProxies(true);
        m_TopLevelClass__reference->setUnique(true);
        m_TopLevelClass__reference->setDerived(false);
        m_TopLevelClass__reference->setOrdered(true);

    }

    // TODO: Initialize data types

    /* EAnnotations for EPackage, the EClasses and their EStructuralFeatures */
    ::ecore::EAnnotation_ptr _annotation;

    _initialize();
}

::ecore::EClass_ptr TopLevelPackagePackage::getTopLevelClass()
{
    return m_TopLevelClassEClass;
}

::ecore::EReference_ptr TopLevelPackagePackage::getTopLevelClass__reference()
{
    return m_TopLevelClass__reference;
}

