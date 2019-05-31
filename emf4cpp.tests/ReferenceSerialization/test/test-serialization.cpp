#include <QUrl>

#include <ecorecpp/resource/ResourceSet.hpp>
#include <ecorecpp/resource/XMLResource.hpp>
#include <ecorecpp/MetaModelRepository.hpp>

#include <ecore.hpp>
#include <ReferenceSerialization.hpp>

namespace rs = ::ReferenceSerialization;
namespace er = ::ecorecpp::resource;
int main(int argc, char* argv[])
{
	rs::ReferenceSerializationFactory_ptr serializationFactory = rs::ReferenceSerializationFactory::_instance();
	rs::Container_ptr container = serializationFactory->createContainer();

	rs::Content_ptr cont1 = serializationFactory->createContent();
	rs::Content_ptr cont2 = serializationFactory->createContent();
	rs::Content_ptr cont3 = serializationFactory->createContent();

	container->getContents().push_back(cont1);
	container->getContents().push_back(cont2);
	container->getContents().push_back(cont3);

	container->getReferences().push_back(cont1);
	container->getReferences().push_back(cont2);
	container->getReferences().push_back(cont3);

	rs::Child_ptr child = serializationFactory->createChild();
	container->setChild(child);
	container->setChildRef(child);

	QUrl file = QUrl::fromLocalFile("./referenceSerialization1.xml");

	er::ResourceSet rSet;
	rSet.getResourceFactoryRegistry()
			->getProtocolToFactoryMap()[file.scheme().toStdString()].reset(
					new ::ecorecpp::resource::XMLResourceFactory() );

	er::Resource_ptr resource = rSet.createResource(file);

	std::cerr << "Initial size of content list: " << container->getContents().size() << std::endl;
	std::cerr << "Initial size of reference list: " << container->getReferences().size() << std::endl;
	resource->getContents()->push_back(container);
	resource->save();

	std::cerr << "Remove one element from content list." << std::endl;
	container->getContents().remove(cont2);
	cont2.reset();
	std::cerr << "Size of content list: " << container->getContents().size() << std::endl;
	std::cerr << "Size of reference list: " << container->getReferences().size() << std::endl;

	const QUrl file1 = QUrl::fromLocalFile("./referenceSerialization2.xml");
	resource->setURI(file1);
	resource->save();
	std::cerr << "Size of content list after serialization: " << container->getContents().size() << std::endl;
	std::cerr << "Size of reference list after serialization: " << container->getReferences().size() << std::endl;

	container->setChild(nullptr);
	child.reset();
	const QUrl file2 = QUrl::fromLocalFile("./referenceSerialization3.xml");
	resource->setURI(file2);
	resource->save();

    return 0;
}

