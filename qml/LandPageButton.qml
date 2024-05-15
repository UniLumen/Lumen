import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Dialogs
import Lumen

Button {
    property alias backgroundColor: buttonRectangleBackground.color
    property alias textContent: buttonText.text
    property alias textColor: buttonText.color
    property alias borderColor: buttonRectangleBackground.border.color
    
    topPadding: 16
    leftPadding: 24
    background: Rectangle {
        id: buttonRectangleBackground

        anchors.fill: parent
        border.width: 0.5
        radius: 4
    }

    contentItem: Text {
        id: buttonText

        font.pointSize: 10
        font.family: Constants.fontPoppins
        anchors.centerIn: parent
    }

    PointingHandCursor{}
}
