import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Dialogs
import Lumen

ApplicationWindow {
    // This is very important, the window doesn't show up without it
    visible: true
    width: Constants.editorWindowWidth
    height: Constants.editorWindowHeight
    color: Constants.backgroundDarkColor

    background: Item {
        anchors.fill: parent
        LumenLogo {
            width: parent.width / 9
            height: parent.height / 15
            anchors{
                left: parent.left
                top : parent.top
                margins: 20
            }
        }
        YellowLinesImage {
            width: parent.width
            height: parent.height / 2
            anchors.bottom: parent.bottom
        }
    }

    Loader {
        id: mainLoader
        anchors.fill: parent;
        source: "LandPage.qml"
    }
}
