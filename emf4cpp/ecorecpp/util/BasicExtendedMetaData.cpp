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

#include "BasicExtendedMetaData.hpp"

#include <vector>
#include <boost/algorithm/string.hpp>

#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <type/TypePackage.hpp>

namespace ecorecpp {
namespace util {

	/* Bad style, but if we use XMLTypePackage::nsURI we get a circular link
	 * dependency... */
const ::ecore::EString BasicExtendedMetaData::s_xmlTypNsURI =
	"http://www.eclipse.org/emf/2003/XMLType";


BasicExtendedMetaData::BasicExtendedMetaData()
	: BasicExtendedMetaData(ExtendedMetaData::ANNOTATION_URI,
							::ecorecpp::MetaModelRepository::_instance()) {
}

BasicExtendedMetaData::BasicExtendedMetaData(::ecorecpp::MetaModelRepository_ptr _registry)
	: BasicExtendedMetaData(ExtendedMetaData::ANNOTATION_URI, _registry) {
}

BasicExtendedMetaData::BasicExtendedMetaData(::ecore::EString _uri,
											 ::ecorecpp::MetaModelRepository_ptr _registry)
	: m_annotationURI(_uri), m_registry(_registry) {
}

BasicExtendedMetaData::~BasicExtendedMetaData() = default;


::ecore::EPackage_ptr BasicExtendedMetaData::getPackage(::ecore::EString nameSpace) {
	return m_registry->getByNSURI(nameSpace);
}

void BasicExtendedMetaData::putPackage(::ecore::EString nameSpace, ::ecore::EPackage_ptr ePackage) {
	throw "not yet implemented";
}

::ecore::EClass_ptr BasicExtendedMetaData::getDocumentRoot(::ecore::EPackage_ptr ePackage) {
	return ::ecore::as<::ecore::EClass>(getType(ePackage, ""));
}

void BasicExtendedMetaData::setDocumentRoot(::ecore::EClass_ptr eClass) {
	setName(eClass, "");
	setContentKind(eClass, MIXED_CONTENT);
}

bool BasicExtendedMetaData::isDocumentRoot(::ecore::EClass_ptr eClass) {
	return getName(eClass) == ::ecore::EString("");
}

::ecore::EReference_ptr BasicExtendedMetaData::getXMLNSPrefixMapFeature(::ecore::EClass_ptr eClass) {
	if (getContentKind(eClass) == MIXED_CONTENT) {
		auto& allReferences = eClass->getEAllReferences();
		for ( auto ref : allReferences ) {
			if (ref->getName() == "xmlns:prefix")
				return ref;
		}
	}
	return ::ecore::EReference_ptr();
}

::ecore::EReference_ptr BasicExtendedMetaData::getXSISchemaLocationMapFeature(::ecore::EClass_ptr eClass) {
	if (getContentKind(eClass) == MIXED_CONTENT) {
		auto& allReferences = eClass->getEAllReferences();
		for ( auto ref : allReferences ) {
			if (ref->getName() == "xsi:schemaLocation")
				return ref;
		}
	}
	return ::ecore::EReference_ptr();
}

/** \sa getName(::ecore::EClassifier_ptr)
 */
bool BasicExtendedMetaData::isQualified(::ecore::EPackage_ptr ePackage) {
	return getExtendedMetaData(ePackage)->isQualified();
}

/** \sa getName(::ecore::EClassifier_ptr)
 */
bool BasicExtendedMetaData::EPackageExtendedMetaData::basicIsQualified() {
	auto eAnnotation = m_ePackage->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("qualified"))
		return eAnnotation->getDetail("qualified") != "false";
	return true;
}

/** \sa getName(::ecore::EClassifier_ptr)
 */
void BasicExtendedMetaData::setQualified(::ecore::EPackage_ptr ePackage, bool isQualified) {
	auto eAnnotation = ePackage->getEAnnotation(ANNOTATION_URI);
	if (!isQualified)
		eAnnotation->setDetail("qualified", "false");
	else
		eAnnotation->removeDetail("qualified");
	getExtendedMetaData(ePackage)->setQualified(isQualified);
}

::ecore::EString BasicExtendedMetaData::getNamespace(::ecore::EPackage_ptr ePackage) {
	if (isQualified(ePackage))
		return ePackage->getNsURI();
	return ::ecore::EString();
}

::ecore::EString BasicExtendedMetaData::getNamespace(::ecore::EClassifier_ptr eClassifier) {
	return getNamespace(eClassifier->getEPackage());
}

::ecore::EString BasicExtendedMetaData::getNamespace(
		::ecore::EStructuralFeature_ptr eStructuralFeature) {
	return getExtendedMetaData(eStructuralFeature)->getNamespace();
}

::ecore::EString BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::basicGetNamespace() {
	auto eAnnotation = m_feature->getEAnnotation(ANNOTATION_URI);
	if (!eAnnotation->hasDetail("namespace"))
		return ::ecore::EString();
	
	auto result = eAnnotation->getDetail("namespace");
	if (result == "##targetNamespace")
		return m_parent->getNamespace(m_feature->getEContainingClass()->getEPackage());
	return result;
}

void BasicExtendedMetaData::setNamespace(::ecore::EStructuralFeature_ptr eStructuralFeature, ::ecore::EString nameSpace) {
	auto packageNamespace = getNamespace(eStructuralFeature->getEContainingClass()->getEPackage());
	auto convertedNamespace = nameSpace;
	if (nameSpace.empty() ? packageNamespace.empty() : nameSpace == packageNamespace)
		convertedNamespace = "##targetNamespace";

	auto eAnnotation = eStructuralFeature->getEAnnotation(ANNOTATION_URI);
	if (!convertedNamespace.empty())
		eAnnotation->setDetail("namespace", convertedNamespace);
	else
		eAnnotation->removeDetail("namespace");
	getExtendedMetaData(eStructuralFeature)->setNamespace(nameSpace);
}

/** Return the name of the EClassifer as defined in the ExtendedMetaData
 * annotations. If no name is defined there, the ordinary name of the
 * EClassifier is returned.
 *
 * The value of the annotations are cached in a class xyExtendedMetaData. For
 * the name attribute and all similar attributes, the following concept is
 * used:
 * # The getter getXY() passes through to the caching class.
 * # The caching class uses basicGetXY() to initialize from the annotations.
 * # The setter setXY() updates first the annotation, and second the caching class.
 * This pattern repeats for all attributes.
 */
::ecore::EString BasicExtendedMetaData::getName(::ecore::EClassifier_ptr eClassifier) {
	return getExtendedMetaData(eClassifier)->getName();
}

/** Update the caching class from the annotation.
 *
 * \sa getName(::ecore::EClassifier_ptr)
 */
::ecore::EString BasicExtendedMetaData::AbstractEClassifierExtendedMetaData::basicGetName() {
	auto eAnnotation = m_classifier->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("name"))
		return eAnnotation->getDetail("name");
	return m_classifier->getName();
}

/** Change the value stored in the annotation and update the caching class.
 *
 * \sa getName(::ecore::EClassifier_ptr)
 */
void BasicExtendedMetaData::setName(::ecore::EClassifier_ptr eClassifier, ::ecore::EString name) {
	auto eAnnotation = eClassifier->getEAnnotation(ANNOTATION_URI);
	eAnnotation->setDetail("name", name);
}

bool BasicExtendedMetaData::isAnonymous(::ecore::EClassifier_ptr eClassifier) {
	auto name = getName(eClassifier);
	return name.length() == 0 || name.find("_._") != ::ecore::EString::npos;
}

::ecore::EString BasicExtendedMetaData::getName(::ecore::EStructuralFeature_ptr eStructuralFeature) {
	return getExtendedMetaData(eStructuralFeature)->getName();
}

