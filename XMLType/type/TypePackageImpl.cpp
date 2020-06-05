// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * type/TypePackageImpl.cpp
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

#include <type/TypePackage.hpp>
#include <type/TypeFactory.hpp>
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
#include <ecore/EDataType.hpp>
#include <ecore/EStringToStringMapEntry.hpp>

using namespace ::type;

TypePackage::TypePackage()
{

    // Feature definitions of AnyType
    m_AnyType__mixed = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_AnyType__any = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_AnyType__anyAttribute = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of ProcessingInstruction
    m_ProcessingInstruction__data = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_ProcessingInstruction__target = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);

    // Feature definitions of SimpleAnyType
    m_SimpleAnyType__rawValue = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_SimpleAnyType__value = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_SimpleAnyType__instanceType = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);

    // Feature definitions of XMLTypeDocumentRoot
    m_XMLTypeDocumentRoot__mixed = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_XMLTypeDocumentRoot__cDATA = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_XMLTypeDocumentRoot__comment = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_XMLTypeDocumentRoot__text = ::ecore::Ptr < ::ecore::EAttribute
            > (new ::ecore::EAttribute);
    m_XMLTypeDocumentRoot__xMLNSPrefixMap = ::ecore::Ptr < ::ecore::EReference
            > (new ::ecore::EReference);
    m_XMLTypeDocumentRoot__xSISchemaLocation = ::ecore::Ptr
            < ::ecore::EReference > (new ::ecore::EReference);
    m_XMLTypeDocumentRoot__processingInstruction = ::ecore::Ptr
            < ::ecore::EReference > (new ::ecore::EReference);

}

