import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item {
    property var comboBoxModel
    property string comboBoxLabel

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

            Rectangle{
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 1
                color: "transparent"
                Text {
                    id: combotxt
                    text: comboBoxLabel
                    font.pointSize: 0.09*parent.width
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
                // color: "transparent"

                contentItem: Text{
                    text: parent.currentText
                    verticalAlignment: Text.AlignVCenter;
                    horizontalAlignment: Text.AlignHCenter;
                    font.pointSize: 0.07*parent.width
                }

                background: Rectangle{
                    color: "transparent"
                }
            }
        }
    }

}
