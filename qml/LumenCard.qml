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
    property int _modelIndex: -1
    signal deleteInvoked

    LumenRectangle {
        anchors.fill: parent

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 8
            spacing: 12

            ColumnLayout {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignTop

                spacing: 32

                RowLayout {
                    Layout.fillWidth: true

                    Image {
                        id: cIcon

                        sourceSize: Constants.sizeNormal
                        fillMode: Image.PreserveAspectFit
                    }

                    Item {
                        Layout.fillWidth: true
                    }

                    Button {
                        id: cDelete

                        Layout.preferredHeight: cIcon.height

                        // Stupid Matrial Style likes to add extra padding!
                        // This is bad
                        contentItem: Image {
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            anchors.right: parent.right

                            source: Constants.iconRemove
                            fillMode: Image.PreserveAspectFit
                        }

                        background: null
                        onClicked: deleteInvoked()
                        visible: _editMode
                    }
                }

                Text {
                    id: cText

                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    font.bold: true
                    font.pixelSize: Constants.sizeHeader2
                    wrapMode: Text.WordWrap
                }

                Text {
                    id: cDescription

                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    font.pixelSize: Constants.sizePrimaryText
                    fontSizeMode: Text.Fit
                    minimumPixelSize: Constants.sizeHeader6
                    wrapMode: Text.WrapAnywhere
                    verticalAlignment: Text.AlignBottom
                }
            }

            Image {
                id: cHelpText

                Layout.alignment: Qt.AlignBottom

                source: Constants.iconInfoBlack
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
}
