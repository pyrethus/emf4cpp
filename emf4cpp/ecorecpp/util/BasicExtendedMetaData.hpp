// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * util/BasicExtendedMetaData.hpp
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

#ifndef BasicExtendedMetaData_HPP
#define BasicExtendedMetaData_HPP

#include <unordered_map>
#include <ecore_forward.hpp>
#include <ecorecpp.hpp>
#include "ExtendedMetaData.hpp"

namespace ecorecpp {
namespace util {

class BasicExtendedMetaData : public ExtendedMetaData {
public:
	BasicExtendedMetaData();
	BasicExtendedMetaData(MetaModelRepository_ptr);
	BasicExtendedMetaData(::ecore::EString, MetaModelRepository_ptr);
	~BasicExtendedMetaData() override;

protected:
	::ecore::EString m_annotationURI;
	MetaModelRepository_ptr m_registry;

	::ecore::EString getQualifiedName(::ecore::EString defaultNamespace, ::ecore::EClassifier_ptr eClassifier);
	::ecore::EString getQualifiedName(::ecore::EString defaultNamespace, ::ecore::EStructuralFeature_ptr eStructuralFeature);

public:
	::ecore::EStructuralFeature_ptr getLocalAttribute(
		::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name);
	::ecore::EStructuralFeature_ptr getLocalElement(
		::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name);
	
