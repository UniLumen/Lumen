import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
Item {
    anchors.fill: parent
    ColumnLayout{
        width: parent.width
        spacing: 35
        Layout.margins: 20
        RowLayout{
            id: ediotrTabBar
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 35
            Layout.margins: 20
            LumenLogo {

            }
            EditorTabBar{

            }
        }
        RowLayout{
            id: tabButtons
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 35
            Layout.margins: 20
            TextLandPage {
                Layout.leftMargin: 40
                text: "Schedules Directory"
                font.pointSize: 30
                font.bold: true
            }
            AddTimeSlot{

            }
        }
        SchedulesTabs{
            id: tabbar
        }
        StackLayout{
            id: layout
            Layout.fillWidth: true
            Layout.fillHeight: true

            currentIndex: tabbar.currentIndex
            TableSchedule{
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            TableSchedule{
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            TableSchedule{
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            TableSchedule{
                Layout.fillWidth: true
                Layout.fillHeight: true
            }


        }
    }
}
