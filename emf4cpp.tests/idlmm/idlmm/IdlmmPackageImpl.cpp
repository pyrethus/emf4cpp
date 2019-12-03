// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * idlmm/IdlmmPackageImpl.cpp
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

#include <idlmm/IdlmmPackage.hpp>
#include <idlmm/IdlmmFactory.hpp>
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

using namespace ::idlmm;

IdlmmPackage::IdlmmPackage()
{

    // Feature definitions of Container
    m_Container__contains = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

    // Feature definitions of Contained
    m_Contained__identifier = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_Contained__repositoryId = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_Contained__version = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_Contained__absoluteName = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_Contained__definedIn = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

    // Feature definitions of InterfaceDef
    m_InterfaceDef__isAbstract = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_InterfaceDef__isCustom = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_InterfaceDef__isTruncatable = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_InterfaceDef__derivesFrom = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

    // Feature definitions of ModuleDef
    m_ModuleDef__prefix = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of IDLType
    m_IDLType__typeCode = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of OperationDef
    m_OperationDef__isOneway = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_OperationDef__contexts = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_OperationDef__parameters = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);
    m_OperationDef__canRaise = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

    // Feature definitions of AttributeDef
    m_AttributeDef__isReadonly = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_AttributeDef__getRaises = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);
    m_AttributeDef__setRaises = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

    // Feature definitions of ConstantDef
    m_ConstantDef__constValue = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of Typed
    m_Typed__containedType = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);
    m_Typed__sharedType = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

    // Feature definitions of ParameterDef
    m_ParameterDef__identifier = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_ParameterDef__direction = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of PrimitiveDef
    m_PrimitiveDef__kind = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of ExceptionDef
    m_ExceptionDef__typeCode = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_ExceptionDef__members = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

    // Feature definitions of Field
    m_Field__identifier = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of FixedDef
    m_FixedDef__digits = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_FixedDef__scale = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of WstringDef
    m_WstringDef__bound = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of StringDef
    m_StringDef__bound = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of AliasDef

    // Feature definitions of ArrayDef
    m_ArrayDef__bound = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of SequenceDef
    m_SequenceDef__bound = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of UnionField
    m_UnionField__identifier = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_UnionField__label = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of TypedefDef

    // Feature definitions of UnionDef
    m_UnionDef__unionMembers = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);
    m_UnionDef__containedDiscrim = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);
    m_UnionDef__sharedDiscrim = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

    // Feature definitions of EnumDef
    m_EnumDef__members = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of StructDef
    m_StructDef__members = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

    // Feature definitions of TranslationUnit
    m_TranslationUnit__identifier = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_TranslationUnit__contains = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);
    m_TranslationUnit__includes = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

    // Feature definitions of Include
    m_Include__importURI = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

}

