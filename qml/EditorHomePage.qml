import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: editorHomePage
    implicitWidth: Constants.widthDefault
    implicitHeight: Constants.heightDefault

    TitleWithUnderline {
        id: titleWithUnderline
        text: Constants.textEditorPageTitle
        anchors{
            top: parent.top
            topMargin: 100
            left: parent.left
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
            destinationPageTabBarIndex: 1
        }
        ListElement {
            title: "Add Doctors/TAs"
            iconPath: "qrc:/images/instructor_icon.svg"
            infoText: "Here you can input all the\ndoctors and TAs available\nat your university"
            destinationPageTabBarIndex: 2
        }
        ListElement {
            title: "Add Courses"
            iconPath: "qrc:/images/course_icon.svg"
            infoText: "Here you can input all the\ncourses available\nat your university"
            destinationPageTabBarIndex: 3
        }
        ListElement {
            title: "Add Schedules"
            iconPath: "qrc:/images/schedule_icon.svg"
            infoText: "Here you can input all\nyears' schedules available\nat your university"
            destinationPageTabBarIndex: 4
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
                destinationPageTabBarIndex: model.destinationPageTabBarIndex
            }
        }

        clip: true
    }
}
