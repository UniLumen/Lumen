import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Button {
    id: moreInfoButton
    hoverEnabled: true

    onClicked: infoPopup.open()

    background: Rectangle {
        color: "transparent"
    }

    font {
        pixelSize: 15
        family: Constants.mainFont
        weight: Font.Light
    }

    icon {
        source: Constants.moreInfoIconBlackPath
        color: hovered ? Constants.yellowColor : Constants.blackColor
    }
    Popup {
        id: infoPopup
        // This sets the parent of the pop-up always as the main screen being displayed
        parent: Overlay.overlay
        // Creates the window dimming effect and disables anything behind the popup to be pressed
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose
        anchors.centerIn: parent
        contentItem: Item{
            id: mainBody
            implicitHeight: 600
            implicitWidth: 600
            anchors.centerIn: parent
            //body of the pop-up
            ColumnLayout{
                anchors.centerIn: parent
                spacing:35
                Text {
                    id: infoText
                    Layout.preferredWidth: 400
                    text: "Enter new time slot info!"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font {
                        pixelSize: 45
                        family: Constants.mainFont
                        weight: Font.DemiBold
                    }
                }

                Rectangle {
                    id: seperatorLine
                    color: "grey"
                    width: parent.width
                    height: 1
               }
                LabeledComboBox{
                    comboBoxModel: ["Data Structures","AI"]
                    comboBoxLabel: "Course"
                    id: courseCB
                    Layout.preferredWidth: 400
                    Layout.preferredHeight: mainBody.height/16
                }
                LabeledComboBox{
                    comboBoxModel: ["Lecture","Section","Lab"]
                    comboBoxLabel: "Type"
                    id: courseTypeCB
                    Layout.preferredWidth: 400
                    Layout.preferredHeight: mainBody.height/16
                }
                LabeledComboBox{
                    comboBoxModel: ["beshoy","Salsabil"]
                    comboBoxLabel: "Instructor"
                    id: doctorCB
                    Layout.preferredWidth: 400
                    Layout.preferredHeight: mainBody.height/16
                }
                LabeledComboBox{
                    comboBoxModel: [1,2,3,4,5]
                    comboBoxLabel: "Group Number"
                    id: groupNumCB
                    Layout.preferredWidth: 400
                    Layout.preferredHeight: mainBody.height/16
                }
                RowLayout{
                    Layout.preferredWidth: 200
                    Layout.preferredHeight: mainBody.height/12
                    Button {
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        id: closeButton
                        hoverEnabled: true

                        onClicked: infoPopup.close()

                        background: Rectangle {
                           color: closeButton.hovered ? Constants.yellowHoverColor : Constants.yellowColor
                           radius: 15
                        }

                        contentItem: Text{
                            text: "Close"
                            color: Constants.whiteColor
                            anchors.centerIn: parent
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            font {
                                pixelSize: 25
                                family: Constants.mainFont
                                weight: Font.Bold
                            }
                        }

                        PointingHandCursor{}
                    }
                    Button {
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        id: saveButton
                        hoverEnabled: true

                        onClicked: infoPopup.close()

                        background: Rectangle {
                           color: saveButton.hovered ? Constants.yellowHoverColor : Constants.yellowColor
                           radius: 15
                        }

                        contentItem: Text{
                            text: "Save"
                            color: Constants.whiteColor
                            anchors.centerIn: parent
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            font {
                                pixelSize: 25
                                family: Constants.mainFont
                                weight: Font.Bold
                            }
                        }

                        PointingHandCursor{}
                    }
                }

            }
       }
    }

    PointingHandCursor{}
}
