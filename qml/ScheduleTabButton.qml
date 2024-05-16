import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
TabButton {
    id: scheduleTabButton
    // when button is NOT clicked
    Material.foreground: Constants.colorWhitePure
    // when button is clicked
    Material.accent: Constants.colorYellowMain
    Layout.preferredWidth: 35
    Layout.preferredHeight: 20
    font {
        pixelSize: parent.activeFocusOnTab? 45: 30
        family: Constants.fontPoppins
        weight: Font.Thin
    }
    PointingHandCursor{}
}
