#!/bin/sh

../org.csu.emf4cpp.generator/emf4cpp.generator.sh \
    --internal --emf4cpp '${CMAKE_CURRENT_SOURCE_DIR}/../builds/emf4cpp-generator-2.0.0-${CMAKE_BUILD_TYPE_LOWER}' \
    XMLType.ecore
