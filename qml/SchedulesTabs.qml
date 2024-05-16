import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts
TabBar {
    id: bar
    Layout.fillWidth: true
    background: Rectangle {
        color: "transparent"
    }
    Material.accent: Constants.yellowColor
    Repeater {
        model: ["Year1G1","Year1G2","Year2G1","Year2G2",]

        ScheduleTabButton {
            text: modelData
        }
    }
}
