file(GLOB_RECURSE EQTMARKETGW_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(EqtMarketGW
    app.cpp
    ${EQTMARKETGW_SOURCES}
)

# Can't compile until Protocol/include/*.hpp exist
add_dependencies(EqtMarketGW generate_protocol_headers)

target_include_directories(EqtMarketGW PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${PROTOCOL_INCLUDE}
)

target_link_libraries(EqtMarketGW PRIVATE
    asio_headers
    pthread
)
