import QtQuick
import QtQuick.Controls
import Qt.labs.qmlmodels
import QtQuick.Layouts

Item{
    id: tableSchedule
    property double tableScheduleWidth: Constants.widthDefault
    property double tableScheduleHeight: 540
    property int currentTable
    ListModel{
        id: daySlotProperties
        ListElement{name: "Saturday"; fontSize: 20;}
        ListElement{name: "Sunday"; fontSize: 20;}
        ListElement{name: "Monday"; fontSize: 20;}
        ListElement{name: "Tuesday"; fontSize: 20;}
        ListElement{name: "Wednesday"; fontSize: 20;}
        ListElement{name: "Thursday"; fontSize: 20;}
    }
    width: tableScheduleWidth
    height: tableScheduleHeight
    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
    FixedRow{
        id: fixedRow
        scheduleEntryWidth: parent.width
        anchors{
            left: parent.left
            right: parent.right
            top: parent.top
        }
    }
    ListView{
        width: tableScheduleWidth
        height: tableScheduleHeight
        anchors.top: fixedRow.bottom
        model: daySlotProperties
        clip: true
        cacheBuffer: 8000
        delegate:TableRow{
            scheduleWidth: tableScheduleWidth
            timeSlotHeight: tableScheduleHeight / 6
            day: model.index
            selectedTable: currentTable
        }
    }
}
