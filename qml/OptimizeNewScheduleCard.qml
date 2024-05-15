import QtQuick
import QtQuick.Controls

LumenRectangle {
    id: optimizeNewScheduleCard

    implicitWidth: optimizeNewScheduleTitle.width + 100
    implicitHeight: 430

    anchors {
        top: optimizeNewScheduleTitle.bottom
        left: optimizeNewScheduleTitle.left
        right: parent.right
        rightMargin: 20
        topMargin: 30
    }

    Image {
        id: gearIcon
        source: Constants.iconGear
        anchors {
            left: parent.left
            top: parent.top
            margins: 10
        }
    }

    Button {
        text: "Undo"
        font {
            family: Constants.fontPoppins
            weight: Font.DemiBold
            pixelSize: 15
        }
        hoverEnabled: true

        background: Rectangle {
            color: parent.hovered ? Constants.colorYellowEditorPageHover : Constants.colorYellowMain
            radius: 12
        }

        anchors {
            top: parent.top
            right: parent.right

            margins: 10
        }

        PointingHandCursor {}

        onClicked: __optimizedSchedulesModel.undoAddedOptimizedSchedules();
    }

    component TextFieldTitle : Text{
            font {
                family: Constants.fontPoppins
                pixelSize: 35
                weight: Font.DemiBold
            }
            color: Constants.colorBlackPure
    }

    TextFieldTitle {
        id: groupNumberText
        text: "Group Number"

        anchors{
            top: gearIcon.bottom
            topMargin: 30
            left: gearIcon.left
            leftMargin: 5
        }
    }

    TextField {
        id: groupNumberTextField
        placeholderText: focus || text ? "" : "Enter group number"

        background: Rectangle {
            implicitWidth: groupNumberText.width + 20
            color: "transparent"
            border.color: Constants.colorGray
            radius: 7
        }

        anchors {
            top: groupNumberText.bottom
            topMargin: 15
            left: groupNumberText.left
        }
    }

    TextFieldTitle {
        id: sectionNumberText
        text: "Section Number"

        anchors{
            top: groupNumberTextField.bottom
            topMargin: 20
            left: groupNumberTextField.left
        }
    }

    TextField {
        id: sectionNumberTextField
        placeholderText: focus || text ? "" : "Enter section number"

        background: Rectangle {
            implicitWidth: groupNumberText.width + 20
            color: "transparent"
            border.color: Constants.colorGray
            radius: 7
        }

        anchors {
            top: sectionNumberText.bottom
            topMargin: 15
            left: sectionNumberText.left
        }
    }

    Text {
        font {
            family: Constants.fontPoppins
            pixelSize: 15
            weight: Font.DemiBold
        }
        color: Constants.colorRed
        text: __optimizedSchedulesModel.inputValidationNote

        anchors {
            bottom: optimizeScheduleButton.top
            right: optimizeScheduleButton.right
            left: parent.left
            margins: 20
        }
    }

    Button {
        id: optimizeScheduleButton
        text: "Optimize Schedule"
        font {
            family: Constants.fontPoppins
            weight: Font.DemiBold
            pixelSize: 15
        }
        hoverEnabled: true

        background: Rectangle {
            color: parent.hovered ? Constants.colorYellowEditorPageHover : Constants.colorYellowMain
            radius: 12
        }

        anchors {
            bottom: parent.bottom
            right: parent.right

            margins: 15
        }

        PointingHandCursor {}

        onClicked: __optimizedSchedulesModel.createOptimizedSchedules(groupNumberTextField.text, sectionNumberTextField.text);
    }
}
