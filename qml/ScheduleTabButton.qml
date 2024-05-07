import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
TabButton {
    id: scheduleTabButton
    // when button is NOT clicked
    Material.foreground: Constants.whiteColor
    // when button is clicked
    Material.accent: Constants.yellowColor
    Layout.preferredWidth: 35
    Layout.preferredHeight: 20
    font {
        pixelSize: parent.activeFocusOnTab? 45: 30
        family: Constants.mainFont
        weight: Font.Thin
    }
    PointingHandCursor{}
}
