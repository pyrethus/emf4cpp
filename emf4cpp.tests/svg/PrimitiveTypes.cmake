
#
# PrimitiveTypes.cmake
# Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
# Copyright (C) INCHRON GmbH 2016-2018 <emf4cpp@inchron.com>
#
# EMF4CPP is free software: you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# EMF4CPP is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#


set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -funroll-loops")

string(TOLOWER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE_LOWER)

set(PrimitiveTypes_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/PrimitiveTypes.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PrimitiveTypes/PrimitiveTypesPackage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PrimitiveTypes/PrimitiveTypesFactory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PrimitiveTypes/PrimitiveTypesPackageImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PrimitiveTypes/PrimitiveTypesFactoryImpl.cpp
)

set(PrimitiveTypes_HEADERS
	${CMAKE_CURRENT_SOURCE_DIR}/PrimitiveTypes.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PrimitiveTypes_forward.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PrimitiveTypes/PrimitiveTypesPackage.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PrimitiveTypes/PrimitiveTypesFactory.hpp
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/PrimitiveTypes.hpp DESTINATION include/emf4cpp/)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/PrimitiveTypes_forward.hpp DESTINATION include/emf4cpp/)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/PrimitiveTypes/PrimitiveTypesFactory.hpp DESTINATION include/emf4cpp/PrimitiveTypes)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/PrimitiveTypes/PrimitiveTypesPackage.hpp DESTINATION include/emf4cpp/PrimitiveTypes)   
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/PrimitiveTypes/dllPrimitiveTypes.hpp DESTINATION include/emf4cpp/PrimitiveTypes)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../../builds/emf4cpp-generator-2.0.0-${CMAKE_BUILD_TYPE_LOWER}/include/emf4cpp ${CMAKE_CURRENT_SOURCE_DIR}/../../builds/emf4cpp-generator-2.0.0-${CMAKE_BUILD_TYPE_LOWER}/include/emf4cpp)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../builds/emf4cpp-generator-2.0.0-${CMAKE_BUILD_TYPE_LOWER}/lib)

add_library(emf4cpp-PrimitiveTypes SHARED ${PrimitiveTypes_HEADERS} ${PrimitiveTypes_SOURCES})
set_target_properties(emf4cpp-PrimitiveTypes PROPERTIES COMPILE_FLAGS "-DMAKE_PRIMITIVETYPES_DLL" VERSION 0.0.1 SOVERSION 1)
target_link_libraries(emf4cpp-PrimitiveTypes emf4cpp-ecore)

install(TARGETS emf4cpp-PrimitiveTypes DESTINATION lib)

