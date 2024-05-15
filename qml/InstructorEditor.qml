import QtQuick
import QtQuick.Layouts
import QtQuick.Controls


Item{
    id: root

    property int _headerSpacing: 32
    property int _cardWidth: 170
    property int _cardHeight: 270
    property int _cellMarginX: 15
    property int _cellMarginY: 25
    property real _splitValue: 0.5

    RowLayout {
        anchors {
            top:  parent.top
            bottom: parent.bottom
            left: parent.left
            right: parent.right
            topMargin: 32
        }

        spacing: 0

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 1 / _splitValue

            spacing: _headerSpacing

            TitleWithUnderline {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.maximumHeight: Math.max(contentHeight, font.pixelSize)

                text: "Instructors"
                color: Constants.colorWhitePure
                font.bold: true
                font.pixelSize: Constants.sizeHeader1
                minimumPixelSize: Constants.sizeHeader6
                fontSizeMode: Text.Fit
                wrapMode: Text.WordWrap
            }

            GridView {
                Layout.fillHeight: true
                Layout.fillWidth: true

                cellWidth: _cardWidth + _cellMarginX
                cellHeight: _cardHeight + _cellMarginY

                clip: true

                model: __instructorModel
                delegate: LumenCard {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    _iconSource: Constants.iconInstructor
                    _text: (model.isDoc ? "Dr. " : "Ta. ") + model.name
                    _description: "Email: " + model.email
                    _editable: true

                    onDeleteInvoked: {
                        __instructorModel.removeInstructorRequest(model.index)
                    }

                    width: _cardWidth
                    height: _cardHeight
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
        }

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 1

            spacing: _headerSpacing

            TitleWithUnderline {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.maximumHeight: Math.max(contentHeight, font.pixelSize)

                text: "Add Instructor"
                color: Constants.colorWhitePure
                font.bold: true
                font.pixelSize: Constants.sizeHeader1
                minimumPixelSize: Constants.sizeHeader6
                fontSizeMode: Text.Fit
                wrapMode: Text.WordWrap
            }

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true

                LumenRectangle {
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

                        columns: 2

                        TextField {
                            id: instructorName

                            Layout.fillWidth: true
                            Layout.columnSpan: 2

                            placeholderText: "Name"
                        }

                        TextField {
                            id: instructorEmail

                            Layout.fillWidth: true
                            Layout.columnSpan: 2

                            placeholderText: "Email"

                            validator: RegularExpressionValidator { regularExpression: /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/ }
                        }

                        CheckBox {
                            id: isDoc

                            Layout.fillWidth: true

                            text: "Check this box if the instructor is a professor"
                        }

                        RoundButton {
                            id: addButton

                            Layout.columnSpan: 2
                            Layout.fillWidth: true
                            Layout.preferredHeight: Constants.sizeHuge.height

                            background: Rectangle {
                                anchors.centerIn: parent

                                height: Math.min(parent.height, parent.width)
                                width: Math.min(parent.height, parent.width)

                                color: Constants.colorYellowMain
                                radius: 100
                            }

                            text: "+"
                            font.pixelSize: Constants.sizeHeader2

                            onClicked: {
                                if (instructorName.displayText.trim() !== "" && instructorEmail.acceptableInput && instructorEmail.displayText.trim() !== "") {
                                    __instructorModel.createInstructorRequest(instructorName.displayText, instructorEmail.displayText, isDoc.checked)
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
