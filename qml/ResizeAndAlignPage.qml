/*************************************************************************
 *
 * Copyright (c) 2017-2019, Klaralvdalens Datakonsult AB (KDAB)
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: mainWindow
    width: 1640
    height: 720
    ListModel{
        id: forModel
        ListElement{
            color: "E5E5E5"
            width: 153.75
            text: "Day"
        }
        ListElement{
            color: "E5E5E5"
            width: 153.75
            text: "Place"
        }
        ListElement{
            color: "E5E5E5"
            width: 153.75
            text: "8 - 10"
        }
        ListElement{
            color: "E5E5E5"
            width: 153.75
            text: "10 - 12"
        }
        ListElement{
            color: "E5E5E5"
            width: 153.75
            text: "12 - 2"
        }
        ListElement{
            color: "E5E5E5"
            width: 153.75
            text: "2 - 4"
        }
        ListElement{
            color: "E5E5E5"
            width: 153.75
            text: "4 - 6"
        }
        ListElement{
            color: "E5E5E5"
            width: 153.75
            text: "6 - 8"
        }

    }
    Component{
        id: forDeg
        Rectangle{
            color: model.color
            width: model.width
            Text{
                color: "black"
                text: model.text
                font.bold: true
                font.pixelSize: 10
                clip: true
                anchors{
                    horizontalCenter: parent.horizontalCenter
                    verticalCenter: parent.verticalCenter
                }
            }
        }
    }
    //--> slide
    // Rectangle{
    //     width: mainWindow.width * 0.75
    //     height: mainWindow.height * 0.75
    //     color: "black"
    //     // clip: true
    //     anchors{
    //         horizontalCenter: parent.horizontalCenter
    //         verticalCenter: parent.verticalCenter
    //     }
        ListView{
            width: 2000
            height: 2000
            anchors{
                // fill: parent
                // top: parent.top
                // left: parent.left
                // right: parent.right
            }
            model: forModel
            delegate: forDeg
            // clip: true
        }

        // ListView{
        //     ListElement{
        //         width: 50
        //         height: 50

        //     }

        // }

    // }










    // ColumnLayout {
    //     anchors.fill: parent
    //     anchors.margins: 5

    //     RowLayout {
    //         Layout.alignment: Qt.AlignTop

    //         Rectangle {
    //             height: 50
    //             width: 200
    //             color: "silver"
    //         }

    //         Rectangle {
    //             height: 50
    //             width: 200
    //             // stretch to cover the rest of the row layout
    //             Layout.fillWidth: true
    //         }
    //     }

    //     RowLayout {
    //         Layout.alignment: Qt.AlignBottom | Qt.AlignRight

    //         Rectangle {
    //             height: 50
    //             width: 200
    //             color: "blue"
    //         }
    //         Rectangle {
    //             height: 50
    //             width: 200
    //            color: "red"
    //         }
    //     }
    // }
    //<-- slide
}


// GridLayout{
//     clip: true
//     Rectangle{
//         width: 100
//         height: 50
//         color: "red"
//         // anchors.fill: parent

//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "silver"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "blue"
//         // anchors.fill: parent
//     }
//     Rectangle{
//         width: 100
//         height: 50
//         color: "red"
//         // anchors.fill: parent
//     }
// }
