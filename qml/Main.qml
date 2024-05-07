import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Dialogs
import Lumen

ApplicationWindow {
    // This is very important, the window doesn't show up without it
    visible: true
    width: Constants.widthDefault
    height: Constants.heightDefault
    color: Constants.colorBackground

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
        source: "LandPage.qml"
    }
}
