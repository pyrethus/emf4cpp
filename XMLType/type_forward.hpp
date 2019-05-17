// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * type_forward.hpp
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

#ifndef _TYPE_FORWARD_HPP
#define _TYPE_FORWARD_HPP

#include <ecore_forward.hpp> // for EDataTypes

/*PROTECTED REGION ID(type_forward) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
// Additional headers here
/*PROTECTED REGION END*/

// EPackage

namespace type
{

// EDataType
    /*PROTECTED REGION ID(type_AnySimpleType) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::any AnySimpleType;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_AnyURI) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t AnyURI;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Base64Binary) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t Base64Binary;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Boolean) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef bool Boolean;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_BooleanObject) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef bool BooleanObject;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Byte) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int8_t Byte;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_ByteObject) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int8_t ByteObject;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Date) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::EDate Date;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_DateTime) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::EDate DateTime;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Decimal) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t Decimal;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Double) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef double Double;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_DoubleObject) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef double DoubleObject;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Duration) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int Duration;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_ENTITIES) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecore::EList_ptr< ::ecorecpp::mapping::type_definitions::string_t > ENTITIES;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_ENTITIESBase) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t ENTITIESBase;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_ENTITY) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t ENTITY;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Float) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef float Float;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_FloatObject) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef float FloatObject;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_GDay) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int GDay;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_GMonth) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int GMonth;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_GMonthDay) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int GMonthDay;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_GYear) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int GYear;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_GYearMonth) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int GYearMonth;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_HexBinary) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t HexBinary;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_ID) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t ID;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_IDREF) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t IDREF;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_IDREFS) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecore::EList_ptr< ::ecorecpp::mapping::type_definitions::string_t > IDREFS;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_IDREFSBase) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecore::EList_ptr< ::ecorecpp::mapping::type_definitions::string_t > IDREFSBase;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Int) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int Int;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Integer) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int64_t Integer;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_IntObject) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int IntObject;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Language) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t Language;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Long) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int64_t Long;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_LongObject) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int64_t LongObject;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Name) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t Name;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_NCName) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t NCName;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_NegativeInteger) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int64_t NegativeInteger;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_NMTOKEN) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t NMTOKEN;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_NMTOKENS) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecore::EList_ptr< ::ecorecpp::mapping::type_definitions::string_t > NMTOKENS;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_NMTOKENSBase) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecore::EList_ptr< ::ecorecpp::mapping::type_definitions::string_t > NMTOKENSBase;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_NonNegativeInteger) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef uint64_t NonNegativeInteger;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_NonPositiveInteger) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int64_t NonPositiveInteger;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_NormalizedString) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t NormalizedString;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_NOTATION) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int NOTATION;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_PositiveInteger) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef uint64_t PositiveInteger;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_QName) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t QName;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Short) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int16_t Short;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_ShortObject) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int ShortObject;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_String) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t String;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Time) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef int Time;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_Token) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef ::ecorecpp::mapping::type_definitions::string_t Token;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_UnsignedByte) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef uint8_t UnsignedByte;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_UnsignedByteObject) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef uint8_t UnsignedByteObject;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_UnsignedInt) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef unsigned int UnsignedInt;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_UnsignedIntObject) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef unsigned int UnsignedIntObject;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_UnsignedLong) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef uint64_t UnsignedLong;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_UnsignedShort) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef uint16_t UnsignedShort;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(type_UnsignedShortObject) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
    typedef uint16_t UnsignedShortObject;
    /*PROTECTED REGION END*/

// EClass
// AnyType
    class AnyType;
    using AnyType_ptr = ::ecore::Ptr<AnyType>;

// ProcessingInstruction
    class ProcessingInstruction;
    using ProcessingInstruction_ptr = ::ecore::Ptr<ProcessingInstruction>;

// SimpleAnyType
    class SimpleAnyType;
    using SimpleAnyType_ptr = ::ecore::Ptr<SimpleAnyType>;

// XMLTypeDocumentRoot
    class XMLTypeDocumentRoot;
    using XMLTypeDocumentRoot_ptr = ::ecore::Ptr<XMLTypeDocumentRoot>;

// EEnum

// Package & Factory
    class TypeFactory;
    using TypeFactory_ptr = ::ecore::Ptr<TypeFactory>;
    class TypePackage;
    using TypePackage_ptr = ::ecore::Ptr<TypePackage>;

} // type

#endif // _TYPE_FORWARD_HPP

