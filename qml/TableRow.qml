import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Time 1.0
Item{
    id: schedule
    property double scheduleWidth: 1200
    property double timeSlotHeight: 100
    property int day
    TimeSlot{
        id: _testtest
        currentDay: schedule.day
    }
    width: scheduleWidth
    height: timeSlots.height
    Rectangle {
        id: daySlot
        color: "white"
        border.width: 1
        border.color: "#828282"
        width: parent.width / 8
        height: timeSlotHeight * Math.ceil(_testtest.rows / 7) //* timeSlots.rows
        anchors.left: parent.left
        MouseArea {
            anchors.fill: parent
            onPressed: {
                console.log(model.index)
                if(model.index)
                    console.log("sat")
            }
        }
        Text {
            id: dayText
            text: model.name
            font.pixelSize: model.fontSize
            font.bold: true
            anchors{
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
            }
        }
        Row{
            spacing: 5
            width: 70
            height: 30
            anchors{
                top: dayText.bottom
                topMargin: 5
                horizontalCenter: parent.horizontalCenter
            }
            Image {
                source: Constants.addButtonPath
                width: 30
                height: 30
                MouseArea{
                    anchors.fill: parent
                    onPressed:{
                        if(_testtest.rows >= 7)
                            _testtest.addRow("newPlace")}
                }
            }
            Image {
                source: Constants.removeButtonPath
                width: 30
                height: 30
                MouseArea{
                    anchors.fill: parent
                    onPressed:{
                        if(_testtest.rows > 7)
                            _testtest.removeRow()
                    }
                }
            }
        }
    }
    GridLayout{
        id: timeSlots
        property int numOfModels: 14
        columnSpacing: 0
        rowSpacing: 0
        clip: true
        columns: 7
        width: schedule.width - daySlot.width
        height: daySlot.height
        anchors.left: daySlot.right
        Repeater {
            id: timeSlotRepeater
            model: _testtest
            delegate: Rectangle {
                width: timeSlots.width / 7
                height: timeSlotHeight
                color: "white"
                border.color: "black"
                border.width: 1
                MouseArea {
                    anchors.fill: parent
                    onPressed: {
                        console.log(model.index % 7)
                        console.log(_testtest.rows)
                    }
                }
                Text{
                    id: name
                    text: model.displayText
                    font.pointSize: 15
                    wrapMode: Text.WrapAnywhere
                    clip: true
                    anchors{
                        horizontalCenter: parent.horizontalCenter
                        verticalCenter: parent.verticalCenter
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onPressed: {
                        //console.log("Day", schedule.day)
                        //console.log(model.index % 7)
                        //console.log(_testtest.rows)
                        //_testtest.editSelectedCell(model.index, "okii")
                        infoPopup.slotIndex = model.index
                        infoPopup.open();
                    }

                }
            }
        }
    }
    Popup {
        id: infoPopup
        property int slotIndex
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
                    id: sectionNumCB
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

                        onClicked: {
                            _testtest.editSelectedCell(infoPopup.slotIndex,day,sectionNumCB.currentSelection,courseTypeCB.currentSelection,doctorCB.currentSelection,doctorCB.currentSelection,courseCB.currentSelection
                                                       ,courseCB.currentSelection + "\n" + courseTypeCB.currentSelection + "(" + sectionNumCB.currentSelection + ")"
                                                       + "\n" + doctorCB.currentSelection + "\n" + doctorCB.currentSelection)
                            infoPopup.close()
                        }

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
}
