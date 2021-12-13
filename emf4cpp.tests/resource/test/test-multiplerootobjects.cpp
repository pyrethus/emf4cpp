#include <cassert>
#include <unordered_map>
#include <string>

#include <ecorecpp/resource/ResourceSet.hpp>
#include <ecorecpp/resource/XMLResource.hpp>
#include <ecorecpp/MetaModelRepository.hpp>

#include <ecore.hpp>
#include <ResourceTests.hpp>

int main(int argc, char* argv[])
{
    auto factory = ::ResourceTests::ResourceTestsFactory::_instance();

	auto no1 = factory->createNamedObject();
	no1->setName("Object1");
	auto root = factory->createRoot();
	auto referrer = factory->createReferrer();
	root->getReferrers().push_back(referrer);
	auto target = factory->createReferenceTarget();
	referrer->setReference(target);

	const QUrl file = QUrl::fromLocalFile("./resourcetest_multiroot.xml");
	::ecorecpp::resource::ResourceSet rSet;
	rSet.getResourceFactoryRegistry()
			->getProtocolToFactoryMap()[file.scheme().toStdString()].reset(
					new ::ecorecpp::resource::XMLResourceFactory() );
	auto resource = rSet.createResource(file);
	resource->getContents()->push_back(no1);
	resource->getContents()->push_back(root);
	resource->getContents()->push_back(target);
	resource->save();

	::ecorecpp::MetaModelRepository::_instance()->load(::ResourceTests::ResourceTestsPackage::_instance());
	auto resource2 = rSet.createResource(file);
	resource2->load();
	const QUrl file1 = QUrl::fromLocalFile("./resourcetest_multiroot_2.xml");
	resource2->setURI(file1);
	resource2->save();

    return 0;
}

