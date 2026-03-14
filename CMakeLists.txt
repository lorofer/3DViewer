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
	${MODEL_DIR}/model.cc
	${MODEL_DIR}/model_facade.cc
)
# Исходники view
set(VIEW_DIR ${SRC_DIR}/desktop)
set(VIEW_FILES
	${VIEW_DIR}/view.cc
	${VIEW_DIR}/desktop.cc
)
# Исходники controller
set(CONTROLLER_DIR ${SRC_DIR}/controller)
set(CONTROLLER_FILES
	${CONTROLLER_DIR}/controller.cc
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
	OpenGL::GL
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