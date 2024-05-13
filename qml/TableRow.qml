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
                            _testtest.addRow()}
                }
            }
            Image {
                source: Constants.removeButtonPath
                width: 30
                height: 30
                MouseArea{
                    anchors.fill: parent
                    // onPressed:{
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
                    text: model.place
                    font.pixelSize: 20
                }
                MouseArea {
                    anchors.fill: parent
                    onPressed: {
                        console.log("Day", schedule.day)
                        console.log(model.index % 7)
                        console.log(_testtest.rows)
                        _testtest.editSelectedCell(model.index, "okii")
                    }
                }
            }
        }
    }
}
