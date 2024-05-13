import QtQuick
import QtQuick.Layouts
Image {
    id: lumenLogo
    Layout.preferredWidth:Constants.lumenLogoWidth
    Layout.preferredHeight: Constants.lumenLogoHeight
    sourceSize: Qt.size(Constants.lumenLogoWidth, Constants.lumenLogoHeight)
    source: Constants.lumenLogoPath
    smooth: true
}
