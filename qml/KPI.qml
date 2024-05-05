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
                // _from: __courseModel.minCreditHours
                // _to: __courseModel.maxCreditHours
                // _value: __courseModel.creditHours
            }

            Text {
                Layout.fillWidth: true

                // text: __courseModel.errorFormated
                // visible: __courseModel.errorFormated
                font.bold: true
                font.pixelSize: Constants.sizePrimaryText
                minimumPixelSize: Constants.sizeHeader6
                fontSizeMode: Text.Fit
                wrapMode: Text.WordWrap
                color: Constants.alertRed
            }

            Text {
                Layout.fillWidth: true

                // text:  __courseModel.noteFormated
                // visible: __courseModel.noteFormated && !(__courseModel.errorFormated)
                font.bold: true
                font.pixelSize: Constants.sizePrimaryText
                minimumPixelSize: Constants.sizeHeader6
                fontSizeMode: Text.Fit
                wrapMode: Text.WordWrap
                color: Constants.accent
            }
        }
    }
}
