// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kdm/code/CodeFactory.cpp
 * Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
 * Copyright (C) INCHRON GmbH 2016-2019 <emf4cpp@inchron.com>
 * Copyright (C) INCHRON AG 2019-2021 <emf4cpp@inchron.com>
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

#include <kdm/code/CodeFactory.hpp>

using namespace ::kdm::code;

::ecore::Ptr< ::kdm::code::CodeFactory > CodeFactory::s_holder;

::kdm::code::CodeFactory_ptr CodeFactory::_instance()
{
    if (!s_holder.get())
        s_holder = ::ecore::Ptr < CodeFactory > (new CodeFactory());

    return s_holder;
}

void CodeFactory::_setFactoryInstance(const CodeFactory_ptr &fac)
{
    CodePackage::_instance()->setEFactoryInstance(fac);
    s_holder = fac;
}
