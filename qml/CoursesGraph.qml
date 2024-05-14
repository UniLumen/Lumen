import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Lumen

Item {
    id: coursesPath
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

    TitleWithUnderline {
        id: courseGraphText
        text: "Courses Graph"
        anchors {
            top: lumenLogo.bottom
            topMargin: 50
            left: lumenLogo.left
        }
    }

    LumenButton {
        text: "Explore Courses"

        anchors {
            top: lumenLogo.bottom
            right: graphbackground.right
            topMargin: 50
        }
    }

    Rectangle {
        id: graphbackground
        width: parent.width
        height: parent.height
        radius: 16
        color: Constants.colorWhitePure

        anchors {
            top: courseGraphText.bottom
            left: courseGraphText.left
            right: parent.right
            bottom: parent.bottom
            topMargin: 50
        }

        Image {
            id: graphCardIcon
            source: Constants.iconGraphCard
            anchors {
                top: parent.top
                left: parent.left
                topMargin: 5
                leftMargin: 5
            }
        }

        Flickable {
            id: fullGraphFlickable
            anchors.fill: parent
            contentWidth: fullGraph.width
            contentHeight: fullGraph.height
            clip: true

            DragHandler {
                cursorShape: Qt.ClosedHandCursor
            }

            //for zooming
            WheelHandler {
                target: fullGraph
                acceptedDevices: PointerDevice.Mouse
                orientation: Qt.Vertical

                property: "scale"
                rotationScale: 0.25
                targetTransformAroundCursor: true
            }

            Image {
                id: fullGraph
                source: Constants.fullGraph
            }
        }
    }

}
