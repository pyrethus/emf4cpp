set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -funroll-loops")

# test
add_executable(test-nil-reference test-nil-reference.cpp)
target_link_libraries(test-nil-reference emf4cpp-ecorecpp emf4cpp-ecore emf4cpp-nil)

add_test(NAME test-nil-reference COMMAND test-nil-reference WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
