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
            //     _from: __courseModel.minCreditHours
            //     _to: __courseModel.maxCreditHours
            //     _value: __courseModel.creditHours
            }

            Text {
                // text: __courseModel.errorFormated
                // visible: __courseModel.errorFormated
                font.pixelSize: Constants.sizePrimaryText
                font.bold: true
                color: Constants.alertRed
            }

            Text {
                // text:  __courseModel.noteFormated
                // visible: __courseModel.noteFormated && !(__courseModel.errorFormated)
                font.pixelSize: Constants.sizePrimaryText
                font.bold: true
                color: Constants.accent
            }
        }
    }
}
