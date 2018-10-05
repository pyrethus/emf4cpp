// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * util/ExtendedMetaData.hpp
 * Copyright (C) INCHRON GmbH 2018 <matthias.doerfel@inchron.com>
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

#ifndef ExtendedMetaData_HPP
#define ExtendedMetaData_HPP

#include <ecorecpp/mapping_forward.hpp>
#include <ecorecpp/mapping/EList.hpp>
#include <ecore_forward.hpp>

namespace ecorecpp {
namespace util {

/** ExtendedMetaData is an abstract base class and emulates the interface
 * class org.eclipse.emf.ecore.util.ExtendedMetaData.
 */
class ExtendedMetaData {
protected:
	ExtendedMetaData() = default;
    static ::ecore::Ptr<ExtendedMetaData> s_instance;

    friend void intrusive_ptr_add_ref(ExtendedMetaData* p)
    {   ++p->m_refCount;}
    friend void intrusive_ptr_release(ExtendedMetaData* p)
    {   if (--p->m_refCount == 0u) delete p;}
    /** Maintains the reference counter, which is used by
     * boost::intrusive_ptr<>. */
    mutable std::atomic_size_t m_refCount;

public:
	virtual ~ExtendedMetaData();

    static ::ecore::Ptr<ExtendedMetaData> _instance();

	static const ::ecore::EString ANNOTATION_URI;
	static const ::ecore::EString XMLNS_URI;
	static const ::ecore::EString XML_URI;
	static const ::ecore::EString XSI_URI;
	static const ::ecore::EString XML_SCHEMA_URI;
	static const ::ecore::EString XMI_URI;
	static const ::ecore::EString XMLNS_PREFIX;
	static const ::ecore::EString XSI_PREFIX;

	virtual ::ecore::EPackage_ptr getPackage(::ecore::EString nameSpace) = 0;
	virtual void putPackage(::ecore::EString nameSpace, ::ecore::EPackage_ptr ePackage) = 0;
	virtual ::ecore::EClass_ptr getDocumentRoot(::ecore::EPackage_ptr ePackage) = 0;
	virtual void setDocumentRoot(::ecore::EClass_ptr eClass) = 0;
	virtual bool isDocumentRoot(::ecore::EClass_ptr eClass) = 0;
	virtual ::ecore::EReference_ptr getXMLNSPrefixMapFeature(::ecore::EClass_ptr eClass) = 0;
	virtual ::ecore::EReference_ptr getXSISchemaLocationMapFeature(::ecore::EClass_ptr eClass) = 0;
	virtual bool isQualified(::ecore::EPackage_ptr ePackage) = 0;
	virtual void setQualified(::ecore::EPackage_ptr ePackage, bool isQualified) = 0;
	virtual ::ecore::EString getNamespace(::ecore::EPackage_ptr ePackage) = 0;
	virtual ::ecore::EString getNamespace(::ecore::EClassifier_ptr eClassifier) = 0;
	virtual ::ecore::EString getNamespace(::ecore::EStructuralFeature_ptr eStructuralFeature) = 0;
	virtual void setNamespace(::ecore::EStructuralFeature_ptr eStructuralFeature, ::ecore::EString nameSpace) = 0;
	virtual ::ecore::EString getName(::ecore::EClassifier_ptr eClassifier) = 0;
	virtual void setName(::ecore::EClassifier_ptr eClassifier, ::ecore::EString name) = 0;
	virtual bool isAnonymous(::ecore::EClassifier_ptr eClassifier) = 0;
	virtual ::ecore::EString getName(::ecore::EStructuralFeature_ptr eStructuralFeature) = 0;
	virtual void setName(::ecore::EStructuralFeature_ptr eStructuralFeature, ::ecore::EString name) = 0;
	virtual ::ecore::EClassifier_ptr getType(::ecore::EString nameSpace, ::ecore::EString name) = 0;
	virtual ::ecore::EStructuralFeature_ptr getAttribute(::ecore::EString nameSpace, ::ecore::EString name) = 0;
	virtual ::ecore::EStructuralFeature_ptr getElement(::ecore::EString nameSpace, ::ecore::EString name) = 0;
	virtual ::ecore::EClassifier_ptr getType(::ecore::EPackage_ptr ePackage, ::ecore::EString name) = 0;
	virtual ::ecore::EStructuralFeature_ptr getAttribute(::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name) = 0;
	virtual ::ecore::EStructuralFeature_ptr getElement(::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name) = 0;
	virtual ::ecore::EStructuralFeature_ptr getSimpleFeature(::ecore::EClass_ptr eClass) = 0;
	virtual ::ecore::EAttribute_ptr getMixedFeature(::ecore::EClass_ptr eClass) = 0;

