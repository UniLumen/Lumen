import QtQuick

Image {
    width: parent.width / 9
    height: parent.height / 15
    anchors{
        left: parent.left
        top : parent.top
    }

    source: Constants.imageLumenLogo
    sourceSize: Constants.tRes128x128
    fillMode: Image.PreserveAspectFit

    MouseArea {
        onClicked: mainLoader.source = "LandPage.qml"
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
    }
}
