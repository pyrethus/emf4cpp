/* -*- C++ -*-
 *
 * Copyright 2016, 2017 INCHRON Gmbh <info@inchron.com>
 */
#include <iostream>

#include <ecore_forward.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EPackage.hpp>
#include <ecorecpp.hpp>
#include <ecorecpp/resource/ResourceSet.hpp>
#include <ecorecpp/resource/XMLResource.hpp>

#include <v_1_0/edate.hpp>
#include <v_2_0/edate.hpp>
#include <v_3_0/edate.hpp>



namespace effective = v_3_0::edate;

ecore::Ptr<ecore::EObject> createModel(const char* option) {
	switch (option[0]) {
	case '1': {
		auto top1 = v_1_0::edate::create<v_1_0::edate::Apollo11>();
		top1->setMember(v_1_0::edate::create<v_1_0::edate::Person>());
		return top1;
	} break;

	case '2': {
		auto top2 = v_2_0::edate::create<v_2_0::edate::Apollo11>();
		top2->setMember(v_2_0::edate::create<v_2_0::edate::Person>());
		return top2;
	} break;

	case '3': {
		auto top3 = v_3_0::edate::create<v_3_0::edate::Apollo11>();
		top3->setMember(v_3_0::edate::create<v_3_0::edate::Person>());
		return top3;
	} break;
	}

	return ecore::Ptr<ecore::EObject>();
}

void dumpModel(const ecore::Ptr<ecore::EObject>& top) {
	if (!top)
		return;

	QUrl outputUrl = QUrl::fromLocalFile("-");
	::ecorecpp::resource::Resource_ptr output =
		  new ecorecpp::resource::XMLResource(outputUrl);

	output->getContents()->push_back(top);

	std::ostringstream stream;
	output->save(stream);
	std::cout << stream.str();
}


std::string readStdIn() {
	const int ReadBufferSize = 1024;
	char readBuffer[ReadBufferSize+1];
	std::string xmi;

	while (1) {
		auto bytesRead = read(0, readBuffer, ReadBufferSize);
		if (bytesRead <= 0)
			break;
		readBuffer[bytesRead] = '\0';
		xmi += readBuffer;
	}

	return xmi;
}

ecore::Ptr<ecore::EObject> parseModel(const std::string& xmi) {
	using ::ecorecpp::resource::Resource;
	using ::ecorecpp::resource::ResourceSet;

	QUrl file = QUrl::fromLocalFile("-");
	/* This is a simple standalone application. No need to consider any
	 * preexisting XMLResourceFactorys. */
	ResourceSet::getInstance().getResourceFactoryRegistry()
		->getProtocolToFactoryMap()[ file.scheme().toStdString() ].reset(
			new ::ecorecpp::resource::XMLResourceFactory() );

	ecore::Ptr<Resource> input = ResourceSet::getInstance().createResource(file);

	std::istringstream istream(xmi);
	input->load(istream);

	ecore::EObject_ptr eObject = input->getContents()->get(0);
	if (eObject) {
		std::cerr << "Read an instance of " << eObject->eClass()->getName()
				  << " from package " << eObject->eClass()->getEPackage()->getNsURI()
				  << "\n\n";
	}

	return eObject;
}



int main(int argc, char* argv[]) {
	auto mmr = ecorecpp::MetaModelRepository::_instance();
	mmr->load(v_1_0::edate::EdatePackage::_instance());
	mmr->load(v_2_0::edate::EdatePackage::_instance());
	mmr->load(v_3_0::edate::EdatePackage::_instance());

	if (argc > 1) {
		dumpModel( createModel( argv[1] ) );
		return 0;
	}

	auto xmi = readStdIn();
	auto in = parseModel(xmi);
	dumpModel(in);

	return 0;
}