	static const int UNSPECIFIED_FEATURE = 0;
	static const int SIMPLE_FEATURE = 1;
	static const int ATTRIBUTE_FEATURE = 2;
	static const int ATTRIBUTE_WILDCARD_FEATURE = 3;
	static const int ELEMENT_FEATURE = 4;
	static const int ELEMENT_WILDCARD_FEATURE = 5;
	static const int GROUP_FEATURE = 6;
	static const int FEATURE_KINDS_MAX = 7;
	static const ::ecore::EString FEATURE_KINDS[];
	virtual int getFeatureKind(::ecore::EStructuralFeature_ptr eStructuralFeature) = 0;
	virtual void setFeatureKind(::ecore::EStructuralFeature_ptr eStructuralFeature, int kind) = 0;

	static const int UNSPECIFIED_CONTENT = 0;
	static const int EMPTY_CONTENT = 1;
	static const int SIMPLE_CONTENT = 2;
	static const int MIXED_CONTENT = 3;
	static const int ELEMENT_ONLY_CONTENT = 4;
	static const int CONTENT_KINDS_MAX = 5;
	static const ::ecore::EString CONTENT_KINDS[];
	virtual int getContentKind(::ecore::EClass_ptr eClass) = 0;
	virtual void setContentKind(::ecore::EClass_ptr eClass, int kind) = 0;

	static const int UNSPECIFIED_DERIVATION = 0;
	static const int RESTRICTION_DERIVATION = 1;
	static const int LIST_DERIVATION = 2;
	static const int UNION_DERIVATION = 3;
	static const int DERIVATION_KINDS_MAX = 4;
	static const ::ecore::EString DERIVATION_KINDS[];
	virtual int getDerivationKind(::ecore::EDataType_ptr eDataType) = 0;

