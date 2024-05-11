import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Dialogs
import Lumen

ApplicationWindow {
    visible: true
    width: Constants.editorWindowWidth
    height: Constants.editorWindowHeight
    color: Constants.backgroundDarkColor

    background: Item {
        anchors.fill: parent

        YellowLinesImage {
            width: parent.width
            height: parent.height / 2
            anchors.bottom: parent.bottom
        }
    }

    Loader {
        id: mainLoader
        anchors.fill: parent;
        source: "TestCompoBix.qml"
    }
}
