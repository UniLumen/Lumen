import QtQuick
import QtQuick.Controls
import lumen
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Dialogs

ApplicationWindow {
    visible: true
    width: Constants.editorWindowWidth
    height: Constants.editorWindowHeight
    Loader {
        id: mainLoader
        anchors.fill: parent;
        source: "LandPage.qml"
    }
}