	::ecore::EPackage_ptr getPackage(::ecore::EString nameSpace) override;
	void putPackage(::ecore::EString nameSpace, ::ecore::EPackage_ptr ePackage) override;
	::ecore::EClass_ptr getDocumentRoot(::ecore::EPackage_ptr ePackage) override;
	void setDocumentRoot(::ecore::EClass_ptr eClass) override;
	bool isDocumentRoot(::ecore::EClass_ptr eClass) override;
	::ecore::EReference_ptr getXMLNSPrefixMapFeature(::ecore::EClass_ptr eClass) override;
	::ecore::EReference_ptr getXSISchemaLocationMapFeature(::ecore::EClass_ptr eClass) override;
	bool isQualified(::ecore::EPackage_ptr ePackage) override;
	void setQualified(::ecore::EPackage_ptr ePackage, bool isQualified) override;
	::ecore::EString getNamespace(::ecore::EPackage_ptr ePackage) override;
	::ecore::EString getNamespace(::ecore::EClassifier_ptr eClassifier) override;
	::ecore::EString getNamespace(::ecore::EStructuralFeature_ptr eStructuralFeature) override;
	void setNamespace(::ecore::EStructuralFeature_ptr eStructuralFeature, ::ecore::EString nameSpace) override;
	::ecore::EString getName(::ecore::EClassifier_ptr eClassifier) override;
	void setName(::ecore::EClassifier_ptr eClassifier, ::ecore::EString name) override;
	bool isAnonymous(::ecore::EClassifier_ptr eClassifier) override;
	::ecore::EString getName(::ecore::EStructuralFeature_ptr eStructuralFeature) override;
	void setName(::ecore::EStructuralFeature_ptr eStructuralFeature, ::ecore::EString name) override;
	::ecore::EClassifier_ptr getType(::ecore::EString nameSpace, ::ecore::EString name) override;
	::ecore::EStructuralFeature_ptr getAttribute(::ecore::EString nameSpace, ::ecore::EString name) override;
	::ecore::EStructuralFeature_ptr getElement(::ecore::EString nameSpace, ::ecore::EString name) override;
	::ecore::EClassifier_ptr getType(::ecore::EPackage_ptr ePackage, ::ecore::EString name) override;
	::ecore::EStructuralFeature_ptr getAttribute(::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name) override;
	::ecore::EStructuralFeature_ptr getElement(::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name) override;
	::ecore::EStructuralFeature_ptr getSimpleFeature(::ecore::EClass_ptr eClass) override;
	::ecore::EAttribute_ptr getMixedFeature(::ecore::EClass_ptr eClass) override;
	int getFeatureKind(::ecore::EStructuralFeature_ptr eStructuralFeature) override;
	void setFeatureKind(::ecore::EStructuralFeature_ptr eStructuralFeature, int kind) override;
	int getContentKind(::ecore::EClass_ptr eClass) override;
	void setContentKind(::ecore::EClass_ptr eClass, int kind) override;
	int getDerivationKind(::ecore::EDataType_ptr eDataType) override;
	::ecore::EDataType_ptr getBaseType(::ecore::EDataType_ptr eDataType) override;
	void setBaseType(::ecore::EDataType_ptr eDataType, ::ecore::EDataType_ptr baseType) override;
	::ecore::EDataType_ptr getItemType(::ecore::EDataType_ptr eDataType) override;
	void setItemType(::ecore::EDataType_ptr eDataType, ::ecore::EDataType_ptr itemType) override;
	mapping::EList<::ecore::EDataType_ptr>::ptr_type getMemberTypes(::ecore::EDataType_ptr eDataType) override;
	void setMemberTypes(::ecore::EDataType_ptr eDataType, const mapping::EList<::ecore::EDataType_ptr>::ptr_type& memberTypes) override;
	mapping::EList<::ecore::EStructuralFeature_ptr>::ptr_type getAllAttributes(::ecore::EClass_ptr eClass) override;
	mapping::EList<::ecore::EStructuralFeature_ptr>::ptr_type getAllElements(::ecore::EClass_ptr eClass) override;
	mapping::EList<::ecore::EStructuralFeature_ptr>::ptr_type getAttributes(::ecore::EClass_ptr eClass) override;
	mapping::EList<::ecore::EStructuralFeature_ptr>::ptr_type getElements(::ecore::EClass_ptr eClass) override;
	bool matches(const mapping::EList<::ecore::EString>::ptr_type& wildcards, ::ecore::EString nameSpace) override;
	bool matches(::ecore::EString wildcard, ::ecore::EString nameSpace) override;
	mapping::EList<::ecore::EString>::ptr_type getWildcards(::ecore::EStructuralFeature_ptr eStructuralFeature) override;
	void setWildcards(::ecore::EStructuralFeature_ptr eStructuralFeature, const mapping::EList<::ecore::EString>::ptr_type& wildcards) override;
	int getProcessingKind(::ecore::EStructuralFeature_ptr eStructuralFeature) override;
	void setProcessingKind(::ecore::EStructuralFeature_ptr eStructuralFeature, int processingKind) override;
	::ecore::EStructuralFeature_ptr getAffiliation(::ecore::EStructuralFeature_ptr eStructuralFeature) override;
	void setAffiliation(::ecore::EStructuralFeature_ptr eStructuralFeature, ::ecore::EStructuralFeature_ptr affiliation) override;
	::ecore::EStructuralFeature_ptr getGroup(::ecore::EStructuralFeature_ptr eStructuralFeature) override;
	void setGroup(::ecore::EStructuralFeature_ptr eStructuralFeature, ::ecore::EStructuralFeature_ptr group) override;
	::ecore::EStructuralFeature_ptr getAffiliation(::ecore::EClass_ptr eClass, ::ecore::EStructuralFeature_ptr eStructuralFeature) override;
	::ecore::EStructuralFeature_ptr getAttributeWildcardAffiliation(::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name) override;
	::ecore::EStructuralFeature_ptr getElementWildcardAffiliation(::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name) override;
	int getWhiteSpaceFacet(::ecore::EDataType_ptr eDataType) override;
	void setWhiteSpaceFacet(::ecore::EDataType_ptr eDataType, int whiteSpace) override;
	mapping::EList<::ecore::EString>::ptr_type getEnumerationFacet(::ecore::EDataType_ptr eDataType) override;
	void setEnumerationFacet(::ecore::EDataType_ptr eDataType, const mapping::EList<::ecore::EString>::ptr_type& literals) override;
	mapping::EList<::ecore::EString>::ptr_type getPatternFacet(::ecore::EDataType_ptr eDataType) override;
	void setPatternFacet(::ecore::EDataType_ptr eDataType, const mapping::EList<::ecore::EString>::ptr_type& pattern) override;
	int getTotalDigitsFacet(::ecore::EDataType_ptr eDataType) override;
	void setTotalDigitsFacet(::ecore::EDataType_ptr eDataType, int digits) override;
	int getFractionDigitsFacet(::ecore::EDataType_ptr eDataType) override;
	void setFractionDigitsFacet(::ecore::EDataType_ptr eDataType, int digits) override;
	int getLengthFacet(::ecore::EDataType_ptr eDataType) override;
	void setLengthFacet(::ecore::EDataType_ptr eDataType, int length) override;
	int getMinLengthFacet(::ecore::EDataType_ptr eDataType) override;
	void setMinLengthFacet(::ecore::EDataType_ptr eDataType, int length) override;
	int getMaxLengthFacet(::ecore::EDataType_ptr eDataType) override;
	void setMaxLengthFacet(::ecore::EDataType_ptr eDataType, int length) override;
	::ecore::EString getMinExclusiveFacet(::ecore::EDataType_ptr eDataType) override;
	void setMinExclusiveFacet(::ecore::EDataType_ptr eDataType, ::ecore::EString literal) override;
	::ecore::EString getMaxExclusiveFacet(::ecore::EDataType_ptr eDataType) override;
	void setMaxExclusiveFacet(::ecore::EDataType_ptr eDataType, ::ecore::EString literal) override;
	::ecore::EString getMinInclusiveFacet(::ecore::EDataType_ptr eDataType) override;
	void setMinInclusiveFacet(::ecore::EDataType_ptr eDataType, ::ecore::EString literal) override;
	::ecore::EString getMaxInclusiveFacet(::ecore::EDataType_ptr eDataType) override;
	void setMaxInclusiveFacet(::ecore::EDataType_ptr eDataType, ::ecore::EString literal) override;
	::ecore::EPackage_ptr demandPackage(::ecore::EString nameSpace) override;
	::ecore::EClassifier_ptr demandType(::ecore::EString nameSpace, ::ecore::EString name) override;
	::ecore::EStructuralFeature_ptr demandFeature(::ecore::EString nameSpace, ::ecore::EString name, bool isElement) override;
	::ecore::EStructuralFeature_ptr demandFeature(::ecore::EString nameSpace, ::ecore::EString name, bool isElement, bool isReference) override;
	mapping::EList<::ecore::EPackage_ptr>::ptr_type demandedPackages() override;


protected:
	/* Bad style, but if we use XMLTypePackage::nsURI we get a circular link
	 * dependency... */
	static const ::ecore::EString s_xmlTypNsURI;