::ecore::EString BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::basicGetName() {
	auto eAnnotation = m_feature->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("name"))
		return eAnnotation->getDetail("name");
	return m_feature->getName();
}

void BasicExtendedMetaData::setName(::ecore::EStructuralFeature_ptr eStructuralFeature, ::ecore::EString name) {
	auto eAnnotation = eStructuralFeature->getEAnnotation(ANNOTATION_URI);
	eAnnotation->setDetail("name", name);
	getExtendedMetaData(eStructuralFeature)->setName(name);
}

::ecore::EClassifier_ptr BasicExtendedMetaData::getType(::ecore::EString nameSpace, ::ecore::EString name) {
	auto ePackage = getPackage(nameSpace);
	if (!ePackage)
		return ::ecore::EClassifier_ptr();
	return getType(ePackage, name);
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::getLocalAttribute(
	::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name) {
	throw "not yet implemented";
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::getAttribute(::ecore::EString nameSpace, ::ecore::EString name) {
	auto ePackage = getPackage(nameSpace);
	if (ePackage) {
		auto documentRoot = getDocumentRoot(ePackage);
		if (documentRoot) {
			return getLocalAttribute(documentRoot, nameSpace, name);
		}
	}

	return ::ecore::EStructuralFeature_ptr();
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::getLocalElement(
	::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name) {
	throw "not yet implemented";
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::getElement(::ecore::EString nameSpace, ::ecore::EString name) {
	auto ePackage = getPackage(nameSpace);
	if (ePackage) {
		auto documentRoot = getDocumentRoot(ePackage);
		if (documentRoot) {
			return getLocalElement(documentRoot, nameSpace, name);
		}
	}
	return ::ecore::EStructuralFeature_ptr();
}

::ecore::EClassifier_ptr BasicExtendedMetaData::getType(::ecore::EPackage_ptr ePackage, ::ecore::EString name) {
	return getExtendedMetaData(ePackage)->getType(name);
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::getAttribute(::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name) {
	auto result = getLocalAttribute(eClass, nameSpace, name);
	if (!result) {
		result = getAttribute(nameSpace, name);
		if (result && !getAffiliation(eClass, result)) {
			return ::ecore::EStructuralFeature_ptr();
		}
	}
	return result;
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::getElement(::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name) {
	auto result = getLocalElement(eClass, nameSpace, name);
	if (!result) {
		result = getElement(nameSpace, name);
		if (result && !getAffiliation(eClass, result)) {
			return ::ecore::EStructuralFeature_ptr();
		}
	}
	return result;
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::getSimpleFeature(::ecore::EClass_ptr eClass) {
	if (getContentKind(eClass) == SIMPLE_CONTENT) {
		auto& allFeatures = eClass->getEStructuralFeatures();
		for (auto feature : allFeatures) {
			if (getFeatureKind(feature) == SIMPLE_FEATURE) {
				return feature;
			}
		}
	}

	return ::ecore::EStructuralFeature_ptr();
}

::ecore::EAttribute_ptr BasicExtendedMetaData::getMixedFeature(::ecore::EClass_ptr eClass) {
	auto kind = getContentKind(eClass);
	if (kind == MIXED_CONTENT || kind == SIMPLE_CONTENT) {
		auto& allAttributes = eClass->getEAllAttributes();
		for (auto attribute : allAttributes) {
			if (getFeatureKind(attribute) == ELEMENT_WILDCARD_FEATURE) {
				return attribute;
			}
		}
	}

	return ::ecore::EAttribute_ptr();
}

int BasicExtendedMetaData::getFeatureKind(::ecore::EStructuralFeature_ptr eStructuralFeature) {
	return getExtendedMetaData(eStructuralFeature)->getFeatureKind();
}

int BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::basicGetFeatureKind() {
	auto eAnnotation = m_feature->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("kind")) {
		auto kind = eAnnotation->getDetail("kind");
		for (int i = 1; i < FEATURE_KINDS_MAX; ++i) {
			if (FEATURE_KINDS[i] == kind) {
				return i;
			}
		}
	}
	return UNSPECIFIED_FEATURE;
}

void BasicExtendedMetaData::setFeatureKind(::ecore::EStructuralFeature_ptr eStructuralFeature, int kind) {
	auto eAnnotation = eStructuralFeature->getEAnnotation(ANNOTATION_URI);
	if (kind > 0 && kind < FEATURE_KINDS_MAX)
		eAnnotation->setDetail("kind", FEATURE_KINDS[kind]);
	else
		eAnnotation->removeDetail("kind");
}

int BasicExtendedMetaData::getContentKind(::ecore::EClass_ptr eClass) {
	return getExtendedMetaData(eClass)->getContentKind();
}

int BasicExtendedMetaData::EClassExtendedMetaData::basicGetContentKind() {
	auto eAnnotation = m_eclass->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("kind")) {
		auto kind = eAnnotation->getDetail("kind");
		for (int i = 1; i < CONTENT_KINDS_MAX; ++i) {
			if (CONTENT_KINDS[i] == kind) {
				return i;
			}
		}
	}
	return UNSPECIFIED_CONTENT;
}

void BasicExtendedMetaData::setContentKind(::ecore::EClass_ptr eClass, int kind) {
	auto eAnnotation = eClass->getEAnnotation(ANNOTATION_URI);
	if (kind > 0 && kind < CONTENT_KINDS_MAX)
		eAnnotation->setDetail("kind", CONTENT_KINDS[kind]);
	else
		eAnnotation->removeDetail("kind");
	getExtendedMetaData(eClass)->setContentKind(kind);
}

/** Return the DERIVATION_KIND for a EDataType.
 *
 * In Java-EMF, there is a similar method for EClassifier, which parses the
 * annotations. But it seems to be unused (declared protected and no visible
 * calls). ExtendedMetaData does not declare this method neither.
 */
int BasicExtendedMetaData::getDerivationKind(::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getDerivationKind();
}

/** The DERIVATION_KIND is a derived value calculated from other cached
 * values. Hence we immediately implement it in the getter of the cache class
 * instead of (always) forwarding to a basicGetXY() method.
 */
int BasicExtendedMetaData::EDataTypeExtendedMetaData::getDerivationKind() {
	if (m_derivationKind == UNINITIALIZED_INT) {
		if (getBaseType())
			m_derivationKind = RESTRICTION_DERIVATION;
		else if (getItemType())
			m_derivationKind = LIST_DERIVATION;
		else if (getMemberTypes()->size() > 0)
			m_derivationKind = UNION_DERIVATION;
		else
			m_derivationKind = UNION_DERIVATION;
	}
	return m_derivationKind;
}

::ecore::EString BasicExtendedMetaData::getQualifiedName(::ecore::EString defaultNamespace, ::ecore::EClassifier_ptr eClassifier) {
    auto nameSpace = getNamespace(eClassifier);
    auto name = getName(eClassifier);
    if (nameSpace.empty()) {
		return nameSpace == defaultNamespace ? name : "#" + name;
    } else {
		return nameSpace == defaultNamespace ? name : nameSpace + "#" + name;
    }
}

::ecore::EString BasicExtendedMetaData::getQualifiedName(::ecore::EString defaultNamespace, ::ecore::EStructuralFeature_ptr eStructuralFeature) {
    auto nameSpace = getNamespace(eStructuralFeature);
    auto name = getName(eStructuralFeature);
    if (nameSpace.empty()) {
		return nameSpace == defaultNamespace ? name : "#" + name;
    } else {
		return nameSpace == defaultNamespace ? name : nameSpace + "#" + name;
    }
}

::ecore::EDataType_ptr BasicExtendedMetaData::getBaseType(::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getBaseType();
}

/* auto const pos=path.find_last_of('/');
 * const auto leaf=path.substr(pos+1);
 */
::ecore::EDataType_ptr BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetBaseType() {
	auto eAnnotation = m_dataType->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("baseType")) {
		auto baseType = eAnnotation->getDetail("baseType");
		if (!baseType.empty()) {
			const auto index = baseType.find_last_of('#');
			auto type = index == ::ecore::EString::npos ?
				m_parent->getType(m_dataType->getEPackage(), baseType) :
				index == 0 ?
				m_parent->getType(::ecore::EString(), baseType.substr(1)) :
				m_parent->getType(baseType.substr(0, index), baseType.substr(index + 1));
			return ::ecore::as<::ecore::EDataType>(type);
		}
	}

	return ::ecore::EDataType_ptr();
}

void BasicExtendedMetaData::setBaseType(::ecore::EDataType_ptr eDataType,
										::ecore::EDataType_ptr baseType) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (!baseType)
		eAnnotation->removeDetail("baseType");
	else
		eAnnotation->setDetail("baseType", getQualifiedName(getNamespace(eDataType), baseType));
	getExtendedMetaData(eDataType)->setBaseType(baseType);
}

::ecore::EDataType_ptr BasicExtendedMetaData::getItemType(::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getItemType();
}

::ecore::EDataType_ptr BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetItemType() {
	auto eAnnotation = m_dataType->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("itemType")) {
		auto itemType = eAnnotation->getDetail("itemType");
		if (!itemType.empty()) {
			const auto index = itemType.find_last_of('#');
			auto type = index == ::ecore::EString::npos ?
				m_parent->getType(m_dataType->getEPackage(), itemType) :
				index == 0 ?
				m_parent->getType(::ecore::EString(), itemType.substr(1)) :
				m_parent->getType(itemType.substr(0, index), itemType.substr(index + 1));
			return ::ecore::as<::ecore::EDataType>(type);
		}
	}
	return ::ecore::EDataType_ptr();
}

void BasicExtendedMetaData::setItemType(::ecore::EDataType_ptr eDataType,
										::ecore::EDataType_ptr itemType) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (!itemType)
		eAnnotation->removeDetail("itemType");
	else
		eAnnotation->setDetail("itemType", getQualifiedName(getNamespace(eDataType), itemType));
	getExtendedMetaData(eDataType)->setItemType(itemType);
}

mapping::EList<::ecore::EDataType_ptr>::ptr_type BasicExtendedMetaData::getMemberTypes(::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getMemberTypes();
}

mapping::EList<::ecore::EDataType_ptr>::ptr_type BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetMemberTypes() {
	throw "not yet implemented";
}

void BasicExtendedMetaData::setMemberTypes(::ecore::EDataType_ptr eDataType,
										   const mapping::EList<::ecore::EDataType_ptr>::ptr_type& memberTypes) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (memberTypes->size() == 0) {
		eAnnotation->removeDetail("memberTypes");
		return;
	}

	auto nameSpace = getNamespace(eDataType);
	::ecore::EString result;
	for (auto memberType : *memberTypes) {
		result += getQualifiedName(nameSpace, memberType);
		result += ' ';
	}

	eAnnotation->setDetail("memberTypes", result.substr(0, result.size() - 1));
	getExtendedMetaData(eDataType)->setMemberTypes(memberTypes);
}

