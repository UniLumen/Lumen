import QtQuick
import QtQuick.Controls

TabButton {
    id: lumenTabButton

    // Sets the color of the text
    // when button is NOT clicked
    Material.foreground: Constants.whiteColor
    // when button is clicked
    Material.accent: Constants.yellowColor
    font {
        pixelSize: 30
        family: Constants.mainFont
        weight: Font.Thin
    }

    icon {
        Material.foreground: Constants.whiteColor
        Material.accent: Constants.yellowColor
        height: 35
        width: 33
    }
}