	/* Internal caching structures */
	class EPackageExtendedMetaData {
	public:
		EPackageExtendedMetaData(BasicExtendedMetaData* parent,
								 const ::ecore::EPackage_ptr& package)
			: m_parent(parent), m_ePackage(package) { }
		bool isQualified();
		void setQualified(bool);
		::ecore::EClassifier_ptr getType(const ::ecore::EString&);
		void rename(const ::ecore::EClassifier_ptr&, const ::ecore::EString&);
	protected:
		bool basicIsQualified();
		bool m_isInitialized = false;
		bool m_isQualified = false;
		std::unordered_map<::ecore::EString, ::ecore::EClassifier_ptr> m_nameToClassifier;

		BasicExtendedMetaData* m_parent = nullptr;
		::ecore::EPackage_ptr m_ePackage;
	};

	std::shared_ptr<EPackageExtendedMetaData> getExtendedMetaData(
		const ::ecore::EPackage_ptr&);
	virtual std::shared_ptr<EPackageExtendedMetaData> createExtendedMetaData(
		const ::ecore::EPackage_ptr&);
	std::unordered_map<
		::ecore::EPackage*,
		std::shared_ptr<EPackageExtendedMetaData> > m_ePackageExtendedMetaDataCache;


	using EString = ::ecore::EString;
	using EStringList = mapping::EList<EString>;
	using EDataTypeList = mapping::EList<::ecore::EDataType_ptr>;

	static const EString UNINITIALIZED_STRING;
	static const int UNINITIALIZED_INT = -2;


