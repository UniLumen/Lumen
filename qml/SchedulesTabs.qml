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
        model: []

        ScheduleTabButton {
            text: modelData
        }
    }
}
