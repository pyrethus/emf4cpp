#include <ecorecpp/MetaModelRepository.hpp>
#include <ecorecpp/parser/parser.hpp>
#include <nil/Root.hpp>
#include <nil/NilPackage.hpp>

int main() {
    auto nilPackage = nil::NilPackage::_instance();
    ecorecpp::MetaModelRepository::_instance()->load(nilPackage);

    ecorecpp::parser::parser parser;
    auto eObject = parser.load("nil.xmi");

    {
        nil::Root_ptr nil (ecore::as<nil::Root>(eObject));
        if (nil->getReference())
            return 1;
        if (nil->getManyReference().size() != 0)
            return 1;
        if (nil->getContainmentReference())
            return 1;
        if (nil->getManyContainmentReference().size() != 0)
            return 1;
    }

    return 0;
}
