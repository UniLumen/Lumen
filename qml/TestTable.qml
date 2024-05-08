import QtQuick
import QtQuick.Controls
import Qt.labs.qmlmodels
import QtQuick.Layouts
Window {
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





























































    // Rectangle {
    //     width: 800
    //     height: 400
    //     anchors.fill: parent
    //     clip: true
    //     // Define rows
    //     Row {
    //         spacing: 20
    //         anchors.fill: parent
    //         clip: true
    //         Text { text: "Time"; horizontalAlignment: Text.AlignHCenter; width: 100 }
    //         Text { text: "Activity"; horizontalAlignment: Text.AlignHCenter; width: 200 }
    //         Text { text: "Subschedule 1"; horizontalAlignment: Text.AlignHCenter; width: 100 }
    //         Text { text: "Subschedule 2"; horizontalAlignment: Text.AlignHCenter; width: 100 }
    //         Text { text: "Subschedule 3"; horizontalAlignment: Text.AlignHCenter; width: 100 }
    //         Text { text: "Subschedule 4"; horizontalAlignment: Text.AlignHCenter; width: 100 }
    //         Text { text: "Subschedule 5"; horizontalAlignment: Text.AlignHCenter; width: 100 }
    //         Text { text: "Subschedule 6"; horizontalAlignment: Text.AlignHCenter; width: 100 }
    //     }

    //     Row {
    //         spacing: 10
    //         anchors.fill: parent
    //         clip: true
    //         Text { text: "Row 1"; width: 100 }
    //         Text { text: "Activity 1"; width: 200 }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //     }

    //     // Repeat the Row for remaining rows (less efficient)
    //     Row {
    //         spacing: 10
    //         anchors.fill: parent
    //         clip: true
    //         Text { text: "Row 2"; width: 100 }
    //         Text { text: "Activity 2"; width: 200 }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //     }

    //     Row {
    //         spacing: 10
    //         anchors.fill: parent
    //         clip: true
    //         Text { text: "Row 3"; width: 100 }
    //         Text { text: "Activity 3"; width: 200 }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //     }

    //     Row {
    //         spacing: 10
    //         anchors.fill: parent
    //         clip: true
    //         Text { text: "Row 4"; width: 100 }
    //         Text { text: "Activity 4"; width: 200 }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //         Rectangle { width: 100; height: 30; color: "lightgray" }
    //     }

        // ... Repeat for remaining rows (less efficient)
    // }



    // Rectangle {
    //     id: rectangle
    //     color: "#ffffff"
    //     anchors.fill: parent
    //     anchors.rightMargin: 0
    //     anchors.bottomMargin: 0
    //     anchors.leftMargin: 0
    //     anchors.topMargin: 0

    //     TableView {
    //         anchors.fill: parent
    //         columnSpacing: 1
    //         rowSpacing: 1
    //         clip: true

    //         model: TableModel {
    //             TableModelColumn { display: "customer" }
    //             TableModelColumn { display: "address" }
    //             TableModelColumn { display: "mobile" }
    //             TableModelColumn { display: "email" }
    //             TableModelColumn { display: "city" }
    //             TableModelColumn { display: "state" }
    //             TableModelColumn { display: "country" }

    //             rows: [
    //                 {
    //                     "customer": "h",
    //                     "address": "down",
    //                     "mobile": "34556",
    //                     "email": "ty@gmail.com",
    //                     "city": "new york",
    //                     "state": "new york",
    //                     "country": "USA"

    //                 },
    //                 {
    //                     "customer": "h",
    //                     "address": "down",
    //                     "mobile": "34556",
    //                     "email": "ty@gmail.com",
    //                     "city": "new york",
    //                     "state": "new york",
    //                     "country": "USA"
    //                 },
    //                 {
    //                     "customer": "h",
    //                     "address": "down",
    //                     "mobile": "34556",
    //                     "email": "ty@gmail.com",
    //                     "city": "new york",
    //                     "state": "new york",
    //                     "country": "USA"
    //                 }
    //             ]
    //         }

    //         delegate: Rectangle {
    //             implicitHeight: 50
    //             implicitWidth: 100
    //             border.width: 1

    //             Text {
    //                 text: display
    //                 anchors.centerIn: parent
    //             }
    //         }
    //     }
    // }
// }