mapping::EList<::ecore::EStructuralFeature_ptr>::ptr_type BasicExtendedMetaData::getAllAttributes(::ecore::EClass_ptr eClass) {
	std::shared_ptr<::ecorecpp::mapping::EList< ::ecore::EStructuralFeature_ptr >> result(
		new ::ecorecpp::mapping::ReferenceEListImpl< ::ecore::EStructuralFeature_ptr, -1, false, false >(
			nullptr, ::ecore::EReference_ptr()));

	auto& allAttributes = eClass->getEAllAttributes();
	for (auto attribute : allAttributes) {
		auto kind = getFeatureKind(attribute);
		if (kind == ATTRIBUTE_FEATURE || kind == ATTRIBUTE_WILDCARD_FEATURE) {
			result->push_back(attribute);
		}
	}
	return result;
}

mapping::EList<::ecore::EStructuralFeature_ptr>::ptr_type BasicExtendedMetaData::getAllElements(::ecore::EClass_ptr eClass) {
	std::shared_ptr<::ecorecpp::mapping::EList< ::ecore::EStructuralFeature_ptr >> result(
		new ::ecorecpp::mapping::ReferenceEListImpl< ::ecore::EStructuralFeature_ptr, -1, false, false >(
			nullptr, ::ecore::EReference_ptr()));

	auto& allFeatures = eClass->getEAllStructuralFeatures();
	for (auto feature : allFeatures) {
		auto kind = getFeatureKind(feature);
		if (kind == ELEMENT_FEATURE || kind == ELEMENT_WILDCARD_FEATURE || kind == GROUP_FEATURE) {
			result->push_back(feature);
		}
	}
	return result;
}

mapping::EList<::ecore::EStructuralFeature_ptr>::ptr_type BasicExtendedMetaData::getAttributes(::ecore::EClass_ptr eClass) {
	std::shared_ptr<::ecorecpp::mapping::EList< ::ecore::EStructuralFeature_ptr >> result(
		new ::ecorecpp::mapping::ReferenceEListImpl< ::ecore::EStructuralFeature_ptr, -1, false, false >(
			nullptr, ::ecore::EReference_ptr()));

	auto& attributes = eClass->getEAttributes();
	for (auto attribute : attributes) {
		auto kind = getFeatureKind(attribute);
		if (kind == ATTRIBUTE_FEATURE || kind == ATTRIBUTE_WILDCARD_FEATURE) {
			result->push_back(attribute);
		}
	}
	return result;
}

mapping::EList<::ecore::EStructuralFeature_ptr>::ptr_type BasicExtendedMetaData::getElements(::ecore::EClass_ptr eClass) {
	std::shared_ptr<::ecorecpp::mapping::EList< ::ecore::EStructuralFeature_ptr >> result(
		new ::ecorecpp::mapping::ReferenceEListImpl< ::ecore::EStructuralFeature_ptr, -1, false, false >(
			nullptr, ::ecore::EReference_ptr()));

	auto& features = eClass->getEStructuralFeatures();
	for (auto feature : features) {
		auto kind = getFeatureKind(feature);
		if (kind == ELEMENT_FEATURE || kind == ELEMENT_WILDCARD_FEATURE || kind == GROUP_FEATURE) {
			result->push_back(feature);
		}
	}
	return result;
}

bool BasicExtendedMetaData::matches(const mapping::EList<::ecore::EString>::ptr_type& wildcards, ::ecore::EString nameSpace) {
	for (auto wildcard : *wildcards)
		if (matches(wildcard, nameSpace))
			return true;
	return false;
}

bool BasicExtendedMetaData::matches(::ecore::EString wildcard, ::ecore::EString nameSpace) {
	if (wildcard.empty())
		return nameSpace.empty();
	// if (wildcard.find("!##")) {
	// 	return !nameSpace.empty() &&
	// 		(!wildcard.endsWith(nameSpace) || wildcard.length() != nameSpace.length() + 3) && 
	// 		!XMLTypePackage.eNS_URI.equals(nameSpace);
	// } else {
	// 	return wildcard.equals("##any") && !XMLTypePackage.eNS_URI.equals(nameSpace)
	// 		|| wildcard.equals(nameSpace);
	// }
	throw "not yet implemented";
}

mapping::EList<::ecore::EString>::ptr_type BasicExtendedMetaData::getWildcards(::ecore::EStructuralFeature_ptr eStructuralFeature) {
	return getExtendedMetaData(eStructuralFeature)->getWildcards();
}

BasicExtendedMetaData::EStringList::ptr_type BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::basicGetWildcards() {
	throw "not yet implemented";
}

