import QtQuick
import QtQuick.Controls

Item {
    implicitWidth: Constants.widthDefault
    implicitHeight: Constants.heightDefault

    TitleWithUnderline {
        id: myOptimizedSchedulesTitle
        text: "My Optimized Schedules"
        anchors{
            top: parent.top
            topMargin: 100
            left: parent.left
        }
    }

    Text {
        id: optimizeNewScheduleTitle
        text: "Optimize a New Schedule"
        font {
            family: Constants.fontPoppins
            pixelSize: 45
            weight: Font.ExtraBold
        }
        color: Constants.colorWhitePure
        width: 350
        anchors{
            top: parent.top
            topMargin: 70
            right: parent.right
            rightMargin: 100
        }
        wrapMode: Text.WordWrap
    }

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

        Button {
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
        }
    }
}
