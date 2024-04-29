cmake_minimum_required(VERSION 3.21.1)

project(lumen LANGUAGES CXX)

# Set C++17 Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# AUTOMOC must be set to ON (DO NOT CHANGE!!!)
set(CMAKE_AUTOMOC ON)
# Auto-embed resources in the target binary
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.3 REQUIRED COMPONENTS Core Qml Quick)

if (Qt6_VERSION VERSION_GREATER_EQUAL 6.3)
    qt_standard_project_setup()
endif()

qt_add_executable(${PROJECT_NAME}
    application.qrc
    src/Main.cpp
    src/Models/Location.h
    src/Models/Location.cpp
    src/Models/Doctor.h
    src/Models/Doctor.cpp
    src/Models/TA.h
    src/Models/TA.cpp
    src/Models/Course.h
    src/Models/Course.cpp
    src/Models/Lecture.h
    src/Models/Lecture.cpp
    src/Models/Section.h
    src/Models/Section.cpp
    src/Models/Models.h
    src/JsonSerializable.h
    src/JsonReader.h
    src/RepositoryManager.h
    src/RepositoryManager.cpp
)

qt_add_resources(${PROJECT_NAME} "configuration"
    PREFIX "/"
    FILES
        qtquickcontrols2.conf
)

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
        qml/LandPage.qml
        qml/LandPageButton.qml
        qml/ManImage.qml
        qml/TextLandPage.qml
        qml/EditorHomePage.qml
        qml/YellowLinesImage.qml
        qml/LumenLogo.qml
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        "./src"
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt6::Core
        Qt6::Qml
        Qt6::Quick
)

add_subdirectory(test/)