void BasicExtendedMetaData::setWildcards(::ecore::EStructuralFeature_ptr eStructuralFeature, const mapping::EList<::ecore::EString>::ptr_type& wildcards) {
	throw "not yet implemented";
	getExtendedMetaData(eStructuralFeature)->setWildcards(wildcards);
}

int BasicExtendedMetaData::getProcessingKind(::ecore::EStructuralFeature_ptr eStructuralFeature) {
	return getExtendedMetaData(eStructuralFeature)->getProcessingKind();
}

int BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::basicGetProcessingKind() {
	auto eAnnotation = m_feature->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("processing")) {
		auto kind = eAnnotation->getDetail("processing");
		for (int i = 1; i < PROCESSING_KINDS_MAX; ++i) {
			if (PROCESSING_KINDS[i] == kind) {
				return i;
			}
		}
	}
	return UNSPECIFIED_PROCESSING;
}

void BasicExtendedMetaData::setProcessingKind(::ecore::EStructuralFeature_ptr eStructuralFeature, int kind) {
		auto eAnnotation = eStructuralFeature->getEAnnotation(ANNOTATION_URI);
	if (kind > 0 && kind < PROCESSING_KINDS_MAX)
		eAnnotation->setDetail("processing", PROCESSING_KINDS[kind]);
	else
		eAnnotation->removeDetail("processing");
	getExtendedMetaData(eStructuralFeature)->setProcessingKind(kind);
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::getAffiliation(
		::ecore::EStructuralFeature_ptr eStructuralFeature) {
	return getExtendedMetaData(eStructuralFeature)->getAffiliation();
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::basicGetAffiliation() {
	auto eAnnotation = m_feature->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("affiliation")) {
		auto qualifiedName = eAnnotation->getDetail("affiliation");
		const auto fragmentIndex = qualifiedName.find_last_of('#');
		if (fragmentIndex == ::ecore::EString::npos) {
			auto ePackage = m_feature->getEContainingClass()->getEPackage();
			auto documentRoot = m_parent->getDocumentRoot(ePackage);
			if (documentRoot)
				return m_parent->getLocalElement(
					documentRoot, m_parent->getNamespace(ePackage), qualifiedName);
		} else if (fragmentIndex == 0) {
			return m_parent->getElement(::ecore::EString(), qualifiedName.substr(1));
		} else {
			return m_parent->getElement(qualifiedName.substr(0, fragmentIndex), qualifiedName.substr(fragmentIndex + 1));
		}
	}

	return ::ecore::EStructuralFeature_ptr();
}

void BasicExtendedMetaData::setAffiliation(::ecore::EStructuralFeature_ptr eStructuralFeature, ::ecore::EStructuralFeature_ptr affiliation) {
	auto eAnnotation = eStructuralFeature->getEAnnotation(ANNOTATION_URI);
	if (!affiliation)
		eAnnotation->removeDetail("affiliation");
	else
		eAnnotation->setDetail(
			"affiliation",
			getQualifiedName(
				getNamespace(eStructuralFeature->getEContainingClass()->getEPackage()),
				affiliation));
	getExtendedMetaData(eStructuralFeature)->setAffiliation(affiliation);
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::getGroup(
		::ecore::EStructuralFeature_ptr eStructuralFeature) {
	return getExtendedMetaData(eStructuralFeature)->getGroup();
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::basicGetGroup() {
	auto eAnnotation = m_feature->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("group")) {
		auto qualifiedName = eAnnotation->getDetail("group");
		const auto fragmentIndex = qualifiedName.find_last_of('#');
		auto eContaingClass = m_feature->getEContainingClass();
		::ecore::EString nameSpace;
		::ecore::EString name;
		if (fragmentIndex == ::ecore::EString::npos) {
			nameSpace = m_parent->getNamespace(eContaingClass->getEPackage());
			name = qualifiedName;
		} else if (fragmentIndex == 0) {
			nameSpace = "";
			name = qualifiedName.substr(1);
		} else {
			nameSpace = qualifiedName.substr(0, fragmentIndex);
			name = qualifiedName.substr(fragmentIndex + 1);
		}

		switch (getFeatureKind()) {
		case ATTRIBUTE_FEATURE:
		case ATTRIBUTE_WILDCARD_FEATURE:
			return m_parent->getAttribute(eContaingClass, nameSpace, name);
		case UNSPECIFIED_FEATURE:
		case ELEMENT_FEATURE:
		case ELEMENT_WILDCARD_FEATURE:
		case GROUP_FEATURE:
			return m_parent->getElement(eContaingClass, nameSpace, name);
		default:
			throw "missing case branch";
		}
	}

	return ::ecore::EStructuralFeature_ptr();
}

void BasicExtendedMetaData::setGroup(::ecore::EStructuralFeature_ptr eStructuralFeature, ::ecore::EStructuralFeature_ptr group) {
	auto eAnnotation = eStructuralFeature->getEAnnotation(ANNOTATION_URI);
	if (!group)
		eAnnotation->removeDetail("group");
	else
		eAnnotation->setDetail(
			"group",
			getQualifiedName(
				getNamespace(eStructuralFeature->getEContainingClass()->getEPackage()),
				group));
	getExtendedMetaData(eStructuralFeature)->setGroup(group);
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::getAffiliation(::ecore::EClass_ptr eClass, ::ecore::EStructuralFeature_ptr eStructuralFeature) {
	if (eClass->getFeatureID(eStructuralFeature) >= 0)
		return eStructuralFeature;

	switch (getFeatureKind(eStructuralFeature)) {
	case ATTRIBUTE_FEATURE:
		if (isDocumentRoot(eStructuralFeature->getEContainingClass())) {
			auto nameSpace = getNamespace(eStructuralFeature);
			auto name = getName(eStructuralFeature);
			auto result = getLocalAttribute(eClass, nameSpace, name);
			if (result)
				return result;

			auto allAttributes = getAllAttributes(eClass);
			for (auto attribute : *allAttributes) {
				if (matches(getWildcards(attribute), nameSpace))
					return attribute;
			}
		}
		return ::ecore::EStructuralFeature_ptr();

	case ELEMENT_FEATURE:
		if (isDocumentRoot(eStructuralFeature->getEContainingClass())) {
			for ( auto affiliation = eStructuralFeature; affiliation;
				  affiliation = getAffiliation(affiliation) ) {
				auto nameSpace = getNamespace(affiliation);
				auto name = getName(affiliation);
				auto result = getLocalElement(eClass, nameSpace, name);
				if (result)
					return result;
			}

			auto nameSpace = getNamespace(eStructuralFeature);
			if (nameSpace == s_xmlTypNsURI)
				return getMixedFeature(eClass);

			auto allElements = getAllElements(eClass);
			for (auto element : *allElements) {
				if (matches(getWildcards(element), nameSpace))
					return element;
			}
		}
		return ::ecore::EStructuralFeature_ptr();

	default:
		return ::ecore::EStructuralFeature_ptr();
	}
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::getAttributeWildcardAffiliation(::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name) {
	auto allAttributes = getAllAttributes(eClass);
	for ( auto attribute : *allAttributes ) {
		if (matches(getWildcards(attribute), nameSpace))
			return attribute;
	}
	return ::ecore::EStructuralFeature_ptr();
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::getElementWildcardAffiliation(::ecore::EClass_ptr eClass, ::ecore::EString nameSpace, ::ecore::EString name) {
	auto allElements = getAllElements(eClass);
	for ( auto element : *allElements ) {
		if (matches(getWildcards(element), nameSpace))
			return element;
	}
	return ::ecore::EStructuralFeature_ptr();

}

int BasicExtendedMetaData::getWhiteSpaceFacet(::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getWhiteSpaceFacet();
}

int BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetWhiteSpaceFacet() {
	auto eAnnotation = m_dataType->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("whiteSpace")) {
		auto kind = eAnnotation->getDetail("whiteSpace");
		for (int i = 1; i < WHITE_SPACE_KINDS_MAX; ++i) {
			if (WHITE_SPACE_KINDS[i] == kind) {
				return i;
			}
		}
	}
	return UNSPECIFIED_WHITE_SPACE;
}

void BasicExtendedMetaData::setWhiteSpaceFacet(::ecore::EDataType_ptr eDataType, int whiteSpace) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (whiteSpace > 0 && whiteSpace < WHITE_SPACE_KINDS_MAX)
		eAnnotation->setDetail("whiteSpace", WHITE_SPACE_KINDS[whiteSpace]);
	else
		eAnnotation->removeDetail("whiteSpace");
	getExtendedMetaData(eDataType)->setWhiteSpaceFacet(whiteSpace);
}

mapping::EList<::ecore::EString>::ptr_type BasicExtendedMetaData::getEnumerationFacet(
		::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getEnumerationFacet();
}

BasicExtendedMetaData::EStringList::ptr_type BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetEnumerationFacet() {
	mapping::EList<::ecore::EString>::ptr_type result(
		new ::ecorecpp::mapping::ReferenceEListImpl< ::ecore::EString, -1, false, false >(
			nullptr, ::ecore::EReference_ptr()));

	auto eAnnotation = m_dataType->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("enumeration")) {
		auto enumerationLiteral = eAnnotation->getDetail("enumeration");
		std::vector<::ecore::EString> tokens;
		boost::split(tokens, enumerationLiteral, boost::is_any_of(" "));
		for ( auto token : tokens ) {
			boost::replace_all(token, "%20", " ");
			boost::replace_all(token, "%25", "%");
			result->push_back(token);
		}
	}

	return result;
}

void BasicExtendedMetaData::setEnumerationFacet(::ecore::EDataType_ptr eDataType,
												const mapping::EList<::ecore::EString>::ptr_type& literals) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (literals->size() == 0) {
		eAnnotation->removeDetail("enumeration");
	} else {
		::ecore::EString result;
		for ( auto literal : *literals ) {
			boost::replace_all(literal, "%", "%25");
			boost::replace_all(literal, " ", "%20");
			result += literal + ' ';
		}
		eAnnotation->setDetail("enumeration", result.substr(0, result.length() - 1));
	}
	getExtendedMetaData(eDataType)->setEnumerationFacet(literals);
}

mapping::EList<::ecore::EString>::ptr_type BasicExtendedMetaData::getPatternFacet(
		::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getPatternFacet();
}

BasicExtendedMetaData::EStringList::ptr_type BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetPatternFacet() {
	mapping::EList<::ecore::EString>::ptr_type result(
		new ::ecorecpp::mapping::ReferenceEListImpl< ::ecore::EString, -1, false, false >(
			nullptr, ::ecore::EReference_ptr()));

	auto eAnnotation = m_dataType->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("pattern")) {
		auto enumerationLiteral = eAnnotation->getDetail("pattern");
		std::vector<::ecore::EString> tokens;
		boost::split(tokens, enumerationLiteral, boost::is_any_of(" "));
		for ( auto token : tokens ) {
			boost::replace_all(token, "%20", " ");
			boost::replace_all(token, "%25", "%");
			result->push_back(token);
		}
	}
	
	return result;
}

