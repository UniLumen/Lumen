import QtQuick

Image {
    width: parent.width / 9
    height: parent.height / 15
    anchors{
        left: parent.left
        top : parent.top
    }

    source: Constants.imageLumenLogo
    fillMode: Image.PreserveAspectFit
    mipmap: true

    MouseArea {
        onClicked: mainLoader.source = "LandPage.qml"
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
    }
}
