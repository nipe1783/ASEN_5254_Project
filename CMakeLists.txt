project(AMP-OMPL-Exploration)

cmake_minimum_required (VERSION 3.16)
set (CMAKE_CXX_STANDARD 17)

find_package(ompl REQUIRED) # make sure this is the ompl with the K-CBS implementation
find_package(yaml-cpp REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories(
    includes
    ${OMPL_INCLUDE_DIRS}
    ${YAML_CPP_INCLUDE_DIRS}
    ${PYTHON_INCLUDE_DIRS}
    /usr/local/include/ompl-1.6
    /usr/include/eigen3
)

file(GLOB OMPL-DEMOS RELATIVE ${CMAKE_SOURCE_DIR}/src/ src/*.cpp )


include(CMakePrintHelpers)
cmake_print_variables(OMPL-DEMOS)
cmake_print_variables(CMAKE_SOURCE_DIR)

foreach( demoFile ${OMPL-DEMOS} )
    string( REPLACE ".cpp" "" demoName ${demoFile} )
    add_executable( ${demoName} src/${demoFile} )
    # Make sure YourLib is linked to each app
    target_link_libraries( ${demoName} ${OMPL_LIBRARIES} ${YAML_CPP_LIBRARIES} ${PYTHON_LIBRARIES})
endforeach( demoFile ${OMPL-DEMOS} )

# ignore BOOST deprecated headers
add_definitions("-DBOOST_ALLOW_DEPRECATED_HEADERS")
add_definitions("-DBOOST_BIND_GLOBAL_PLACEHOLDERS")