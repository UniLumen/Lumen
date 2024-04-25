cmake_minimum_required(VERSION 3.21.1)

<<<<<<< HEAD
project(lumen LANGUAGES CXX)

# Set C++17 Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
=======
project(lumenApp LANGUAGES CXX)
>>>>>>> af28fad (Migrate from QtQuick Design Studio project to QtQuick project)

# AUTOMOC must be set to ON (DO NOT CHANGE!!!)
set(CMAKE_AUTOMOC ON)
# Auto-embed resources in the target binary
set(CMAKE_AUTORCC ON)

<<<<<<< HEAD
<<<<<<< HEAD
find_package(Qt6 6.3 REQUIRED COMPONENTS Core Qml Quick)
=======
find_package(Qt6 6.2 REQUIRED COMPONENTS Core Qml Quick)
>>>>>>> af28fad (Migrate from QtQuick Design Studio project to QtQuick project)
=======
find_package(Qt6 6.2 REQUIRED COMPONENTS Core Qml Quick QuickControls2)
>>>>>>> b9ca6aa (changed CMake file to include Qt Quick Controls library)

if (Qt6_VERSION VERSION_GREATER_EQUAL 6.3)
    qt_standard_project_setup()
endif()

<<<<<<< HEAD
qt_add_executable(${PROJECT_NAME}
    application.qrc
    src/Main.cpp
)
=======
qt_add_executable(${PROJECT_NAME} src/Main.cpp)
>>>>>>> af28fad (Migrate from QtQuick Design Studio project to QtQuick project)

qt_add_resources(${PROJECT_NAME} "configuration"
    PREFIX "/"
    FILES
        qtquickcontrols2.conf
)

<<<<<<< HEAD
set_source_files_properties(qml/Constants.qml
    PROPERTIES
        QT_QML_SINGLETON_TYPE true
)

qt_add_qml_module(${CMAKE_PROJECT_NAME}
    URI "Lumen"
    VERSION 1.0
    RESOURCE_PREFIX "/qt/qml"
    QML_FILES
        qml/Main.qml
        qml/Constants.qml
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        "./src"
)

=======
target_include_directories(${PROJECT_NAME}
    PRIVATE
        "./src"
)

>>>>>>> af28fad (Migrate from QtQuick Design Studio project to QtQuick project)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt6::Core
        Qt6::Qml
        Qt6::Quick
        Qt6::QuickControls2
)

add_subdirectory(qml/)
add_subdirectory(test/)