	class AbstractEClassifierExtendedMetaData {
	public:
		AbstractEClassifierExtendedMetaData(BasicExtendedMetaData* parent,
											const ::ecore::EClassifier_ptr& classifier)
			: m_parent(parent), m_classifier(classifier) { }
		virtual ~AbstractEClassifierExtendedMetaData();

		virtual EString getName() = 0;
		virtual void setName(const EString& name) = 0;
		virtual int getContentKind() = 0;
		virtual void setContentKind(int kind) = 0;
		virtual int getDerivationKind() = 0;
		virtual ::ecore::EDataType_ptr getBaseType() = 0;
		virtual void setBaseType(const ::ecore::EDataType_ptr& baseType) = 0;
		virtual ::ecore::EDataType_ptr getItemType() = 0;
		virtual void setItemType(const ::ecore::EDataType_ptr& itemType) = 0;
		virtual EDataTypeList::ptr_type getMemberTypes() = 0;
		virtual void setMemberTypes(const EDataTypeList::ptr_type& memberTypes) = 0;
		virtual int getWhiteSpaceFacet() = 0;
		virtual void setWhiteSpaceFacet(int whiteSpace) = 0;
		virtual EStringList::ptr_type getEnumerationFacet() = 0;
		virtual void setEnumerationFacet(const EStringList::ptr_type& literals) = 0;
		virtual EStringList::ptr_type getPatternFacet() = 0;
		virtual void setPatternFacet(const EStringList::ptr_type& literals) = 0;
		virtual int getTotalDigitsFacet() = 0;
		virtual void setTotalDigitsFacet(int digits) = 0;
		virtual int getFractionDigitsFacet() = 0;
		virtual void setFractionDigitsFacet(int digits) = 0;
		virtual int getLengthFacet() = 0;
		virtual void setLengthFacet(int length) = 0;
		virtual int getMinLengthFacet() = 0;
		virtual void setMinLengthFacet(int length) = 0;
		virtual int getMaxLengthFacet() = 0;
		virtual void setMaxLengthFacet(int length) = 0;
		virtual EString getMinExclusiveFacet() = 0;
		virtual void setMinExclusiveFacet(const EString& literal) = 0;
		virtual EString getMaxExclusiveFacet() = 0;
		virtual void setMaxExclusiveFacet(const EString& literal) = 0;
		virtual EString getMinInclusiveFacet() = 0;
		virtual void setMinInclusiveFacet(const EString& literal) = 0;
		virtual EString getMaxInclusiveFacet() = 0;
		virtual void setMaxInclusiveFacet(const EString& literal) = 0;

	protected:
		BasicExtendedMetaData* m_parent = nullptr;
		::ecore::EClassifier_ptr m_classifier;
		EString basicGetName();
	};


	class EClassExtendedMetaData : public AbstractEClassifierExtendedMetaData {
	public:
		EClassExtendedMetaData(BasicExtendedMetaData* parent,
							   const ::ecore::EClass_ptr& eclass)
			: AbstractEClassifierExtendedMetaData(parent, eclass),
			  m_eclass(eclass) { }
		~EClassExtendedMetaData() override;

		EString getName() override;
		void setName(const EString& name) override;
		int getContentKind() override;
		void setContentKind(int kind) override;
		int getDerivationKind() override;
		::ecore::EDataType_ptr getBaseType() override;
		void setBaseType(const ::ecore::EDataType_ptr& baseType) override;
		::ecore::EDataType_ptr getItemType() override;
		void setItemType(const ::ecore::EDataType_ptr& itemType) override;
		EDataTypeList::ptr_type getMemberTypes() override;
		void setMemberTypes(const EDataTypeList::ptr_type& memberTypes) override;
		int getWhiteSpaceFacet() override;
		void setWhiteSpaceFacet(int whiteSpace) override;
		EStringList::ptr_type getEnumerationFacet() override;
		void setEnumerationFacet(const EStringList::ptr_type& literals) override;
		EStringList::ptr_type getPatternFacet() override;
		void setPatternFacet(const EStringList::ptr_type& literals) override;
		int getTotalDigitsFacet() override;
		void setTotalDigitsFacet(int digits) override;
		int getFractionDigitsFacet() override;
		void setFractionDigitsFacet(int digits) override;
		int getLengthFacet() override;
		void setLengthFacet(int length) override;
		int getMinLengthFacet() override;
		void setMinLengthFacet(int length) override;
		int getMaxLengthFacet() override;
		void setMaxLengthFacet(int length) override;
		EString getMinExclusiveFacet() override;
		void setMinExclusiveFacet(const EString& literal) override;
		EString getMaxExclusiveFacet() override;
		void setMaxExclusiveFacet(const EString& literal) override;
		EString getMinInclusiveFacet() override;
		void setMinInclusiveFacet(const EString& literal) override;
		EString getMaxInclusiveFacet() override;
		void setMaxInclusiveFacet(const EString& literal) override;

