import QtQuick
import QtQuick.Controls

Button {
    id: homePageCard

    property alias infoText: moreInfoButton.infoPopupText

    display: AbstractButton.TextUnderIcon
    hoverEnabled: true

    background: Rectangle {
        color: homePageCard.hovered && !moreInfoButton.hovered ? Constants.colorYellowMain : Constants.colorWhitePure
        implicitWidth: 380
        implicitHeight: 420
        radius: 25
    }

    font {
        pixelSize: 35
        family: Constants.fontPoppins
        weight: Font.Bold
    }

    icon {
        height: 94
        width: 73
    }

    MoreInfoButton {
        id: moreInfoButton
        anchors {
            bottom: homePageCard.bottom
            left: homePageCard.left
            margins: 15
        }
    }

    PointingHandCursor{}
}
