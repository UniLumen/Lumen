import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

ApplicationWindow {
    width: Constants.widthDefault
    height: Constants.heightDefault

    color: Constants.colorBackground

    background: Item {
        anchors.fill: parent

        YellowLinesImage {
            width: parent.width
            height: parent.height / 2
            anchors.bottom: parent.bottom
        }
    }

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

        EditorSchedule{}
    }
}
