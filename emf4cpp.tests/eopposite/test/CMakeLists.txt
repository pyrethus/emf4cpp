include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/..  ${CMAKE_CURRENT_SOURCE_DIR}/../../../emf4cpp)
link_directories(/opt/emf4cpp/lib)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -funroll-loops")

# test
add_executable(test-eopposite test.cpp)
target_link_libraries(test-eopposite emf4cpp-ecorecpp emf4cpp-ecore emf4cpp-eopposite)

add_test(NAME test-eopposite COMMAND test-eopposite)
