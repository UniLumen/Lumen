import QtQuick
import QtQuick.Layouts
Item{
    property double scheduleEntryWidth: 1200
    property double scheduleSlotHeight: 52
    height: scheduleSlotHeight
    width: scheduleEntryWidth
    ListModel{
        id: modelProperties
        ListElement{name: "Day"; topRightRadius: 0; topLeftRadius: 15; fontSize: 14}
        ListElement{name: "Place"; topRightRadius: 0; topLeftRadius: 0; fontSize: 14}
        ListElement{name: "8 - 10"; topRightRadius: 0; topLeftRadius: 0; fontSize: 14}
        ListElement{name: "10 - 12"; topRightRadius: 0; topLeftRadius: 0; fontSize: 14}
        ListElement{name: "12 - 2"; topRightRadius: 0; topLeftRadius: 0; fontSize: 14}
        ListElement{name: "2 - 4"; topRightRadius: 0; topLeftRadius: 0; fontSize: 14}
        ListElement{name: "4 - 6"; topRightRadius: 0; topLeftRadius: 0; fontSize: 14}
        ListElement{name: "6 - 8"; topRightRadius: 15; topLeftRadius: 0; fontSize: 14}
    }
    Component{
        id: scheduleSlot
        Rectangle{
            width: scheduleEntryWidth / 8
            height: scheduleSlotHeight
            color: "#E5E5E5"
            border.width: 1
            border.color: "#828282"
            topLeftRadius: model.topLeftRadius
            topRightRadius: model.topRightRadius
            Text {
                text: model.name
                font.bold: true
                font.pixelSize: model.fontSize
                anchors{horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter}
            }
        }
    }
    RowLayout{
        id: scheduleEntry
        spacing: 0
        height: scheduleSlotHeight
        anchors{
            top: parent.top
            left: parent.left
            right: parent.right
        }
        Repeater{
            model: modelProperties
            delegate: scheduleSlot
        }
    }
}
