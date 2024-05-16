import QtQuick
import QtQuick.Layouts

Item {
    implicitWidth: Constants.widthDefault
    implicitHeight: Constants.heightDefault

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
