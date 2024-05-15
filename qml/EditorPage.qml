import QtQuick
import QtQuick.Layouts

Item {
    implicitWidth: Constants.widthDefault
    implicitHeight: Constants.heightDefault

    LumenLogo {
        id: lumenLogo
    }

    EditorTabBar {
        id: editorTabBar
        anchors {
            left: lumenLogo.right
            right: parent.right
            bottom: lumenLogo.bottom
            leftMargin: 20
            bottomMargin: -8
        }
    }

    StackLayout {
        id: stackView
        currentIndex: editorTabBar.currentIndex
        anchors {
            top: lumenLogo.bottom
            right: parent.right
            left: parent.left
            bottom: parent.bottom
        }

        EditorHomePage {}

        LocationEditor {}

        InstructorEditor {}

        CourseEditor {}
    }
}
