// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * base/base1/base2/Base2PackageImpl.cpp
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

#include <base/base1/base2/Base2Package.hpp>
#include <base/base1/base2/Base2Factory.hpp>
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

using namespace ::base::base1::base2;

Base2Package::Base2Package()
{

    // Feature definitions of Base20
    m_Base20__valBase20 = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

}

void Base2Package::_initPackage()
{
    // Factory
    ::ecore::EFactory_ptr _fa = Base2Factory::_instance();
    basicsetEFactoryInstance(_fa);
    _fa->basicsetEPackage(_this());

// Create classes and their features
    auto &classifiers = (::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EClassifier_ptr, -1, true, true >&) getEClassifiers();

    // Base20
    m_Base20EClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_Base20EClass->setClassifierID(BASE20);
    m_Base20EClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_Base20EClass);
    // m_Base20__valBase20 has already been allocated above
    m_Base20__valBase20->setFeatureID(
            ::base::base1::base2::Base2Package::BASE20__VALBASE20);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_Base20EClass->getEStructuralFeatures()).basicAdd(
            m_Base20__valBase20);
    m_Base20__valBase20->basicsetEContainingClass(m_Base20EClass);

    // Create enums

    // Create data types

    // Initialize package
    setName("base2");
    setNsPrefix("base2");
    setNsURI("http:///com.example.base.ecore/base/base1/base2");

    // TODO: bounds for type parameters

    // Add supertypes to classes
    m_Base20EClass->getESuperTypes().push_back(
            dynamic_cast< ::base::base1::Base1Package* >(::base::base1::Base1Package::_instance().get())->getBase10());
    m_Base20EClass->getESuperTypes().push_back(
            dynamic_cast< ::base::base1::Base1Package* >(::base::base1::Base1Package::_instance().get())->getBase11());

    // TODO: Initialize classes and features; add operations and parameters
    // TODO: GenericTypes
    // Base20
    m_Base20EClass->setName("Base20");
    m_Base20EClass->setAbstract(false);
    m_Base20EClass->setInterface(false);
    m_Base20__valBase20->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEInt());
    m_Base20__valBase20->setName("valBase20");
    m_Base20__valBase20->setDefaultValueLiteral("");
    m_Base20__valBase20->setLowerBound(0);
    m_Base20__valBase20->setUpperBound(1);
    m_Base20__valBase20->setTransient(false);
    m_Base20__valBase20->setVolatile(false);
    m_Base20__valBase20->setChangeable(true);
    m_Base20__valBase20->setUnsettable(false);
    m_Base20__valBase20->setID(false);
    m_Base20__valBase20->setUnique(true);
    m_Base20__valBase20->setDerived(false);
    m_Base20__valBase20->setOrdered(true);

    // TODO: Initialize data types

    /* EAnnotations for EPackage, the EClasses and their EStructuralFeatures */
    ::ecore::EAnnotation_ptr _annotation;

    _initialize();
}

::ecore::EClass_ptr Base2Package::getBase20()
{
    return m_Base20EClass;
}

::ecore::EAttribute_ptr Base2Package::getBase20__valBase20()
{
    return m_Base20__valBase20;
}

