#include <ecorecpp.hpp>

#include <iostream>

#include "../EOperationBody.hpp"
#include "../EOperationBody/EOperationBodyFactory.hpp"
#include "../EOperationBody/Integer.hpp"

int main(int argc, char* argv[])
{
    ::ecore::EPackage_ptr _epkg = ::EOperationBody::EOperationBodyPackage::_instance();
    ::ecorecpp::MetaModelRepository::_instance()->load(_epkg);

	auto l = ::EOperationBody::create<::EOperationBody::Integer>();
	l->setValue(18);
	auto r = ::EOperationBody::create<::EOperationBody::Integer>();
	r->setValue(23);

	auto sum = l->add(l, r);
	sum->increment();

	std::cout << "expected 42, got " << sum->getValue() << "\n";
}
