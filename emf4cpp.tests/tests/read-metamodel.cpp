#include <ecorecpp.hpp>
#include <ecorecpp/resource/ResourceSet.hpp>
#include <ecorecpp/resource/XMLResource.hpp>
#include <ecore/EcorePackage.hpp>

int main(int argc, char* argv[])
{
    using ::ecorecpp::resource::Resource;
    using ::ecorecpp::resource::ResourceSet;
    // ::ecorecpp::util::print_all(::ecore::EcorePackage::_instance());

    assert(argc > 1);

    ::ecorecpp::MetaModelRepository_ptr mmr =
            ::ecorecpp::MetaModelRepository::_instance();

    for (int i = 1; i < argc; i++)
    {
        try
        {
            QUrl root{QUrl::fromLocalFile(argv[i])};
            root.setFragment("//");

            ResourceSet::getInstance().getResourceFactoryRegistry()
                    ->getProtocolToFactoryMap()[root.scheme().toStdString()].reset(
                            new ::ecorecpp::resource::XMLResourceFactory() );

            ::ecore::EObject_ptr _eobj = ResourceSet::getInstance().getEObject(root, true);

            assert(_eobj);

            ::ecore::EPackage_ptr _epkg = ::ecore::as<
                    ::ecore::EPackage >(_eobj);

            assert(_epkg);

            std::cout << _eobj.get();

            mmr->load(_epkg);
        } catch (const char* e)
        {
            std::cout << e << std::endl;
        }
    }
}

