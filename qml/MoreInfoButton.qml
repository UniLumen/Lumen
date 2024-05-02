import QtQuick
import QtQuick.Controls

Button {
    id: moreInfoButton

    hoverEnabled: true

    background: Rectangle {
        color: "transparent"
    }

    font {
        pixelSize: 15
        family: Constants.mainFont
        weight: Font.Light
    }

    icon {
        source: Constants.moreInfoIconPath
        color: hovered ? Constants.yellowColor : Constants.blackColor
    }
}
