import QtQuick
import QtQuick.Controls

Button {
    id: moreInfoButton
    hoverEnabled: true

    onClicked: infoPopup.open()

    background: Rectangle {
        color: "transparent"
    }

    font {
        pixelSize: 15
        family: Constants.fontPoppins
        weight: Font.Light
    }

    icon {
        source: Constants.iconInfoBlack
        color: hovered ? Constants.colorYellowMain : Constants.colorBlackPure
    }

    Popup {
        id: infoPopup
        // This sets the parent of the pop-up always as the main screen being displayed
        parent: Overlay.overlay
        anchors.centerIn: parent
        // Creates the window dimming effect and disables anything behind the popup to be pressed
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose
        property string infoText: model.infoText

        contentItem: Item{
            implicitHeight: infoText.height + infoIcon.height + seperatorLine.height +
                            closeButton.height + closeButton.anchors.bottomMargin + closeButton.anchors.topMargin
            implicitWidth: infoText.width
            anchors.centerIn: parent

            Image {
                id: infoIcon
                source: Constants.iconInfoYellow
                anchors {
                    top: infoPopup.top
                    horizontalCenter: infoText.horizontalCenter
                    margins: 5
                }
                smooth: true
            }

            Text {
               id: infoText
               text: infoPopup.infoText
               font {
                   pixelSize: 20
                   family: Constants.fontPoppins
                   weight: Font.DemiBold
               }
               verticalAlignment: Text.AlignVCenter
               horizontalAlignment: Text.AlignHCenter
               anchors {
                   top: infoIcon.bottom
                   topMargin: 10
               }
            }

            Rectangle {
                id: seperatorLine
                color: "grey"
                width: parent.width
                height: 1
                anchors {
                    right: infoPopup.right
                    left: infoPopup.left
                    top: infoText.bottom
                    topMargin: 20
                }
           }

            Button {
                id: closeButton
                hoverEnabled: true

                anchors {
                    top: seperatorLine.bottom
                    bottom: infoPopup.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: 5
                    bottomMargin: 25
                }

                onClicked: infoPopup.close()

                background: Rectangle {
                   color: closeButton.hovered ? Constants.colorYellowEditorPageHover : Constants.colorYellowMain
                   radius: 15
                }

                contentItem: Text{
                    text: "Close"
                    color: Constants.colorWhitePure
                    anchors.centerIn: parent
                    font {
                        family: Constants.fontPoppins
                        weight: Font.Bold
                    }
                }

                PointingHandCursor{}
            }
       }
    }

    PointingHandCursor{}
}
