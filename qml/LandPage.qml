import QtQuick
import QtQuick.Controls
import lumen
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Dialogs

Rectangle {

    id: landPage
    width: Constants.editorWindowWidth
    height: Constants.editorWindowHeight
    color: Constants.backgroundDarkColor
    anchors.fill: parent
    YellowLinesImage {id: yellowLinesImage}
    LumenLogo {id: lumenLogo}
    RowLayout{
        anchors.fill: parent
        spacing: 10
        ColumnLayout {
            anchors.left: parent.left
            anchors.margins: 20
            spacing: 35
            ColumnLayout{
                RowLayout{
                    TextLandPage { text: "Schedule "}
                    TextLandPage {
                        text: "optimized!"
                        color:  Constants.yellowLandPageColor
                    }
                }
                RowLayout{
                    TextLandPage { text: "Brain power"}
                    TextLandPage {
                        text: "maximized!"
                        color:  Constants.yellowLandPageColor
                    }
                }
            }
            ColumnLayout{
                TextLandPage {
                    text: "Unleash your brain power."
                    font.pointSize: 20
                    font.bold: false
                }
                TextLandPage {
                    text: "Build your ideal class schedule in minutes."
                    font.pointSize: 20
                    font.bold: false
                }
            }
            RowLayout{
                spacing : 20
                LandPageButton {
                    id: editorButton
                    backgroundColor: editorButton.hovered ? Constants.yellowLandPageColor : Constants.whiteLandPageButtonColor
                    textContent:  "Enter as an editor"
                    borderColor: Constants.backgroundDarkColor
                    textColor: Constants.backgroundDarkColor
                }
                LandPageButton{
                    id: userButton
                    backgroundColor: userButton.hovered ? Constants.yellowLandPageColor: Constants.backgroundDarkColor
                    textContent: "  Enter as a user"
                    borderColor: Constants.whiteLandPageButtonColor
                    textColor: Constants.whiteLandPageButtonColor
                }
            }
        }
        ManImage{id: manImage}
    }
}
