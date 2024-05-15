import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Dialogs
import Lumen

Item {
    id: landPage

    LumenLogo {}

    RowLayout {
        anchors.fill: parent
        spacing: 5

        ColumnLayout {
            Layout.alignment: Qt.AlignLeft
            spacing: 35

            ColumnLayout{
                RowLayout{
                    LandPageText {
                        text: "Schedule "
                    }
                    LandPageText {
                        text: "optimized!"
                        color:  Constants.colorYellowMain
                    }
                }

                RowLayout{
                    LandPageText {
                        text: "Brain power"
                    }
                    LandPageText {
                        text: "maximized!"
                        color:  Constants.colorYellowMain
                    }
                }
            }

            ColumnLayout{
                LandPageText {
                    text: "Unleash your brain power."
                    font.pointSize: 20
                    font.bold: false
                }
                LandPageText {
                    text: "Build your ideal class schedule in minutes."
                    font.pointSize: 20
                    font.bold: false
                }
            }

            RowLayout{
                spacing : 20

                LandPageButton {
                    id: userButton
                    backgroundColor: userButton.hovered ? Constants.colorYellowMain : Constants.colorWhiteLandPageButton
                    textContent:  "Enter as a user"
                    borderColor: Constants.colorBackground
                    textColor: Constants.colorBackground

                    onClicked: mainLoader.source = "UserDashboard.qml"
                }

                LandPageButton{
                    id: editorButton
                    backgroundColor: editorButton.hovered ? Constants.colorYellowMain : Constants.colorBackground
                    textContent: " Enter as an editor "
                    borderColor: editorButton.hovered ? Constants.colorBackground : Constants.colorWhiteLandPageButton
                    textColor: editorButton.hovered ? Constants.colorBlackPure : Constants.colorWhiteLandPageButton

                    onClicked: mainLoader.source = "EditorPage.qml"
                }
            }
        }

        ManImage{
            id: manImage

            Layout.alignment: Qt.AlignCenter
            Layout.margins: 20
        }
    }
}
