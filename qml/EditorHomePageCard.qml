import QtQuick
import QtQuick.Controls

Button {
    id: homePageCard

    display: AbstractButton.TextUnderIcon
    hoverEnabled: true
    text: model.title

    background: Rectangle {
        color: homePageCard.hovered && !moreInfoButton.hovered ? Constants.yellowColor : Constants.whiteColor
        implicitWidth: 380
        implicitHeight: 420
        radius: 25
    }

    font {
        pixelSize: 35
        family: Constants.mainFont
        weight: Font.Bold
    }

    icon {
        height: 94
        width: 73
        source: model.iconPath
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
