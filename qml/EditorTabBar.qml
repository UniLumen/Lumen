import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts
TabBar {
    id: editorTabBar
    background: Rectangle {
        color: "transparent"
    }
    Layout.topMargin: 20
    Layout.fillWidth: true
    // Sets the color of the default bottom highlight line that is in QT TabBar, I don't want this line so I set it's color to transparent
    // Check https://stackoverflow.com/questions/42460451/color-of-line-in-tabbar-qt-qml
    Material.accent: "transparent"

    // Here I could use repeater like in EditorHomePage.qml
    // But then I would need to use a ListModel which for some reason doesn't allow constants inside it
    // So for now I will leave it like this

    LumenTabButton {
        // Space is added as a hacky way to add a margin between icon and text
        text: Constants.dashboardTabText
        icon.source: Constants.homePageIconPath
    }

    LumenTabButton {
        text: Constants.locationsTabText
        icon.source: Constants.locationIconPath
    }

    LumenTabButton {
        text: Constants.instructorsTabtext
        icon.source: Constants.instructorIconPath
    }

    LumenTabButton {
        text: Constants.coursesTabText
        icon.source: Constants.coursesIconPath
    }

    LumenTabButton {
        text: Constants.schedulesTabText
        icon.source: Constants.scheduleIconPath
    }
}
