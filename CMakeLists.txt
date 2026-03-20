cmake_minimum_required(VERSION 3.10)
project(3dviewer)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS OFF)


# Исходники
set(SRC_DIR src)
set(MAIN ${SRC_DIR}/main.cc)
# Исходники model
set(MODEL_DIR ${SRC_DIR}/model)
set(MODEL_FILES
	${MODEL_DIR}/obj_parser.cc
	${MODEL_DIR}/wireframe.cc
	${MODEL_DIR}/model.cc
)
# Исходники view
set(VIEW_DIR ${SRC_DIR}/desktop)
set(VIEW_FILES
	${VIEW_DIR}/view.cc
	${VIEW_DIR}/wireframe_controller_widget.cc
	${VIEW_DIR}/wireframe_widget.cc
)
# Исходники controller
set(CONTROLLER_DIR ${SRC_DIR}/controller)
set(CONTROLLER_FILES
	${CONTROLLER_DIR}/controller.cc
)


# Qt & OpenGL libs
find_package(Qt6 REQUIRED COMPONENTS
	Core
	Widgets
	OpenGLWidgets
)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
set(QT_LIBS
	Qt6::Core
	Qt6::Widgets
	Qt6::OpenGLWidgets
	OpenGL::GL
	OpenGL::GLU
)
# Настройка Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set(3D_VIEWER 3dviewer.out)
add_executable(${3D_VIEWER}
	${MODEL_FILES}
	${VIEW_FILES}
	${CONTROLLER_FILES}
	${MAIN}
)
target_include_directories(${3D_VIEWER} PRIVATE
	${MODEL_DIR}
	${VIEW_DIR}
	${CONTROLLER_DIR}
)
target_link_libraries(${3D_VIEWER} PRIVATE
	${QT_LIBS}
)


find_package(GTest REQUIRED)
set(TESTS_LIBS
    GTest::gtest
    GTest::gtest_main
)

set(TESTS_TARGET tests.out)
set(TESTS_DIR tests)
set(TESTS_FILES
	${TESTS_DIR}/model_tests.cc
)
add_executable(${TESTS_TARGET}
	${TESTS_FILES}
	${MODEL_FILES}
)
target_include_directories(${TESTS_TARGET} PRIVATE
	${MODEL_DIR}
)
target_link_libraries(${TESTS_TARGET} PRIVATE
    ${TESTS_LIBS}
)


# Цели из задания
install(
	TARGETS ${3D_VIEWER}
	DESTINATION ${CMAKE_BINARY_DIR}
)
add_custom_target(
	uninstall
	COMMAND rm -f ${3D_VIEWER}
)
set_directory_properties(PROPERTIES
    ADDITIONAL_CLEAN_FILES "${CMAKE_CURRENT_BINARY_DIR}/3DViewer_v2.0.tar.gz"
)
# add_custom_target(dvi)
add_custom_target(
	dist ALL
	DEPENDS ${3D_VIEWER}
	COMMAND tar -czvf 3DViewer_v2.0.tar.gz ${3D_VIEWER}
)
add_custom_target(
	tests ALL
	DEPENDS ${TESTS_TARGET}
)


file(GLOB_RECURSE ALL_FILES 
    "${SRC_DIR}/*.cc" "${SRC_DIR}/*.h"
    "${MODEL_DIR}/*.cc" "${MODEL_DIR}/*.h"
    "${VIEW_DIR}/*.cc" "${VIEW_DIR}/*.h"
    "${CONTROLLER_DIR}/*.cc" "${CONTROLLER_DIR}/*.h"
)

add_custom_target(
	clang-format-apply
	COMMAND cp ${CMAKE_CURRENT_LIST_DIR}/materials/linters/.clang-format ${CMAKE_CURRENT_LIST_DIR}
	COMMAND clang-format -i ${ALL_FILES}
	COMMAND rm -f ${CMAKE_CURRENT_LIST_DIR}/.clang-format
)
add_custom_target(
	clang-format-check
	COMMAND cp ${CMAKE_CURRENT_LIST_DIR}/materials/linters/.clang-format ${CMAKE_CURRENT_LIST_DIR}
	COMMAND clang-format -n ${ALL_FILES}
	COMMAND rm -f ${CMAKE_CURRENT_LIST_DIR}/.clang-format
)