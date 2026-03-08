cmake_minimum_required(VERSION 3.10)
project(3dviewer)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS OFF)


set(SOURCES_DIR src)
set(SOURCES_FILES
	${SOURCES_DIR}/main.cc
	${SOURCES_DIR}/obj_parser.cc
	${SOURCES_DIR}/model.cc
)


set(PARSER_TEST parser_test.out)
add_executable(${PARSER_TEST}
	${SOURCES_FILES}
)
target_include_directories(${PARSER_TEST} PRIVATE
	${SOURCES_DIR}
)