void IdlmmPackage::_initPackage()
{
    // Factory
    ::ecore::EFactory_ptr _fa = IdlmmFactory::_instance();
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
    // m_Container__contains has already been allocated above
    m_Container__contains->setFeatureID(
            ::idlmm::IdlmmPackage::CONTAINER__CONTAINS);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ContainerEClass->getEStructuralFeatures()).basicAdd(
            m_Container__contains);
    m_Container__contains->basicsetEContainingClass(m_ContainerEClass);

    // Contained
    m_ContainedEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_ContainedEClass->setClassifierID(CONTAINED);
    m_ContainedEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_ContainedEClass);
    // m_Contained__identifier has already been allocated above
    m_Contained__identifier->setFeatureID(
            ::idlmm::IdlmmPackage::CONTAINED__IDENTIFIER);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ContainedEClass->getEStructuralFeatures()).basicAdd(
            m_Contained__identifier);
    m_Contained__identifier->basicsetEContainingClass(m_ContainedEClass);
    // m_Contained__repositoryId has already been allocated above
    m_Contained__repositoryId->setFeatureID(
            ::idlmm::IdlmmPackage::CONTAINED__REPOSITORYID);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ContainedEClass->getEStructuralFeatures()).basicAdd(
            m_Contained__repositoryId);
    m_Contained__repositoryId->basicsetEContainingClass(m_ContainedEClass);
    // m_Contained__version has already been allocated above
    m_Contained__version->setFeatureID(
            ::idlmm::IdlmmPackage::CONTAINED__VERSION);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ContainedEClass->getEStructuralFeatures()).basicAdd(
            m_Contained__version);
    m_Contained__version->basicsetEContainingClass(m_ContainedEClass);
    // m_Contained__absoluteName has already been allocated above
    m_Contained__absoluteName->setFeatureID(
            ::idlmm::IdlmmPackage::CONTAINED__ABSOLUTENAME);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ContainedEClass->getEStructuralFeatures()).basicAdd(
            m_Contained__absoluteName);
    m_Contained__absoluteName->basicsetEContainingClass(m_ContainedEClass);
    // m_Contained__definedIn has already been allocated above
    m_Contained__definedIn->setFeatureID(
            ::idlmm::IdlmmPackage::CONTAINED__DEFINEDIN);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ContainedEClass->getEStructuralFeatures()).basicAdd(
            m_Contained__definedIn);
    m_Contained__definedIn->basicsetEContainingClass(m_ContainedEClass);

    // InterfaceDef
    m_InterfaceDefEClass = ::ecore::Ptr < ::ecore::EClass
            > (new ::ecore::EClass);
    m_InterfaceDefEClass->setClassifierID(INTERFACEDEF);
    m_InterfaceDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_InterfaceDefEClass);
    // m_InterfaceDef__isAbstract has already been allocated above
    m_InterfaceDef__isAbstract->setFeatureID(
            ::idlmm::IdlmmPackage::INTERFACEDEF__ISABSTRACT);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_InterfaceDefEClass->getEStructuralFeatures()).basicAdd(
            m_InterfaceDef__isAbstract);
    m_InterfaceDef__isAbstract->basicsetEContainingClass(m_InterfaceDefEClass);
    // m_InterfaceDef__isCustom has already been allocated above
    m_InterfaceDef__isCustom->setFeatureID(
            ::idlmm::IdlmmPackage::INTERFACEDEF__ISCUSTOM);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_InterfaceDefEClass->getEStructuralFeatures()).basicAdd(
            m_InterfaceDef__isCustom);
    m_InterfaceDef__isCustom->basicsetEContainingClass(m_InterfaceDefEClass);
    // m_InterfaceDef__isTruncatable has already been allocated above
    m_InterfaceDef__isTruncatable->setFeatureID(
            ::idlmm::IdlmmPackage::INTERFACEDEF__ISTRUNCATABLE);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_InterfaceDefEClass->getEStructuralFeatures()).basicAdd(
            m_InterfaceDef__isTruncatable);
    m_InterfaceDef__isTruncatable->basicsetEContainingClass(
            m_InterfaceDefEClass);
    // m_InterfaceDef__derivesFrom has already been allocated above
    m_InterfaceDef__derivesFrom->setFeatureID(
            ::idlmm::IdlmmPackage::INTERFACEDEF__DERIVESFROM);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_InterfaceDefEClass->getEStructuralFeatures()).basicAdd(
            m_InterfaceDef__derivesFrom);
    m_InterfaceDef__derivesFrom->basicsetEContainingClass(m_InterfaceDefEClass);

    // ModuleDef
    m_ModuleDefEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_ModuleDefEClass->setClassifierID(MODULEDEF);
    m_ModuleDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_ModuleDefEClass);
    // m_ModuleDef__prefix has already been allocated above
    m_ModuleDef__prefix->setFeatureID(::idlmm::IdlmmPackage::MODULEDEF__PREFIX);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ModuleDefEClass->getEStructuralFeatures()).basicAdd(
            m_ModuleDef__prefix);
    m_ModuleDef__prefix->basicsetEContainingClass(m_ModuleDefEClass);

    // IDLType
    m_IDLTypeEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_IDLTypeEClass->setClassifierID(IDLTYPE);
    m_IDLTypeEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_IDLTypeEClass);
    // m_IDLType__typeCode has already been allocated above
    m_IDLType__typeCode->setFeatureID(::idlmm::IdlmmPackage::IDLTYPE__TYPECODE);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_IDLTypeEClass->getEStructuralFeatures()).basicAdd(
            m_IDLType__typeCode);
    m_IDLType__typeCode->basicsetEContainingClass(m_IDLTypeEClass);

    // OperationDef
    m_OperationDefEClass = ::ecore::Ptr < ::ecore::EClass
            > (new ::ecore::EClass);
    m_OperationDefEClass->setClassifierID(OPERATIONDEF);
    m_OperationDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_OperationDefEClass);
    // m_OperationDef__parameters has already been allocated above
    m_OperationDef__parameters->setFeatureID(
            ::idlmm::IdlmmPackage::OPERATIONDEF__PARAMETERS);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_OperationDefEClass->getEStructuralFeatures()).basicAdd(
            m_OperationDef__parameters);
    m_OperationDef__parameters->basicsetEContainingClass(m_OperationDefEClass);
    // m_OperationDef__isOneway has already been allocated above
    m_OperationDef__isOneway->setFeatureID(
            ::idlmm::IdlmmPackage::OPERATIONDEF__ISONEWAY);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_OperationDefEClass->getEStructuralFeatures()).basicAdd(
            m_OperationDef__isOneway);
    m_OperationDef__isOneway->basicsetEContainingClass(m_OperationDefEClass);
    // m_OperationDef__contexts has already been allocated above
    m_OperationDef__contexts->setFeatureID(
            ::idlmm::IdlmmPackage::OPERATIONDEF__CONTEXTS);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_OperationDefEClass->getEStructuralFeatures()).basicAdd(
            m_OperationDef__contexts);
    m_OperationDef__contexts->basicsetEContainingClass(m_OperationDefEClass);
    // m_OperationDef__canRaise has already been allocated above
    m_OperationDef__canRaise->setFeatureID(
            ::idlmm::IdlmmPackage::OPERATIONDEF__CANRAISE);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_OperationDefEClass->getEStructuralFeatures()).basicAdd(
            m_OperationDef__canRaise);
    m_OperationDef__canRaise->basicsetEContainingClass(m_OperationDefEClass);

    // AttributeDef
    m_AttributeDefEClass = ::ecore::Ptr < ::ecore::EClass
            > (new ::ecore::EClass);
    m_AttributeDefEClass->setClassifierID(ATTRIBUTEDEF);
    m_AttributeDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_AttributeDefEClass);
    // m_AttributeDef__getRaises has already been allocated above
    m_AttributeDef__getRaises->setFeatureID(
            ::idlmm::IdlmmPackage::ATTRIBUTEDEF__GETRAISES);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_AttributeDefEClass->getEStructuralFeatures()).basicAdd(
            m_AttributeDef__getRaises);
    m_AttributeDef__getRaises->basicsetEContainingClass(m_AttributeDefEClass);
    // m_AttributeDef__setRaises has already been allocated above
    m_AttributeDef__setRaises->setFeatureID(
            ::idlmm::IdlmmPackage::ATTRIBUTEDEF__SETRAISES);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_AttributeDefEClass->getEStructuralFeatures()).basicAdd(
            m_AttributeDef__setRaises);
    m_AttributeDef__setRaises->basicsetEContainingClass(m_AttributeDefEClass);
    // m_AttributeDef__isReadonly has already been allocated above
    m_AttributeDef__isReadonly->setFeatureID(
            ::idlmm::IdlmmPackage::ATTRIBUTEDEF__ISREADONLY);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_AttributeDefEClass->getEStructuralFeatures()).basicAdd(
            m_AttributeDef__isReadonly);
    m_AttributeDef__isReadonly->basicsetEContainingClass(m_AttributeDefEClass);

    // ConstantDef
    m_ConstantDefEClass = ::ecore::Ptr < ::ecore::EClass
            > (new ::ecore::EClass);
    m_ConstantDefEClass->setClassifierID(CONSTANTDEF);
    m_ConstantDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_ConstantDefEClass);
    // m_ConstantDef__constValue has already been allocated above
    m_ConstantDef__constValue->setFeatureID(
            ::idlmm::IdlmmPackage::CONSTANTDEF__CONSTVALUE);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ConstantDefEClass->getEStructuralFeatures()).basicAdd(
            m_ConstantDef__constValue);
    m_ConstantDef__constValue->basicsetEContainingClass(m_ConstantDefEClass);

    // Typed
    m_TypedEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_TypedEClass->setClassifierID(TYPED);
    m_TypedEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_TypedEClass);
    // m_Typed__containedType has already been allocated above
    m_Typed__containedType->setFeatureID(
            ::idlmm::IdlmmPackage::TYPED__CONTAINEDTYPE);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_TypedEClass->getEStructuralFeatures()).basicAdd(
            m_Typed__containedType);
    m_Typed__containedType->basicsetEContainingClass(m_TypedEClass);
    // m_Typed__sharedType has already been allocated above
    m_Typed__sharedType->setFeatureID(::idlmm::IdlmmPackage::TYPED__SHAREDTYPE);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_TypedEClass->getEStructuralFeatures()).basicAdd(
            m_Typed__sharedType);
    m_Typed__sharedType->basicsetEContainingClass(m_TypedEClass);

    // ParameterDef
    m_ParameterDefEClass = ::ecore::Ptr < ::ecore::EClass
            > (new ::ecore::EClass);
    m_ParameterDefEClass->setClassifierID(PARAMETERDEF);
    m_ParameterDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_ParameterDefEClass);
    // m_ParameterDef__identifier has already been allocated above
    m_ParameterDef__identifier->setFeatureID(
            ::idlmm::IdlmmPackage::PARAMETERDEF__IDENTIFIER);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ParameterDefEClass->getEStructuralFeatures()).basicAdd(
            m_ParameterDef__identifier);
    m_ParameterDef__identifier->basicsetEContainingClass(m_ParameterDefEClass);
    // m_ParameterDef__direction has already been allocated above
    m_ParameterDef__direction->setFeatureID(
            ::idlmm::IdlmmPackage::PARAMETERDEF__DIRECTION);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ParameterDefEClass->getEStructuralFeatures()).basicAdd(
            m_ParameterDef__direction);
    m_ParameterDef__direction->basicsetEContainingClass(m_ParameterDefEClass);

    // PrimitiveDef
    m_PrimitiveDefEClass = ::ecore::Ptr < ::ecore::EClass
            > (new ::ecore::EClass);
    m_PrimitiveDefEClass->setClassifierID(PRIMITIVEDEF);
    m_PrimitiveDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_PrimitiveDefEClass);
    // m_PrimitiveDef__kind has already been allocated above
    m_PrimitiveDef__kind->setFeatureID(
            ::idlmm::IdlmmPackage::PRIMITIVEDEF__KIND);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_PrimitiveDefEClass->getEStructuralFeatures()).basicAdd(
            m_PrimitiveDef__kind);
    m_PrimitiveDef__kind->basicsetEContainingClass(m_PrimitiveDefEClass);

    // ExceptionDef
    m_ExceptionDefEClass = ::ecore::Ptr < ::ecore::EClass
            > (new ::ecore::EClass);
    m_ExceptionDefEClass->setClassifierID(EXCEPTIONDEF);
    m_ExceptionDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_ExceptionDefEClass);
    // m_ExceptionDef__typeCode has already been allocated above
    m_ExceptionDef__typeCode->setFeatureID(
            ::idlmm::IdlmmPackage::EXCEPTIONDEF__TYPECODE);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ExceptionDefEClass->getEStructuralFeatures()).basicAdd(
            m_ExceptionDef__typeCode);
    m_ExceptionDef__typeCode->basicsetEContainingClass(m_ExceptionDefEClass);
    // m_ExceptionDef__members has already been allocated above
    m_ExceptionDef__members->setFeatureID(
            ::idlmm::IdlmmPackage::EXCEPTIONDEF__MEMBERS);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ExceptionDefEClass->getEStructuralFeatures()).basicAdd(
            m_ExceptionDef__members);
    m_ExceptionDef__members->basicsetEContainingClass(m_ExceptionDefEClass);

    // Field
    m_FieldEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_FieldEClass->setClassifierID(FIELD);
    m_FieldEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_FieldEClass);
    // m_Field__identifier has already been allocated above
    m_Field__identifier->setFeatureID(::idlmm::IdlmmPackage::FIELD__IDENTIFIER);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_FieldEClass->getEStructuralFeatures()).basicAdd(
            m_Field__identifier);
    m_Field__identifier->basicsetEContainingClass(m_FieldEClass);

    // FixedDef
    m_FixedDefEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_FixedDefEClass->setClassifierID(FIXEDDEF);
    m_FixedDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_FixedDefEClass);
    // m_FixedDef__digits has already been allocated above
    m_FixedDef__digits->setFeatureID(::idlmm::IdlmmPackage::FIXEDDEF__DIGITS);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_FixedDefEClass->getEStructuralFeatures()).basicAdd(
            m_FixedDef__digits);
    m_FixedDef__digits->basicsetEContainingClass(m_FixedDefEClass);
    // m_FixedDef__scale has already been allocated above
    m_FixedDef__scale->setFeatureID(::idlmm::IdlmmPackage::FIXEDDEF__SCALE);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_FixedDefEClass->getEStructuralFeatures()).basicAdd(
            m_FixedDef__scale);
    m_FixedDef__scale->basicsetEContainingClass(m_FixedDefEClass);

    // WstringDef
    m_WstringDefEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_WstringDefEClass->setClassifierID(WSTRINGDEF);
    m_WstringDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_WstringDefEClass);
    // m_WstringDef__bound has already been allocated above
    m_WstringDef__bound->setFeatureID(::idlmm::IdlmmPackage::WSTRINGDEF__BOUND);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_WstringDefEClass->getEStructuralFeatures()).basicAdd(
            m_WstringDef__bound);
    m_WstringDef__bound->basicsetEContainingClass(m_WstringDefEClass);

    // StringDef
    m_StringDefEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_StringDefEClass->setClassifierID(STRINGDEF);
    m_StringDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_StringDefEClass);
    // m_StringDef__bound has already been allocated above
    m_StringDef__bound->setFeatureID(::idlmm::IdlmmPackage::STRINGDEF__BOUND);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_StringDefEClass->getEStructuralFeatures()).basicAdd(
            m_StringDef__bound);
    m_StringDef__bound->basicsetEContainingClass(m_StringDefEClass);

    // AliasDef
    m_AliasDefEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_AliasDefEClass->setClassifierID(ALIASDEF);
    m_AliasDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_AliasDefEClass);

    // ArrayDef
    m_ArrayDefEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_ArrayDefEClass->setClassifierID(ARRAYDEF);
    m_ArrayDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_ArrayDefEClass);
    // m_ArrayDef__bound has already been allocated above
    m_ArrayDef__bound->setFeatureID(::idlmm::IdlmmPackage::ARRAYDEF__BOUND);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ArrayDefEClass->getEStructuralFeatures()).basicAdd(
            m_ArrayDef__bound);
    m_ArrayDef__bound->basicsetEContainingClass(m_ArrayDefEClass);

    // SequenceDef
    m_SequenceDefEClass = ::ecore::Ptr < ::ecore::EClass
            > (new ::ecore::EClass);
    m_SequenceDefEClass->setClassifierID(SEQUENCEDEF);
    m_SequenceDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_SequenceDefEClass);
    // m_SequenceDef__bound has already been allocated above
    m_SequenceDef__bound->setFeatureID(
            ::idlmm::IdlmmPackage::SEQUENCEDEF__BOUND);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_SequenceDefEClass->getEStructuralFeatures()).basicAdd(
            m_SequenceDef__bound);
    m_SequenceDef__bound->basicsetEContainingClass(m_SequenceDefEClass);

    // UnionField
    m_UnionFieldEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_UnionFieldEClass->setClassifierID(UNIONFIELD);
    m_UnionFieldEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_UnionFieldEClass);
    // m_UnionField__identifier has already been allocated above
    m_UnionField__identifier->setFeatureID(
            ::idlmm::IdlmmPackage::UNIONFIELD__IDENTIFIER);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_UnionFieldEClass->getEStructuralFeatures()).basicAdd(
            m_UnionField__identifier);
    m_UnionField__identifier->basicsetEContainingClass(m_UnionFieldEClass);
    // m_UnionField__label has already been allocated above
    m_UnionField__label->setFeatureID(::idlmm::IdlmmPackage::UNIONFIELD__LABEL);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_UnionFieldEClass->getEStructuralFeatures()).basicAdd(
            m_UnionField__label);
    m_UnionField__label->basicsetEContainingClass(m_UnionFieldEClass);

    // TypedefDef
    m_TypedefDefEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_TypedefDefEClass->setClassifierID(TYPEDEFDEF);
    m_TypedefDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_TypedefDefEClass);

    // UnionDef
    m_UnionDefEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_UnionDefEClass->setClassifierID(UNIONDEF);
    m_UnionDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_UnionDefEClass);
    // m_UnionDef__unionMembers has already been allocated above
    m_UnionDef__unionMembers->setFeatureID(
            ::idlmm::IdlmmPackage::UNIONDEF__UNIONMEMBERS);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_UnionDefEClass->getEStructuralFeatures()).basicAdd(
            m_UnionDef__unionMembers);
    m_UnionDef__unionMembers->basicsetEContainingClass(m_UnionDefEClass);
    // m_UnionDef__containedDiscrim has already been allocated above
    m_UnionDef__containedDiscrim->setFeatureID(
            ::idlmm::IdlmmPackage::UNIONDEF__CONTAINEDDISCRIM);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_UnionDefEClass->getEStructuralFeatures()).basicAdd(
            m_UnionDef__containedDiscrim);
    m_UnionDef__containedDiscrim->basicsetEContainingClass(m_UnionDefEClass);
    // m_UnionDef__sharedDiscrim has already been allocated above
    m_UnionDef__sharedDiscrim->setFeatureID(
            ::idlmm::IdlmmPackage::UNIONDEF__SHAREDDISCRIM);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_UnionDefEClass->getEStructuralFeatures()).basicAdd(
            m_UnionDef__sharedDiscrim);
    m_UnionDef__sharedDiscrim->basicsetEContainingClass(m_UnionDefEClass);

    // EnumDef
    m_EnumDefEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_EnumDefEClass->setClassifierID(ENUMDEF);
    m_EnumDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_EnumDefEClass);
    // m_EnumDef__members has already been allocated above
    m_EnumDef__members->setFeatureID(::idlmm::IdlmmPackage::ENUMDEF__MEMBERS);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_EnumDefEClass->getEStructuralFeatures()).basicAdd(
            m_EnumDef__members);
    m_EnumDef__members->basicsetEContainingClass(m_EnumDefEClass);

    // StructDef
    m_StructDefEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_StructDefEClass->setClassifierID(STRUCTDEF);
    m_StructDefEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_StructDefEClass);
    // m_StructDef__members has already been allocated above
    m_StructDef__members->setFeatureID(
            ::idlmm::IdlmmPackage::STRUCTDEF__MEMBERS);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_StructDefEClass->getEStructuralFeatures()).basicAdd(
            m_StructDef__members);
    m_StructDef__members->basicsetEContainingClass(m_StructDefEClass);

    // TranslationUnit
    m_TranslationUnitEClass = ::ecore::Ptr < ::ecore::EClass
            > (new ::ecore::EClass);
    m_TranslationUnitEClass->setClassifierID(TRANSLATIONUNIT);
    m_TranslationUnitEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_TranslationUnitEClass);
    // m_TranslationUnit__contains has already been allocated above
    m_TranslationUnit__contains->setFeatureID(
            ::idlmm::IdlmmPackage::TRANSLATIONUNIT__CONTAINS);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_TranslationUnitEClass->getEStructuralFeatures()).basicAdd(
            m_TranslationUnit__contains);
    m_TranslationUnit__contains->basicsetEContainingClass(
            m_TranslationUnitEClass);
    // m_TranslationUnit__identifier has already been allocated above
    m_TranslationUnit__identifier->setFeatureID(
            ::idlmm::IdlmmPackage::TRANSLATIONUNIT__IDENTIFIER);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_TranslationUnitEClass->getEStructuralFeatures()).basicAdd(
            m_TranslationUnit__identifier);
    m_TranslationUnit__identifier->basicsetEContainingClass(
            m_TranslationUnitEClass);
    // m_TranslationUnit__includes has already been allocated above
    m_TranslationUnit__includes->setFeatureID(
            ::idlmm::IdlmmPackage::TRANSLATIONUNIT__INCLUDES);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_TranslationUnitEClass->getEStructuralFeatures()).basicAdd(
            m_TranslationUnit__includes);
    m_TranslationUnit__includes->basicsetEContainingClass(
            m_TranslationUnitEClass);

    // Include
    m_IncludeEClass = ::ecore::Ptr < ::ecore::EClass > (new ::ecore::EClass);
    m_IncludeEClass->setClassifierID(INCLUDE);
    m_IncludeEClass->basicsetEPackage(_this());
    classifiers.basicAdd(m_IncludeEClass);
    // m_Include__importURI has already been allocated above
    m_Include__importURI->setFeatureID(
            ::idlmm::IdlmmPackage::INCLUDE__IMPORTURI);
    static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_IncludeEClass->getEStructuralFeatures()).basicAdd(
            m_Include__importURI);
    m_Include__importURI->basicsetEContainingClass(m_IncludeEClass);

    // Create enums

    m_ParameterModeEEnum = ::ecore::Ptr < ::ecore::EEnum > (new ::ecore::EEnum);
    m_ParameterModeEEnum->setClassifierID(PARAMETERMODE);
    m_ParameterModeEEnum->basicsetEPackage(_this());
    classifiers.basicAdd(m_ParameterModeEEnum);

    m_PrimitiveKindEEnum = ::ecore::Ptr < ::ecore::EEnum > (new ::ecore::EEnum);
    m_PrimitiveKindEEnum->setClassifierID(PRIMITIVEKIND);
    m_PrimitiveKindEEnum->basicsetEPackage(_this());
    classifiers.basicAdd(m_PrimitiveKindEEnum);

    // Create data types

    m_EAnyEDataType = ::ecore::Ptr < ::ecore::EDataType
            > (new ::ecore::EDataType);
    m_EAnyEDataType->setClassifierID(EANY);
    m_EAnyEDataType->basicsetEPackage(_this());
    classifiers.basicAdd(m_EAnyEDataType);

    m_ETypeCodeEDataType = ::ecore::Ptr < ::ecore::EDataType
            > (new ::ecore::EDataType);
    m_ETypeCodeEDataType->setClassifierID(ETYPECODE);
    m_ETypeCodeEDataType->basicsetEPackage(_this());
    classifiers.basicAdd(m_ETypeCodeEDataType);

    // Initialize package
    setName("idlmm");
    setNsPrefix("idlmm");
    setNsURI("http://idlmm/1.0");

    // TODO: bounds for type parameters

    // Add supertypes to classes
    m_ContainerEClass->getESuperTypes().push_back(m_ContainedEClass);
    m_InterfaceDefEClass->getESuperTypes().push_back(m_ContainerEClass);
    m_InterfaceDefEClass->getESuperTypes().push_back(m_TypedefDefEClass);
    m_ModuleDefEClass->getESuperTypes().push_back(m_ContainerEClass);
    m_OperationDefEClass->getESuperTypes().push_back(m_ContainedEClass);
    m_OperationDefEClass->getESuperTypes().push_back(m_TypedEClass);
    m_AttributeDefEClass->getESuperTypes().push_back(m_ContainedEClass);
    m_AttributeDefEClass->getESuperTypes().push_back(m_TypedEClass);
    m_ConstantDefEClass->getESuperTypes().push_back(m_ContainedEClass);
    m_ConstantDefEClass->getESuperTypes().push_back(m_TypedEClass);
    m_ParameterDefEClass->getESuperTypes().push_back(m_TypedEClass);
    m_PrimitiveDefEClass->getESuperTypes().push_back(m_IDLTypeEClass);
    m_ExceptionDefEClass->getESuperTypes().push_back(m_ContainedEClass);
    m_FieldEClass->getESuperTypes().push_back(m_TypedEClass);
    m_FixedDefEClass->getESuperTypes().push_back(m_IDLTypeEClass);
    m_WstringDefEClass->getESuperTypes().push_back(m_IDLTypeEClass);
    m_StringDefEClass->getESuperTypes().push_back(m_IDLTypeEClass);
    m_AliasDefEClass->getESuperTypes().push_back(m_TypedEClass);
    m_AliasDefEClass->getESuperTypes().push_back(m_TypedefDefEClass);
    m_ArrayDefEClass->getESuperTypes().push_back(m_TypedEClass);
    m_ArrayDefEClass->getESuperTypes().push_back(m_IDLTypeEClass);
    m_SequenceDefEClass->getESuperTypes().push_back(m_TypedEClass);
    m_SequenceDefEClass->getESuperTypes().push_back(m_IDLTypeEClass);
    m_UnionFieldEClass->getESuperTypes().push_back(m_TypedEClass);
    m_TypedefDefEClass->getESuperTypes().push_back(m_IDLTypeEClass);
    m_TypedefDefEClass->getESuperTypes().push_back(m_ContainedEClass);
    m_UnionDefEClass->getESuperTypes().push_back(m_TypedefDefEClass);
    m_EnumDefEClass->getESuperTypes().push_back(m_TypedefDefEClass);
    m_StructDefEClass->getESuperTypes().push_back(m_TypedefDefEClass);

    // TODO: Initialize classes and features; add operations and parameters
    // TODO: GenericTypes
    // Container
    m_ContainerEClass->setName("Container");
    m_ContainerEClass->setAbstract(true);
    m_ContainerEClass->setInterface(false);
    m_Container__contains->setEType(m_ContainedEClass);
    m_Container__contains->setName("contains");
    m_Container__contains->setDefaultValueLiteral("");
    m_Container__contains->setLowerBound(0);
    m_Container__contains->setUpperBound(-1);
    m_Container__contains->setTransient(false);
    m_Container__contains->setVolatile(false);
    m_Container__contains->setChangeable(true);
    m_Container__contains->setContainment(true);
    m_Container__contains->setResolveProxies(true);
    m_Container__contains->setUnique(true);
    m_Container__contains->setDerived(false);
    m_Container__contains->setOrdered(true);
    m_Container__contains->setEOpposite(
            ::ecore::as < ::ecore::EReference
                    > (m_ContainedEClass->getEStructuralFeatures()[4]));
    // Contained
    m_ContainedEClass->setName("Contained");
    m_ContainedEClass->setAbstract(true);
    m_ContainedEClass->setInterface(false);
    m_Contained__identifier->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_Contained__identifier->setName("identifier");
    m_Contained__identifier->setDefaultValueLiteral("");
    m_Contained__identifier->setLowerBound(0);
    m_Contained__identifier->setUpperBound(1);
    m_Contained__identifier->setTransient(false);
    m_Contained__identifier->setVolatile(false);
    m_Contained__identifier->setChangeable(true);
    m_Contained__identifier->setUnsettable(false);
    m_Contained__identifier->setID(false);
    m_Contained__identifier->setUnique(true);
    m_Contained__identifier->setDerived(false);
    m_Contained__identifier->setOrdered(true);
    m_Contained__repositoryId->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_Contained__repositoryId->setName("repositoryId");
    m_Contained__repositoryId->setDefaultValueLiteral("");
    m_Contained__repositoryId->setLowerBound(0);
    m_Contained__repositoryId->setUpperBound(1);
    m_Contained__repositoryId->setTransient(false);
    m_Contained__repositoryId->setVolatile(false);
    m_Contained__repositoryId->setChangeable(true);
    m_Contained__repositoryId->setUnsettable(false);
    m_Contained__repositoryId->setID(false);
    m_Contained__repositoryId->setUnique(true);
    m_Contained__repositoryId->setDerived(false);
    m_Contained__repositoryId->setOrdered(true);
    m_Contained__version->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_Contained__version->setName("version");
    m_Contained__version->setDefaultValueLiteral("");
    m_Contained__version->setLowerBound(0);
    m_Contained__version->setUpperBound(1);
    m_Contained__version->setTransient(false);
    m_Contained__version->setVolatile(false);
    m_Contained__version->setChangeable(true);
    m_Contained__version->setUnsettable(false);
    m_Contained__version->setID(false);
    m_Contained__version->setUnique(true);
    m_Contained__version->setDerived(false);
    m_Contained__version->setOrdered(true);
    m_Contained__absoluteName->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_Contained__absoluteName->setName("absoluteName");
    m_Contained__absoluteName->setDefaultValueLiteral("");
    m_Contained__absoluteName->setLowerBound(0);
    m_Contained__absoluteName->setUpperBound(1);
    m_Contained__absoluteName->setTransient(false);
    m_Contained__absoluteName->setVolatile(false);
    m_Contained__absoluteName->setChangeable(true);
    m_Contained__absoluteName->setUnsettable(false);
    m_Contained__absoluteName->setID(false);
    m_Contained__absoluteName->setUnique(true);
    m_Contained__absoluteName->setDerived(false);
    m_Contained__absoluteName->setOrdered(true);
    m_Contained__definedIn->setEType(m_ContainerEClass);
    m_Contained__definedIn->setName("definedIn");
    m_Contained__definedIn->setDefaultValueLiteral("");
    m_Contained__definedIn->setLowerBound(0);
    m_Contained__definedIn->setUpperBound(1);
    m_Contained__definedIn->setTransient(false);
    m_Contained__definedIn->setVolatile(false);
    m_Contained__definedIn->setChangeable(true);
    m_Contained__definedIn->setContainment(false);
    m_Contained__definedIn->setResolveProxies(true);
    m_Contained__definedIn->setUnique(true);
    m_Contained__definedIn->setDerived(false);
    m_Contained__definedIn->setOrdered(true);
    m_Contained__definedIn->setEOpposite(
            ::ecore::as < ::ecore::EReference
                    > (m_ContainerEClass->getEStructuralFeatures()[0]));
    // InterfaceDef
    m_InterfaceDefEClass->setName("InterfaceDef");
    m_InterfaceDefEClass->setAbstract(false);
    m_InterfaceDefEClass->setInterface(false);
    m_InterfaceDef__isAbstract->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEBoolean());
    m_InterfaceDef__isAbstract->setName("isAbstract");
    m_InterfaceDef__isAbstract->setDefaultValueLiteral("");
    m_InterfaceDef__isAbstract->setLowerBound(0);
    m_InterfaceDef__isAbstract->setUpperBound(1);
    m_InterfaceDef__isAbstract->setTransient(false);
    m_InterfaceDef__isAbstract->setVolatile(false);
    m_InterfaceDef__isAbstract->setChangeable(true);
    m_InterfaceDef__isAbstract->setUnsettable(false);
    m_InterfaceDef__isAbstract->setID(false);
    m_InterfaceDef__isAbstract->setUnique(true);
    m_InterfaceDef__isAbstract->setDerived(false);
    m_InterfaceDef__isAbstract->setOrdered(true);
    m_InterfaceDef__isCustom->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEBoolean());
    m_InterfaceDef__isCustom->setName("isCustom");
    m_InterfaceDef__isCustom->setDefaultValueLiteral("");
    m_InterfaceDef__isCustom->setLowerBound(0);
    m_InterfaceDef__isCustom->setUpperBound(1);
    m_InterfaceDef__isCustom->setTransient(false);
    m_InterfaceDef__isCustom->setVolatile(false);
    m_InterfaceDef__isCustom->setChangeable(true);
    m_InterfaceDef__isCustom->setUnsettable(false);
    m_InterfaceDef__isCustom->setID(false);
    m_InterfaceDef__isCustom->setUnique(true);
    m_InterfaceDef__isCustom->setDerived(false);
    m_InterfaceDef__isCustom->setOrdered(true);
    m_InterfaceDef__isTruncatable->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEBoolean());
    m_InterfaceDef__isTruncatable->setName("isTruncatable");
    m_InterfaceDef__isTruncatable->setDefaultValueLiteral("");
    m_InterfaceDef__isTruncatable->setLowerBound(0);
    m_InterfaceDef__isTruncatable->setUpperBound(1);
    m_InterfaceDef__isTruncatable->setTransient(false);
    m_InterfaceDef__isTruncatable->setVolatile(false);
    m_InterfaceDef__isTruncatable->setChangeable(true);
    m_InterfaceDef__isTruncatable->setUnsettable(false);
    m_InterfaceDef__isTruncatable->setID(false);
    m_InterfaceDef__isTruncatable->setUnique(true);
    m_InterfaceDef__isTruncatable->setDerived(false);
    m_InterfaceDef__isTruncatable->setOrdered(true);
    m_InterfaceDef__derivesFrom->setEType(m_InterfaceDefEClass);
    m_InterfaceDef__derivesFrom->setName("derivesFrom");
    m_InterfaceDef__derivesFrom->setDefaultValueLiteral("");
    m_InterfaceDef__derivesFrom->setLowerBound(0);
    m_InterfaceDef__derivesFrom->setUpperBound(-1);
    m_InterfaceDef__derivesFrom->setTransient(false);
    m_InterfaceDef__derivesFrom->setVolatile(false);
    m_InterfaceDef__derivesFrom->setChangeable(true);
    m_InterfaceDef__derivesFrom->setContainment(false);
    m_InterfaceDef__derivesFrom->setResolveProxies(true);
    m_InterfaceDef__derivesFrom->setUnique(true);
    m_InterfaceDef__derivesFrom->setDerived(false);
    m_InterfaceDef__derivesFrom->setOrdered(true);
    // ModuleDef
    m_ModuleDefEClass->setName("ModuleDef");
    m_ModuleDefEClass->setAbstract(false);
    m_ModuleDefEClass->setInterface(false);
    m_ModuleDef__prefix->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_ModuleDef__prefix->setName("prefix");
    m_ModuleDef__prefix->setDefaultValueLiteral("");
    m_ModuleDef__prefix->setLowerBound(0);
    m_ModuleDef__prefix->setUpperBound(1);
    m_ModuleDef__prefix->setTransient(false);
    m_ModuleDef__prefix->setVolatile(false);
    m_ModuleDef__prefix->setChangeable(true);
    m_ModuleDef__prefix->setUnsettable(false);
    m_ModuleDef__prefix->setID(false);
    m_ModuleDef__prefix->setUnique(true);
    m_ModuleDef__prefix->setDerived(false);
    m_ModuleDef__prefix->setOrdered(true);
    // IDLType
    m_IDLTypeEClass->setName("IDLType");
    m_IDLTypeEClass->setAbstract(true);
    m_IDLTypeEClass->setInterface(false);
    m_IDLType__typeCode->setEType(m_ETypeCodeEDataType);
    m_IDLType__typeCode->setName("typeCode");
    m_IDLType__typeCode->setDefaultValueLiteral("");
    m_IDLType__typeCode->setLowerBound(0);
    m_IDLType__typeCode->setUpperBound(1);
    m_IDLType__typeCode->setTransient(false);
    m_IDLType__typeCode->setVolatile(false);
    m_IDLType__typeCode->setChangeable(true);
    m_IDLType__typeCode->setUnsettable(false);
    m_IDLType__typeCode->setID(false);
    m_IDLType__typeCode->setUnique(true);
    m_IDLType__typeCode->setDerived(false);
    m_IDLType__typeCode->setOrdered(true);
    // OperationDef
    m_OperationDefEClass->setName("OperationDef");
    m_OperationDefEClass->setAbstract(false);
    m_OperationDefEClass->setInterface(false);
    m_OperationDef__isOneway->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEBoolean());
    m_OperationDef__isOneway->setName("isOneway");
    m_OperationDef__isOneway->setDefaultValueLiteral("");
    m_OperationDef__isOneway->setLowerBound(0);
    m_OperationDef__isOneway->setUpperBound(1);
    m_OperationDef__isOneway->setTransient(false);
    m_OperationDef__isOneway->setVolatile(false);
    m_OperationDef__isOneway->setChangeable(true);
    m_OperationDef__isOneway->setUnsettable(false);
    m_OperationDef__isOneway->setID(false);
    m_OperationDef__isOneway->setUnique(true);
    m_OperationDef__isOneway->setDerived(false);
    m_OperationDef__isOneway->setOrdered(true);
    m_OperationDef__contexts->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_OperationDef__contexts->setName("contexts");
    m_OperationDef__contexts->setDefaultValueLiteral("");
    m_OperationDef__contexts->setLowerBound(0);
    m_OperationDef__contexts->setUpperBound(-1);
    m_OperationDef__contexts->setTransient(false);
    m_OperationDef__contexts->setVolatile(false);
    m_OperationDef__contexts->setChangeable(true);
    m_OperationDef__contexts->setUnsettable(false);
    m_OperationDef__contexts->setID(false);
    m_OperationDef__contexts->setUnique(true);
    m_OperationDef__contexts->setDerived(false);
    m_OperationDef__contexts->setOrdered(true);
    m_OperationDef__parameters->setEType(m_ParameterDefEClass);
    m_OperationDef__parameters->setName("parameters");
    m_OperationDef__parameters->setDefaultValueLiteral("");
    m_OperationDef__parameters->setLowerBound(0);
    m_OperationDef__parameters->setUpperBound(-1);
    m_OperationDef__parameters->setTransient(false);
    m_OperationDef__parameters->setVolatile(false);
    m_OperationDef__parameters->setChangeable(true);
    m_OperationDef__parameters->setContainment(true);
    m_OperationDef__parameters->setResolveProxies(true);
    m_OperationDef__parameters->setUnique(true);
    m_OperationDef__parameters->setDerived(false);
    m_OperationDef__parameters->setOrdered(true);
    m_OperationDef__canRaise->setEType(m_ExceptionDefEClass);
    m_OperationDef__canRaise->setName("canRaise");
    m_OperationDef__canRaise->setDefaultValueLiteral("");
    m_OperationDef__canRaise->setLowerBound(0);
    m_OperationDef__canRaise->setUpperBound(-1);
    m_OperationDef__canRaise->setTransient(false);
    m_OperationDef__canRaise->setVolatile(false);
    m_OperationDef__canRaise->setChangeable(true);
    m_OperationDef__canRaise->setContainment(false);
    m_OperationDef__canRaise->setResolveProxies(true);
    m_OperationDef__canRaise->setUnique(true);
    m_OperationDef__canRaise->setDerived(false);
    m_OperationDef__canRaise->setOrdered(true);
    // AttributeDef
    m_AttributeDefEClass->setName("AttributeDef");
    m_AttributeDefEClass->setAbstract(false);
    m_AttributeDefEClass->setInterface(false);
    m_AttributeDef__isReadonly->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEBoolean());
    m_AttributeDef__isReadonly->setName("isReadonly");
    m_AttributeDef__isReadonly->setDefaultValueLiteral("");
    m_AttributeDef__isReadonly->setLowerBound(0);
    m_AttributeDef__isReadonly->setUpperBound(1);
    m_AttributeDef__isReadonly->setTransient(false);
    m_AttributeDef__isReadonly->setVolatile(false);
    m_AttributeDef__isReadonly->setChangeable(true);
    m_AttributeDef__isReadonly->setUnsettable(false);
    m_AttributeDef__isReadonly->setID(false);
    m_AttributeDef__isReadonly->setUnique(true);
    m_AttributeDef__isReadonly->setDerived(false);
    m_AttributeDef__isReadonly->setOrdered(true);
    m_AttributeDef__getRaises->setEType(m_ExceptionDefEClass);
    m_AttributeDef__getRaises->setName("getRaises");
    m_AttributeDef__getRaises->setDefaultValueLiteral("");
    m_AttributeDef__getRaises->setLowerBound(0);
    m_AttributeDef__getRaises->setUpperBound(-1);
    m_AttributeDef__getRaises->setTransient(false);
    m_AttributeDef__getRaises->setVolatile(false);
    m_AttributeDef__getRaises->setChangeable(true);
    m_AttributeDef__getRaises->setContainment(false);
    m_AttributeDef__getRaises->setResolveProxies(true);
    m_AttributeDef__getRaises->setUnique(true);
    m_AttributeDef__getRaises->setDerived(false);
    m_AttributeDef__getRaises->setOrdered(true);
    m_AttributeDef__setRaises->setEType(m_ExceptionDefEClass);
    m_AttributeDef__setRaises->setName("setRaises");
    m_AttributeDef__setRaises->setDefaultValueLiteral("");
    m_AttributeDef__setRaises->setLowerBound(0);
    m_AttributeDef__setRaises->setUpperBound(-1);
    m_AttributeDef__setRaises->setTransient(false);
    m_AttributeDef__setRaises->setVolatile(false);
    m_AttributeDef__setRaises->setChangeable(true);
    m_AttributeDef__setRaises->setContainment(false);
    m_AttributeDef__setRaises->setResolveProxies(true);
    m_AttributeDef__setRaises->setUnique(true);
    m_AttributeDef__setRaises->setDerived(false);
    m_AttributeDef__setRaises->setOrdered(true);
    // ConstantDef
    m_ConstantDefEClass->setName("ConstantDef");
    m_ConstantDefEClass->setAbstract(false);
    m_ConstantDefEClass->setInterface(false);
    m_ConstantDef__constValue->setEType(m_EAnyEDataType);
    m_ConstantDef__constValue->setName("constValue");
    m_ConstantDef__constValue->setDefaultValueLiteral("");
    m_ConstantDef__constValue->setLowerBound(0);
    m_ConstantDef__constValue->setUpperBound(1);
    m_ConstantDef__constValue->setTransient(false);
    m_ConstantDef__constValue->setVolatile(false);
    m_ConstantDef__constValue->setChangeable(true);
    m_ConstantDef__constValue->setUnsettable(false);
    m_ConstantDef__constValue->setID(false);
    m_ConstantDef__constValue->setUnique(true);
    m_ConstantDef__constValue->setDerived(false);
    m_ConstantDef__constValue->setOrdered(true);
    // Typed
    m_TypedEClass->setName("Typed");
    m_TypedEClass->setAbstract(true);
    m_TypedEClass->setInterface(false);
    m_Typed__containedType->setEType(m_IDLTypeEClass);
    m_Typed__containedType->setName("containedType");
    m_Typed__containedType->setDefaultValueLiteral("");
    m_Typed__containedType->setLowerBound(0);
    m_Typed__containedType->setUpperBound(1);
    m_Typed__containedType->setTransient(false);
    m_Typed__containedType->setVolatile(false);
    m_Typed__containedType->setChangeable(true);
    m_Typed__containedType->setContainment(true);
    m_Typed__containedType->setResolveProxies(true);
    m_Typed__containedType->setUnique(true);
    m_Typed__containedType->setDerived(false);
    m_Typed__containedType->setOrdered(true);
    m_Typed__sharedType->setEType(m_TypedefDefEClass);
    m_Typed__sharedType->setName("sharedType");
    m_Typed__sharedType->setDefaultValueLiteral("");
    m_Typed__sharedType->setLowerBound(0);
    m_Typed__sharedType->setUpperBound(1);
    m_Typed__sharedType->setTransient(false);
    m_Typed__sharedType->setVolatile(false);
    m_Typed__sharedType->setChangeable(true);
    m_Typed__sharedType->setContainment(false);
    m_Typed__sharedType->setResolveProxies(true);
    m_Typed__sharedType->setUnique(true);
    m_Typed__sharedType->setDerived(false);
    m_Typed__sharedType->setOrdered(true);
    // ParameterDef
    m_ParameterDefEClass->setName("ParameterDef");
    m_ParameterDefEClass->setAbstract(false);
    m_ParameterDefEClass->setInterface(false);
    m_ParameterDef__identifier->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_ParameterDef__identifier->setName("identifier");
    m_ParameterDef__identifier->setDefaultValueLiteral("");
    m_ParameterDef__identifier->setLowerBound(0);
    m_ParameterDef__identifier->setUpperBound(1);
    m_ParameterDef__identifier->setTransient(false);
    m_ParameterDef__identifier->setVolatile(false);
    m_ParameterDef__identifier->setChangeable(true);
    m_ParameterDef__identifier->setUnsettable(false);
    m_ParameterDef__identifier->setID(false);
    m_ParameterDef__identifier->setUnique(true);
    m_ParameterDef__identifier->setDerived(false);
    m_ParameterDef__identifier->setOrdered(true);
    m_ParameterDef__direction->setEType(m_ParameterModeEEnum);
    m_ParameterDef__direction->setName("direction");
    m_ParameterDef__direction->setDefaultValueLiteral("");
    m_ParameterDef__direction->setLowerBound(0);
    m_ParameterDef__direction->setUpperBound(1);
    m_ParameterDef__direction->setTransient(false);
    m_ParameterDef__direction->setVolatile(false);
    m_ParameterDef__direction->setChangeable(true);
    m_ParameterDef__direction->setUnsettable(false);
    m_ParameterDef__direction->setID(false);
    m_ParameterDef__direction->setUnique(true);
    m_ParameterDef__direction->setDerived(false);
    m_ParameterDef__direction->setOrdered(true);
    // PrimitiveDef
    m_PrimitiveDefEClass->setName("PrimitiveDef");
    m_PrimitiveDefEClass->setAbstract(false);
    m_PrimitiveDefEClass->setInterface(false);
    m_PrimitiveDef__kind->setEType(m_PrimitiveKindEEnum);
    m_PrimitiveDef__kind->setName("kind");
    m_PrimitiveDef__kind->setDefaultValueLiteral("");
    m_PrimitiveDef__kind->setLowerBound(0);
    m_PrimitiveDef__kind->setUpperBound(1);
    m_PrimitiveDef__kind->setTransient(false);
    m_PrimitiveDef__kind->setVolatile(false);
    m_PrimitiveDef__kind->setChangeable(true);
    m_PrimitiveDef__kind->setUnsettable(false);
    m_PrimitiveDef__kind->setID(false);
    m_PrimitiveDef__kind->setUnique(true);
    m_PrimitiveDef__kind->setDerived(false);
    m_PrimitiveDef__kind->setOrdered(true);
    // ExceptionDef
    m_ExceptionDefEClass->setName("ExceptionDef");
    m_ExceptionDefEClass->setAbstract(false);
    m_ExceptionDefEClass->setInterface(false);
    m_ExceptionDef__typeCode->setEType(m_ETypeCodeEDataType);
    m_ExceptionDef__typeCode->setName("typeCode");
    m_ExceptionDef__typeCode->setDefaultValueLiteral("");
    m_ExceptionDef__typeCode->setLowerBound(0);
    m_ExceptionDef__typeCode->setUpperBound(1);
    m_ExceptionDef__typeCode->setTransient(false);
    m_ExceptionDef__typeCode->setVolatile(false);
    m_ExceptionDef__typeCode->setChangeable(true);
    m_ExceptionDef__typeCode->setUnsettable(false);
    m_ExceptionDef__typeCode->setID(false);
    m_ExceptionDef__typeCode->setUnique(true);
    m_ExceptionDef__typeCode->setDerived(false);
    m_ExceptionDef__typeCode->setOrdered(true);
    m_ExceptionDef__members->setEType(m_FieldEClass);
    m_ExceptionDef__members->setName("members");
    m_ExceptionDef__members->setDefaultValueLiteral("");
    m_ExceptionDef__members->setLowerBound(0);
    m_ExceptionDef__members->setUpperBound(-1);
    m_ExceptionDef__members->setTransient(false);
    m_ExceptionDef__members->setVolatile(false);
    m_ExceptionDef__members->setChangeable(true);
    m_ExceptionDef__members->setContainment(true);
    m_ExceptionDef__members->setResolveProxies(true);
    m_ExceptionDef__members->setUnique(true);
    m_ExceptionDef__members->setDerived(false);
    m_ExceptionDef__members->setOrdered(true);
    // Field
    m_FieldEClass->setName("Field");
    m_FieldEClass->setAbstract(false);
    m_FieldEClass->setInterface(false);
    m_Field__identifier->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_Field__identifier->setName("identifier");
    m_Field__identifier->setDefaultValueLiteral("");
    m_Field__identifier->setLowerBound(0);
    m_Field__identifier->setUpperBound(1);
    m_Field__identifier->setTransient(false);
    m_Field__identifier->setVolatile(false);
    m_Field__identifier->setChangeable(true);
    m_Field__identifier->setUnsettable(false);
    m_Field__identifier->setID(false);
    m_Field__identifier->setUnique(true);
    m_Field__identifier->setDerived(false);
    m_Field__identifier->setOrdered(true);
    // FixedDef
    m_FixedDefEClass->setName("FixedDef");
    m_FixedDefEClass->setAbstract(false);
    m_FixedDefEClass->setInterface(false);
    m_FixedDef__digits->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_FixedDef__digits->setName("digits");
    m_FixedDef__digits->setDefaultValueLiteral("");
    m_FixedDef__digits->setLowerBound(0);
    m_FixedDef__digits->setUpperBound(1);
    m_FixedDef__digits->setTransient(false);
    m_FixedDef__digits->setVolatile(false);
    m_FixedDef__digits->setChangeable(true);
    m_FixedDef__digits->setUnsettable(false);
    m_FixedDef__digits->setID(false);
    m_FixedDef__digits->setUnique(true);
    m_FixedDef__digits->setDerived(false);
    m_FixedDef__digits->setOrdered(true);
    m_FixedDef__scale->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_FixedDef__scale->setName("scale");
    m_FixedDef__scale->setDefaultValueLiteral("");
    m_FixedDef__scale->setLowerBound(0);
    m_FixedDef__scale->setUpperBound(1);
    m_FixedDef__scale->setTransient(false);
    m_FixedDef__scale->setVolatile(false);
    m_FixedDef__scale->setChangeable(true);
    m_FixedDef__scale->setUnsettable(false);
    m_FixedDef__scale->setID(false);
    m_FixedDef__scale->setUnique(true);
    m_FixedDef__scale->setDerived(false);
    m_FixedDef__scale->setOrdered(true);
    // WstringDef
    m_WstringDefEClass->setName("WstringDef");
    m_WstringDefEClass->setAbstract(false);
    m_WstringDefEClass->setInterface(false);
    m_WstringDef__bound->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_WstringDef__bound->setName("bound");
    m_WstringDef__bound->setDefaultValueLiteral("");
    m_WstringDef__bound->setLowerBound(0);
    m_WstringDef__bound->setUpperBound(1);
    m_WstringDef__bound->setTransient(false);
    m_WstringDef__bound->setVolatile(false);
    m_WstringDef__bound->setChangeable(true);
    m_WstringDef__bound->setUnsettable(false);
    m_WstringDef__bound->setID(false);
    m_WstringDef__bound->setUnique(true);
    m_WstringDef__bound->setDerived(false);
    m_WstringDef__bound->setOrdered(true);
    // StringDef
    m_StringDefEClass->setName("StringDef");
    m_StringDefEClass->setAbstract(false);
    m_StringDefEClass->setInterface(false);
    m_StringDef__bound->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_StringDef__bound->setName("bound");
    m_StringDef__bound->setDefaultValueLiteral("");
    m_StringDef__bound->setLowerBound(0);
    m_StringDef__bound->setUpperBound(1);
    m_StringDef__bound->setTransient(false);
    m_StringDef__bound->setVolatile(false);
    m_StringDef__bound->setChangeable(true);
    m_StringDef__bound->setUnsettable(false);
    m_StringDef__bound->setID(false);
    m_StringDef__bound->setUnique(true);
    m_StringDef__bound->setDerived(false);
    m_StringDef__bound->setOrdered(true);
    // AliasDef
    m_AliasDefEClass->setName("AliasDef");
    m_AliasDefEClass->setAbstract(false);
    m_AliasDefEClass->setInterface(false);
    // ArrayDef
    m_ArrayDefEClass->setName("ArrayDef");
    m_ArrayDefEClass->setAbstract(false);
    m_ArrayDefEClass->setInterface(false);
    m_ArrayDef__bound->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_ArrayDef__bound->setName("bound");
    m_ArrayDef__bound->setDefaultValueLiteral("");
    m_ArrayDef__bound->setLowerBound(0);
    m_ArrayDef__bound->setUpperBound(1);
    m_ArrayDef__bound->setTransient(false);
    m_ArrayDef__bound->setVolatile(false);
    m_ArrayDef__bound->setChangeable(true);
    m_ArrayDef__bound->setUnsettable(false);
    m_ArrayDef__bound->setID(false);
    m_ArrayDef__bound->setUnique(true);
    m_ArrayDef__bound->setDerived(false);
    m_ArrayDef__bound->setOrdered(true);
    // SequenceDef
    m_SequenceDefEClass->setName("SequenceDef");
    m_SequenceDefEClass->setAbstract(false);
    m_SequenceDefEClass->setInterface(false);
    m_SequenceDef__bound->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_SequenceDef__bound->setName("bound");
    m_SequenceDef__bound->setDefaultValueLiteral("");
    m_SequenceDef__bound->setLowerBound(0);
    m_SequenceDef__bound->setUpperBound(1);
    m_SequenceDef__bound->setTransient(false);
    m_SequenceDef__bound->setVolatile(false);
    m_SequenceDef__bound->setChangeable(true);
    m_SequenceDef__bound->setUnsettable(false);
    m_SequenceDef__bound->setID(false);
    m_SequenceDef__bound->setUnique(true);
    m_SequenceDef__bound->setDerived(false);
    m_SequenceDef__bound->setOrdered(true);
    // UnionField
    m_UnionFieldEClass->setName("UnionField");
    m_UnionFieldEClass->setAbstract(false);
    m_UnionFieldEClass->setInterface(false);
    m_UnionField__identifier->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_UnionField__identifier->setName("identifier");
    m_UnionField__identifier->setDefaultValueLiteral("");
    m_UnionField__identifier->setLowerBound(0);
    m_UnionField__identifier->setUpperBound(1);
    m_UnionField__identifier->setTransient(false);
    m_UnionField__identifier->setVolatile(false);
    m_UnionField__identifier->setChangeable(true);
    m_UnionField__identifier->setUnsettable(false);
    m_UnionField__identifier->setID(false);
    m_UnionField__identifier->setUnique(true);
    m_UnionField__identifier->setDerived(false);
    m_UnionField__identifier->setOrdered(true);
    m_UnionField__label->setEType(m_EAnyEDataType);
    m_UnionField__label->setName("label");
    m_UnionField__label->setDefaultValueLiteral("");
    m_UnionField__label->setLowerBound(0);
    m_UnionField__label->setUpperBound(-1);
    m_UnionField__label->setTransient(false);
    m_UnionField__label->setVolatile(false);
    m_UnionField__label->setChangeable(true);
    m_UnionField__label->setUnsettable(false);
    m_UnionField__label->setID(false);
    m_UnionField__label->setUnique(true);
    m_UnionField__label->setDerived(false);
    m_UnionField__label->setOrdered(true);
    // TypedefDef
    m_TypedefDefEClass->setName("TypedefDef");
    m_TypedefDefEClass->setAbstract(true);
    m_TypedefDefEClass->setInterface(false);
    // UnionDef
    m_UnionDefEClass->setName("UnionDef");
    m_UnionDefEClass->setAbstract(false);
    m_UnionDefEClass->setInterface(false);
    m_UnionDef__unionMembers->setEType(m_UnionFieldEClass);
    m_UnionDef__unionMembers->setName("unionMembers");
    m_UnionDef__unionMembers->setDefaultValueLiteral("");
    m_UnionDef__unionMembers->setLowerBound(0);
    m_UnionDef__unionMembers->setUpperBound(-1);
    m_UnionDef__unionMembers->setTransient(false);
    m_UnionDef__unionMembers->setVolatile(false);
    m_UnionDef__unionMembers->setChangeable(true);
    m_UnionDef__unionMembers->setContainment(true);
    m_UnionDef__unionMembers->setResolveProxies(true);
    m_UnionDef__unionMembers->setUnique(true);
    m_UnionDef__unionMembers->setDerived(false);
    m_UnionDef__unionMembers->setOrdered(true);
    m_UnionDef__containedDiscrim->setEType(m_IDLTypeEClass);
    m_UnionDef__containedDiscrim->setName("containedDiscrim");
    m_UnionDef__containedDiscrim->setDefaultValueLiteral("");
    m_UnionDef__containedDiscrim->setLowerBound(0);
    m_UnionDef__containedDiscrim->setUpperBound(1);
    m_UnionDef__containedDiscrim->setTransient(false);
    m_UnionDef__containedDiscrim->setVolatile(false);
    m_UnionDef__containedDiscrim->setChangeable(true);
    m_UnionDef__containedDiscrim->setContainment(true);
    m_UnionDef__containedDiscrim->setResolveProxies(true);
    m_UnionDef__containedDiscrim->setUnique(true);
    m_UnionDef__containedDiscrim->setDerived(false);
    m_UnionDef__containedDiscrim->setOrdered(true);
    m_UnionDef__sharedDiscrim->setEType(m_TypedefDefEClass);
    m_UnionDef__sharedDiscrim->setName("sharedDiscrim");
    m_UnionDef__sharedDiscrim->setDefaultValueLiteral("");
    m_UnionDef__sharedDiscrim->setLowerBound(0);
    m_UnionDef__sharedDiscrim->setUpperBound(1);
    m_UnionDef__sharedDiscrim->setTransient(false);
    m_UnionDef__sharedDiscrim->setVolatile(false);
    m_UnionDef__sharedDiscrim->setChangeable(true);
    m_UnionDef__sharedDiscrim->setContainment(false);
    m_UnionDef__sharedDiscrim->setResolveProxies(true);
    m_UnionDef__sharedDiscrim->setUnique(true);
    m_UnionDef__sharedDiscrim->setDerived(false);
    m_UnionDef__sharedDiscrim->setOrdered(true);
    // EnumDef
    m_EnumDefEClass->setName("EnumDef");
    m_EnumDefEClass->setAbstract(false);
    m_EnumDefEClass->setInterface(false);
    m_EnumDef__members->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_EnumDef__members->setName("members");
    m_EnumDef__members->setDefaultValueLiteral("");
    m_EnumDef__members->setLowerBound(0);
    m_EnumDef__members->setUpperBound(-1);
    m_EnumDef__members->setTransient(false);
    m_EnumDef__members->setVolatile(false);
    m_EnumDef__members->setChangeable(true);
    m_EnumDef__members->setUnsettable(false);
    m_EnumDef__members->setID(false);
    m_EnumDef__members->setUnique(true);
    m_EnumDef__members->setDerived(false);
    m_EnumDef__members->setOrdered(true);
    // StructDef
    m_StructDefEClass->setName("StructDef");
    m_StructDefEClass->setAbstract(false);
    m_StructDefEClass->setInterface(false);
    m_StructDef__members->setEType(m_FieldEClass);
    m_StructDef__members->setName("members");
    m_StructDef__members->setDefaultValueLiteral("");
    m_StructDef__members->setLowerBound(0);
    m_StructDef__members->setUpperBound(-1);
    m_StructDef__members->setTransient(false);
    m_StructDef__members->setVolatile(false);
    m_StructDef__members->setChangeable(true);
    m_StructDef__members->setContainment(true);
    m_StructDef__members->setResolveProxies(true);
    m_StructDef__members->setUnique(true);
    m_StructDef__members->setDerived(false);
    m_StructDef__members->setOrdered(true);
    // TranslationUnit
    m_TranslationUnitEClass->setName("TranslationUnit");
    m_TranslationUnitEClass->setAbstract(false);
    m_TranslationUnitEClass->setInterface(false);
    m_TranslationUnit__identifier->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_TranslationUnit__identifier->setName("identifier");
    m_TranslationUnit__identifier->setDefaultValueLiteral("");
    m_TranslationUnit__identifier->setLowerBound(0);
    m_TranslationUnit__identifier->setUpperBound(1);
    m_TranslationUnit__identifier->setTransient(false);
    m_TranslationUnit__identifier->setVolatile(false);
    m_TranslationUnit__identifier->setChangeable(true);
    m_TranslationUnit__identifier->setUnsettable(false);
    m_TranslationUnit__identifier->setID(false);
    m_TranslationUnit__identifier->setUnique(true);
    m_TranslationUnit__identifier->setDerived(false);
    m_TranslationUnit__identifier->setOrdered(true);
    m_TranslationUnit__contains->setEType(m_ContainedEClass);
    m_TranslationUnit__contains->setName("contains");
    m_TranslationUnit__contains->setDefaultValueLiteral("");
    m_TranslationUnit__contains->setLowerBound(0);
    m_TranslationUnit__contains->setUpperBound(-1);
    m_TranslationUnit__contains->setTransient(false);
    m_TranslationUnit__contains->setVolatile(false);
    m_TranslationUnit__contains->setChangeable(true);
    m_TranslationUnit__contains->setContainment(true);
    m_TranslationUnit__contains->setResolveProxies(true);
    m_TranslationUnit__contains->setUnique(true);
    m_TranslationUnit__contains->setDerived(false);
    m_TranslationUnit__contains->setOrdered(true);
    m_TranslationUnit__includes->setEType(m_IncludeEClass);
    m_TranslationUnit__includes->setName("includes");
    m_TranslationUnit__includes->setDefaultValueLiteral("");
    m_TranslationUnit__includes->setLowerBound(0);
    m_TranslationUnit__includes->setUpperBound(-1);
    m_TranslationUnit__includes->setTransient(false);
    m_TranslationUnit__includes->setVolatile(false);
    m_TranslationUnit__includes->setChangeable(true);
    m_TranslationUnit__includes->setContainment(true);
    m_TranslationUnit__includes->setResolveProxies(true);
    m_TranslationUnit__includes->setUnique(true);
    m_TranslationUnit__includes->setDerived(false);
    m_TranslationUnit__includes->setOrdered(true);
    // Include
    m_IncludeEClass->setName("Include");
    m_IncludeEClass->setAbstract(false);
    m_IncludeEClass->setInterface(false);
    m_Include__importURI->setEType(
            dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEString());
    m_Include__importURI->setName("importURI");
    m_Include__importURI->setDefaultValueLiteral("");
    m_Include__importURI->setLowerBound(0);
    m_Include__importURI->setUpperBound(1);
    m_Include__importURI->setTransient(false);
    m_Include__importURI->setVolatile(false);
    m_Include__importURI->setChangeable(true);
    m_Include__importURI->setUnsettable(false);
    m_Include__importURI->setID(false);
    m_Include__importURI->setUnique(true);
    m_Include__importURI->setDerived(false);
    m_Include__importURI->setOrdered(true);

    // TODO: Initialize data types

    // EAny
    m_EAnyEDataType->setName("EAny");
    m_EAnyEDataType->setSerializable(true);

    // ETypeCode
    m_ETypeCodeEDataType->setName("ETypeCode");
    m_ETypeCodeEDataType->setSerializable(true);

    // ParameterMode
    m_ParameterModeEEnum->setName("ParameterMode");
    m_ParameterModeEEnum->setSerializable(true);

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PARAM_IN
        _el->setName("PARAM_IN");
        _el->setValue(0);
        _el->setLiteral("PARAM_IN");
        _el->setEEnum(m_ParameterModeEEnum);
        m_ParameterModeEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PARAM_OUT
        _el->setName("PARAM_OUT");
        _el->setValue(1);
        _el->setLiteral("PARAM_OUT");
        _el->setEEnum(m_ParameterModeEEnum);
        m_ParameterModeEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PARAM_INOUT
        _el->setName("PARAM_INOUT");
        _el->setValue(2);
        _el->setLiteral("PARAM_INOUT");
        _el->setEEnum(m_ParameterModeEEnum);
        m_ParameterModeEEnum->getELiterals().push_back(_el);
    }

    // PrimitiveKind
    m_PrimitiveKindEEnum->setName("PrimitiveKind");
    m_PrimitiveKindEEnum->setSerializable(true);

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_NULL
        _el->setName("PK_NULL");
        _el->setValue(0);
        _el->setLiteral("PK_NULL");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_VOID
        _el->setName("PK_VOID");
        _el->setValue(1);
        _el->setLiteral("PK_VOID");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_SHORT
        _el->setName("PK_SHORT");
        _el->setValue(2);
        _el->setLiteral("PK_SHORT");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_LONG
        _el->setName("PK_LONG");
        _el->setValue(3);
        _el->setLiteral("PK_LONG");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_USHORT
        _el->setName("PK_USHORT");
        _el->setValue(4);
        _el->setLiteral("PK_USHORT");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_ULONG
        _el->setName("PK_ULONG");
        _el->setValue(5);
        _el->setLiteral("PK_ULONG");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_FLOAT
        _el->setName("PK_FLOAT");
        _el->setValue(6);
        _el->setLiteral("PK_FLOAT");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_DOUBLE
        _el->setName("PK_DOUBLE");
        _el->setValue(7);
        _el->setLiteral("PK_DOUBLE");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_BOOLEAN
        _el->setName("PK_BOOLEAN");
        _el->setValue(8);
        _el->setLiteral("PK_BOOLEAN");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_CHAR
        _el->setName("PK_CHAR");
        _el->setValue(9);
        _el->setLiteral("PK_CHAR");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_OCTET
        _el->setName("PK_OCTET");
        _el->setValue(10);
        _el->setLiteral("PK_OCTET");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_ANY
        _el->setName("PK_ANY");
        _el->setValue(11);
        _el->setLiteral("PK_ANY");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_LONGDOUBLE
        _el->setName("PK_LONGDOUBLE");
        _el->setValue(12);
        _el->setLiteral("PK_LONGDOUBLE");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_WSTRING
        _el->setName("PK_WSTRING");
        _el->setValue(13);
        _el->setLiteral("PK_WSTRING");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_TYPECODE
        _el->setName("PK_TYPECODE");
        _el->setValue(14);
        _el->setLiteral("PK_TYPECODE");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_WCHAR
        _el->setName("PK_WCHAR");
        _el->setValue(15);
        _el->setLiteral("PK_WCHAR");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_PRINCIPAL
        _el->setName("PK_PRINCIPAL");
        _el->setValue(16);
        _el->setLiteral("PK_PRINCIPAL");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_STRING
        _el->setName("PK_STRING");
        _el->setValue(17);
        _el->setLiteral("PK_STRING");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_ULONGLONG
        _el->setName("PK_ULONGLONG");
        _el->setValue(18);
        _el->setLiteral("PK_ULONGLONG");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_OBJREF
        _el->setName("PK_OBJREF");
        _el->setValue(19);
        _el->setLiteral("PK_OBJREF");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    {
        ::ecore::EEnumLiteral_ptr _el = ::ecore::Ptr < ::ecore::EEnumLiteral
                > (new ::ecore::EEnumLiteral);
        // PK_LONGLONG
        _el->setName("PK_LONGLONG");
        _el->setValue(20);
        _el->setLiteral("PK_LONGLONG");
        _el->setEEnum(m_PrimitiveKindEEnum);
        m_PrimitiveKindEEnum->getELiterals().push_back(_el);
    }

    /* EAnnotations for EPackage, the EClasses and their EStructuralFeatures */
    ::ecore::EAnnotation_ptr _annotation;

    _initialize();
}

