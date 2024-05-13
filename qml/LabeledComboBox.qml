import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item {
    property var comboBoxModel
    property string comboBoxLabel
    readonly property string currentSelection: combo.displayText

    implicitHeight: 40
    implicitWidth: 100

    Rectangle{
        id: comboRect
        anchors.fill: parent
        border.color: "black"
        border.width: 1
        radius:0.05*comboRect.width

        RowLayout{
            anchors.fill: parent
            anchors.centerIn: parent
            Rectangle{
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 1
                color: "transparent"
                Text {
                    id: combotxt
                    text: comboBoxLabel
                    font.pointSize: 15
                    anchors.centerIn: parent
                }
            }

            Rectangle{
                id: separator
                Layout.maximumWidth: 1
                Layout.preferredWidth: 1
                Layout.fillHeight: true
                Layout.fillWidth: true
                color: "black"
            }

            ComboBox{
                id:combo
                model: comboBoxModel
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 1

                contentItem: Text{
                    text: parent.currentText
                    font.pointSize: 15
                    verticalAlignment: Text.AlignVCenter;
                    horizontalAlignment: Text.AlignLeft;
                }

                background: Rectangle{
                    color: "transparent"
                }
            }
        }
    }

}
