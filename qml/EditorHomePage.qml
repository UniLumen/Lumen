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
        text: Constants.textEditorPageTitle
        anchors{
            top: lumenLogo.bottom
            topMargin: 100
            left: lumenLogo.left
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

    RowLayout {
        id: cardsGrid

        anchors {
            left: parent.left
            right: parent.right
            top: titleWithUnderline.bottom
            topMargin: 150
        }
        spacing: 64

        Repeater {
            model: cardsModel
            delegate: EditorHomePageCard {
                Layout.fillWidth: true
                Layout.preferredHeight: 440

                text: model.title
                icon.source: model.iconPath
                infoText: model.infoText
            }
        }

        clip: true
    }
}
