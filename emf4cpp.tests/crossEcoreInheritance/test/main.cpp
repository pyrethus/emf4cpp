/* -*- C++ -*-
 *
 * Copyright 2019 INCHRON Gmbh <info@inchron.com>
 */
#include <iostream>

#include <ecore_forward.hpp>
#include <ecore/EClass.hpp>

#include <base.hpp>
#include <derived.hpp>


void print(const ::ecore::EClass_ptr& eClass) {
	std::cout << "EClass: " << eClass->getName() << "; Features: " << '\n';
	for ( auto feature : eClass->getEAllStructuralFeatures() ) {
		std::cout << feature->getName() << ": ContainerClass: " << feature->getEContainingClass()->getName()
			<< "; Container Class ID: " << feature->getFeatureID()
			<< "; (derived) Class ID: " << eClass->getFeatureID(feature) << '\n';
	}

	std::cout << std::endl;
}

int main() {

	/*auto basePackage =*/ ::base::BasePackage::_instance();
	/*auto derivedPackage =*/ ::derived::DerivedPackage::_instance();

	auto base01 = ::base::create<::base::Base01>();
	print(base01->eClass());
	auto base02 = ::base::create<::base::Base02>();
	print(base02->eClass());
	auto base03 = ::base::create<::base::Base03>();
	print(base03->eClass());
	auto base10 = ::base::base1::create<::base::base1::Base10>();
	print(base10->eClass());
	auto base11 = ::base::base1::create<::base::base1::Base11>();
	print(base11->eClass());
	auto base20 = ::base::base1::base2::create<::base::base1::base2::Base20>();
	print(base20->eClass());

	auto derived01 = ::derived::create<::derived::Derived01>();
	print(derived01->eClass());
	auto derived02 = ::derived::create<::derived::Derived02>();
	print(derived02->eClass());

	return 0;
}
