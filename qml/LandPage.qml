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
                    Text {
                        text: "Schedule "
                        font.family: constants.poppinsFont
                        font.bold: true
                        font.pointSize:35
                        color: Constants.whiteColor
                        anchors.horizontalCenter: parent
                    }
                    Text {
                        text: "optimized!"
                        font.family: Constants.poppinsFont
                        font.bold: true
                        font.pointSize:35
                        color: Constants.yellowColor
                        anchors.horizontalCenter: parent
                    }
                }
                RowLayout{
                    Text {
                        text: "Brain power"
                        font.family: Constants.poppinsFont
                        font.bold: true
                        font.pointSize:35
                        color: Constants.whiteColor
                        anchors.horizontalCenter: parent
                    }
                    Text {
                        text: "maximized!"
                        font.family: Constants.poppinsFont
                        font.bold: true
                        font.pointSize: 35
                        color: Constants.yellowColor
                        anchors.horizontalCenter: parent
                    }
                }}
            ColumnLayout{
                Text {
                    text: "Unleash your brain power."
                    font.pointSize: 14
                    font.family:Constants.poppinsFont
                    font.weight: medium
                    color: Constants.whiteColor
                    anchors.horizontalCenter: parent
                }
                Text {
                    text: "Build your ideal class schedule in minutes."
                    font.pointSize: 14
                    font.weight: medium
                    font.family: Constants.poppinsFont
                    color:  Constants.whiteColor
                    anchors.horizontalCenter: parent
                }
            }
            RowLayout{
                spacing : 20
                Button {
                    id: editorButton
                    hoverEnabled: true
                    background: Rectangle {
                        width: 140
                        implicitHeight: 34
                        color: editorButton.hovered ? Constants.yellowColor : Constants.buttonColor
                        border.width: 0.5
                        border.color: Constants.backgroundDarkColor
                        radius: 4
                    }
                    contentItem: Text {
                        text: "Enter as an editor"
                        font.family: Constants.poppinsFont
                        anchors.centerIn: parent
                        font.pointSize: 10
                        color: Constants.backgroundDarkColor
                    }
                    onClicked: {

                    }
                }

                Button {
                    id: userButton
                    background: Rectangle {
                        width: 140
                        implicitHeight: 30
                        color: userButton.hovered ? Constants.yellowColor: Constants.backgroundDarkColor
                        border.width: 0.5
                        radius: 4
                        border.color: Constants.buttonColor
                    }
                    contentItem: Text {
                        text: "  Enter as a user"
                        font.pointSize: 10
                        font.family: Constants.poppinsFont
                        anchors.centerIn: parent
                        color: Constants.buttonColor

                    }
                    onClicked: {

                    }
                }
            }
        }
        Image {
            anchors{
                right: parent.right
                margins:20
            }
            sourceSize: Qt.size(parent.width/2.3,parent.height/2.3)
            fillMode: Image.PreserveAspectFit
            mipmap: true
            source: Constants.manPhotoPath
        }
    }
}