	protected:
		EString m_name = UNINITIALIZED_STRING;
		int m_contentKind = UNINITIALIZED_INT;
		::ecore::EClass_ptr m_eclass;

		int basicGetContentKind();
	};


	class EDataTypeExtendedMetaData : public AbstractEClassifierExtendedMetaData {
	public:
		EDataTypeExtendedMetaData(BasicExtendedMetaData* parent,
							   const ::ecore::EDataType_ptr& dataType)
			: AbstractEClassifierExtendedMetaData(parent, dataType),
			  m_dataType(dataType) { }
		~EDataTypeExtendedMetaData() override;

		EString getName() override;
		void setName(const EString& name) override;
		int getContentKind() override;
		void setContentKind(int kind) override;
		int getDerivationKind() override;
		::ecore::EDataType_ptr getBaseType() override;
		void setBaseType(const ::ecore::EDataType_ptr& baseType) override;
		::ecore::EDataType_ptr getItemType() override;
		void setItemType(const ::ecore::EDataType_ptr& itemType) override;
		EDataTypeList::ptr_type getMemberTypes() override;
		void setMemberTypes(const EDataTypeList::ptr_type& memberTypes) override;
		int getWhiteSpaceFacet() override;
		void setWhiteSpaceFacet(int whiteSpace) override;
		EStringList::ptr_type getEnumerationFacet() override;
		void setEnumerationFacet(const EStringList::ptr_type& literals) override;
		EStringList::ptr_type getPatternFacet() override;
		void setPatternFacet(const EStringList::ptr_type& literals) override;
		int getTotalDigitsFacet() override;
		void setTotalDigitsFacet(int digits) override;
		int getFractionDigitsFacet() override;
		void setFractionDigitsFacet(int digits) override;
		int getLengthFacet() override;
		void setLengthFacet(int length) override;
		int getMinLengthFacet() override;
		void setMinLengthFacet(int length) override;
		int getMaxLengthFacet() override;
		void setMaxLengthFacet(int length) override;
		EString getMinExclusiveFacet() override;
		void setMinExclusiveFacet(const EString& literal) override;
		EString getMaxExclusiveFacet() override;
		void setMaxExclusiveFacet(const EString& literal) override;
		EString getMinInclusiveFacet() override;
		void setMinInclusiveFacet(const EString& literal) override;
		EString getMaxInclusiveFacet() override;
		void setMaxInclusiveFacet(const EString& literal) override;

	protected:
		EString m_name = UNINITIALIZED_STRING;
		::ecore::EDataType_ptr m_baseType;
		bool m_baseTypeInitialized = false;
		::ecore::EDataType_ptr m_itemType;
		bool m_itemTypeInitialized = false;
		EDataTypeList::ptr_type m_memberTypes;
		int m_derivationKind = UNINITIALIZED_INT;
		int m_whiteSpace = UNINITIALIZED_INT;
		EStringList::ptr_type m_enumerationLiterals;
		EStringList::ptr_type m_pattern;
		int m_totalDigits = UNINITIALIZED_INT;
		int m_fractionDigits = UNINITIALIZED_INT;
		int m_length = UNINITIALIZED_INT;
		int m_minLength = UNINITIALIZED_INT;
		int m_maxLength = UNINITIALIZED_INT;
		EString m_minExclusive = UNINITIALIZED_STRING;
		EString m_maxExclusive = UNINITIALIZED_STRING;
		EString m_minInclusive = UNINITIALIZED_STRING;
		EString m_maxInclusive = UNINITIALIZED_STRING;
		
