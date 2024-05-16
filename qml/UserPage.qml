import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

ApplicationWindow {
    width: Constants.widthDefault
    height: Constants.heightDefault

    color: Constants.colorBackground

    background: Item {
        anchors.fill: parent

        YellowLinesImage {
            width: parent.width
            height: parent.height / 2
            anchors.bottom: parent.bottom
        }
    }

    LumenLogo {
        id: lumenLogo
    }

    UserTabBar {
        id: tabBar
        anchors {
            left: lumenLogo.right
            right: parent.right
            bottom: lumenLogo.bottom
            leftMargin: 20
            bottomMargin: -8
        }
    }

    StackLayout {
        id: stackView
        currentIndex: tabBar.currentIndex
        anchors {
            top: lumenLogo.bottom
            right: parent.right
            left: parent.left
            bottom: parent.bottom
        }

        UserDashboard {}

        UserOptimizedSchedules {}
    }
}
