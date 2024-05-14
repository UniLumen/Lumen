import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item {
    id: root

    LumenLogo {
        id: lumenLogo
    }

    EditorTabBar {
        id: editorTabBar

        anchors {
            left: lumenLogo.right
            right: parent.right
            bottom: lumenLogo.bottom
            leftMargin: 20
            bottomMargin: -8
        }
    }

    GridView {
        id: gView

        anchors {
            top: editorTabBar.bottom;
            bottom: parent.bottom;
        }

        width: parent.width * 3 / 5
        cellWidth: gView.width / 4
        cellHeight: gView.cellWidth * 1.5
        clip: true

        model: __courseModel

        delegate: CardTemplate {
            cardTitle: model.title

            content1: "Credit Hours: " + model.creditHours
            content2: "Year Of Study: " + model.YearOfStudy
            content3: "Offering Departmnet: " + model.dept
            iconPath: "qrc:/images/course_icon.svg"

            RoundButton {
                id: removeButton

                anchors{
                    right: parent.right
                }

                width: parent.width/5
                height: removeButton.width

                background: Image{
                    id: removeImage
                    source: "qrc:/images/icon_remove.svg"
                }

                onClicked: __courseModel.removeCourseRequest(model.index)
            }
        }

        displaced: Transition {
            NumberAnimation { properties: "x,y"; duration: 250 }
        }

        remove: Transition {
            NumberAnimation { property: "opacity"; to: 0; duration: 250 }
        }

        add: Transition {
            NumberAnimation { property: "opacity"; from: 0; to: 1; duration: 250 }
        }
    }

    Rectangle {
        id: courseForm

        anchors {
            left: gView.right
            top: parent.top
            bottom: parent.bottom
        }

        width: parent.width * 1.5 / 5
        radius: courseForm.width*0.07
        color: "white"

        GridLayout{
            anchors {
                fill: parent
                margins: 0.05 * parent.width
            }

            columns: 2

            Text {
                id: formTitle

                text: "Enter New Subject !"
                font.pointSize: 0.06 *parent.width

                Layout.column: 0
                Layout.columnSpan: 2
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
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
                radius: 0.05 * subjectNameRect.width

                TextInput {
                    id:subjectName
                    anchors.fill: parent
                    font.pixelSize: parent.height*0.7
                    leftPadding: 0.05*parent.width
                }
            }


            LabeledComboBox {
                id: yearCombo
                comboBoxLabel: "Year"
                comboBoxModel: ["1","2","3","4"]
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            }

            LabeledComboBox {
                id: deptCombo
                comboBoxLabel: "Department"
                comboBoxModel: ["CS","CSys","IT","SC"]
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            }

            LabeledComboBox {
                id: creditCombo
                comboBoxLabel: "CreditHours"
                comboBoxModel: ["1","2","3","4"]
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            }

            Rectangle {
                id: checkBoxRect

                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                Layout.preferredWidth: 1
                Layout.preferredHeight: creditCombo.height
                Layout.fillWidth: true

                clip: true
                border.color: "black"
                border.width: 1
                radius: 0.05 * checkBoxRect.width

                RowLayout {
                    anchors.fill: parent

                    CheckBox {
                        id:labCheckBox
                        text: "Lab"
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    }

                    CheckBox {
                        id:tutorialCheckBox
                        text: "Section"
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    }
                }
            }

            RoundButton{
                id: addButton

                background: Image {
                    id: addImage
                    source: "qrc:/images/addButton.svg"
                }

                Layout.preferredWidth: parent.width * 0.15
                Layout.preferredHeight: addButton.width
                radius: addButton.width / 2
                Layout.columnSpan: 2
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                onClicked: {
                    var courseDTO = {
                        "name": subjectName.displayText,
                        "year": yearCombo.currentSelection,
                        "dept": deptCombo.currentSelection,
                        "creditHours": creditCombo.currentSelection,
                        "hasLab": labCheckBox.checked,
                        "hasTutorial": tutorialCheckBox.checked
                    };

                    __courseModel.createCourse(courseDTO);
                }
            }
        }
    }
}