void TypePackage::_initPackage()
{
    // Factory
    ::ecore::EFactory_ptr _fa = TypeFactory::_instance();
    basicsetEFactoryInstance(_fa);
    _fa->basicsetEPackage(_this());

// Create classes and their features
    auto &classifiers = (::ecorecpp::mapping::ReferenceEListImpl<
            ::ecore::EClassifier_ptr, -1, true, true >&) getEClassifiers();

    { // AnyType
        m_AnyTypeEClass = ::ecore::Ptr < ::ecore::EClass
                > (new ::ecore::EClass);
        m_AnyTypeEClass->setClassifierID(ANYTYPE);
        m_AnyTypeEClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_AnyTypeEClass);
        // m_AnyType__mixed has already been allocated above
        m_AnyType__mixed->setFeatureID(::type::TypePackage::ANYTYPE__MIXED);
        m_AnyType__mixed->setName("mixed");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_AnyTypeEClass->getEStructuralFeatures()).basicAdd(
                m_AnyType__mixed);
        m_AnyType__mixed->basicsetEContainingClass(m_AnyTypeEClass);
        // m_AnyType__any has already been allocated above
        m_AnyType__any->setFeatureID(::type::TypePackage::ANYTYPE__ANY);
        m_AnyType__any->setName("any");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_AnyTypeEClass->getEStructuralFeatures()).basicAdd(
                m_AnyType__any);
        m_AnyType__any->basicsetEContainingClass(m_AnyTypeEClass);
        // m_AnyType__anyAttribute has already been allocated above
        m_AnyType__anyAttribute->setFeatureID(
                ::type::TypePackage::ANYTYPE__ANYATTRIBUTE);
        m_AnyType__anyAttribute->setName("anyAttribute");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_AnyTypeEClass->getEStructuralFeatures()).basicAdd(
                m_AnyType__anyAttribute);
        m_AnyType__anyAttribute->basicsetEContainingClass(m_AnyTypeEClass);
    }

    { // ProcessingInstruction
        m_ProcessingInstructionEClass = ::ecore::Ptr < ::ecore::EClass
                > (new ::ecore::EClass);
        m_ProcessingInstructionEClass->setClassifierID(PROCESSINGINSTRUCTION);
        m_ProcessingInstructionEClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_ProcessingInstructionEClass);
        // m_ProcessingInstruction__data has already been allocated above
        m_ProcessingInstruction__data->setFeatureID(
                ::type::TypePackage::PROCESSINGINSTRUCTION__DATA);
        m_ProcessingInstruction__data->setName("data");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ProcessingInstructionEClass->getEStructuralFeatures()).basicAdd(
                m_ProcessingInstruction__data);
        m_ProcessingInstruction__data->basicsetEContainingClass(
                m_ProcessingInstructionEClass);
        // m_ProcessingInstruction__target has already been allocated above
        m_ProcessingInstruction__target->setFeatureID(
                ::type::TypePackage::PROCESSINGINSTRUCTION__TARGET);
        m_ProcessingInstruction__target->setName("target");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_ProcessingInstructionEClass->getEStructuralFeatures()).basicAdd(
                m_ProcessingInstruction__target);
        m_ProcessingInstruction__target->basicsetEContainingClass(
                m_ProcessingInstructionEClass);
    }

    { // SimpleAnyType
        m_SimpleAnyTypeEClass = ::ecore::Ptr < ::ecore::EClass
                > (new ::ecore::EClass);
        m_SimpleAnyTypeEClass->setClassifierID(SIMPLEANYTYPE);
        m_SimpleAnyTypeEClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_SimpleAnyTypeEClass);
        // m_SimpleAnyType__rawValue has already been allocated above
        m_SimpleAnyType__rawValue->setFeatureID(
                ::type::TypePackage::SIMPLEANYTYPE__RAWVALUE);
        m_SimpleAnyType__rawValue->setName("rawValue");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_SimpleAnyTypeEClass->getEStructuralFeatures()).basicAdd(
                m_SimpleAnyType__rawValue);
        m_SimpleAnyType__rawValue->basicsetEContainingClass(
                m_SimpleAnyTypeEClass);
        // m_SimpleAnyType__value has already been allocated above
        m_SimpleAnyType__value->setFeatureID(
                ::type::TypePackage::SIMPLEANYTYPE__VALUE);
        m_SimpleAnyType__value->setName("value");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_SimpleAnyTypeEClass->getEStructuralFeatures()).basicAdd(
                m_SimpleAnyType__value);
        m_SimpleAnyType__value->basicsetEContainingClass(m_SimpleAnyTypeEClass);
        // m_SimpleAnyType__instanceType has already been allocated above
        m_SimpleAnyType__instanceType->setFeatureID(
                ::type::TypePackage::SIMPLEANYTYPE__INSTANCETYPE);
        m_SimpleAnyType__instanceType->setName("instanceType");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_SimpleAnyTypeEClass->getEStructuralFeatures()).basicAdd(
                m_SimpleAnyType__instanceType);
        m_SimpleAnyType__instanceType->basicsetEContainingClass(
                m_SimpleAnyTypeEClass);
    }

    { // XMLTypeDocumentRoot
        m_XMLTypeDocumentRootEClass = ::ecore::Ptr < ::ecore::EClass
                > (new ::ecore::EClass);
        m_XMLTypeDocumentRootEClass->setClassifierID(XMLTYPEDOCUMENTROOT);
        m_XMLTypeDocumentRootEClass->basicsetEPackage(_this());
        classifiers.basicAdd(m_XMLTypeDocumentRootEClass);
        // m_XMLTypeDocumentRoot__mixed has already been allocated above
        m_XMLTypeDocumentRoot__mixed->setFeatureID(
                ::type::TypePackage::XMLTYPEDOCUMENTROOT__MIXED);
        m_XMLTypeDocumentRoot__mixed->setName("mixed");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_XMLTypeDocumentRootEClass->getEStructuralFeatures()).basicAdd(
                m_XMLTypeDocumentRoot__mixed);
        m_XMLTypeDocumentRoot__mixed->basicsetEContainingClass(
                m_XMLTypeDocumentRootEClass);
        // m_XMLTypeDocumentRoot__xMLNSPrefixMap has already been allocated above
        m_XMLTypeDocumentRoot__xMLNSPrefixMap->setFeatureID(
                ::type::TypePackage::XMLTYPEDOCUMENTROOT__XMLNSPREFIXMAP);
        m_XMLTypeDocumentRoot__xMLNSPrefixMap->setName("xMLNSPrefixMap");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_XMLTypeDocumentRootEClass->getEStructuralFeatures()).basicAdd(
                m_XMLTypeDocumentRoot__xMLNSPrefixMap);
        m_XMLTypeDocumentRoot__xMLNSPrefixMap->basicsetEContainingClass(
                m_XMLTypeDocumentRootEClass);
        // m_XMLTypeDocumentRoot__xSISchemaLocation has already been allocated above
        m_XMLTypeDocumentRoot__xSISchemaLocation->setFeatureID(
                ::type::TypePackage::XMLTYPEDOCUMENTROOT__XSISCHEMALOCATION);
        m_XMLTypeDocumentRoot__xSISchemaLocation->setName("xSISchemaLocation");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_XMLTypeDocumentRootEClass->getEStructuralFeatures()).basicAdd(
                m_XMLTypeDocumentRoot__xSISchemaLocation);
        m_XMLTypeDocumentRoot__xSISchemaLocation->basicsetEContainingClass(
                m_XMLTypeDocumentRootEClass);
        // m_XMLTypeDocumentRoot__cDATA has already been allocated above
        m_XMLTypeDocumentRoot__cDATA->setFeatureID(
                ::type::TypePackage::XMLTYPEDOCUMENTROOT__CDATA);
        m_XMLTypeDocumentRoot__cDATA->setName("cDATA");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_XMLTypeDocumentRootEClass->getEStructuralFeatures()).basicAdd(
                m_XMLTypeDocumentRoot__cDATA);
        m_XMLTypeDocumentRoot__cDATA->basicsetEContainingClass(
                m_XMLTypeDocumentRootEClass);
        // m_XMLTypeDocumentRoot__comment has already been allocated above
        m_XMLTypeDocumentRoot__comment->setFeatureID(
                ::type::TypePackage::XMLTYPEDOCUMENTROOT__COMMENT);
        m_XMLTypeDocumentRoot__comment->setName("comment");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_XMLTypeDocumentRootEClass->getEStructuralFeatures()).basicAdd(
                m_XMLTypeDocumentRoot__comment);
        m_XMLTypeDocumentRoot__comment->basicsetEContainingClass(
                m_XMLTypeDocumentRootEClass);
        // m_XMLTypeDocumentRoot__processingInstruction has already been allocated above
        m_XMLTypeDocumentRoot__processingInstruction->setFeatureID(
                ::type::TypePackage::XMLTYPEDOCUMENTROOT__PROCESSINGINSTRUCTION);
        m_XMLTypeDocumentRoot__processingInstruction->setName(
                "processingInstruction");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_XMLTypeDocumentRootEClass->getEStructuralFeatures()).basicAdd(
                m_XMLTypeDocumentRoot__processingInstruction);
        m_XMLTypeDocumentRoot__processingInstruction->basicsetEContainingClass(
                m_XMLTypeDocumentRootEClass);
        // m_XMLTypeDocumentRoot__text has already been allocated above
        m_XMLTypeDocumentRoot__text->setFeatureID(
                ::type::TypePackage::XMLTYPEDOCUMENTROOT__TEXT);
        m_XMLTypeDocumentRoot__text->setName("text");
        static_cast< ::ecorecpp::mapping::ReferenceEListImpl<
                ::ecore::EStructuralFeature_ptr, -1, true, true >& >(m_XMLTypeDocumentRootEClass->getEStructuralFeatures()).basicAdd(
                m_XMLTypeDocumentRoot__text);
        m_XMLTypeDocumentRoot__text->basicsetEContainingClass(
                m_XMLTypeDocumentRootEClass);
    }

    // Create enums

    // Create data types

    { // AnySimpleType
        m_AnySimpleTypeEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_AnySimpleTypeEDataType->setClassifierID(ANYSIMPLETYPE);
        m_AnySimpleTypeEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_AnySimpleTypeEDataType);
    }

    { // AnyURI
        m_AnyURIEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_AnyURIEDataType->setClassifierID(ANYURI);
        m_AnyURIEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_AnyURIEDataType);
    }

    { // Base64Binary
        m_Base64BinaryEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_Base64BinaryEDataType->setClassifierID(BASE64BINARY);
        m_Base64BinaryEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_Base64BinaryEDataType);
    }

    { // Boolean
        m_BooleanEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_BooleanEDataType->setClassifierID(BOOLEAN);
        m_BooleanEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_BooleanEDataType);
    }

    { // BooleanObject
        m_BooleanObjectEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_BooleanObjectEDataType->setClassifierID(BOOLEANOBJECT);
        m_BooleanObjectEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_BooleanObjectEDataType);
    }

    { // Byte
        m_ByteEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_ByteEDataType->setClassifierID(BYTE);
        m_ByteEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_ByteEDataType);
    }

    { // ByteObject
        m_ByteObjectEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_ByteObjectEDataType->setClassifierID(BYTEOBJECT);
        m_ByteObjectEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_ByteObjectEDataType);
    }

    { // Date
        m_DateEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_DateEDataType->setClassifierID(DATE);
        m_DateEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_DateEDataType);
    }

    { // DateTime
        m_DateTimeEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_DateTimeEDataType->setClassifierID(DATETIME);
        m_DateTimeEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_DateTimeEDataType);
    }

    { // Decimal
        m_DecimalEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_DecimalEDataType->setClassifierID(DECIMAL);
        m_DecimalEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_DecimalEDataType);
    }

    { // Double
        m_DoubleEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_DoubleEDataType->setClassifierID(DOUBLE);
        m_DoubleEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_DoubleEDataType);
    }

    { // DoubleObject
        m_DoubleObjectEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_DoubleObjectEDataType->setClassifierID(DOUBLEOBJECT);
        m_DoubleObjectEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_DoubleObjectEDataType);
    }

    { // Duration
        m_DurationEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_DurationEDataType->setClassifierID(DURATION);
        m_DurationEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_DurationEDataType);
    }

    { // ENTITIES
        m_ENTITIESEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_ENTITIESEDataType->setClassifierID(ENTITIES);
        m_ENTITIESEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_ENTITIESEDataType);
    }

    { // ENTITIESBase
        m_ENTITIESBaseEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_ENTITIESBaseEDataType->setClassifierID(ENTITIESBASE);
        m_ENTITIESBaseEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_ENTITIESBaseEDataType);
    }

    { // ENTITY
        m_ENTITYEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_ENTITYEDataType->setClassifierID(ENTITY);
        m_ENTITYEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_ENTITYEDataType);
    }

    { // Float
        m_FloatEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_FloatEDataType->setClassifierID(FLOAT);
        m_FloatEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_FloatEDataType);
    }

    { // FloatObject
        m_FloatObjectEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_FloatObjectEDataType->setClassifierID(FLOATOBJECT);
        m_FloatObjectEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_FloatObjectEDataType);
    }

    { // GDay
        m_GDayEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_GDayEDataType->setClassifierID(GDAY);
        m_GDayEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_GDayEDataType);
    }

    { // GMonth
        m_GMonthEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_GMonthEDataType->setClassifierID(GMONTH);
        m_GMonthEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_GMonthEDataType);
    }

    { // GMonthDay
        m_GMonthDayEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_GMonthDayEDataType->setClassifierID(GMONTHDAY);
        m_GMonthDayEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_GMonthDayEDataType);
    }

    { // GYear
        m_GYearEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_GYearEDataType->setClassifierID(GYEAR);
        m_GYearEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_GYearEDataType);
    }

    { // GYearMonth
        m_GYearMonthEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_GYearMonthEDataType->setClassifierID(GYEARMONTH);
        m_GYearMonthEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_GYearMonthEDataType);
    }

    { // HexBinary
        m_HexBinaryEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_HexBinaryEDataType->setClassifierID(HEXBINARY);
        m_HexBinaryEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_HexBinaryEDataType);
    }

    { // ID
        m_IDEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_IDEDataType->setClassifierID(ID);
        m_IDEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_IDEDataType);
    }

    { // IDREF
        m_IDREFEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_IDREFEDataType->setClassifierID(IDREF);
        m_IDREFEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_IDREFEDataType);
    }

    { // IDREFS
        m_IDREFSEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_IDREFSEDataType->setClassifierID(IDREFS);
        m_IDREFSEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_IDREFSEDataType);
    }

    { // IDREFSBase
        m_IDREFSBaseEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_IDREFSBaseEDataType->setClassifierID(IDREFSBASE);
        m_IDREFSBaseEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_IDREFSBaseEDataType);
    }

    { // Int
        m_IntEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_IntEDataType->setClassifierID(INT);
        m_IntEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_IntEDataType);
    }

    { // Integer
        m_IntegerEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_IntegerEDataType->setClassifierID(INTEGER);
        m_IntegerEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_IntegerEDataType);
    }

    { // IntObject
        m_IntObjectEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_IntObjectEDataType->setClassifierID(INTOBJECT);
        m_IntObjectEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_IntObjectEDataType);
    }

    { // Language
        m_LanguageEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_LanguageEDataType->setClassifierID(LANGUAGE);
        m_LanguageEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_LanguageEDataType);
    }

    { // Long
        m_LongEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_LongEDataType->setClassifierID(LONG);
        m_LongEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_LongEDataType);
    }

    { // LongObject
        m_LongObjectEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_LongObjectEDataType->setClassifierID(LONGOBJECT);
        m_LongObjectEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_LongObjectEDataType);
    }

    { // Name
        m_NameEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_NameEDataType->setClassifierID(NAME);
        m_NameEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_NameEDataType);
    }

    { // NCName
        m_NCNameEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_NCNameEDataType->setClassifierID(NCNAME);
        m_NCNameEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_NCNameEDataType);
    }

    { // NegativeInteger
        m_NegativeIntegerEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_NegativeIntegerEDataType->setClassifierID(NEGATIVEINTEGER);
        m_NegativeIntegerEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_NegativeIntegerEDataType);
    }

    { // NMTOKEN
        m_NMTOKENEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_NMTOKENEDataType->setClassifierID(NMTOKEN);
        m_NMTOKENEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_NMTOKENEDataType);
    }

    { // NMTOKENS
        m_NMTOKENSEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_NMTOKENSEDataType->setClassifierID(NMTOKENS);
        m_NMTOKENSEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_NMTOKENSEDataType);
    }

    { // NMTOKENSBase
        m_NMTOKENSBaseEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_NMTOKENSBaseEDataType->setClassifierID(NMTOKENSBASE);
        m_NMTOKENSBaseEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_NMTOKENSBaseEDataType);
    }

    { // NonNegativeInteger
        m_NonNegativeIntegerEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_NonNegativeIntegerEDataType->setClassifierID(NONNEGATIVEINTEGER);
        m_NonNegativeIntegerEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_NonNegativeIntegerEDataType);
    }

    { // NonPositiveInteger
        m_NonPositiveIntegerEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_NonPositiveIntegerEDataType->setClassifierID(NONPOSITIVEINTEGER);
        m_NonPositiveIntegerEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_NonPositiveIntegerEDataType);
    }

    { // NormalizedString
        m_NormalizedStringEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_NormalizedStringEDataType->setClassifierID(NORMALIZEDSTRING);
        m_NormalizedStringEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_NormalizedStringEDataType);
    }

    { // NOTATION
        m_NOTATIONEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_NOTATIONEDataType->setClassifierID(NOTATION);
        m_NOTATIONEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_NOTATIONEDataType);
    }

    { // PositiveInteger
        m_PositiveIntegerEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_PositiveIntegerEDataType->setClassifierID(POSITIVEINTEGER);
        m_PositiveIntegerEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_PositiveIntegerEDataType);
    }

    { // QName
        m_QNameEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_QNameEDataType->setClassifierID(QNAME);
        m_QNameEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_QNameEDataType);
    }

    { // Short
        m_ShortEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_ShortEDataType->setClassifierID(SHORT);
        m_ShortEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_ShortEDataType);
    }

    { // ShortObject
        m_ShortObjectEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_ShortObjectEDataType->setClassifierID(SHORTOBJECT);
        m_ShortObjectEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_ShortObjectEDataType);
    }

    { // String
        m_StringEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_StringEDataType->setClassifierID(STRING);
        m_StringEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_StringEDataType);
    }

    { // Time
        m_TimeEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_TimeEDataType->setClassifierID(TIME);
        m_TimeEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_TimeEDataType);
    }

    { // Token
        m_TokenEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_TokenEDataType->setClassifierID(TOKEN);
        m_TokenEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_TokenEDataType);
    }

    { // UnsignedByte
        m_UnsignedByteEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_UnsignedByteEDataType->setClassifierID(UNSIGNEDBYTE);
        m_UnsignedByteEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_UnsignedByteEDataType);
    }

    { // UnsignedByteObject
        m_UnsignedByteObjectEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_UnsignedByteObjectEDataType->setClassifierID(UNSIGNEDBYTEOBJECT);
        m_UnsignedByteObjectEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_UnsignedByteObjectEDataType);
    }

    { // UnsignedInt
        m_UnsignedIntEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_UnsignedIntEDataType->setClassifierID(UNSIGNEDINT);
        m_UnsignedIntEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_UnsignedIntEDataType);
    }

    { // UnsignedIntObject
        m_UnsignedIntObjectEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_UnsignedIntObjectEDataType->setClassifierID(UNSIGNEDINTOBJECT);
        m_UnsignedIntObjectEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_UnsignedIntObjectEDataType);
    }

    { // UnsignedLong
        m_UnsignedLongEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_UnsignedLongEDataType->setClassifierID(UNSIGNEDLONG);
        m_UnsignedLongEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_UnsignedLongEDataType);
    }

    { // UnsignedShort
        m_UnsignedShortEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_UnsignedShortEDataType->setClassifierID(UNSIGNEDSHORT);
        m_UnsignedShortEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_UnsignedShortEDataType);
    }

    { // UnsignedShortObject
        m_UnsignedShortObjectEDataType = ::ecore::Ptr < ::ecore::EDataType
                > (new ::ecore::EDataType);
        m_UnsignedShortObjectEDataType->setClassifierID(UNSIGNEDSHORTOBJECT);
        m_UnsignedShortObjectEDataType->basicsetEPackage(_this());
        classifiers.basicAdd(m_UnsignedShortObjectEDataType);
    }

    // Initialize package
    setName("type");
    setNsPrefix("ecore.xml.type");
    setNsURI("http://www.eclipse.org/emf/2003/XMLType");

    // TODO: bounds for type parameters

    // Add supertypes to classes
    m_SimpleAnyTypeEClass->getESuperTypes().push_back(m_AnyTypeEClass);

    // TODO: Initialize classes and features; add operations and parameters
    // TODO: GenericTypes
    { // AnyType
        m_AnyTypeEClass->setName("AnyType");
        m_AnyTypeEClass->setAbstract(false);
        m_AnyTypeEClass->setInterface(false);
        m_AnyType__mixed->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEFeatureMapEntry());
        m_AnyType__mixed->setDefaultValueLiteral("");
        m_AnyType__mixed->setLowerBound(0);
        m_AnyType__mixed->setUpperBound(-1);
        m_AnyType__mixed->setTransient(false);
        m_AnyType__mixed->setVolatile(false);
        m_AnyType__mixed->setChangeable(true);
        m_AnyType__mixed->setUnsettable(false);
        m_AnyType__mixed->setID(false);
        m_AnyType__mixed->setUnique(false);
        m_AnyType__mixed->setDerived(false);
        m_AnyType__mixed->setOrdered(true);
        m_AnyType__any->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEFeatureMapEntry());
        m_AnyType__any->setDefaultValueLiteral("");
        m_AnyType__any->setLowerBound(0);
        m_AnyType__any->setUpperBound(-1);
        m_AnyType__any->setTransient(true);
        m_AnyType__any->setVolatile(true);
        m_AnyType__any->setChangeable(true);
        m_AnyType__any->setUnsettable(false);
        m_AnyType__any->setID(false);
        m_AnyType__any->setUnique(false);
        m_AnyType__any->setDerived(true);
        m_AnyType__any->setOrdered(true);
        m_AnyType__anyAttribute->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEFeatureMapEntry());
        m_AnyType__anyAttribute->setDefaultValueLiteral("");
        m_AnyType__anyAttribute->setLowerBound(0);
        m_AnyType__anyAttribute->setUpperBound(-1);
        m_AnyType__anyAttribute->setTransient(false);
        m_AnyType__anyAttribute->setVolatile(false);
        m_AnyType__anyAttribute->setChangeable(true);
        m_AnyType__anyAttribute->setUnsettable(false);
        m_AnyType__anyAttribute->setID(false);
        m_AnyType__anyAttribute->setUnique(false);
        m_AnyType__anyAttribute->setDerived(false);
        m_AnyType__anyAttribute->setOrdered(true);

    }

    { // ProcessingInstruction
        m_ProcessingInstructionEClass->setName("ProcessingInstruction");
        m_ProcessingInstructionEClass->setAbstract(false);
        m_ProcessingInstructionEClass->setInterface(false);
        m_ProcessingInstruction__data->setEType(m_StringEDataType);
        m_ProcessingInstruction__data->setDefaultValueLiteral("");
        m_ProcessingInstruction__data->setLowerBound(0);
        m_ProcessingInstruction__data->setUpperBound(1);
        m_ProcessingInstruction__data->setTransient(false);
        m_ProcessingInstruction__data->setVolatile(false);
        m_ProcessingInstruction__data->setChangeable(true);
        m_ProcessingInstruction__data->setUnsettable(false);
        m_ProcessingInstruction__data->setID(false);
        m_ProcessingInstruction__data->setUnique(true);
        m_ProcessingInstruction__data->setDerived(false);
        m_ProcessingInstruction__data->setOrdered(true);
        m_ProcessingInstruction__target->setEType(m_StringEDataType);
        m_ProcessingInstruction__target->setDefaultValueLiteral("");
        m_ProcessingInstruction__target->setLowerBound(1);
        m_ProcessingInstruction__target->setUpperBound(1);
        m_ProcessingInstruction__target->setTransient(false);
        m_ProcessingInstruction__target->setVolatile(false);
        m_ProcessingInstruction__target->setChangeable(true);
        m_ProcessingInstruction__target->setUnsettable(false);
        m_ProcessingInstruction__target->setID(false);
        m_ProcessingInstruction__target->setUnique(true);
        m_ProcessingInstruction__target->setDerived(false);
        m_ProcessingInstruction__target->setOrdered(true);

    }

    { // SimpleAnyType
        m_SimpleAnyTypeEClass->setName("SimpleAnyType");
        m_SimpleAnyTypeEClass->setAbstract(false);
        m_SimpleAnyTypeEClass->setInterface(false);
        m_SimpleAnyType__rawValue->setEType(m_StringEDataType);
        m_SimpleAnyType__rawValue->setDefaultValueLiteral("");
        m_SimpleAnyType__rawValue->setLowerBound(0);
        m_SimpleAnyType__rawValue->setUpperBound(1);
        m_SimpleAnyType__rawValue->setTransient(true);
        m_SimpleAnyType__rawValue->setVolatile(true);
        m_SimpleAnyType__rawValue->setChangeable(true);
        m_SimpleAnyType__rawValue->setUnsettable(false);
        m_SimpleAnyType__rawValue->setID(false);
        m_SimpleAnyType__rawValue->setUnique(true);
        m_SimpleAnyType__rawValue->setDerived(true);
        m_SimpleAnyType__rawValue->setOrdered(true);
        m_SimpleAnyType__value->setEType(m_AnySimpleTypeEDataType);
        m_SimpleAnyType__value->setDefaultValueLiteral("");
        m_SimpleAnyType__value->setLowerBound(0);
        m_SimpleAnyType__value->setUpperBound(1);
        m_SimpleAnyType__value->setTransient(true);
        m_SimpleAnyType__value->setVolatile(true);
        m_SimpleAnyType__value->setChangeable(true);
        m_SimpleAnyType__value->setUnsettable(false);
        m_SimpleAnyType__value->setID(false);
        m_SimpleAnyType__value->setUnique(true);
        m_SimpleAnyType__value->setDerived(true);
        m_SimpleAnyType__value->setOrdered(true);

        m_SimpleAnyType__instanceType->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEDataType());
        m_SimpleAnyType__instanceType->setDefaultValueLiteral("");
        m_SimpleAnyType__instanceType->setLowerBound(1);
        m_SimpleAnyType__instanceType->setUpperBound(1);
        m_SimpleAnyType__instanceType->setTransient(false);
        m_SimpleAnyType__instanceType->setVolatile(false);
        m_SimpleAnyType__instanceType->setChangeable(true);
        m_SimpleAnyType__instanceType->setContainment(false);
        m_SimpleAnyType__instanceType->setResolveProxies(false);
        m_SimpleAnyType__instanceType->setUnique(true);
        m_SimpleAnyType__instanceType->setDerived(false);
        m_SimpleAnyType__instanceType->setOrdered(true);

    }

    { // XMLTypeDocumentRoot
        m_XMLTypeDocumentRootEClass->setName("XMLTypeDocumentRoot");
        m_XMLTypeDocumentRootEClass->setAbstract(false);
        m_XMLTypeDocumentRootEClass->setInterface(false);
        m_XMLTypeDocumentRoot__mixed->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEFeatureMapEntry());
        m_XMLTypeDocumentRoot__mixed->setDefaultValueLiteral("");
        m_XMLTypeDocumentRoot__mixed->setLowerBound(0);
        m_XMLTypeDocumentRoot__mixed->setUpperBound(-1);
        m_XMLTypeDocumentRoot__mixed->setTransient(false);
        m_XMLTypeDocumentRoot__mixed->setVolatile(false);
        m_XMLTypeDocumentRoot__mixed->setChangeable(true);
        m_XMLTypeDocumentRoot__mixed->setUnsettable(false);
        m_XMLTypeDocumentRoot__mixed->setID(false);
        m_XMLTypeDocumentRoot__mixed->setUnique(false);
        m_XMLTypeDocumentRoot__mixed->setDerived(false);
        m_XMLTypeDocumentRoot__mixed->setOrdered(true);
        m_XMLTypeDocumentRoot__cDATA->setEType(m_StringEDataType);
        m_XMLTypeDocumentRoot__cDATA->setDefaultValueLiteral("");
        m_XMLTypeDocumentRoot__cDATA->setLowerBound(0);
        m_XMLTypeDocumentRoot__cDATA->setUpperBound(-2);
        m_XMLTypeDocumentRoot__cDATA->setTransient(true);
        m_XMLTypeDocumentRoot__cDATA->setVolatile(true);
        m_XMLTypeDocumentRoot__cDATA->setChangeable(true);
        m_XMLTypeDocumentRoot__cDATA->setUnsettable(false);
        m_XMLTypeDocumentRoot__cDATA->setID(false);
        m_XMLTypeDocumentRoot__cDATA->setUnique(false);
        m_XMLTypeDocumentRoot__cDATA->setDerived(true);
        m_XMLTypeDocumentRoot__cDATA->setOrdered(true);
        m_XMLTypeDocumentRoot__comment->setEType(m_StringEDataType);
        m_XMLTypeDocumentRoot__comment->setDefaultValueLiteral("");
        m_XMLTypeDocumentRoot__comment->setLowerBound(0);
        m_XMLTypeDocumentRoot__comment->setUpperBound(-2);
        m_XMLTypeDocumentRoot__comment->setTransient(true);
        m_XMLTypeDocumentRoot__comment->setVolatile(true);
        m_XMLTypeDocumentRoot__comment->setChangeable(true);
        m_XMLTypeDocumentRoot__comment->setUnsettable(false);
        m_XMLTypeDocumentRoot__comment->setID(false);
        m_XMLTypeDocumentRoot__comment->setUnique(false);
        m_XMLTypeDocumentRoot__comment->setDerived(true);
        m_XMLTypeDocumentRoot__comment->setOrdered(true);
        m_XMLTypeDocumentRoot__text->setEType(m_StringEDataType);
        m_XMLTypeDocumentRoot__text->setDefaultValueLiteral("");
        m_XMLTypeDocumentRoot__text->setLowerBound(0);
        m_XMLTypeDocumentRoot__text->setUpperBound(-2);
        m_XMLTypeDocumentRoot__text->setTransient(true);
        m_XMLTypeDocumentRoot__text->setVolatile(true);
        m_XMLTypeDocumentRoot__text->setChangeable(true);
        m_XMLTypeDocumentRoot__text->setUnsettable(false);
        m_XMLTypeDocumentRoot__text->setID(false);
        m_XMLTypeDocumentRoot__text->setUnique(false);
        m_XMLTypeDocumentRoot__text->setDerived(true);
        m_XMLTypeDocumentRoot__text->setOrdered(true);

        m_XMLTypeDocumentRoot__xMLNSPrefixMap->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEStringToStringMapEntry());
        m_XMLTypeDocumentRoot__xMLNSPrefixMap->setDefaultValueLiteral("");
        m_XMLTypeDocumentRoot__xMLNSPrefixMap->setLowerBound(0);
        m_XMLTypeDocumentRoot__xMLNSPrefixMap->setUpperBound(-1);
        m_XMLTypeDocumentRoot__xMLNSPrefixMap->setTransient(true);
        m_XMLTypeDocumentRoot__xMLNSPrefixMap->setVolatile(false);
        m_XMLTypeDocumentRoot__xMLNSPrefixMap->setChangeable(true);
        m_XMLTypeDocumentRoot__xMLNSPrefixMap->setContainment(true);
        m_XMLTypeDocumentRoot__xMLNSPrefixMap->setResolveProxies(false);
        m_XMLTypeDocumentRoot__xMLNSPrefixMap->setUnique(true);
        m_XMLTypeDocumentRoot__xMLNSPrefixMap->setDerived(false);
        m_XMLTypeDocumentRoot__xMLNSPrefixMap->setOrdered(true);
        m_XMLTypeDocumentRoot__xSISchemaLocation->setEType(
                dynamic_cast< ::ecore::EcorePackage* >(::ecore::EcorePackage::_instance().get())->getEStringToStringMapEntry());
        m_XMLTypeDocumentRoot__xSISchemaLocation->setDefaultValueLiteral("");
        m_XMLTypeDocumentRoot__xSISchemaLocation->setLowerBound(0);
        m_XMLTypeDocumentRoot__xSISchemaLocation->setUpperBound(-1);
        m_XMLTypeDocumentRoot__xSISchemaLocation->setTransient(true);
        m_XMLTypeDocumentRoot__xSISchemaLocation->setVolatile(false);
        m_XMLTypeDocumentRoot__xSISchemaLocation->setChangeable(true);
        m_XMLTypeDocumentRoot__xSISchemaLocation->setContainment(true);
        m_XMLTypeDocumentRoot__xSISchemaLocation->setResolveProxies(false);
        m_XMLTypeDocumentRoot__xSISchemaLocation->setUnique(true);
        m_XMLTypeDocumentRoot__xSISchemaLocation->setDerived(false);
        m_XMLTypeDocumentRoot__xSISchemaLocation->setOrdered(true);
        m_XMLTypeDocumentRoot__processingInstruction->setEType(
                m_ProcessingInstructionEClass);
        m_XMLTypeDocumentRoot__processingInstruction->setDefaultValueLiteral(
                "");
        m_XMLTypeDocumentRoot__processingInstruction->setLowerBound(0);
        m_XMLTypeDocumentRoot__processingInstruction->setUpperBound(-2);
        m_XMLTypeDocumentRoot__processingInstruction->setTransient(true);
        m_XMLTypeDocumentRoot__processingInstruction->setVolatile(true);
        m_XMLTypeDocumentRoot__processingInstruction->setChangeable(true);
        m_XMLTypeDocumentRoot__processingInstruction->setContainment(true);
        m_XMLTypeDocumentRoot__processingInstruction->setResolveProxies(false);
        m_XMLTypeDocumentRoot__processingInstruction->setUnique(true);
        m_XMLTypeDocumentRoot__processingInstruction->setDerived(true);
        m_XMLTypeDocumentRoot__processingInstruction->setOrdered(true);

    }

    // TODO: Initialize data types

    { // AnySimpleType
        m_AnySimpleTypeEDataType->setName("AnySimpleType");
        m_AnySimpleTypeEDataType->setSerializable(true);
    }

    { // AnyURI
        m_AnyURIEDataType->setName("AnyURI");
        m_AnyURIEDataType->setSerializable(true);
    }

    { // Base64Binary
        m_Base64BinaryEDataType->setName("Base64Binary");
        m_Base64BinaryEDataType->setSerializable(true);
    }

    { // Boolean
        m_BooleanEDataType->setName("Boolean");
        m_BooleanEDataType->setSerializable(true);
    }

    { // BooleanObject
        m_BooleanObjectEDataType->setName("BooleanObject");
        m_BooleanObjectEDataType->setSerializable(true);
    }

    { // Byte
        m_ByteEDataType->setName("Byte");
        m_ByteEDataType->setSerializable(true);
    }

    { // ByteObject
        m_ByteObjectEDataType->setName("ByteObject");
        m_ByteObjectEDataType->setSerializable(true);
    }

    { // Date
        m_DateEDataType->setName("Date");
        m_DateEDataType->setSerializable(true);
    }

    { // DateTime
        m_DateTimeEDataType->setName("DateTime");
        m_DateTimeEDataType->setSerializable(true);
    }

    { // Decimal
        m_DecimalEDataType->setName("Decimal");
        m_DecimalEDataType->setSerializable(true);
    }

    { // Double
        m_DoubleEDataType->setName("Double");
        m_DoubleEDataType->setSerializable(true);
    }

    { // DoubleObject
        m_DoubleObjectEDataType->setName("DoubleObject");
        m_DoubleObjectEDataType->setSerializable(true);
    }

    { // Duration
        m_DurationEDataType->setName("Duration");
        m_DurationEDataType->setSerializable(true);
    }

    { // ENTITIES
        m_ENTITIESEDataType->setName("ENTITIES");
        m_ENTITIESEDataType->setSerializable(true);
    }

    { // ENTITIESBase
        m_ENTITIESBaseEDataType->setName("ENTITIESBase");
        m_ENTITIESBaseEDataType->setSerializable(true);
    }

    { // ENTITY
        m_ENTITYEDataType->setName("ENTITY");
        m_ENTITYEDataType->setSerializable(true);
    }

    { // Float
        m_FloatEDataType->setName("Float");
        m_FloatEDataType->setSerializable(true);
    }

    { // FloatObject
        m_FloatObjectEDataType->setName("FloatObject");
        m_FloatObjectEDataType->setSerializable(true);
    }

    { // GDay
        m_GDayEDataType->setName("GDay");
        m_GDayEDataType->setSerializable(true);
    }

    { // GMonth
        m_GMonthEDataType->setName("GMonth");
        m_GMonthEDataType->setSerializable(true);
    }

    { // GMonthDay
        m_GMonthDayEDataType->setName("GMonthDay");
        m_GMonthDayEDataType->setSerializable(true);
    }

    { // GYear
        m_GYearEDataType->setName("GYear");
        m_GYearEDataType->setSerializable(true);
    }

    { // GYearMonth
        m_GYearMonthEDataType->setName("GYearMonth");
        m_GYearMonthEDataType->setSerializable(true);
    }

    { // HexBinary
        m_HexBinaryEDataType->setName("HexBinary");
        m_HexBinaryEDataType->setSerializable(true);
    }

    { // ID
        m_IDEDataType->setName("ID");
        m_IDEDataType->setSerializable(true);
    }

    { // IDREF
        m_IDREFEDataType->setName("IDREF");
        m_IDREFEDataType->setSerializable(true);
    }

    { // IDREFS
        m_IDREFSEDataType->setName("IDREFS");
        m_IDREFSEDataType->setSerializable(true);
    }

    { // IDREFSBase
        m_IDREFSBaseEDataType->setName("IDREFSBase");
        m_IDREFSBaseEDataType->setSerializable(true);
    }

    { // Int
        m_IntEDataType->setName("Int");
        m_IntEDataType->setSerializable(true);
    }

    { // Integer
        m_IntegerEDataType->setName("Integer");
        m_IntegerEDataType->setSerializable(true);
    }

    { // IntObject
        m_IntObjectEDataType->setName("IntObject");
        m_IntObjectEDataType->setSerializable(true);
    }

    { // Language
        m_LanguageEDataType->setName("Language");
        m_LanguageEDataType->setSerializable(true);
    }

    { // Long
        m_LongEDataType->setName("Long");
        m_LongEDataType->setSerializable(true);
    }

    { // LongObject
        m_LongObjectEDataType->setName("LongObject");
        m_LongObjectEDataType->setSerializable(true);
    }

    { // Name
        m_NameEDataType->setName("Name");
        m_NameEDataType->setSerializable(true);
    }

    { // NCName
        m_NCNameEDataType->setName("NCName");
        m_NCNameEDataType->setSerializable(true);
    }

    { // NegativeInteger
        m_NegativeIntegerEDataType->setName("NegativeInteger");
        m_NegativeIntegerEDataType->setSerializable(true);
    }

    { // NMTOKEN
        m_NMTOKENEDataType->setName("NMTOKEN");
        m_NMTOKENEDataType->setSerializable(true);
    }

    { // NMTOKENS
        m_NMTOKENSEDataType->setName("NMTOKENS");
        m_NMTOKENSEDataType->setSerializable(true);
    }

    { // NMTOKENSBase
        m_NMTOKENSBaseEDataType->setName("NMTOKENSBase");
        m_NMTOKENSBaseEDataType->setSerializable(true);
    }

    { // NonNegativeInteger
        m_NonNegativeIntegerEDataType->setName("NonNegativeInteger");
        m_NonNegativeIntegerEDataType->setSerializable(true);
    }

    { // NonPositiveInteger
        m_NonPositiveIntegerEDataType->setName("NonPositiveInteger");
        m_NonPositiveIntegerEDataType->setSerializable(true);
    }

    { // NormalizedString
        m_NormalizedStringEDataType->setName("NormalizedString");
        m_NormalizedStringEDataType->setSerializable(true);
    }

    { // NOTATION
        m_NOTATIONEDataType->setName("NOTATION");
        m_NOTATIONEDataType->setSerializable(true);
    }

    { // PositiveInteger
        m_PositiveIntegerEDataType->setName("PositiveInteger");
        m_PositiveIntegerEDataType->setSerializable(true);
    }

    { // QName
        m_QNameEDataType->setName("QName");
        m_QNameEDataType->setSerializable(true);
    }

    { // Short
        m_ShortEDataType->setName("Short");
        m_ShortEDataType->setSerializable(true);
    }

    { // ShortObject
        m_ShortObjectEDataType->setName("ShortObject");
        m_ShortObjectEDataType->setSerializable(true);
    }

    { // String
        m_StringEDataType->setName("String");
        m_StringEDataType->setSerializable(true);
    }

    { // Time
        m_TimeEDataType->setName("Time");
        m_TimeEDataType->setSerializable(true);
    }

    { // Token
        m_TokenEDataType->setName("Token");
        m_TokenEDataType->setSerializable(true);
    }

    { // UnsignedByte
        m_UnsignedByteEDataType->setName("UnsignedByte");
        m_UnsignedByteEDataType->setSerializable(true);
    }

    { // UnsignedByteObject
        m_UnsignedByteObjectEDataType->setName("UnsignedByteObject");
        m_UnsignedByteObjectEDataType->setSerializable(true);
    }

    { // UnsignedInt
        m_UnsignedIntEDataType->setName("UnsignedInt");
        m_UnsignedIntEDataType->setSerializable(true);
    }

    { // UnsignedIntObject
        m_UnsignedIntObjectEDataType->setName("UnsignedIntObject");
        m_UnsignedIntObjectEDataType->setSerializable(true);
    }

    { // UnsignedLong
        m_UnsignedLongEDataType->setName("UnsignedLong");
        m_UnsignedLongEDataType->setSerializable(true);
    }

    { // UnsignedShort
        m_UnsignedShortEDataType->setName("UnsignedShort");
        m_UnsignedShortEDataType->setSerializable(true);
    }

    { // UnsignedShortObject
        m_UnsignedShortObjectEDataType->setName("UnsignedShortObject");
        m_UnsignedShortObjectEDataType->setSerializable(true);
    }

    /* EAnnotations for EPackage, the EClasses and their EStructuralFeatures */
    ::ecore::EAnnotation_ptr _annotation;

    _annotation = m_AnyTypeEClass->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "anyType");
    _annotation->setDetail("kind", "mixed");

    _annotation = m_AnyType__mixed->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("kind", "elementWildcard");
    _annotation->setDetail("name", ":mixed");

    _annotation = m_AnyType__any->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("kind", "elementWildcard");
    _annotation->setDetail("wildcards", "##any");
    _annotation->setDetail("name", ":1");
    _annotation->setDetail("processing", "lax");

    _annotation = m_AnyType__anyAttribute->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("kind", "attributeWildcard");
    _annotation->setDetail("wildcards", "##any");
    _annotation->setDetail("name", ":2");
    _annotation->setDetail("processing", "lax");

    _annotation = m_ProcessingInstructionEClass->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "processingInstruction_._type");
    _annotation->setDetail("kind", "empty");

    _annotation = m_ProcessingInstruction__data->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("kind", "attribute");
    _annotation->setDetail("name", "data");

    _annotation = m_ProcessingInstruction__target->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("kind", "attribute");
    _annotation->setDetail("name", "target");

    _annotation = m_SimpleAnyTypeEClass->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "simpleAnyType");
    _annotation->setDetail("kind", "simple");

    _annotation = m_SimpleAnyType__rawValue->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", ":3");
    _annotation->setDetail("kind", "simple");

    _annotation = m_SimpleAnyType__value->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", ":4");
    _annotation->setDetail("kind", "simple");

    _annotation = m_SimpleAnyType__instanceType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", ":5");
    _annotation->setDetail("kind", "simple");

    _annotation = m_XMLTypeDocumentRootEClass->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "");
    _annotation->setDetail("kind", "mixed");

    _annotation = m_XMLTypeDocumentRoot__mixed->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("kind", "elementWildcard");
    _annotation->setDetail("name", ":mixed");

    _annotation = m_XMLTypeDocumentRoot__xMLNSPrefixMap->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("kind", "attribute");
    _annotation->setDetail("name", "xmlns:prefix");

    _annotation = m_XMLTypeDocumentRoot__xSISchemaLocation->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("kind", "attribute");
    _annotation->setDetail("name", "xsi:schemaLocation");

    _annotation = m_XMLTypeDocumentRoot__cDATA->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("kind", "element");
    _annotation->setDetail("name", "cDATA");
    _annotation->setDetail("namespace", "##targetNamespace");

    _annotation = m_XMLTypeDocumentRoot__cDATA->getEAnnotation(
            "http://www.eclipse.org/emf/2002/GenModel");
    _annotation->setDetail("suppressedGetVisibility", "true");

    _annotation = m_XMLTypeDocumentRoot__comment->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("kind", "element");
    _annotation->setDetail("name", "comment");
    _annotation->setDetail("namespace", "##targetNamespace");

    _annotation = m_XMLTypeDocumentRoot__comment->getEAnnotation(
            "http://www.eclipse.org/emf/2002/GenModel");
    _annotation->setDetail("suppressedGetVisibility", "true");

    _annotation = m_XMLTypeDocumentRoot__processingInstruction->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("kind", "element");
    _annotation->setDetail("name", "processingInstruction");
    _annotation->setDetail("namespace", "##targetNamespace");

    _annotation = m_XMLTypeDocumentRoot__processingInstruction->getEAnnotation(
            "http://www.eclipse.org/emf/2002/GenModel");
    _annotation->setDetail("suppressedGetVisibility", "true");

    _annotation = m_XMLTypeDocumentRoot__text->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("kind", "element");
    _annotation->setDetail("name", "text");
    _annotation->setDetail("namespace", "##targetNamespace");

    _annotation = m_XMLTypeDocumentRoot__text->getEAnnotation(
            "http://www.eclipse.org/emf/2002/GenModel");
    _annotation->setDetail("suppressedGetVisibility", "true");

    _annotation = m_AnySimpleTypeEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "anySimpleType");

    _annotation = m_AnyURIEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "anyURI");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_Base64BinaryEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "base64Binary");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_BooleanEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "boolean");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_BooleanObjectEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "boolean:Object");
    _annotation->setDetail("baseType", "boolean");

    _annotation = m_ByteEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "byte");

    _annotation = m_ByteObjectEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "byte:Object");
    _annotation->setDetail("baseType", "byte");

    _annotation = m_DateEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "date");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_DateTimeEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "dateTime");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_DecimalEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "decimal");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_DoubleEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "double");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_DoubleObjectEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "double:Object");
    _annotation->setDetail("baseType", "double");

    _annotation = m_DurationEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "duration");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_ENTITIESEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "ENTITIES");
    _annotation->setDetail("baseType", "ENTITIES_._base");
    _annotation->setDetail("minLength", "1");

    _annotation = m_ENTITIESBaseEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "ENTITIES_._base");
    _annotation->setDetail("itemType", "ENTITY");

    _annotation = m_ENTITYEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "ENTITY");
    _annotation->setDetail("baseType", "NCName");

    _annotation = m_FloatEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "float");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_FloatObjectEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "float:Object");
    _annotation->setDetail("baseType", "float");

    _annotation = m_GDayEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "gDay");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_GMonthEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "gMonth");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_GMonthDayEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "gMonthDay");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_GYearEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "gYear");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_GYearMonthEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "gYearMonth");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_HexBinaryEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "hexBinary");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_IDEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "ID");
    _annotation->setDetail("baseType", "NCName");

    _annotation = m_IDREFEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "IDREF");
    _annotation->setDetail("baseType", "NCName");

    _annotation = m_IDREFSEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "IDREFS");
    _annotation->setDetail("baseType", "IDREFS_._base");
    _annotation->setDetail("minLength", "1");

    _annotation = m_IDREFSBaseEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "IDREFS_._base");
    _annotation->setDetail("itemType", "IDREF");

    _annotation = m_IntEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "int");

    _annotation = m_IntegerEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "integer");

    _annotation = m_IntObjectEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "int:Object");
    _annotation->setDetail("baseType", "int");

    _annotation = m_LanguageEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "language");
    _annotation->setDetail("baseType", "token");
    _annotation->setDetail("pattern", "[a-zA-Z]{1,8}(-[a-zA-Z0-9]{1,8})*");

    _annotation = m_LongEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "long");

    _annotation = m_LongObjectEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "long:Object");
    _annotation->setDetail("baseType", "long");

    _annotation = m_NameEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "Name");
    _annotation->setDetail("baseType", "token");
    _annotation->setDetail("pattern", "\\i\\c*");

    _annotation = m_NCNameEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "NCName");
    _annotation->setDetail("baseType", "Name");
    _annotation->setDetail("pattern", "[\\i-[:]][\\c-[:]]*");

    _annotation = m_NegativeIntegerEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "negativeInteger");
    _annotation->setDetail("baseType", "nonPositiveInteger");
    _annotation->setDetail("maxInclusive", "-1");

    _annotation = m_NMTOKENEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "NMTOKEN");
    _annotation->setDetail("baseType", "token");
    _annotation->setDetail("pattern", "\\c+");

    _annotation = m_NMTOKENSEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "NMTOKENS");
    _annotation->setDetail("baseType", "NMTOKENS_._base");
    _annotation->setDetail("minLength", "1");

    _annotation = m_NMTOKENSBaseEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "NMTOKENS_._base");
    _annotation->setDetail("itemType", "NMTOKEN");

    _annotation = m_NonNegativeIntegerEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "nonNegativeInteger");
    _annotation->setDetail("baseType", "integer");
    _annotation->setDetail("minInclusive", "0");

    _annotation = m_NonPositiveIntegerEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "nonPositiveInteger");
    _annotation->setDetail("baseType", "integer");
    _annotation->setDetail("maxInclusive", "0");

    _annotation = m_NormalizedStringEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "normalizedString");
    _annotation->setDetail("baseType", "string");
    _annotation->setDetail("whiteSpace", "replace");

    _annotation = m_NOTATIONEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "NOTATION");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_PositiveIntegerEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "positiveInteger");
    _annotation->setDetail("baseType", "nonNegativeInteger");
    _annotation->setDetail("minInclusive", "1");

    _annotation = m_QNameEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "QName");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_ShortEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "short");

    _annotation = m_ShortObjectEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "short:Object");
    _annotation->setDetail("baseType", "short");

    _annotation = m_StringEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "string");
    _annotation->setDetail("whiteSpace", "preserve");

    _annotation = m_TimeEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "time");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_TokenEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "token");
    _annotation->setDetail("baseType", "normalizedString");
    _annotation->setDetail("whiteSpace", "collapse");

    _annotation = m_UnsignedByteEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "unsignedByte");
    _annotation->setDetail("maxInclusive", "255");
    _annotation->setDetail("minInclusive", "0");

    _annotation = m_UnsignedByteObjectEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "unsignedByte:Object");
    _annotation->setDetail("baseType", "unsignedByte");

    _annotation = m_UnsignedIntEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "unsignedInt");
    _annotation->setDetail("maxInclusive", "4294967295");
    _annotation->setDetail("minInclusive", "0");

    _annotation = m_UnsignedIntObjectEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "unsignedInt:Object");
    _annotation->setDetail("baseType", "unsignedInt");

    _annotation = m_UnsignedLongEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "unsignedLong");
    _annotation->setDetail("baseType", "nonNegativeInteger");
    _annotation->setDetail("maxInclusive", "18446744073709551615");
    _annotation->setDetail("minInclusive", "0");

    _annotation = m_UnsignedShortEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "unsignedShort");
    _annotation->setDetail("maxInclusive", "65535");
    _annotation->setDetail("minInclusive", "0");

    _annotation = m_UnsignedShortObjectEDataType->getEAnnotation(
            "http:///org/eclipse/emf/ecore/util/ExtendedMetaData");
    _annotation->setDetail("name", "unsignedShort:Object");
    _annotation->setDetail("baseType", "unsignedShort");

    _initialize();
}

