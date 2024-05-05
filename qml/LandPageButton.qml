import QtQuick
import QtQuick.Controls
import lumen
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Dialogs

Button {
    property alias backgroundColor: buttonRectangleBackground.color
    property alias textContent: buttonText.text
    property alias textColor: buttonText.color
    property alias borderColor: buttonRectangleBackground.border.color
    background: Rectangle {
        id: buttonRectangleBackground
        width: parent.width
        height: parent.height/1.4
        border.width: 0.5
        radius: 4
    }
    contentItem: Text {
        id: buttonText
        font.pointSize: 10
        font.family: Constants.poppinsFont
        anchors.centerIn: parent
    }
}
