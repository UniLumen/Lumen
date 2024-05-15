import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
Item {
    anchors.fill: parent
    ColumnLayout{
        width: parent.width
        spacing: 35
        Layout.margins: 20
        // RowLayout{
        //     id: ediotrTabBar
        //     Layout.fillHeight: true
        //     Layout.fillWidth: true
        //     spacing: 35
        //     Layout.margins: 20
        //     LumenLogo{

        //     }

        //     EditorTabBar{

        //     }
        // }
        RowLayout{
            id: tabButtons
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 35
            Layout.margins: 20
            LandPageText {
                Layout.leftMargin: 40
                text: "Schedules Directory"
                font.pointSize: 30
                font.bold: true
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
                currentTable: tabbar.currentIndex
                //anchors.fill: parent
            }
            TableSchedule{
                currentTable: tabbar.currentIndex
               //anchors.fill: parent
            }
            TableSchedule{
                currentTable: tabbar.currentIndex
               //anchors.fill: parent
            }
            TableSchedule{
                currentTable: tabbar.currentIndex
                //anchors.fill: parent
            }
        }
    }
}