void BasicExtendedMetaData::setPatternFacet(::ecore::EDataType_ptr eDataType,
											const mapping::EList<::ecore::EString>::ptr_type& pattern) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (pattern->size() == 0) {
		eAnnotation->removeDetail("pattern");
	} else {
		::ecore::EString result;
		for ( auto literal : *pattern ) {
			boost::replace_all(literal, "%", "%25");
			boost::replace_all(literal, " ", "%20");
			result += literal + ' ';
		}
		eAnnotation->setDetail("enumeration", result.substr(0, result.length() - 1));
	}
	getExtendedMetaData(eDataType)->setPatternFacet(pattern);
}

int BasicExtendedMetaData::getTotalDigitsFacet(::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getTotalDigitsFacet();
}

int BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetTotalDigitsFacet() {
	auto eAnnotation = m_dataType->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("totalDigits")) {
		auto literal = eAnnotation->getDetail("totalDigits");
		try {
			return std::stoi(literal);
		} catch (std::exception& e) { }
	}
	return -1;
}

void BasicExtendedMetaData::setTotalDigitsFacet(::ecore::EDataType_ptr eDataType, int digits) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (digits == -1)
		eAnnotation->removeDetail("totalDigits");
	else
		eAnnotation->setDetail("totalDigits", std::to_string(digits));
	getExtendedMetaData(eDataType)->setTotalDigitsFacet(digits);
}

int BasicExtendedMetaData::getFractionDigitsFacet(::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getFractionDigitsFacet();
}

int BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetFractionDigitsFacet() {
	auto eAnnotation = m_dataType->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("fractionDigits")) {
		auto literal = eAnnotation->getDetail("fractionDigits");
		try {
			return std::stoi(literal);
		} catch (std::exception& e) { }
	}
	return -1;
}

void BasicExtendedMetaData::setFractionDigitsFacet(::ecore::EDataType_ptr eDataType, int digits) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (digits == -1)
		eAnnotation->removeDetail("fractionDigits");
	else
		eAnnotation->setDetail("fractionDigits", std::to_string(digits));
	getExtendedMetaData(eDataType)->setFractionDigitsFacet(digits);
}

int BasicExtendedMetaData::getLengthFacet(::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getLengthFacet();
}

int BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetLengthFacet() {
	auto eAnnotation = m_dataType->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("length")) {
		auto literal = eAnnotation->getDetail("length");
		try {
			return std::stoi(literal);
		} catch (std::exception& e) { }
	}
	return -1;
}

void BasicExtendedMetaData::setLengthFacet(::ecore::EDataType_ptr eDataType, int length) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (length == -1)
		eAnnotation->removeDetail("length");
	else
		eAnnotation->setDetail("length", std::to_string(length));
	getExtendedMetaData(eDataType)->setLengthFacet(length);
}

int BasicExtendedMetaData::getMinLengthFacet(::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getMinLengthFacet();
}

int BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetMinLengthFacet() {
	auto eAnnotation = m_dataType->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("minLength")) {
		auto literal = eAnnotation->getDetail("minLength");
		try {
			return std::stoi(literal);
		} catch (std::exception& e) { }
	}
	return -1;
}

void BasicExtendedMetaData::setMinLengthFacet(::ecore::EDataType_ptr eDataType, int length) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (length == -1)
		eAnnotation->removeDetail("minLength");
	else
		eAnnotation->setDetail("minLength", std::to_string(length));
	getExtendedMetaData(eDataType)->setMinLengthFacet(length);
}

int BasicExtendedMetaData::getMaxLengthFacet(::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getMaxLengthFacet();
}

int BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetMaxLengthFacet() {
	auto eAnnotation = m_dataType->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("maxLength")) {
		auto literal = eAnnotation->getDetail("maxLength");
		try {
			return std::stoi(literal);
		} catch (std::exception& e) { }
	}
	return -1;
}

void BasicExtendedMetaData::setMaxLengthFacet(::ecore::EDataType_ptr eDataType, int length) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (length == -1)
		eAnnotation->removeDetail("maxLength");
	else
		eAnnotation->setDetail("maxLength", std::to_string(length));
	getExtendedMetaData(eDataType)->setMaxLengthFacet(length);
}

::ecore::EString BasicExtendedMetaData::getMinExclusiveFacet(::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getMinExclusiveFacet();
}

