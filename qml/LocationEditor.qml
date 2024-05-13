import QtQuick
import QtQuick.Layouts
import QtQuick.Controls


Item{
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

        model: _locationModel

        delegate: CardTemplate{
            cardTitle: model.name
            content1: "Building:" + model.building
            content2: "Floor: " + model.floor
            iconPath: "qrc:/images/location_icon.svg"

            RoundButton{
                id: removeButton
                background: Image{
                    id: removeImage
                    source: "qrc:/images/icon_remove.svg"
                }
                width: parent.width/5
                height: removeButton.width

                anchors{
                    right: parent.right
                }

                onClicked: _locationModel.onRemoveLocation(model.index)
            }
        }
    }

    Rectangle{
        id: courseForm
        width: parent.width*1.5/5
        color: "white"
        anchors{
            left: gView.right
            top: parent.top
            bottom: parent.bottom
        }
        radius: courseForm.width*0.07

        GridLayout{
            columns: 2
            anchors.margins: 0.05*parent.width
            height: 0.7*parent.height
            anchors{
                left: parent.left
                right: parent.right
                verticalCenter: parent.verticalCenter
            }

            rowSpacing: 60
            Text {
                id: formTitle
                text: "Enter New Location !"
                Layout.column: 0
                Layout.columnSpan: 2
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                font.pointSize: 0.06*parent.width
            }

            Rectangle{
                id: locationNameRect
                Layout.preferredWidth: 1
                Layout.preferredHeight: floorCombo.height
                Layout.fillWidth: true
                Layout.columnSpan: 2
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                border.color: "black"
                border.width: 1
                radius: 0.05*locationNameRect.width
                clip: true

                TextInput{
                    id:locationName
                    anchors.fill: parent
                    font.pixelSize: parent.height*0.7
                    leftPadding: 0.05*parent.width
                }
            }


            LabeledComboBox{
                id: floorCombo
                comboBoxLabel: "Floor Number"
                comboBoxModel: ["1","2","3","4"]
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            }

            LabeledComboBox{
                id: buildingCombo
                comboBoxLabel: "Building"
                comboBoxModel: ["Faculty Building","Genedy"]
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            }

            Rectangle{
                id: descriptionRect
                border.width: 1
                border.color: "black"
                Layout.columnSpan: 2
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                Layout.fillHeight: true
                radius: 0.05*descriptionRect.width

                TextInput{
                    id: descriptionText
                    anchors.fill: parent
                    leftPadding: 0.05*parent.width
                    topPadding:  0.05*parent.width
                }

            }


            RoundButton{
                id: addButton
                background: Image{
                    id: addImage
                    source: "qrc:/images/addButton.svg"
                }

                Layout.preferredWidth: parent.width*0.15
                Layout.preferredHeight: addButton.width
                radius: addButton.width/2
                Layout.columnSpan: 2
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                onClicked: _locationModel.onAddLocation(locationName.displayText, buildingCombo.currentSelection, floorCombo.currentSelection, descriptionText.displayText)
            }
        }
    }
}