		::ecore::EDataType_ptr m_dataType;

		::ecore::EDataType_ptr basicGetBaseType();
		::ecore::EDataType_ptr basicGetItemType();
		EDataTypeList::ptr_type basicGetMemberTypes();
		int basicGetWhiteSpaceFacet();
		EStringList::ptr_type basicGetEnumerationFacet();
		EStringList::ptr_type basicGetPatternFacet();
		int basicGetTotalDigitsFacet();
		int basicGetFractionDigitsFacet();
		int basicGetLengthFacet();
		int basicGetMinLengthFacet();
		int basicGetMaxLengthFacet();
		EString basicGetMinExclusiveFacet();
		EString basicGetMaxExclusiveFacet();
		EString basicGetMinInclusiveFacet();
		EString basicGetMaxInclusiveFacet();
	};

	std::shared_ptr<AbstractEClassifierExtendedMetaData> getExtendedMetaData(
		const ::ecore::EClassifier_ptr&);
	virtual std::shared_ptr<AbstractEClassifierExtendedMetaData> createExtendedMetaData(
		const ::ecore::EClassifier_ptr&);
	std::unordered_map<
		::ecore::EClassifier*,
		std::shared_ptr<AbstractEClassifierExtendedMetaData> > m_eClassifierExtendedMetaDataCache;


	class EStructuralFeatureExtendedMetaData {
	public:
		EStructuralFeatureExtendedMetaData(BasicExtendedMetaData* parent,
										   const ::ecore::EStructuralFeature_ptr& feature)
			: m_parent(parent), m_feature(feature) { }
		EString getName();
		void setName(const EString& name);
		EString getNamespace();
		void setNamespace(const EString& nameSpace);
		int getFeatureKind();
		void setFeatureKind(int kind);
		EStringList::ptr_type getWildcards();
		void setWildcards(const EStringList::ptr_type& wildcards);
		int getProcessingKind();
		void setProcessingKind(int kind);
		::ecore::EStructuralFeature_ptr getGroup();
		void setGroup(const ::ecore::EStructuralFeature_ptr& group);
		::ecore::EStructuralFeature_ptr getAffiliation();
		void setAffiliation(const ::ecore::EStructuralFeature_ptr& affiliation);
		// Map<EClass, FeatureMapUtil.Validator> getValidatorMap();

	protected:
		EString m_name = UNINITIALIZED_STRING;
		EString m_namespace = UNINITIALIZED_STRING;
		int m_featureKind = UNINITIALIZED_INT;
		EStringList::ptr_type m_wildcards;
		int m_processingKind = UNINITIALIZED_INT;
		::ecore::EStructuralFeature_ptr m_group;
		bool m_groupInitialized = false;
		::ecore::EStructuralFeature_ptr m_affiliation;
		bool m_affiliationInitialized = false;

		BasicExtendedMetaData* m_parent = nullptr;
		::ecore::EStructuralFeature_ptr m_feature;

		EString basicGetName();
		EString basicGetNamespace();
		int basicGetFeatureKind();
		EStringList::ptr_type basicGetWildcards();
		int basicGetProcessingKind();
		::ecore::EStructuralFeature_ptr basicGetGroup();
		::ecore::EStructuralFeature_ptr basicGetAffiliation();
		// Map<EClass, FeatureMapUtil.Validator> basicGetValidatorMap();
	};

	std::shared_ptr<EStructuralFeatureExtendedMetaData> getExtendedMetaData(
		const ::ecore::EStructuralFeature_ptr&);
	virtual std::shared_ptr<EStructuralFeatureExtendedMetaData> createExtendedMetaData(
		const ::ecore::EStructuralFeature_ptr&);
	std::unordered_map<
		::ecore::EStructuralFeature*,
		std::shared_ptr<EStructuralFeatureExtendedMetaData> > m_eStructuralFeatureExtendedMetaDataCache;

};

} // util
} // ecorecpp

#endif // BasicExtendedMetaData_HPP
