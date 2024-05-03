import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: editorHomePage
    width: Constants.editorWindowWidth
    height: Constants.editorWindowHeight
    color: Constants.darkBackgroundColor

    YellowLinesImage {id: yellowLinesImage}

    LumenLogo {id: lumenLogo}

    TitleWithUnderline {
        id: titleWithUnderline
        title: Constants.editorWelcomeText
        anchors{
            top: lumenLogo.bottom
            topMargin: 100
            left: lumenLogo.left
            leftMargin: 30
        }
    }

    // Here I was unable to use constants for the iconPaths, QT doesn't allow this inside ListModel for some reason
    ListModel{
        id: cardsModel
        ListElement {
            title: "Add Location"
            iconPath: "qrc:/images/location_icon.svg"
            infoText: "Here you can input all the\nlocations and classes available\nat your university"
        }
        ListElement {
            title: "Add Doctors/TAs"
            iconPath: "qrc:/images/instructor_icon.svg"
            infoText: "Here you can input all the\nDoctors and TAs available\nat your university"
        }
        ListElement {
            title: "Add Courses"
            iconPath: "qrc:/images/course_icon.svg"
            infoText: "Here you can input all the\nCourses available\nat your university"
        }
        ListElement {
            title: "Add Schedules"
            iconPath: "qrc:/images/schedule_icon.svg"
            infoText: "Here you can input all\nyears' schedules available\nat your university"
        }
    }

    GridLayout {
        id: cardsGrid
        rows: 1
        columns: 4
        columnSpacing: 20

        anchors {
            left: parent.left
            leftMargin: 40
            right: parent.right
            top: titleWithUnderline.bottom
            topMargin: 150
        }

        Repeater {
            model: cardsModel
            delegate: EditorHomePageCard {}
        }
    }
}
