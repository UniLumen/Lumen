import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item {
    id: root

    LumenRectangle {
        anchors {
            left: parent.left
            right: parent.right
        }
        implicitHeight: cLayout.implicitHeight + 2 * cLayout.anchors.margins

        ColumnLayout {
            id: cLayout

            anchors {
                fill: parent
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
                _from: __userModel.minCreditHours
                _to: __userModel.maxCreditHours
                _value: __userModel.creditHours
            }

            Text {
                Layout.fillWidth: true

                text: __userModel.error
                visible: __userModel.error
                font.bold: true
                font.pixelSize: Constants.sizePrimaryText
                minimumPixelSize: Constants.sizeHeader6
                fontSizeMode: Text.Fit
                wrapMode: Text.WordWrap
                color: Constants.colorRed
            }

            Text {
                Layout.fillWidth: true

                text:  __userModel.note
                visible: __userModel.note && !(__userModel.error)
                font.bold: true
                font.pixelSize: Constants.sizePrimaryText
                minimumPixelSize: Constants.sizeHeader6
                fontSizeMode: Text.Fit
                wrapMode: Text.WordWrap
                color: Constants.colorYellowMain
            }

            ColumnLayout {
                Layout.fillWidth: true
                spacing: 4

                Text {
                    Layout.fillWidth: true

                    text: "Course Name"
                    font.bold: true
                    font.pixelSize: Constants.sizeHeader2
                    minimumPixelSize: Constants.sizeHeader6
                    fontSizeMode: Text.Fit
                    wrapMode: Text.WordWrap

                    visible: _editMode
                }

                ComboBox {
                    id: cComboBox

                    Layout.preferredWidth: parent.width / 1.5
                    Layout.preferredHeight: contentItem.height

                    model:  __courseModel
                    textRole: "title"
                    valueRole: "id"
                    visible: _editMode                    
                }
            }

            Button {
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignBottom | Qt.AlignRight

                padding: 10;
                visible: _editMode

                contentItem: Text {
                    text: "Add Course"
                    font.bold: true
                    font.pixelSize: Constants.sizePrimaryText
                    minimumPixelSize: Constants.sizeHeader6
                    fontSizeMode: Text.Fit
                    wrapMode: Text.WordWrap
                }

                background: LumenRectangle {
                    color: Constants.colorYellowMain
                }

                onClicked: {
                    __userModel.addCourseRequest(cComboBox.currentValue)
                }
            }
        }
    }
}
