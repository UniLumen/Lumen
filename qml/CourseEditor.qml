import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item {
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

                text: "Courses"
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

                model: __courseModel
                delegate: LumenCard {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    _iconSource: Constants.iconCourse
                    _text: model.title
                    _helpText: model.code
                    _description: "Course hours: " + model.creditHours
                    _editable: true

                    onDeleteInvoked: {
                        __courseModel.removeCourseRequest(model.index)
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

                text: "Add Course"
                color: Constants.colorWhitePure
                font.bold: true
                font.pixelSize: Constants.sizeHeader1
                minimumPixelSize: Constants.sizeHeader6
                fontSizeMode: Text.Fit
                wrapMode: Text.WordWrap
            }

            CourseForm {
                Layout.fillWidth: true
                Layout.fillHeight: true;
            }
        }
    }
}