BasicExtendedMetaData::EString BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetMinExclusiveFacet() {
	auto eAnnotation = m_dataType->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("minExclusive"))
		return eAnnotation->getDetail("minExclusive");
	return ::ecore::EString();
}

void BasicExtendedMetaData::setMinExclusiveFacet(::ecore::EDataType_ptr eDataType, ::ecore::EString literal) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (literal.empty())
		eAnnotation->removeDetail("minExclusive");
	else
		eAnnotation->setDetail("minExclusive", literal);
	getExtendedMetaData(eDataType)->setMinExclusiveFacet(literal);
}

::ecore::EString BasicExtendedMetaData::getMaxExclusiveFacet(::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getMaxExclusiveFacet();
}

BasicExtendedMetaData::EString BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetMaxExclusiveFacet() {
	auto eAnnotation = m_dataType->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("maxExclusive"))
		return eAnnotation->getDetail("maxExclusive");
	return ::ecore::EString();
}

void BasicExtendedMetaData::setMaxExclusiveFacet(::ecore::EDataType_ptr eDataType, ::ecore::EString literal) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (literal.empty())
		eAnnotation->removeDetail("maxExclusive");
	else
		eAnnotation->setDetail("maxExclusive", literal);
	getExtendedMetaData(eDataType)->setMaxExclusiveFacet(literal);
}

::ecore::EString BasicExtendedMetaData::getMinInclusiveFacet(::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getMinInclusiveFacet();
}

BasicExtendedMetaData::EString BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetMinInclusiveFacet() {
	auto eAnnotation = m_dataType->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("minInclusive"))
		return eAnnotation->getDetail("minInclusive");
	return ::ecore::EString();
}

void BasicExtendedMetaData::setMinInclusiveFacet(::ecore::EDataType_ptr eDataType, ::ecore::EString literal) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (literal.empty())
		eAnnotation->removeDetail("minInclusive");
	else
		eAnnotation->setDetail("minInclusive", literal);
	getExtendedMetaData(eDataType)->setMinInclusiveFacet(literal);
}

::ecore::EString BasicExtendedMetaData::getMaxInclusiveFacet(::ecore::EDataType_ptr eDataType) {
	return getExtendedMetaData(eDataType)->getMaxInclusiveFacet();
}

BasicExtendedMetaData::EString BasicExtendedMetaData::EDataTypeExtendedMetaData::basicGetMaxInclusiveFacet() {
	auto eAnnotation = m_dataType->getEAnnotation(ANNOTATION_URI);
	if (eAnnotation->hasDetail("maxInclusive"))
		return eAnnotation->getDetail("maxInclusive");
	return ::ecore::EString();
}
void BasicExtendedMetaData::setMaxInclusiveFacet(::ecore::EDataType_ptr eDataType, ::ecore::EString literal) {
	auto eAnnotation = eDataType->getEAnnotation(ANNOTATION_URI);
	if (literal.empty())
		eAnnotation->removeDetail("maxInclusive");
	else
		eAnnotation->setDetail("maxInclusive", literal);
	getExtendedMetaData(eDataType)->setMaxInclusiveFacet(literal);
}

::ecore::EPackage_ptr BasicExtendedMetaData::demandPackage(::ecore::EString nameSpace) {
	return ::ecore::EPackage_ptr();
}