::ecore::EDataType_ptr TypePackage::getAnySimpleType()
{
    return m_AnySimpleTypeEDataType;
}
::ecore::EClass_ptr TypePackage::getAnyType()
{
    return m_AnyTypeEClass;
}
::ecore::EDataType_ptr TypePackage::getAnyURI()
{
    return m_AnyURIEDataType;
}
::ecore::EDataType_ptr TypePackage::getBase64Binary()
{
    return m_Base64BinaryEDataType;
}
::ecore::EDataType_ptr TypePackage::getBoolean()
{
    return m_BooleanEDataType;
}
::ecore::EDataType_ptr TypePackage::getBooleanObject()
{
    return m_BooleanObjectEDataType;
}
::ecore::EDataType_ptr TypePackage::getByte()
{
    return m_ByteEDataType;
}
::ecore::EDataType_ptr TypePackage::getByteObject()
{
    return m_ByteObjectEDataType;
}
::ecore::EDataType_ptr TypePackage::getDate()
{
    return m_DateEDataType;
}
::ecore::EDataType_ptr TypePackage::getDateTime()
{
    return m_DateTimeEDataType;
}
::ecore::EDataType_ptr TypePackage::getDecimal()
{
    return m_DecimalEDataType;
}
::ecore::EDataType_ptr TypePackage::getDouble()
{
    return m_DoubleEDataType;
}
::ecore::EDataType_ptr TypePackage::getDoubleObject()
{
    return m_DoubleObjectEDataType;
}
::ecore::EDataType_ptr TypePackage::getDuration()
{
    return m_DurationEDataType;
}
::ecore::EDataType_ptr TypePackage::getENTITIES()
{
    return m_ENTITIESEDataType;
}
::ecore::EDataType_ptr TypePackage::getENTITIESBase()
{
    return m_ENTITIESBaseEDataType;
}
::ecore::EDataType_ptr TypePackage::getENTITY()
{
    return m_ENTITYEDataType;
}
::ecore::EDataType_ptr TypePackage::getFloat()
{
    return m_FloatEDataType;
}
::ecore::EDataType_ptr TypePackage::getFloatObject()
{
    return m_FloatObjectEDataType;
}
::ecore::EDataType_ptr TypePackage::getGDay()
{
    return m_GDayEDataType;
}
::ecore::EDataType_ptr TypePackage::getGMonth()
{
    return m_GMonthEDataType;
}
::ecore::EDataType_ptr TypePackage::getGMonthDay()
{
    return m_GMonthDayEDataType;
}
::ecore::EDataType_ptr TypePackage::getGYear()
{
    return m_GYearEDataType;
}
::ecore::EDataType_ptr TypePackage::getGYearMonth()
{
    return m_GYearMonthEDataType;
}
::ecore::EDataType_ptr TypePackage::getHexBinary()
{
    return m_HexBinaryEDataType;
}
::ecore::EDataType_ptr TypePackage::getID()
{
    return m_IDEDataType;
}
::ecore::EDataType_ptr TypePackage::getIDREF()
{
    return m_IDREFEDataType;
}
::ecore::EDataType_ptr TypePackage::getIDREFS()
{
    return m_IDREFSEDataType;
}
::ecore::EDataType_ptr TypePackage::getIDREFSBase()
{
    return m_IDREFSBaseEDataType;
}
::ecore::EDataType_ptr TypePackage::getInt()
{
    return m_IntEDataType;
}
::ecore::EDataType_ptr TypePackage::getInteger()
{
    return m_IntegerEDataType;
}
::ecore::EDataType_ptr TypePackage::getIntObject()
{
    return m_IntObjectEDataType;
}
::ecore::EDataType_ptr TypePackage::getLanguage()
{
    return m_LanguageEDataType;
}
::ecore::EDataType_ptr TypePackage::getLong()
{
    return m_LongEDataType;
}
::ecore::EDataType_ptr TypePackage::getLongObject()
{
    return m_LongObjectEDataType;
}
::ecore::EDataType_ptr TypePackage::getName_()
{
    return m_NameEDataType;
}
::ecore::EDataType_ptr TypePackage::getNCName()
{
    return m_NCNameEDataType;
}
::ecore::EDataType_ptr TypePackage::getNegativeInteger()
{
    return m_NegativeIntegerEDataType;
}
::ecore::EDataType_ptr TypePackage::getNMTOKEN()
{
    return m_NMTOKENEDataType;
}
::ecore::EDataType_ptr TypePackage::getNMTOKENS()
{
    return m_NMTOKENSEDataType;
}
::ecore::EDataType_ptr TypePackage::getNMTOKENSBase()
{
    return m_NMTOKENSBaseEDataType;
}
::ecore::EDataType_ptr TypePackage::getNonNegativeInteger()
{
    return m_NonNegativeIntegerEDataType;
}
::ecore::EDataType_ptr TypePackage::getNonPositiveInteger()
{
    return m_NonPositiveIntegerEDataType;
}
::ecore::EDataType_ptr TypePackage::getNormalizedString()
{
    return m_NormalizedStringEDataType;
}
::ecore::EDataType_ptr TypePackage::getNOTATION()
{
    return m_NOTATIONEDataType;
}
::ecore::EDataType_ptr TypePackage::getPositiveInteger()
{
    return m_PositiveIntegerEDataType;
}
::ecore::EClass_ptr TypePackage::getProcessingInstruction()
{
    return m_ProcessingInstructionEClass;
}
::ecore::EDataType_ptr TypePackage::getQName()
{
    return m_QNameEDataType;
}
::ecore::EDataType_ptr TypePackage::getShort()
{
    return m_ShortEDataType;
}
::ecore::EDataType_ptr TypePackage::getShortObject()
{
    return m_ShortObjectEDataType;
}
::ecore::EClass_ptr TypePackage::getSimpleAnyType()
{
    return m_SimpleAnyTypeEClass;
}
::ecore::EDataType_ptr TypePackage::getString()
{
    return m_StringEDataType;
}
::ecore::EDataType_ptr TypePackage::getTime()
{
    return m_TimeEDataType;
}
::ecore::EDataType_ptr TypePackage::getToken()
{
    return m_TokenEDataType;
}
::ecore::EDataType_ptr TypePackage::getUnsignedByte()
{
    return m_UnsignedByteEDataType;
}
::ecore::EDataType_ptr TypePackage::getUnsignedByteObject()
{
    return m_UnsignedByteObjectEDataType;
}
::ecore::EDataType_ptr TypePackage::getUnsignedInt()
{
    return m_UnsignedIntEDataType;
}
::ecore::EDataType_ptr TypePackage::getUnsignedIntObject()
{
    return m_UnsignedIntObjectEDataType;
}
::ecore::EDataType_ptr TypePackage::getUnsignedLong()
{
    return m_UnsignedLongEDataType;
}
::ecore::EDataType_ptr TypePackage::getUnsignedShort()
{
    return m_UnsignedShortEDataType;
}
::ecore::EDataType_ptr TypePackage::getUnsignedShortObject()
{
    return m_UnsignedShortObjectEDataType;
}
::ecore::EClass_ptr TypePackage::getXMLTypeDocumentRoot()
{
    return m_XMLTypeDocumentRootEClass;
}

