import QtQuick
import QtQuick.Controls
import lumen
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Dialogs

ApplicationWindow {
    visible: true
    width:1000
    height: 500

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: landPage

        Component {
            id: landPage
            Rectangle {
                color: "#282D32"
                anchors.fill: parent
                Image {
                    anchors.bottom: parent.bottom
                    source: "file://lines.svg"
                    width: parent.width
                    height: parent.height/2
                }
                Image {
                    anchors{
                        left:parent.left
                        margins: 20
                        top : parent.top
                    }
                    source: "file://logo.svg"
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
                                    font.family: "poppins"
                                    font.bold: true
                                    font.pixelSize: 50
                                    color: "#FFFFFF"
                                    anchors.horizontalCenter: parent
                                }
                                Text {
                                    text: "optimized!"
                                    font.family: "poppins"
                                    font.bold: true
                                    font.pixelSize: 50
                                    color: "#FCB80A"
                                    anchors.horizontalCenter: parent
                                }
                            }
                            RowLayout{
                                Text {
                                    text: "Brain power"
                                    font.family: "poppins"
                                    font.bold: true
                                    font.pixelSize: 50
                                    color: "#FFFFFF"
                                    anchors.horizontalCenter: parent
                                }
                                Text {
                                    text: "maximized!"
                                    font.family: "poppins"
                                    font.bold: true
                                    font.pixelSize: 50
                                    color: "#FCB80A"
                                    anchors.horizontalCenter: parent
                                }
                            }}
                        ColumnLayout{
                            Text {
                                text: "Unleash your brain power."
                                font.pixelSize: 20
                                font.family: "poppins"
                                color: "#FFFFFF"
                                anchors.horizontalCenter: parent
                            }
                            Text {
                                text: "Build your ideal class schedule in minutes."
                                font.pixelSize: 20
                                font.family: "poppins"
                                color: "#FFFFFF"
                                anchors.horizontalCenter: parent
                            }
                        }
                        RowLayout{
                            spacing : 30
                            Button {
                                text: "Enter as an editor  "

                                background: Rectangle {
                                    width: 140
                                    height: 80
                                    color: "#FFFFFF"
                                    border.width: 0.5
                                    radius: 4
                                    border.color: "#FFFFFF"
                                }
                                contentItem: Text {
                                    text: parent.text
                                    font.family: "poppins"
                                    anchors.centerIn: parent
                                    font.pixelSize: 12
                                    color: "#282D32"
                                }
                                onClicked: {

                                }
                            }

                            Button {
                                text: " Enter as a user"

                                background: Rectangle {
                                    width: 140
                                    height: 80
                                    color: "#282D32"
                                    border.width: 0.5
                                    border.color: "#FFFFFF"
                                    radius: 4
                                    MouseArea {
                                                hoverEnabled: true
                                                onEntered: {
                                                  color: "#pink"
                                                }
                                                onExited: {
                                                  color: "transparent"
                                                }
                                          }
                                }
                                contentItem: Text {
                                    text: parent.text
                                    font.pixelSize: 12
                                    font.family: "poppins"
                                    anchors.centerIn: parent
                                    color: "#FFFFFF"
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
                        source: "file://man.svg"
                    }
                }
            }
        }
    }
}
