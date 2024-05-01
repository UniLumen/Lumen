import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import Lumen

Item {
    id: root

    property alias _iconSource: cIcon.source
    property alias _text: cText.text
    property alias _description: cDescription.text
    property string _helpText: ""

    LumenRectangle {
        anchors.fill: parent

        ColumnLayout {
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                margins: 8
            }
            spacing: 32

            Image {
                id: cIcon

                sourceSize: Constants.sizeNormal
                fillMode: Image.PreserveAspectFit
            }

            Text {
                id: cText

                Layout.preferredWidth: parent.width
                font.bold: true
                font.pixelSize: Constants.sizeHeader2
                wrapMode: Text.WordWrap
            }

            Text {
                id: cDescription

                Layout.preferredWidth: parent.width
                font.pixelSize: Constants.sizePrimaryText
                wrapMode: Text.WordWrap
            }
        }

        Image {
            id: cHelpText

            anchors {
                bottom: parent.bottom
                left: parent.left
                margins: 8
            }

            source: Constants.iconInfo
            sourceSize: Constants.sizeSmall
            fillMode: Image.PreserveAspectFit

            MouseArea {
                anchors.fill: parent
                onEntered: ToolTip.visible = true
                onExited: ToolTip.visible = false
                hoverEnabled: true
                ToolTip.text: _helpText
            }
        }
    }
}
