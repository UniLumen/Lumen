import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item {
    LumenRectangle {
        id: root

        anchors {
            left: parent.left
            right: parent.right
        }

        height: cLayout.implicitHeight + 2 * cLayout.anchors.margins

        ColumnLayout {
            id: cLayout

            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                margins: 8
            }
            spacing: 32

            Image {
                Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                source: Constants.iconKpi
                sourceSize: Constants.sizeNormal
                fillMode: Image.PreserveAspectFit
            }

            CreditHoursDisplay {
                _value: 0.5
            }

            ColumnLayout {
                spacing: 2

                Text {
                    text: qsTr("Select Credit Hours Range")
                    font.pixelSize: Constants.sizeHeader2
                    font.bold: true
                    wrapMode: Text.WordWrap
                }

                RadioButton {
                    checked: true
                    text: qsTr("14 Credit hours: GPA < 2")
                    font.pixelSize: Constants.sizePrimaryText
                }
                RadioButton {
                    text: qsTr("18 Credit hours: 2 <= GPA < 3")
                    font.pixelSize: Constants.sizePrimaryText
                }
                RadioButton {
                    text: qsTr("21 Credit hours: 3 <= GPA")
                    font.pixelSize: Constants.sizePrimaryText
                }
            }
        }
    }
}
