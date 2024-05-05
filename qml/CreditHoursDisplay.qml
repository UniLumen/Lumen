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
        Layout.fillWidth: true

        text: "Credit Hours"
        font.bold: true
        font.pixelSize: Constants.sizeHeader2
        minimumPixelSize: Constants.sizeHeader6
        fontSizeMode: Text.Fit
        wrapMode: Text.WordWrap
    }

    Rectangle {
        id: cProgressBar

        Layout.alignment: Qt.AlignRight
        Layout.fillWidth: true
        Layout.preferredHeight: 8
        Layout.bottomMargin: 14

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
