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

                validator: RegularExpressionValidator { regularExpression: /^[a-zA-Z0-9]*$/ }
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

                enabled: yearCombo.currentValue > 2
            }

            ComboBox {
                id: creditCombo
                displayText: "CreditHours: " + currentValue
                model: [1, 2, 3, 4, 5]
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

                        onCheckStateChanged: {
                            lectureManAttenCheckBox.enabled = checked
                            lectureManAttenCheckBox.checked = false;
                        }
                    }

                    CheckBox {
                        id:labCheckBox

                        Layout.fillWidth: true

                        text: "Lab"

                        onCheckStateChanged: {
                            labManAttendCheckBox.enabled = checked
                            labManAttendCheckBox.checked = false;
                        }
                    }

                    CheckBox {
                        id:tutorialCheckBox

                        Layout.fillWidth: true

                        text: "Section"

                        onCheckStateChanged: {
                            tutorialManAttendCheckBox.enabled = checked
                            tutorialManAttendCheckBox.checked = false;
                        }
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

                        enabled: false
                    }

                    CheckBox {
                        id:labManAttendCheckBox

                        Layout.fillWidth: true

                        text: "Lab"

                        enabled: false
                    }

                    CheckBox {
                        id:tutorialManAttendCheckBox

                        Layout.fillWidth: true

                        text: "Section"

                        enabled: false
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
                    if ((subjectName.displayText.trim() !== "") && (subjectCode.displayText.trim() !== "")) {
                        var deptValue = deptCombo.enabled ? deptCombo.currentValue : "";

                        var courseDTO = {
                            "name": subjectName.displayText.trim(),
                            "year": yearCombo.currentValue,
                            "dept": deptValue,
                            "code": subjectCode.displayText.trim(),
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
}
