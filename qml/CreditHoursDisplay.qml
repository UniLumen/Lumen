import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import Lumen

ColumnLayout {
    property real _value: 0.5
    property real _from: 0.0
    property real _to: 1.0

    spacing: 4

    Text {
        text: "Credit Hours"
        font.pixelSize: Constants.sizeHeader2
        font.bold: true
    }

    Rectangle {
        id: cProgressBar

        Layout.alignment: Qt.AlignRight
        Layout.fillWidth: true
        Layout.bottomMargin: 14

        height: 8
        radius: 100
        color: Constants.background

        Text {
            anchors {
                left: parent.left
                top: parent.bottom
            }

            text: _from
            font.pixelSize: Constants.sizeSecondaryText
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            anchors {
                right: parent.right
                top: parent.bottom
            }

            text: _to
            font.pixelSize: Constants.sizeSecondaryText
            verticalAlignment: Text.AlignVCenter
        }

        Rectangle {
            anchors {
                top: parent.top
                left: parent.left
            }

            height: parent.height
            radius: parent.radius
            width: parent.width * Math.max(0, (_value - _from) / (_to - _from))
            color: (_value >= _from && _value <= _to) ? Constants.accent : Constants.alertRed

            Text {
                anchors {
                    right: parent.right
                    top: parent.bottom
                }

                text: _value
                font.pixelSize: Constants.sizeSecondaryText
                verticalAlignment: Text.AlignVCenter
                visible: (_value > _from && _value < _to)
            }
        }
    }
}