	virtual ::ecore::EDataType_ptr getBaseType(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setBaseType(::ecore::EDataType_ptr eDataType, ::ecore::EDataType_ptr baseType) = 0;
	virtual ::ecore::EDataType_ptr getItemType(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setItemType(::ecore::EDataType_ptr eDataType, ::ecore::EDataType_ptr itemType) = 0;
	virtual mapping::EList<::ecore::EDataType_ptr>::ptr_type getMemberTypes(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setMemberTypes(::ecore::EDataType_ptr eDataType, const mapping::EList<::ecore::EDataType_ptr>::ptr_type& memberTypes) = 0;
	virtual mapping::EList<::ecore::EStructuralFeature_ptr>::ptr_type getAllAttributes(::ecore::EClass_ptr eClass) = 0;
	virtual mapping::EList<::ecore::EStructuralFeature_ptr>::ptr_type getAllElements(::ecore::EClass_ptr eClass) = 0;
	virtual mapping::EList<::ecore::EStructuralFeature_ptr>::ptr_type getAttributes(::ecore::EClass_ptr eClass) = 0;
	virtual mapping::EList<::ecore::EStructuralFeature_ptr>::ptr_type getElements(::ecore::EClass_ptr eClass) = 0;
	virtual bool matches(const mapping::EList<::ecore::EString>::ptr_type& wildcards, ::ecore::EString nameSpace) = 0;
	virtual bool matches(::ecore::EString wildcard, ::ecore::EString nameSpace) = 0;
	virtual mapping::EList<::ecore::EString>::ptr_type getWildcards(::ecore::EStructuralFeature_ptr eStructuralFeature) = 0;
	virtual void setWildcards(::ecore::EStructuralFeature_ptr eStructuralFeature, const mapping::EList<::ecore::EString>::ptr_type& wildcards) = 0;

	static const int UNSPECIFIED_PROCESSING = 0;
	static const int STRICT_PROCESSING = 1;
	static const int LAX_PROCESSING = 2;
	static const int SKIP_PROCESSING = 3;
	static const int PROCESSING_KINDS_MAX = 4;
	static const ::ecore::EString PROCESSING_KINDS[];
	virtual int getProcessingKind(::ecore::EStructuralFeature_ptr eStructuralFeature) = 0;
	virtual void setProcessingKind(::ecore::EStructuralFeature_ptr eStructuralFeature, int processingKind) = 0;

	virtual ::ecore::EStructuralFeature_ptr getAffiliation(::ecore::EStructuralFeature_ptr eStructuralFeature) = 0;
	virtual void setAffiliation(::ecore::EStructuralFeature_ptr eStructuralFeature, ::ecore::EStructuralFeature_ptr affiliation) = 0;
	virtual ::ecore::EStructuralFeature_ptr getGroup(::ecore::EStructuralFeature_ptr eStructuralFeature) = 0;
	virtual void setGroup(::ecore::EStructuralFeature_ptr eStructuralFeature, ::ecore::EStructuralFeature_ptr group) = 0;
	virtual ::ecore::EStructuralFeature_ptr getAffiliation(::ecore::EClass_ptr eClass, ::ecore::EStructuralFeature_ptr eStructuralFeature) = 0;
	virtual ::ecore::EStructuralFeature_ptr getAttributeWildcardAffiliation(::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name) = 0;
	virtual ::ecore::EStructuralFeature_ptr getElementWildcardAffiliation(::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name) = 0;

	static const int UNSPECIFIED_WHITE_SPACE = 0;
	static const int PRESERVE_WHITE_SPACE = 1;
	static const int REPLACE_WHITE_SPACE = 2;
	static const int COLLAPSE_WHITE_SPACE = 3;
	static const int WHITE_SPACE_KINDS_MAX = 4;
	static const ::ecore::EString WHITE_SPACE_KINDS[];
	virtual int getWhiteSpaceFacet(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setWhiteSpaceFacet(::ecore::EDataType_ptr eDataType, int whiteSpace) = 0;

	virtual mapping::EList<::ecore::EString>::ptr_type getEnumerationFacet(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setEnumerationFacet(::ecore::EDataType_ptr eDataType, const mapping::EList<::ecore::EString>::ptr_type& literals) = 0;
	virtual mapping::EList<::ecore::EString>::ptr_type getPatternFacet(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setPatternFacet(::ecore::EDataType_ptr eDataType, const mapping::EList<::ecore::EString>::ptr_type& pattern) = 0;
	virtual int getTotalDigitsFacet(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setTotalDigitsFacet(::ecore::EDataType_ptr eDataType, int digits) = 0;
	virtual int getFractionDigitsFacet(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setFractionDigitsFacet(::ecore::EDataType_ptr eDataType, int digits) = 0;
	virtual int getLengthFacet(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setLengthFacet(::ecore::EDataType_ptr eDataType, int length) = 0;
	virtual int getMinLengthFacet(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setMinLengthFacet(::ecore::EDataType_ptr eDataType, int length) = 0;
	virtual int getMaxLengthFacet(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setMaxLengthFacet(::ecore::EDataType_ptr eDataType, int length) = 0;
	virtual ::ecore::EString getMinExclusiveFacet(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setMinExclusiveFacet(::ecore::EDataType_ptr eDataType, ::ecore::EString literal) = 0;
	virtual ::ecore::EString getMaxExclusiveFacet(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setMaxExclusiveFacet(::ecore::EDataType_ptr eDataType, ::ecore::EString literal) = 0;
	virtual ::ecore::EString getMinInclusiveFacet(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setMinInclusiveFacet(::ecore::EDataType_ptr eDataType, ::ecore::EString literal) = 0;
	virtual ::ecore::EString getMaxInclusiveFacet(::ecore::EDataType_ptr eDataType) = 0;
	virtual void setMaxInclusiveFacet(::ecore::EDataType_ptr eDataType, ::ecore::EString literal) = 0;
	virtual ::ecore::EPackage_ptr demandPackage(::ecore::EString nameSpace) = 0;
	virtual ::ecore::EClassifier_ptr demandType(::ecore::EString nameSpace, ::ecore::EString name) = 0;
	virtual ::ecore::EStructuralFeature_ptr demandFeature(::ecore::EString nameSpace, ::ecore::EString name, bool isElement) = 0;
	virtual ::ecore::EStructuralFeature_ptr demandFeature(::ecore::EString nameSpace, ::ecore::EString name, bool isElement, bool isReference) = 0;
	virtual mapping::EList<::ecore::EPackage_ptr>::ptr_type demandedPackages() = 0;
};

} // util
} // ecorecpp

#endif // ExtendedMetaData_HPP