::ecore::EClassifier_ptr BasicExtendedMetaData::demandType(::ecore::EString nameSpace, ::ecore::EString name) {
	return ::ecore::EClassifier_ptr();
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::demandFeature(::ecore::EString nameSpace, ::ecore::EString name, bool isElement) {
	return ::ecore::EStructuralFeature_ptr();
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::demandFeature(::ecore::EString nameSpace, ::ecore::EString name, bool isElement, bool isReference) {
	return ::ecore::EStructuralFeature_ptr();
}

mapping::EList<::ecore::EPackage_ptr>::ptr_type BasicExtendedMetaData::demandedPackages() {
	mapping::EList<::ecore::EPackage_ptr>::ptr_type result(
		new ::ecorecpp::mapping::ReferenceEListImpl< ::ecore::EPackage_ptr, -1, false, false >(
			nullptr, ::ecore::EReference_ptr()));
	return result;
}


/*
 * Internal caching structures
 */

bool BasicExtendedMetaData::EPackageExtendedMetaData::isQualified() {
	if (!m_isInitialized)
		setQualified(basicIsQualified());
	return m_isQualified;
}

void BasicExtendedMetaData::EPackageExtendedMetaData::setQualified(bool b) {
	m_isQualified = b;
	m_isInitialized = true;
}

::ecore::EClassifier_ptr BasicExtendedMetaData::EPackageExtendedMetaData::getType(
		const ::ecore::EString& name) {
	auto result = m_nameToClassifier.find(name);

	if (result == m_nameToClassifier.end()) {
		auto& allClassifiers = m_ePackage->getEClassifiers();
		std::cerr << "Sequential insert, len " << allClassifiers.size() << "\n";
		if (allClassifiers.size() != m_nameToClassifier.size()) {
			const auto parent = m_parent;
			for ( auto&& eClassifier : allClassifiers ) {
				/* EMF takes extra effort to keep existing entries. In C++ the
				 * container does this for you. */
				m_nameToClassifier.insert({ parent->getName(eClassifier), eClassifier });
			}
		}

		result = m_nameToClassifier.find(name);
	}
	if (result == m_nameToClassifier.end())
		throw std::logic_error(
		std::string("ExtendedMetaData: EClassifier not found: ") + name);
	return result->second;
}

void BasicExtendedMetaData::EPackageExtendedMetaData::rename(
		const ::ecore::EClassifier_ptr&, const ::ecore::EString&) {
	throw "not yet implemented";
}

std::shared_ptr<BasicExtendedMetaData::EPackageExtendedMetaData>
BasicExtendedMetaData::getExtendedMetaData(
		const ::ecore::EPackage_ptr& ePackage) {
	auto it = m_ePackageExtendedMetaDataCache.find(ePackage.get());
	if (it == m_ePackageExtendedMetaDataCache.end()) {
		it = m_ePackageExtendedMetaDataCache.insert(
			{ePackage.get(), createExtendedMetaData(ePackage)}).first;
	}
	return it->second;
}

std::shared_ptr<BasicExtendedMetaData::EPackageExtendedMetaData>
BasicExtendedMetaData::createExtendedMetaData(
		const ::ecore::EPackage_ptr& ePackage) {
	return std::make_shared<EPackageExtendedMetaData>(this, ePackage);
}



BasicExtendedMetaData::AbstractEClassifierExtendedMetaData::~AbstractEClassifierExtendedMetaData() = default;

const ::ecore::EString BasicExtendedMetaData::UNINITIALIZED_STRING(
	{"-uninitialized-"});


BasicExtendedMetaData::EClassExtendedMetaData::~EClassExtendedMetaData() = default;

BasicExtendedMetaData::EString BasicExtendedMetaData::EClassExtendedMetaData::getName() {
	if (m_name == UNINITIALIZED_STRING)
		setName(basicGetName());
	return m_name;
}

void BasicExtendedMetaData::EClassExtendedMetaData::setName(const EString& name) {
	m_name = name;
}

int BasicExtendedMetaData::EClassExtendedMetaData::getContentKind() {
	if (m_contentKind == UNINITIALIZED_INT)
		setContentKind(basicGetContentKind());
	return m_contentKind;
}

void BasicExtendedMetaData::EClassExtendedMetaData::setContentKind(int kind) {
	m_contentKind = kind;
}

int BasicExtendedMetaData::EClassExtendedMetaData::getDerivationKind() {
	return 0;
}

::ecore::EDataType_ptr BasicExtendedMetaData::EClassExtendedMetaData::getBaseType() {
	return ::ecore::EDataType_ptr();
}

void BasicExtendedMetaData::EClassExtendedMetaData::setBaseType(const ::ecore::EDataType_ptr& baseType) {
	throw std::logic_error("Unsupported operation");
}

::ecore::EDataType_ptr BasicExtendedMetaData::EClassExtendedMetaData::getItemType() {
	return ::ecore::EDataType_ptr();
}

void BasicExtendedMetaData::EClassExtendedMetaData::setItemType(const ::ecore::EDataType_ptr& itemType) {
	throw std::logic_error("Unsupported operation");
}

BasicExtendedMetaData::EDataTypeList::ptr_type BasicExtendedMetaData::EClassExtendedMetaData::getMemberTypes() {
	return EDataTypeList::ptr_type();
}

void BasicExtendedMetaData::EClassExtendedMetaData::setMemberTypes(const EDataTypeList::ptr_type& memberTypes) {
	throw std::logic_error("Unsupported operation");
}

int BasicExtendedMetaData::EClassExtendedMetaData::getWhiteSpaceFacet() {
	return 0;
}

void BasicExtendedMetaData::EClassExtendedMetaData::setWhiteSpaceFacet(int whiteSpace) {
	throw std::logic_error("Unsupported operation");
}

BasicExtendedMetaData::EStringList::ptr_type BasicExtendedMetaData::EClassExtendedMetaData::getEnumerationFacet() {
	return EStringList::ptr_type();
}

void BasicExtendedMetaData::EClassExtendedMetaData::setEnumerationFacet(const EStringList::ptr_type& literals) {
	throw std::logic_error("Unsupported operation");
}

BasicExtendedMetaData::EStringList::ptr_type BasicExtendedMetaData::EClassExtendedMetaData::getPatternFacet() {
	return EStringList::ptr_type();
}

void BasicExtendedMetaData::EClassExtendedMetaData::setPatternFacet(const EStringList::ptr_type& literals) {
	throw std::logic_error("Unsupported operation");
}

int BasicExtendedMetaData::EClassExtendedMetaData::getTotalDigitsFacet() {
	return -1;
}

void BasicExtendedMetaData::EClassExtendedMetaData::setTotalDigitsFacet(int digits) {
	throw std::logic_error("Unsupported operation");
}

int BasicExtendedMetaData::EClassExtendedMetaData::getFractionDigitsFacet() {
	return -1;
}

void BasicExtendedMetaData::EClassExtendedMetaData::setFractionDigitsFacet(int digits) {
	throw std::logic_error("Unsupported operation");
}

int BasicExtendedMetaData::EClassExtendedMetaData::getLengthFacet() {
	return -1;
}

void BasicExtendedMetaData::EClassExtendedMetaData::setLengthFacet(int length) {
	throw std::logic_error("Unsupported operation");
}

int BasicExtendedMetaData::EClassExtendedMetaData::getMinLengthFacet() {
	return -1;
}

void BasicExtendedMetaData::EClassExtendedMetaData::setMinLengthFacet(int length) {
	throw std::logic_error("Unsupported operation");
}

int BasicExtendedMetaData::EClassExtendedMetaData::getMaxLengthFacet() {
	return -1;
}

void BasicExtendedMetaData::EClassExtendedMetaData::setMaxLengthFacet(int length) {
	throw std::logic_error("Unsupported operation");
}

BasicExtendedMetaData::EString BasicExtendedMetaData::EClassExtendedMetaData::getMinExclusiveFacet() {
	return EString();
}

void BasicExtendedMetaData::EClassExtendedMetaData::setMinExclusiveFacet(const EString& literal) {
	throw std::logic_error("Unsupported operation");
}

BasicExtendedMetaData::EString BasicExtendedMetaData::EClassExtendedMetaData::getMaxExclusiveFacet() {
	return EString();
}

void BasicExtendedMetaData::EClassExtendedMetaData::setMaxExclusiveFacet(const EString& literal) {
	throw std::logic_error("Unsupported operation");
}

BasicExtendedMetaData::EString BasicExtendedMetaData::EClassExtendedMetaData::getMinInclusiveFacet() {
	return EString();
}

void BasicExtendedMetaData::EClassExtendedMetaData::setMinInclusiveFacet(const EString& literal) {
	throw std::logic_error("Unsupported operation");
}

BasicExtendedMetaData::EString BasicExtendedMetaData::EClassExtendedMetaData::getMaxInclusiveFacet() {
	return EString();
}

void BasicExtendedMetaData::EClassExtendedMetaData::setMaxInclusiveFacet(const EString& literal) {
	throw std::logic_error("Unsupported operation");
}



BasicExtendedMetaData::EDataTypeExtendedMetaData::~EDataTypeExtendedMetaData() = default;

BasicExtendedMetaData::EString BasicExtendedMetaData::EDataTypeExtendedMetaData::getName() {
	if (m_name == UNINITIALIZED_STRING)
		setName(basicGetName());
	return m_name;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setName(const EString& name) {
	m_name = name;
}

int BasicExtendedMetaData::EDataTypeExtendedMetaData::getContentKind() {
	return 0;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setContentKind(int kind) {
}

::ecore::EDataType_ptr BasicExtendedMetaData::EDataTypeExtendedMetaData::getBaseType() {
	if (!m_baseTypeInitialized)
		setBaseType(basicGetBaseType());
	return m_baseType;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setBaseType(const ::ecore::EDataType_ptr& baseType) {
	m_baseType = baseType;
	m_baseTypeInitialized = true;
	m_derivationKind = UNINITIALIZED_INT;
}

::ecore::EDataType_ptr BasicExtendedMetaData::EDataTypeExtendedMetaData::getItemType() {
	if (!m_itemTypeInitialized)
		setItemType(basicGetItemType());
	return m_itemType;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setItemType(const ::ecore::EDataType_ptr& itemType) {
	m_itemType = itemType;
	m_itemTypeInitialized = true;
	m_derivationKind = UNINITIALIZED_INT;
}

BasicExtendedMetaData::EDataTypeList::ptr_type BasicExtendedMetaData::EDataTypeExtendedMetaData::getMemberTypes() {
	if (!m_memberTypes)
		setMemberTypes(basicGetMemberTypes());
	return m_memberTypes;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setMemberTypes(const EDataTypeList::ptr_type& memberTypes) {
	std::shared_ptr< mapping::EListImpl<::ecore::EDataType_ptr> > newList(
		new mapping::EListImpl<::ecore::EDataType_ptr> );
	newList->insert_all(*memberTypes);

	m_memberTypes = newList;
}

int BasicExtendedMetaData::EDataTypeExtendedMetaData::getWhiteSpaceFacet() {
	if (m_whiteSpace == UNINITIALIZED_INT)
		setWhiteSpaceFacet(basicGetWhiteSpaceFacet());
	return m_whiteSpace;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setWhiteSpaceFacet(int whiteSpace) {
	m_whiteSpace = whiteSpace;
}

BasicExtendedMetaData::EStringList::ptr_type BasicExtendedMetaData::EDataTypeExtendedMetaData::getEnumerationFacet() {
	if (!m_enumerationLiterals)
		setEnumerationFacet(basicGetEnumerationFacet());
	return m_enumerationLiterals;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setEnumerationFacet(const EStringList::ptr_type& literals) {
	std::shared_ptr< mapping::EListImpl<::ecore::EString> > newList(
		new mapping::EListImpl<::ecore::EString> );
	newList->insert_all(*literals);

	m_enumerationLiterals = newList;
}

BasicExtendedMetaData::EStringList::ptr_type BasicExtendedMetaData::EDataTypeExtendedMetaData::getPatternFacet() {
	if (!m_pattern)
		setPatternFacet(basicGetPatternFacet());
	return m_pattern;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setPatternFacet(const EStringList::ptr_type& literals) {
	std::shared_ptr< mapping::EListImpl<::ecore::EString> > newList(
		new mapping::EListImpl<::ecore::EString> );
	newList->insert_all(*literals);

	m_pattern = newList;
}

int BasicExtendedMetaData::EDataTypeExtendedMetaData::getTotalDigitsFacet() {
	if (m_totalDigits == UNINITIALIZED_INT)
		setTotalDigitsFacet(basicGetTotalDigitsFacet());
	return m_totalDigits;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setTotalDigitsFacet(int digits) {
	m_totalDigits = digits;
}

int BasicExtendedMetaData::EDataTypeExtendedMetaData::getFractionDigitsFacet() {
	if (m_fractionDigits == UNINITIALIZED_INT)
		setFractionDigitsFacet(basicGetFractionDigitsFacet());
	return m_fractionDigits;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setFractionDigitsFacet(int digits) {
	m_fractionDigits = digits;
}

int BasicExtendedMetaData::EDataTypeExtendedMetaData::getLengthFacet() {
	if (m_length == UNINITIALIZED_INT)
		setLengthFacet(basicGetLengthFacet());
	return m_length;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setLengthFacet(int length) {
	m_length = length;
}

int BasicExtendedMetaData::EDataTypeExtendedMetaData::getMinLengthFacet() {
	if (m_minLength == UNINITIALIZED_INT)
		setMinLengthFacet(basicGetMinLengthFacet());
	return m_minLength;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setMinLengthFacet(int length) {
	m_minLength = length;
}

int BasicExtendedMetaData::EDataTypeExtendedMetaData::getMaxLengthFacet() {
	if (m_maxLength == UNINITIALIZED_INT)
		setMaxLengthFacet(basicGetMaxLengthFacet());
	return m_maxLength;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setMaxLengthFacet(int length) {
	m_maxLength = length;
}

BasicExtendedMetaData::EString BasicExtendedMetaData::EDataTypeExtendedMetaData::getMinExclusiveFacet() {
	if (m_minExclusive == UNINITIALIZED_STRING)
		setMinExclusiveFacet(basicGetMinExclusiveFacet());
	return m_minExclusive;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setMinExclusiveFacet(const EString& literal) {
	m_minExclusive = literal;
}

BasicExtendedMetaData::EString BasicExtendedMetaData::EDataTypeExtendedMetaData::getMaxExclusiveFacet() {
	if (m_maxExclusive == UNINITIALIZED_STRING)
		setMaxExclusiveFacet(basicGetMaxExclusiveFacet());
	return m_maxExclusive;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setMaxExclusiveFacet(const EString& literal) {
	m_maxExclusive = literal;
}

BasicExtendedMetaData::EString BasicExtendedMetaData::EDataTypeExtendedMetaData::getMinInclusiveFacet() {
	if (m_minInclusive == UNINITIALIZED_STRING)
		setMinInclusiveFacet(basicGetMinInclusiveFacet());
	return m_minInclusive;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setMinInclusiveFacet(const EString& literal) {
	m_minInclusive = literal;
}

BasicExtendedMetaData::EString BasicExtendedMetaData::EDataTypeExtendedMetaData::getMaxInclusiveFacet() {
	if (m_maxInclusive == UNINITIALIZED_STRING)
		setMaxInclusiveFacet(basicGetMaxInclusiveFacet());
	return m_maxInclusive;
}

void BasicExtendedMetaData::EDataTypeExtendedMetaData::setMaxInclusiveFacet(const EString& literal) {
	m_maxInclusive = literal;
}


std::shared_ptr<BasicExtendedMetaData::AbstractEClassifierExtendedMetaData>
BasicExtendedMetaData::getExtendedMetaData(
		const ::ecore::EClassifier_ptr& eClassifier) {
	auto it = m_eClassifierExtendedMetaDataCache.find(eClassifier.get());
	if (it == m_eClassifierExtendedMetaDataCache.end()) {
		it = m_eClassifierExtendedMetaDataCache.insert(
			{eClassifier.get(), createExtendedMetaData(eClassifier)}).first;
	}
	return it->second;
}

std::shared_ptr<BasicExtendedMetaData::AbstractEClassifierExtendedMetaData>
BasicExtendedMetaData::createExtendedMetaData(
		const ::ecore::EClassifier_ptr& eClassifier) {
	if (auto eclass = ::ecore::as<::ecore::EClass>(eClassifier))
		return std::make_shared<EClassExtendedMetaData>(this, eclass);
	else if (auto dataType = ::ecore::as<::ecore::EDataType>(eClassifier))
		return std::make_shared<EDataTypeExtendedMetaData>(this, dataType);
	throw std::logic_error("ExtendedMetaData requested for unknown meta class");
}



::ecore::EString BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::getName() {
	if (m_name == UNINITIALIZED_STRING)
		setName(basicGetName());
	return m_name;
}

void BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::setName(const EString& name) {
	m_name = name;
}

::ecore::EString BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::getNamespace() {
	if (m_namespace == UNINITIALIZED_STRING)
		setNamespace(basicGetNamespace());
	return m_namespace;
}

void BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::setNamespace(const EString& nameSpace) {
	m_namespace = nameSpace;
}

int BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::getFeatureKind() {
	if (m_featureKind == UNINITIALIZED_INT)
		setFeatureKind(basicGetFeatureKind());
	return m_featureKind;
}

void BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::setFeatureKind(int kind) {
	m_featureKind = kind;
}

BasicExtendedMetaData::EStringList::ptr_type BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::getWildcards() {
	if (!m_wildcards)
		setWildcards(basicGetWildcards());
	return m_wildcards;
}

void BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::setWildcards(const EStringList::ptr_type& wildcards) {
	std::shared_ptr< mapping::EListImpl<::ecore::EString> > newList(
		new mapping::EListImpl<::ecore::EString> );
	newList->insert_all(*wildcards);

	m_wildcards = newList;
}

int BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::getProcessingKind() {
	if (m_processingKind == UNINITIALIZED_INT)
		setProcessingKind(basicGetProcessingKind());
	return m_processingKind;
}

void BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::setProcessingKind(int kind) {
	m_processingKind = kind;
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::getGroup() {
	if (!m_groupInitialized)
		setGroup(basicGetGroup());
	return m_group;
}

void BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::setGroup(const ::ecore::EStructuralFeature_ptr& group) {
	m_group = group;
	m_groupInitialized = true;
}

::ecore::EStructuralFeature_ptr BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::getAffiliation() {
	if (!m_affiliationInitialized)
		setAffiliation(basicGetAffiliation());
	return m_affiliation;
}

void BasicExtendedMetaData::EStructuralFeatureExtendedMetaData::setAffiliation(const ::ecore::EStructuralFeature_ptr& affiliation) {
	m_affiliation = affiliation;
	m_affiliationInitialized = true;
}


std::shared_ptr<BasicExtendedMetaData::EStructuralFeatureExtendedMetaData>
BasicExtendedMetaData::getExtendedMetaData(
		const ::ecore::EStructuralFeature_ptr& feature) {
	auto it = m_eStructuralFeatureExtendedMetaDataCache.find(feature.get());
	if (it == m_eStructuralFeatureExtendedMetaDataCache.end()) {
		it = m_eStructuralFeatureExtendedMetaDataCache.insert(
			{feature.get(), createExtendedMetaData(feature)}).first;
	}
	return it->second;
}

std::shared_ptr<BasicExtendedMetaData::EStructuralFeatureExtendedMetaData>
BasicExtendedMetaData::createExtendedMetaData(
		const ::ecore::EStructuralFeature_ptr& feature) {
	return std::make_shared<EStructuralFeatureExtendedMetaData>(this, feature	);
}

} // util
} // ecorecpp
