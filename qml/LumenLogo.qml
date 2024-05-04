import QtQuick

Image{
    id: lumenLogo
    sourceSize: Qt.size(Constants.lumenLogoWidth, Constants.lumenLogoHeight)
    anchors {
        top: parent.top
        left: parent.left
        margins: 40
    }
    source: Constants.lumenLogoPath
    smooth: true
}

