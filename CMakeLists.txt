cmake_minimum_required(VERSION 3.20)
project(ProgrammingExam)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "~/Qt/6.3.0/gcc_64/lib/cmake")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)

set(MODELS
        Base/Model/model.cpp)

set(VIEWS
        Base/View/view.cpp
        Base/View/audioplayer.cpp Base/View/settings.cpp Base/View/settings.h)

set(CONTROLLERS
        Base/Controller/main_controller.cpp)

set(SOURCES
        Base/main.cpp
        ${MODELS}
        ${VIEWS}
        ${CONTROLLERS}
        )

set(LIBRARIES
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Multimedia
        )


qt6_add_big_resources(RESOURCES resources.qrc)

add_executable(BaseWorking ${SOURCES} ${RESOURCES})

target_link_libraries(BaseWorking ${LIBRARIES})