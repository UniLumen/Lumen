import QtQuick

Item {
    id: titleWithUnderline
    property alias title: titleText.text

    Text {
        id: titleText
        font {
            family: Constants.fontPoppins
            pixelSize: 45
            weight: Font.ExtraBold
        }
        color: Constants.colorWhitePure
        anchors {
            left: parent.left
            top: parent.top
        }
    }

    Rectangle {
        height: titleText.height / 4
        width: titleText.width / 4
        radius: 8
        color: Constants.colorYellowMain
        anchors {
            top: titleText.bottom
            topMargin: 10
            left: parent.left
        }
    }
}