::ecore::EAttribute_ptr TypePackage::getAnyType__mixed()
{
    return m_AnyType__mixed;
}
::ecore::EAttribute_ptr TypePackage::getAnyType__any()
{
    return m_AnyType__any;
}
::ecore::EAttribute_ptr TypePackage::getAnyType__anyAttribute()
{
    return m_AnyType__anyAttribute;
}
::ecore::EAttribute_ptr TypePackage::getProcessingInstruction__data()
{
    return m_ProcessingInstruction__data;
}
::ecore::EAttribute_ptr TypePackage::getProcessingInstruction__target()
{
    return m_ProcessingInstruction__target;
}
::ecore::EAttribute_ptr TypePackage::getSimpleAnyType__rawValue()
{
    return m_SimpleAnyType__rawValue;
}
::ecore::EAttribute_ptr TypePackage::getSimpleAnyType__value()
{
    return m_SimpleAnyType__value;
}
::ecore::EReference_ptr TypePackage::getSimpleAnyType__instanceType()
{
    return m_SimpleAnyType__instanceType;
}
::ecore::EAttribute_ptr TypePackage::getXMLTypeDocumentRoot__mixed()
{
    return m_XMLTypeDocumentRoot__mixed;
}
::ecore::EReference_ptr TypePackage::getXMLTypeDocumentRoot__xMLNSPrefixMap()
{
    return m_XMLTypeDocumentRoot__xMLNSPrefixMap;
}
::ecore::EReference_ptr TypePackage::getXMLTypeDocumentRoot__xSISchemaLocation()
{
    return m_XMLTypeDocumentRoot__xSISchemaLocation;
}
::ecore::EAttribute_ptr TypePackage::getXMLTypeDocumentRoot__cDATA()
{
    return m_XMLTypeDocumentRoot__cDATA;
}
::ecore::EAttribute_ptr TypePackage::getXMLTypeDocumentRoot__comment()
{
    return m_XMLTypeDocumentRoot__comment;
}
::ecore::EReference_ptr TypePackage::getXMLTypeDocumentRoot__processingInstruction()
{
    return m_XMLTypeDocumentRoot__processingInstruction;
}
::ecore::EAttribute_ptr TypePackage::getXMLTypeDocumentRoot__text()
{
    return m_XMLTypeDocumentRoot__text;
}

