import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material

TabBar {
    id: editorTabBar

    background: Rectangle {
        color: "transparent"
    }

    // Sets the color of the default bottom highlight line that is in QT TabBar, I don't want this line so I set it's color to transparent
    // Check https://stackoverflow.com/questions/42460451/color-of-line-in-tabbar-qt-qml
    Material.accent: "transparent"

    // Here I could use repeater like in EditorHomePage.qml
    // But then I would need to use a ListModel which for some reason doesn't allow constants inside it
    // So for now I will leave it like this

    LumenTabButton {
        text: Constants.textDashboardTab
        icon.source: Constants.iconHome
    }

    LumenTabButton {
        text: Constants.textSchedulesTab
        icon.source: Constants.iconSchedule
    }


    LumenTabButton {
        text: "Courses Graph"
        icon.source: Constants.iconGraph
    }
}
