import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: editorHomePage
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

    TitleWithUnderline {
        id: titleWithUnderline
        title: Constants.textEditorPageTitle
        anchors{
            top: lumenLogo.bottom
            topMargin: 100
            left: lumenLogo.left
            leftMargin: 30
        }
    }

    // Here I was unable to use constants for anything, QT doesn't allow this inside ListModel for some reason
    // Should try to find a fix for this
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
            infoText: "Here you can input all the\ndoctors and TAs available\nat your university"
        }
        ListElement {
            title: "Add Courses"
            iconPath: "qrc:/images/course_icon.svg"
            infoText: "Here you can input all the\ncourses available\nat your university"
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
            delegate: EditorHomePageCard {
                text: model.title
                icon.source: model.iconPath
                infoText: model.infoText
            }
        }
    }
}
