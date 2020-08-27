cmake_minimum_required(VERSION 3.5)

project (tianchi_example)

set (CMAKE_CXX_STANDARD 11)

add_library(tianchi_example SHARED
    src/plugin_build.cc
    src/plugin_searcher.cc
)

target_link_libraries(tianchi_example
    # path to libaitheta2.so file
	${PROJECT_SOURCE_DIR}/lib/libaitheta2.so.2.2.0
)

target_include_directories(tianchi_example
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    PUBLIC ${PROJECT_SOURCE_DIR}/deps/aitheta2
    PUBLIC ${PROJECT_SOURCE_DIR}/deps
)
