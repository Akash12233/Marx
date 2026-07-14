cmake_minimum_required(VERSION 3.20)
project(ExecutionManagementSystem CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Python3 REQUIRED COMPONENTS Interpreter)

# ---------------------------------------------------------------------------
# Protocol header generation (shared by every component below)
# ---------------------------------------------------------------------------
set(PROTOCOL_DIR       ${CMAKE_SOURCE_DIR}/Protocol)
set(PROTOCOL_SCHEMA    ${PROTOCOL_DIR}/schema)
set(PROTOCOL_INCLUDE   ${PROTOCOL_DIR}/include)
set(PROTOCOL_GENERATOR ${PROTOCOL_DIR}/generator/generator.py)
set(PROTOCOL_STAMP     ${CMAKE_BINARY_DIR}/protocol_generated.stamp)

file(GLOB_RECURSE PROTOCOL_SCHEMA_FILES    ${PROTOCOL_SCHEMA}/*.xml)
file(GLOB_RECURSE PROTOCOL_GENERATOR_FILES ${PROTOCOL_DIR}/generator/*.py
                                            ${PROTOCOL_DIR}/generator/templates/*.j2)

add_custom_command(
    OUTPUT  ${PROTOCOL_STAMP}
    COMMAND ${Python3_EXECUTABLE} ${PROTOCOL_GENERATOR}
    COMMAND ${CMAKE_COMMAND} -E touch ${PROTOCOL_STAMP}
    DEPENDS ${PROTOCOL_SCHEMA_FILES} ${PROTOCOL_GENERATOR_FILES}
    WORKING_DIRECTORY ${PROTOCOL_DIR}/generator
    COMMENT "Generating protocol headers from XML schema"
    VERBATIM
)
add_custom_target(generate_protocol_headers DEPENDS ${PROTOCOL_STAMP})

# ---------------------------------------------------------------------------
# Components — each owns its own CMakeLists.txt
# ---------------------------------------------------------------------------
#add_subdirectory(EqLogger)
add_subdirectory(EqtMarketGW)

# ---------------------------------------------------------------------------
# Tests
# ---------------------------------------------------------------------------
enable_testing()
if(EXISTS ${CMAKE_SOURCE_DIR}/Test/CMakeLists.txt)
    add_subdirectory(Test)
endif()