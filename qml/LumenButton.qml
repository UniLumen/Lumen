import QtQuick
import QtQuick.Controls
import Lumen

Button {
    id: lumenButton

    background: Rectangle {
        id: bacground
        property bool hovered: false

        color: Constants.colorYellowMain
        opacity: hovered? 0.6:1
        anchors.fill: parent
        radius: 16
    }

    font {
        pixelSize: 24
        family: Constants.fontPoppins
        weight: Font.Thin
    }

    Text {
        color: Constants.colorBackground
    }

    HoverHandler {
        onHoveredChanged: bacground.hovered ^= 1
    }

    PointingHandCursor{}
}
