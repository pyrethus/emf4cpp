include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/..  ${CMAKE_CURRENT_SOURCE_DIR}/../../../emf4cpp)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -funroll-loops")

# test
add_executable(test-serialization test-serialization.cpp)
target_link_libraries(test-serialization emf4cpp-ecorecpp emf4cpp-ecore emf4cpp-ReferenceSerialization)

add_test(NAME test-serialization COMMAND test-serialization)
