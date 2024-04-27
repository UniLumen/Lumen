set_source_files_properties(Constants.qml
    PROPERTIES
        QT_QML_SINGLETON_TYPE true
)

qt6_add_qml_module(${CMAKE_PROJECT_NAME}
    URI "lumen"
    VERSION 1.0
    RESOURCE_PREFIX "/qt/qml"
    QML_FILES
        Main.qml
        Constants.qml
        CardTemplate.qml
        CourseEditor.qml
)
