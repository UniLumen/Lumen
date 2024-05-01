import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import Lumen

ColumnLayout {
    property real _value: 0.5

    spacing: 4

    Text {
        text: "Credit Hours"
        font.pixelSize: Constants.sizeHeader2
        font.bold: true
    }

    RowLayout {
        Layout.fillWidth: true
        spacing: 64

        Text {
            id: cText

            text: qsTr("From 12 to 21")
            font.pixelSize: Constants.sizeSecondaryText
            verticalAlignment: Text.AlignVCenter
        }

        Rectangle {
            id: cProgressBar

            Layout.alignment: Qt.AlignRight
            Layout.fillWidth: true

            height: 8
            radius: 100
            color: Constants.background

            Rectangle {
                anchors {
                    top: parent.top
                    left: parent.left
                }

                height: parent.height
                radius: parent.radius
                width: parent.width * _value
                color:  Constants.accent
            }
        }
    }
}