::ecore::EClass_ptr IdlmmPackage::getContainer()
{
    return m_ContainerEClass;
}
::ecore::EClass_ptr IdlmmPackage::getContained()
{
    return m_ContainedEClass;
}
::ecore::EClass_ptr IdlmmPackage::getInterfaceDef()
{
    return m_InterfaceDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getModuleDef()
{
    return m_ModuleDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getIDLType()
{
    return m_IDLTypeEClass;
}
::ecore::EClass_ptr IdlmmPackage::getOperationDef()
{
    return m_OperationDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getAttributeDef()
{
    return m_AttributeDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getConstantDef()
{
    return m_ConstantDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getTyped()
{
    return m_TypedEClass;
}
::ecore::EClass_ptr IdlmmPackage::getParameterDef()
{
    return m_ParameterDefEClass;
}
::ecore::EEnum_ptr IdlmmPackage::getParameterMode()
{
    return m_ParameterModeEEnum;
}
::ecore::EClass_ptr IdlmmPackage::getPrimitiveDef()
{
    return m_PrimitiveDefEClass;
}
::ecore::EEnum_ptr IdlmmPackage::getPrimitiveKind()
{
    return m_PrimitiveKindEEnum;
}
::ecore::EClass_ptr IdlmmPackage::getExceptionDef()
{
    return m_ExceptionDefEClass;
}
::ecore::EDataType_ptr IdlmmPackage::getEAny()
{
    return m_EAnyEDataType;
}
::ecore::EDataType_ptr IdlmmPackage::getETypeCode()
{
    return m_ETypeCodeEDataType;
}
::ecore::EClass_ptr IdlmmPackage::getField()
{
    return m_FieldEClass;
}
::ecore::EClass_ptr IdlmmPackage::getFixedDef()
{
    return m_FixedDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getWstringDef()
{
    return m_WstringDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getStringDef()
{
    return m_StringDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getAliasDef()
{
    return m_AliasDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getArrayDef()
{
    return m_ArrayDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getSequenceDef()
{
    return m_SequenceDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getUnionField()
{
    return m_UnionFieldEClass;
}
::ecore::EClass_ptr IdlmmPackage::getTypedefDef()
{
    return m_TypedefDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getUnionDef()
{
    return m_UnionDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getEnumDef()
{
    return m_EnumDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getStructDef()
{
    return m_StructDefEClass;
}
::ecore::EClass_ptr IdlmmPackage::getTranslationUnit()
{
    return m_TranslationUnitEClass;
}
::ecore::EClass_ptr IdlmmPackage::getInclude()
{
    return m_IncludeEClass;
}

::ecore::EReference_ptr IdlmmPackage::getContainer__contains()
{
    return m_Container__contains;
}
::ecore::EAttribute_ptr IdlmmPackage::getContained__identifier()
{
    return m_Contained__identifier;
}
::ecore::EAttribute_ptr IdlmmPackage::getContained__repositoryId()
{
    return m_Contained__repositoryId;
}
::ecore::EAttribute_ptr IdlmmPackage::getContained__version()
{
    return m_Contained__version;
}
::ecore::EAttribute_ptr IdlmmPackage::getContained__absoluteName()
{
    return m_Contained__absoluteName;
}
::ecore::EReference_ptr IdlmmPackage::getContained__definedIn()
{
    return m_Contained__definedIn;
}
::ecore::EAttribute_ptr IdlmmPackage::getInterfaceDef__isAbstract()
{
    return m_InterfaceDef__isAbstract;
}
::ecore::EAttribute_ptr IdlmmPackage::getInterfaceDef__isCustom()
{
    return m_InterfaceDef__isCustom;
}
::ecore::EAttribute_ptr IdlmmPackage::getInterfaceDef__isTruncatable()
{
    return m_InterfaceDef__isTruncatable;
}
::ecore::EReference_ptr IdlmmPackage::getInterfaceDef__derivesFrom()
{
    return m_InterfaceDef__derivesFrom;
}
::ecore::EAttribute_ptr IdlmmPackage::getModuleDef__prefix()
{
    return m_ModuleDef__prefix;
}
::ecore::EAttribute_ptr IdlmmPackage::getIDLType__typeCode()
{
    return m_IDLType__typeCode;
}
::ecore::EReference_ptr IdlmmPackage::getOperationDef__parameters()
{
    return m_OperationDef__parameters;
}
::ecore::EAttribute_ptr IdlmmPackage::getOperationDef__isOneway()
{
    return m_OperationDef__isOneway;
}
::ecore::EAttribute_ptr IdlmmPackage::getOperationDef__contexts()
{
    return m_OperationDef__contexts;
}
::ecore::EReference_ptr IdlmmPackage::getOperationDef__canRaise()
{
    return m_OperationDef__canRaise;
}
::ecore::EReference_ptr IdlmmPackage::getAttributeDef__getRaises()
{
    return m_AttributeDef__getRaises;
}
::ecore::EReference_ptr IdlmmPackage::getAttributeDef__setRaises()
{
    return m_AttributeDef__setRaises;
}
::ecore::EAttribute_ptr IdlmmPackage::getAttributeDef__isReadonly()
{
    return m_AttributeDef__isReadonly;
}
::ecore::EAttribute_ptr IdlmmPackage::getConstantDef__constValue()
{
    return m_ConstantDef__constValue;
}
::ecore::EReference_ptr IdlmmPackage::getTyped__containedType()
{
    return m_Typed__containedType;
}
::ecore::EReference_ptr IdlmmPackage::getTyped__sharedType()
{
    return m_Typed__sharedType;
}
::ecore::EAttribute_ptr IdlmmPackage::getParameterDef__identifier()
{
    return m_ParameterDef__identifier;
}
::ecore::EAttribute_ptr IdlmmPackage::getParameterDef__direction()
{
    return m_ParameterDef__direction;
}
::ecore::EAttribute_ptr IdlmmPackage::getPrimitiveDef__kind()
{
    return m_PrimitiveDef__kind;
}
::ecore::EAttribute_ptr IdlmmPackage::getExceptionDef__typeCode()
{
    return m_ExceptionDef__typeCode;
}
::ecore::EReference_ptr IdlmmPackage::getExceptionDef__members()
{
    return m_ExceptionDef__members;
}
::ecore::EAttribute_ptr IdlmmPackage::getField__identifier()
{
    return m_Field__identifier;
}
::ecore::EAttribute_ptr IdlmmPackage::getFixedDef__digits()
{
    return m_FixedDef__digits;
}
::ecore::EAttribute_ptr IdlmmPackage::getFixedDef__scale()
{
    return m_FixedDef__scale;
}
::ecore::EAttribute_ptr IdlmmPackage::getWstringDef__bound()
{
    return m_WstringDef__bound;
}
::ecore::EAttribute_ptr IdlmmPackage::getStringDef__bound()
{
    return m_StringDef__bound;
}
::ecore::EAttribute_ptr IdlmmPackage::getArrayDef__bound()
{
    return m_ArrayDef__bound;
}
::ecore::EAttribute_ptr IdlmmPackage::getSequenceDef__bound()
{
    return m_SequenceDef__bound;
}
::ecore::EAttribute_ptr IdlmmPackage::getUnionField__identifier()
{
    return m_UnionField__identifier;
}
::ecore::EAttribute_ptr IdlmmPackage::getUnionField__label()
{
    return m_UnionField__label;
}
::ecore::EReference_ptr IdlmmPackage::getUnionDef__unionMembers()
{
    return m_UnionDef__unionMembers;
}
::ecore::EReference_ptr IdlmmPackage::getUnionDef__containedDiscrim()
{
    return m_UnionDef__containedDiscrim;
}
::ecore::EReference_ptr IdlmmPackage::getUnionDef__sharedDiscrim()
{
    return m_UnionDef__sharedDiscrim;
}
::ecore::EAttribute_ptr IdlmmPackage::getEnumDef__members()
{
    return m_EnumDef__members;
}
::ecore::EReference_ptr IdlmmPackage::getStructDef__members()
{
    return m_StructDef__members;
}
::ecore::EReference_ptr IdlmmPackage::getTranslationUnit__contains()
{
    return m_TranslationUnit__contains;
}
::ecore::EAttribute_ptr IdlmmPackage::getTranslationUnit__identifier()
{
    return m_TranslationUnit__identifier;
}
::ecore::EReference_ptr IdlmmPackage::getTranslationUnit__includes()
{
    return m_TranslationUnit__includes;
}
::ecore::EAttribute_ptr IdlmmPackage::getInclude__importURI()
{
    return m_Include__importURI;
}

