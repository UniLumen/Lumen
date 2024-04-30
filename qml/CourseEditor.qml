import QtQuick
import QtQuick.Layouts
import QtQuick.Controls


Item{
    id: root
    anchors.fill: parent

    GridView{
        id: gView
        width: parent.width*3/5
        height: parent.height*3/5
        cellWidth: gView.width/4
        cellHeight: gView.cellWidth*1.5
        clip:true

        model: _courseModel

        delegate: CardTemplate{
            cardTitle: model.name
            content1: "Credit Hours:" + model.creditHours
            content2: "Year Of Study: " + model.YearOfStudy
            content3: "Offering Departmnet: " + model.dept
        }
    }

    Rectangle{
        id: courseForm
        width: parent.width*1.5/5
        height: parent.height*3/5
        color: "white"
        anchors{
            verticalCenter: gView.verticalCenter
            left: gView.right
            topMargin: 60
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
                id: subjectTxt
                Layout.preferredWidth: 1
                Layout.preferredHeight: yearCombo.height
                Layout.fillWidth: true
                Layout.columnSpan: 2
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                border.color: "black"
                border.width: 1
                radius: 0.05*subjectTxt.width

                TextInput{
                    anchors.fill: parent
                    font.pixelSize: parent.height*0.7
                    leftPadding: 0.05*parent.width


                    cursorDelegate: Rectangle{
                        width: 1
                        height: parent.font.pixelSize
                        color: "black"


                        anchors{
                            top: parent.top
                            bottom: parent.bottom
                        }
                    }
                }
            }


            LabeledComboBox{
                id: yearCombo
                comboBoxLabel: "Year"
                comboBoxModel: ["1","2","3","4"]
                Layout.fillWidth: true
                // Layout.fillHeight: true
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            }

            LabeledComboBox{
                id: deptCombo
                comboBoxLabel: "Department"
                comboBoxModel: ["1","2","3","4"]
                Layout.fillWidth: true
                // Layout.fillHeight: true
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            }

            LabeledComboBox{
                id: creditCombo
                comboBoxLabel: "CreditHours"
                comboBoxModel: ["1","2","3","4"]
                Layout.fillWidth: true
                // Layout.fillHeight: true
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            }


            Rectangle{
                id: checkBoxRect
                clip:true
                border.color: black
                border.width: 1
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

                Layout.preferredWidth: 1
                Layout.preferredHeight: creditCombo.height

                Layout.fillWidth: true


                radius: 0.05*checkBoxRect.width

                RowLayout{
                    anchors.fill: parent

                    CheckBox{
                        text: "Lab"
                        // Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    }

                    CheckBox{
                        text: "Section"
                        // Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    }
                }
            }

            Rectangle{
                id: submit
                Layout.preferredWidth: 0.05*parent.width
                Layout.preferredHeight: submit.width
                color:"green"
                radius: submit.width/2
                Layout.columnSpan: 2
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            }




        }
    }
}

