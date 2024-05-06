import QtQuick
import QtQuick.Layouts
Item {
    anchors.fill: parent
    ColumnLayout{
        width: parent.width
        spacing: 35
        Layout.margins: 20
        RowLayout{
            id: tabBar
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 35
            Layout.margins: 20
            LumenLogo {

            }
            EditorTabBar{

            }
        }
        TextLandPage {
            Layout.leftMargin: 40
            text: "Schedules Directory"
            font.pointSize: 30
            font.bold: true
        }
    }
}
