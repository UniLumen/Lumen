import QtQuick
import QtQuick.Controls
import Qt.labs.qmlmodels
import QtQuick.Layouts
ApplicationWindow {
    id: mainWindow
    width: 1600
    height: 720
    Rectangle{
        id: schedule
        width: mainWindow.width * 0.75
        height: mainWindow.height * 0.75
        color: "pink"
        anchors{
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }
        RowLayout{
            id: fixedRow
            implicitWidth: parent.width
            implicitHeight: parent.height
            clip: true
            spacing: 0
            anchors{
                left: parent.left
                right: parent.right
                top: parent.top
            }
            Rectangle{
                width: parent.width / 8
                height: 100
                color: "blue"
            }
            Rectangle{
                width: parent.width / 8
                height: 100
                color: "red"
            }
            Rectangle{
                width: parent.width / 8
                height: 100
                color: "yellow"
            }
            Rectangle{
                width: parent.width / 8
                height: 100
                color: "lightblue"
            }
            Rectangle{
                width: parent.width / 8
                height: 100
                color: "lightgreen"
            }
            Rectangle{
                width: parent.width / 8
                height: 100
                color: "pink"
            }
            Rectangle{
                width: parent.width / 8
                height: 100
                color: "red"
            }
            Rectangle{
                width: parent.width / 8
                height: 100
                color: "lightblue"
            }
        }
        Rectangle{
            color: "black"
            width: mainWindow.width * 0.75
            height: mainWindow.height * 0.75
            anchors.top: fixedRow.bottom
            ListView{
                width: parent.width
                height: parent.height
                model: 7
                clip: true
                delegate:TableRow{
                    scheduleWidth: mainWindow.width * 0.75
                    timeSlotHeight: 100
                }
            }
        }
    }
}
