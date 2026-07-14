file(GLOB_RECURSE EQTLOGGER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(EqtLogger STATIC ${EQTLOGGER_SOURCES})

target_include_directories(EqtLogger PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)