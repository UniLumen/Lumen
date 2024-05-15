import QtQuick

Text {
    id: root

    font {
        family: Constants.fontPoppins
        pixelSize: 45
        weight: Font.ExtraBold
    }
    color: Constants.colorWhitePure

    Rectangle {
        height: parent.contentHeight / 4
        width: parent.contentWidth / 4
        radius: 8
        color: Constants.colorYellowMain
        anchors {
            top: root.bottom
            topMargin: 10
            left: parent.left
        }
    }
}
