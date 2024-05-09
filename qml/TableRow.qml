import QtQuick
import QtQuick.Layouts
Item{
    id: schedule
    property double scheduleWidth: 1200
    property double timeSlotHeight: 100
    width: scheduleWidth
    height: timeSlots.height
    Rectangle {
        id: daySlot
        color: "green"
        border.width: 1
        width: parent.width / 8
        height: timeSlotHeight * Math.ceil(timeSlots.numOfModels / 7) //* timeSlots.rows
        anchors.left: parent.left
        MouseArea {
            anchors.fill: parent
            onPressed: {
                timeSlots.numOfModels = timeSlots.numOfModels + 7
                console.log(model.index)
                if(model.index)
                    console.log("sat")
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
            model: timeSlots.numOfModels
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
                        timeSlots.numOfModels = timeSlots.numOfModels - 7
                    }
                }
            }
        }
    }
}
