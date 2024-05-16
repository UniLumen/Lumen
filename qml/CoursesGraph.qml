import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Lumen

Item {
    id: coursesPath
    implicitWidth: Constants.widthDefault
    implicitHeight: Constants.heightDefault

    TitleWithUnderline {
        id: courseGraphText
        text: "Courses Graph"
        anchors {
            top: parent.top
            topMargin: 50
            left: parent.left
        }
    }

    Rectangle {
        id: exploreCoursesCard
        width: 500
        height: 600
        radius: 16
        color: Constants.colorWhitePure
        anchors {
            top: courseGraphText.bottom
            right: parent.right
            topMargin: 50
        }

        Image {
            id: exploreCoursesIcon
            source: Constants.iconExplore
            scale: 1.2
            anchors {
                top: parent.top
                left: parent.left
                topMargin: 10
                leftMargin: 10
            }
        }

        Text {
            id: cardHeader
            text: "Explore Courses"
            font {
                pixelSize: 36
                family: Constants.fontPoppins
                weight: Font.Bold
            }
            anchors {
                top: exploreCoursesIcon.bottom
                left: exploreCoursesIcon.left
                topMargin: 20
            }
        }
        Text {
            id: courseNameHeader
            text: "Course Name"
            font {
                pixelSize: 36
                family: Constants.fontPoppins
                weight: Font.Bold
            }
            anchors {
                top: cardHeader.bottom
                left: cardHeader.left
                topMargin: 20
            }
        }

        ComboBox {
            model:[
                "Introduction to CS",
                "Physics I",
                "Calculus I",
                "Object Oriented Programming" ,
                "Database Management Systems",
                "Artificial Intelligence",
                "Data Structure",
                "Computer Graphics (CS-SC)",
                "Numerical Computing (SC)",
                "Software Engineering (Common)",
                "Analysis & Design of Algorithms (common)",
                "Pattern Recognition (CS)",
                "Natural Language Processing (CS)",
                "Digital Multimedia (IS)",
                "Image Processing (CS)",
                "Mobile Computing (IS-Csys)"
            ]
            anchors {
                top: courseNameHeader.bottom
                left: courseNameHeader.left
                topMargin: 50
            }
        }
    }

    Rectangle {
        id: graphbackground
        width: 1200
        // height: 600
        radius: 16
        color: Constants.colorWhitePure

        anchors {
            top: courseGraphText.bottom
            left: courseGraphText.left
            // right: parent.right
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
