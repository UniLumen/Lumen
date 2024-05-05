import QtQuick

Image {
    id: manImage
    sourceSize: Qt.size(parent.width/2.3,parent.height/2.3)
    fillMode: Image.PreserveAspectFit
    mipmap: true
    source: Constants.manPhotoPath
}
