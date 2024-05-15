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
    property alias _checkBox0: cCheckBox0
    property alias _checkBox1: cCheckBox1
    property alias _checkBox2: cCheckBox2
    property bool _editable: false

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

                spacing: 16

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
                        visible: _editable
                    }
                }

                ColumnLayout {
                    Layout.fillWidth: true

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

                    GridLayout {
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        columns: 2
                        columnSpacing: 0
                        rowSpacing: 0

                        CheckBox {
                            id: cCheckBox0

                            Layout.fillWidth: true
                            Layout.preferredHeight: 20
                            padding: 0

                            visible: text
                            checkable: false
                            hoverEnabled: false
                            enabled: false
                        }
                        CheckBox {
                            id: cCheckBox1

                            Layout.fillWidth: true
                            Layout.preferredHeight: 20
                            padding: 0

                            visible: text
                            checkable: false
                            enabled: false
                            hoverEnabled: false
                        }
                        CheckBox {
                            id: cCheckBox2

                            Layout.fillWidth: true
                            Layout.preferredHeight: 20
                            padding: 0

                            visible: text
                            checkable: false
                            enabled: false
                        }
                    }
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

                visible: _helpText
            }
        }
    }
}
