import QtQuick
import QtQuick.Controls
import lumen
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Dialogs

ApplicationWindow {
    visible: true
    width:800
    height:600

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: landPage

        Component {
            id: landPage
            Rectangle {
                color: Constants.backgroundDarkColor
                anchors.fill: parent
                Image {
                    anchors.bottom: parent.bottom
                    source: Constants.yellowLinesImagePath
                    width: parent.width
                    height: parent.height/2
                }
                Image {
                    anchors{
                        left:parent.left
                        margins: 20
                        top : parent.top
                    }
                    source: Constants.lumenLogoPath
                    width: parent.width/9
                    height: parent.height/15

                }
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
                                    font.family: Constants.mainFont
                                    font.bold: true
                                    font.pointSize: 50 * Qt.scaleFactor
                                    color: Constants.mainFont
                                    anchors.horizontalCenter: parent
                                }
                                Text {
                                    text: "optimized!"
                                    font.family: Constants.mainFont
                                    font.bold: true
                                    font.pointSize: 50 * Qt.scaleFactor
                                    color: Constants.yellowColor
                                    anchors.horizontalCenter: parent
                                }
                            }
                            RowLayout{
                                Text {
                                    text: "Brain power"
                                    font.family: Constants.mainFont
                                    font.bold: true
                                    font.pointSize: 50 * Qt.scaleFactor
                                    color: Constants.WhiteColor
                                    anchors.horizontalCenter: parent
                                }
                                Text {
                                    text: "maximized!"
                                    font.family: Constants.mainFont
                                    font.bold: true
                                    font.pointSize: 50 * Qt.scaleFactor
                                    color: Constants.yellowColor
                                    anchors.horizontalCenter: parent
                                }
                            }}
                        ColumnLayout{
                            Text {
                                text: "Unleash your brain power."
                                font.pointSize: 20 * Qt.scaleFactor
                                font.family:Constants.mainFont
                                color: Constants.mainFont
                                anchors.horizontalCenter: parent
                            }
                            Text {
                                text: "Build your ideal class schedule in minutes."
                                font.pointSize: 20 * Qt.scaleFactor
                                font.family: Constants.mainFont
                                color:  Constants.WhiteColor
                                anchors.horizontalCenter: parent
                            }
                        }
                        RowLayout{
                            spacing : 30
                            Button {
                                id: editorButton
                                hoverEnabled: true
                                background: Rectangle {
                                    color: editorButton.hovered ? Constants.yellowColor: Constants.backgroundDarkColor
                                    border.width: 0.5
                                    radius: 4
                                    border.color:  Constants.WhiteColor
                                }
                                contentItem: Text {
                                    text: "Enter as an editor  "
                                    font.family: Constants.mainFont
                                    anchors.centerIn: parent
                                    font.pointSize: 14 * Qt.scaleFactor
                                    color: Constants.whiteColor
                                }
                                onClicked: {

                                }
                            }

                            Button {
                                id: userButton
                                background: Rectangle {
                                    color: userButton.hovered ? Constants.yellowColor : Constants.whiteColor
                                    border.width: 0.5
                                    border.color: Constants.mainFont
                                    radius: 4
                                }
                                contentItem: Text {
                                    text: " Enter as a user"
                                    font.pointSize: 14 * Qt.scaleFactor
                                    font.family: Constants.mainFont
                                    anchors.centerIn: parent
                                    color: Constants.backgroundDarkColor
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
                        sourceSize: Qt.size(parent.width/2.3,parent.height/2)
                        source: Constants.manPhotoPath
                    }
                }
            }
        }
    }
}
