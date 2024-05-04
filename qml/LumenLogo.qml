import QtQuick
Image {
    width: parent.width/9
    height: parent.height/15
    anchors{
        left:parent.left
        margins: 20
        top : parent.top
    }
    source: Constants.lumenLogoPath

    fillMode: Image.PreserveAspectFit
    mipmap: true

}
