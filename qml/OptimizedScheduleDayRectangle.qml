import QtQuick

Rectangle {
    property alias dayName: day.text

    implicitHeight: 17
    implicitWidth: 32

    Text {
        id: day
        font {
            family: Constants.fontPoppins
            pixelSize: 9
        }
        color: Constants.colorBlackPure

        anchors.centerIn: parent
    }
}
