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
        }
    }
}
