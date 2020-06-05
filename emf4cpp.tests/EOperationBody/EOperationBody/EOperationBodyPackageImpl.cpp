// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * EOperationBody/EOperationBodyPackageImpl.cpp
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

#include <EOperationBody/EOperationBodyPackage.hpp>
#include <EOperationBody/EOperationBodyFactory.hpp>
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

using namespace ::EOperationBody;

EOperationBodyPackage::EOperationBodyPackage()
{

    // Feature definitions of Integer
    m_Integer__value = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

}

void EOperationBodyPackage::_initPackage()
{
    // Factory
    ::ecore::EFactory_ptr _fa = EOperationBodyFactory::_instance();
    basicsetEFactoryInstance(_fa);
    _fa->basicsetEPackage(_this());

// Create classes and their features
    auto &classifiers = (::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EClassifier_ptr, -1, true, true >&) getEClassifiers();

    { // Integer
        m_IntegerEClass = ::ecore::Ptr < ::ecore::EClass
                > (new ::ecore::EClass);
        m_IntegerEClass->setClassifierID(INTEGER);
        m_IntegerEClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_IntegerEClass);
        // m_Integer__value has already been allocated above
        m_Integer__value->setFeatureID(
                ::EOperationBody::EOperationBodyPackage::INTEGER__VALUE);
        m_Integer__value->setName("value");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_IntegerEClass->getEStructuralFeatures()).basicAdd(
                m_Integer__value);
        m_Integer__value->basicsetEContainingClass(m_IntegerEClass);
    }

    // Create enums

    // Create data types

    // Initialize package
    setName("EOperationBody");
    setNsPrefix("EOperationBody");
    setNsURI("http://www.example.org/EOperationBody");

    // TODO: bounds for type parameters

    // Add supertypes to classes

    // TODO: Initialize classes and features; add operations and parameters
    // TODO: GenericTypes
    { // Integer
        m_IntegerEClass->setName("Integer");
        m_IntegerEClass->setAbstract(false);
        m_IntegerEClass->setInterface(false);
        m_Integer__value->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEInt());
        m_Integer__value->setDefaultValueLiteral("");
        m_Integer__value->setLowerBound(0);
        m_Integer__value->setUpperBound(1);
        m_Integer__value->setTransient(false);
        m_Integer__value->setVolatile(false);
        m_Integer__value->setChangeable(true);
        m_Integer__value->setUnsettable(false);
        m_Integer__value->setID(false);
        m_Integer__value->setUnique(true);
        m_Integer__value->setDerived(false);
        m_Integer__value->setOrdered(true);

        { // increment()
            auto _op = ::ecore::Ptr < ::ecore::EOperation
                    > (new ::ecore::EOperation);
            _op->setEType(m_IntegerEClass);
            _op->setName("increment");
            _op->setLowerBound(0);
            _op->setUpperBound(1);
            _op->setUnique(true);
            _op->setOrdered(true);
            m_IntegerEClass->getEOperations().push_back(_op);
        }
        { // add()
            auto _op = ::ecore::Ptr < ::ecore::EOperation
                    > (new ::ecore::EOperation);
            _op->setEType(m_IntegerEClass);
            _op->setName("add");
            _op->setLowerBound(0);
            _op->setUpperBound(1);
            _op->setUnique(true);
            _op->setOrdered(true);
            { // lhs
                auto _pa = ::ecore::Ptr < ::ecore::EParameter
                        > (new ::ecore::EParameter);
                _pa->setEType(m_IntegerEClass);
                _pa->setName("lhs");
                _pa->setLowerBound(0);
                _pa->setUpperBound(1);
                _pa->setUnique(true);
                _pa->setOrdered(true);
                _op->getEParameters().push_back(_pa);
            }
            { // rhs
                auto _pa = ::ecore::Ptr < ::ecore::EParameter
                        > (new ::ecore::EParameter);
                _pa->setEType(m_IntegerEClass);
                _pa->setName("rhs");
                _pa->setLowerBound(0);
                _pa->setUpperBound(1);
                _pa->setUnique(true);
                _pa->setOrdered(true);
                _op->getEParameters().push_back(_pa);
            }
            m_IntegerEClass->getEOperations().push_back(_op);
        }
    }

    // TODO: Initialize data types

    /* EAnnotations for EPackage, the EClasses and their EStructuralFeatures */
    ::ecore::EAnnotation_ptr _annotation;

    _initialize();
}

::ecore::EClass_ptr EOperationBodyPackage::getInteger()
{
    return m_IntegerEClass;
}

::ecore::EAttribute_ptr EOperationBodyPackage::getInteger__value()
{
    return m_Integer__value;
}

