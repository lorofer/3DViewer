cmake_minimum_required(VERSION 3.10)
project(3dviewer)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS OFF)


# Исходники
set(SOURCES_DIR src)
set(SOURCES_FILES
	${SOURCES_DIR}/main.cc
	${SOURCES_DIR}/obj_parser.cc
	${SOURCES_DIR}/model.cc
)
# Desktop
set(DESKTOP_DIR ${SOURCES_DIR}/desktop)
set(DESKTOP_FILES
	${DESKTOP_DIR}/desktop.cc
)


# Qt libs
find_package(Qt6 REQUIRED COMPONENTS
	Core
	Widgets
	OpenGLWidgets
)
set(QT_LIBS
	Qt6::Core
	Qt6::Widgets
	Qt6::OpenGLWidgets
)
# Настройка Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set(PARSER_TEST parser_test.out)
add_executable(${PARSER_TEST}
	${SOURCES_FILES}
)
target_include_directories(${PARSER_TEST} PRIVATE
	${SOURCES_DIR}
)


set(DESKTOP_TARGET 3dviewer_desktop.out)
add_executable(${DESKTOP_TARGET}
	${DESKTOP_FILES}
)
target_link_libraries(${DESKTOP_TARGET} PRIVATE
	${QT_LIBS}
)