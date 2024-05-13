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

        model: _courseModel

        delegate: CardTemplate{
            cardTitle: model.name
            content1: "Credit Hours:" + model.creditHours
            content2: "Year Of Study: " + model.YearOfStudy
            content3: "Offering Departmnet: " + model.dept
            iconPath: "qrc:/images/course_icon.svg"

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

                onClicked: _courseModel.onRemoveCourse(model.index)
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
            anchors.fill: parent
            columns: 2
            anchors.margins: 0.05*parent.width
            Text {
                id: formTitle
                text: "Enter New Subject !"
                Layout.column: 0
                Layout.columnSpan: 2
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                font.pointSize: 0.06*parent.width
            }

            Rectangle{
                id: subjectNameRect
                Layout.preferredWidth: 1
                Layout.preferredHeight: yearCombo.height
                Layout.fillWidth: true
                Layout.columnSpan: 2
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                border.color: "black"
                border.width: 1
                radius: 0.05*subjectNameRect.width

                TextInput{
                    id:subjectName
                    anchors.fill: parent
                    font.pixelSize: parent.height*0.7
                    leftPadding: 0.05*parent.width
                }
            }


            LabeledComboBox{
                id: yearCombo
                comboBoxLabel: "Year"
                comboBoxModel: ["1","2","3","4"]
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            }

            LabeledComboBox{
                id: deptCombo
                comboBoxLabel: "Department"
                comboBoxModel: ["CS","CSys","IT","SC"]
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            }

            LabeledComboBox{
                id: creditCombo
                comboBoxLabel: "CreditHours"
                comboBoxModel: ["1","2","3","4"]
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            }


            Rectangle{
                id: checkBoxRect
                clip:true
                border.color: "black"
                border.width: 1
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

                Layout.preferredWidth: 1
                Layout.preferredHeight: creditCombo.height

                Layout.fillWidth: true


                radius: 0.05*checkBoxRect.width

                RowLayout{
                    anchors.fill: parent

                    CheckBox{
                        id:labCheckBox
                        text: "Lab"
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    }

                    CheckBox{
                        id:tutorialCheckBox
                        text: "Section"
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    }
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

                onClicked: _courseModel.onAddCourse(subjectName.displayText, yearCombo.currentSelection, deptCombo.currentSelection,
                                                    creditCombo.currentSelection,
                                                    labCheckBox.checkState == Qt.Checked, tutorialCheckBox.checkState == Qt.Checked )
            }



        }
    }
}

