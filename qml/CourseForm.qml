import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item {
    id: root

    LumenRectangle {
        id: courseForm

        anchors {
            left: parent.left
            right: parent.right
        }
        implicitHeight: cLayout.implicitHeight + 2 * cLayout.anchors.margins

        GridLayout {
            id: cLayout

            anchors {
                fill: parent
                margins: 0.05 * parent.width
            }

            columns: 3

            TextField {
                id: subjectName

                Layout.fillWidth: true
                Layout.columnSpan: 2

                placeholderText: "Course Name"
            }

            TextField {
                id: subjectCode

                Layout.fillWidth: true
                Layout.columnSpan: 1

                placeholderText: "Course Code"
            }

            ComboBox {
                id: yearCombo

                displayText: "Year: " + currentValue
                model: [1, 2, 3, 4]
                Layout.fillWidth: true
            }

            ComboBox {
                id: deptCombo

                displayText: "Department: " + currentValue
                model: ["CS", "CSys", "IT", "SC"]
                Layout.fillWidth: true
            }

            ComboBox {
                id: creditCombo
                displayText: "CreditHours: " + currentValue
                model: [1, 2, 3, 4]
                Layout.fillWidth: true
            }

            GroupBox {
                Layout.fillWidth: true
                Layout.columnSpan: 3

                title: "Components"

                RowLayout {
                    anchors.fill: parent

                    CheckBox {
                        id: lectureCheckBox

                        Layout.fillWidth: true

                        text: "Lecture"
                    }

                    CheckBox {
                        id:labCheckBox

                        Layout.fillWidth: true

                        text: "Lab"
                    }

                    CheckBox {
                        id:tutorialCheckBox

                        Layout.fillWidth: true

                        text: "Section"
                    }
                }
            }

            GroupBox {
                Layout.fillWidth: true
                Layout.columnSpan: 3

                title: "Mandatory Attendance"

                RowLayout {
                    anchors.fill: parent

                    CheckBox {
                        id: lectureManAttenCheckBox

                        Layout.fillWidth: true

                        text: "Lecture"
                    }

                    CheckBox {
                        id:labManAttendCheckBox

                        Layout.fillWidth: true

                        text: "Lab"
                    }

                    CheckBox {
                        id:tutorialManAttendCheckBox

                        Layout.fillWidth: true

                        text: "Section"
                    }
                }
            }

            RoundButton {
                id: addButton

                Layout.columnSpan: 3
                Layout.fillWidth: true
                Layout.preferredHeight: Constants.sizeHuge.height

                background: Image {
                    id: addImage
                    source: Constants.iconAdd
                    fillMode: Image.PreserveAspectFit
                    mipmap: true
                }

                onClicked: {
                    var courseDTO = {
                        "name": subjectName.displayText,
                        "year": yearCombo.currentValue,
                        "dept": deptCombo.currentValue,
                        "code": subjectCode.displayText,
                        "creditHours": creditCombo.currentValue,
                        "hasLecture": lectureCheckBox.checked,
                        "hasLab": labCheckBox.checked,
                        "hasTutorial": tutorialCheckBox.checked,
                        "isLectureMandatory": lectureManAttenCheckBox.checked,
                        "isLabMandatory": labManAttendCheckBox.checked,
                        "isTutorialMandatory": tutorialManAttendCheckBox.checked,
                    };

                    __courseModel.createCourse(courseDTO);
                }
            }
        }
    }
}
