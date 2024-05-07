import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item {
    id: root

    anchors.fill: parent


    GridView{
        id: gView
        width: parent.width*3/5
        height: parent.height
        cellWidth: gView.width/4
        cellHeight: gView.cellWidth*1.5
        clip:true

        displaced: Transition{
            NumberAnimation { properties: "x,y"; duration: 250 }
        }

        remove: Transition{
            NumberAnimation { property: "opacity"; to: 0; duration: 250 }
        }

        add: Transition{
            NumberAnimation { property: "opacity"; from: 0; to: 1; duration: 250 }
        }

        model: _instructorModel

        delegate: CardTemplate{
            cardTitle: model.name
            content1: "Email: " + model.email

            RoundButton{
                id: removeButton
                background: Image{
                    id: removeImage
                    source: "qrc:/resources/removeButton.png"
                }
                width: parent.width/5
                height: removeButton.width

                anchors{
                    right: parent.right
                }

                onClicked: _instructorModel.onRemoveInstructor(model.index)
            }
        }
    }

    Rectangle{
        id: instructorForm
        width: parent.width*1.5/5
        color: "white"
        anchors{
            left: gView.right
            top: parent.top
            bottom: parent.bottom
        }
        radius: instructorForm.width*0.07

        GridLayout{
            anchors{
                left: parent.left
                right: parent.right
                top: parent.top
            }
            height: 0.6*parent.height

            anchors.margins: 0.05*parent.width
            columns: 2
            Text {
                id: formTitle
                text: "Enter New Instructor !"
                Layout.column: 0
                Layout.columnSpan: 2
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                font.pointSize: 0.06*parent.width
            }

            Rectangle{
                id: instructorNameRect
                Layout.preferredWidth: 1
                Layout.preferredHeight: 50
                Layout.fillWidth: true
                Layout.columnSpan: 2
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                border.color: "black"
                border.width: 1
                radius: 0.08*instructorNameRect.width
                clip:true

                TextInput{
                    id:instructorName
                    font.pixelSize: parent.height*0.7
                    text: "Doctor/Ta Name"
                    anchors.fill: parent
                    leftPadding: 0.05*parent.width
                }
            }

            Rectangle{
                id: instructorEmailRect
                Layout.preferredWidth: 1
                Layout.preferredHeight: 50
                Layout.fillWidth: true
                Layout.columnSpan: 2
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                border.color: "black"
                border.width: 1
                radius: 0.08*instructorEmailRect.width
                clip:true

                TextInput{
                    id:instructorEmail
                    text: "Email"
                    anchors.fill: parent
                    font.pixelSize: parent.height*0.7
                    leftPadding: 0.05*parent.width
                }
            }

            RoundButton{
                id: addButton
                background: Image{
                    id: addImage
                    source: "qrc:/resources/addButton.svg"
                }

                Layout.preferredWidth: parent.width*0.15
                Layout.preferredHeight: addButton.width
                radius: addButton.width/2
                Layout.columnSpan: 2
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                onClicked: _instructorModel.onAddInstructor(instructorName.displayText, instructorEmail.displayText)
            }
        }
    }
}
