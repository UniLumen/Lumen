import QtQuick
import QtQuick.Controls

TabButton {
    id: lumenTabButton

    // Sets the color of the text
    // When button is NOT clicked
    Material.foreground: Constants.colorWhitePure
    // When button is clicked
    Material.accent: Constants.colorYellowMain

    font {
        pixelSize: 30
        family: Constants.fontPoppins
        weight: Font.Thin
    }

    icon {
        Material.foreground: Constants.colorWhitePure
        Material.accent: Constants.colorYellowMain
        height: 35
        width: 33
    }

    PointingHandCursor{}
}
