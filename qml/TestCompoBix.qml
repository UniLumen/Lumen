import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item{
//     width: 452
//     height: 57
//     radius: 4
//     color: "transparent"
//     border.color: "#BABABA"
//     border.width: 2
    ComboBox{
        width: 452
        height: 57
        flat: true
        // anchors.fill: parent
        model: ["2", "222", "22"]
        font.bold: true
        // delegate: forMod
        // Layout.fillWidth: true
        // Layout.fillHeight: true
        // font.Medium: true
        // font.Medium: true
        background: Rectangle{
            anchors.fill: parent
            radius: 4
            color: "transparent"
            border.color: "#BABABA"
            border.width: 2
        }
    }
}















































// ComboBox {
//     id: comboBox
//     model: ListModel {
//         ListElement { text: "Option 1" }
//         ListElement { text: "Option 2" }
//         ListElement { text: "Option 3" }
//     }
//     delegate: ItemDelegate {
//         text: model.text
//     }
//     onActivated: {
//         console.log("Selected: " + model.text)
//     }
// }

















// Item {
//     property var comboBoxModel
//     property string comboBoxLabel
//     readonly property string currentSelection: combo.displayText

//     implicitHeight: 40
//     implicitWidth: 100

//     Rectangle{
//         id: comboRect
//         anchors.fill: parent
//         border.color: "black"
//         border.width: 1
//         radius:0.05*comboRect.width

//         RowLayout{
//             anchors.fill: parent

//             Rectangle{
//                 Layout.fillWidth: true
//                 Layout.fillHeight: true
//                 Layout.preferredWidth: 1
//                 color: "transparent"
//                 Text {
//                     id: combotxt
//                     text: comboBoxLabel
//                     font.pointSize: 0.09*parent.width
//                     anchors.centerIn: parent
//                 }
//             }

//             Rectangle{
//                 id: separator
//                 Layout.maximumWidth: 1
//                 Layout.preferredWidth: 1
//                 Layout.fillHeight: true
//                 Layout.fillWidth: true
//                 color: "black"
//             }

//             ComboBox{
//                 id:combo
//                 model: comboBoxModel
//                 Layout.fillWidth: true
//                 Layout.fillHeight: true
//                 Layout.preferredWidth: 1

//                 contentItem: Text{
//                     text: parent.currentText
//                     verticalAlignment: Text.AlignVCenter;
//                     horizontalAlignment: Text.AlignHCenter;
//                     font.pointSize: 0.07*parent.width
//                 }

//                 background: Rectangle{
//                     color: "transparent"
//                 }
//             }
//         }
//     }

// }
