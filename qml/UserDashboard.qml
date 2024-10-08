import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Lumen

Item {
    property int _headerSpacing: 32
    property int _cardWidth: 200
    property int _cardHeight: 300
    property int _cellMarginX: 15
    property int _cellMarginY: 25
    property real _splitValue: 0.5
    property bool _editMode: false

    RowLayout {
        anchors {
            top:  parent.top
            bottom: parent.bottom
            left: parent.left
            right: parent.right
            topMargin: 32
        }

        spacing: 0

        // Courses
        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 1 / _splitValue

            spacing: _headerSpacing

            TitleWithUnderline {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.maximumHeight: Math.max(contentHeight, font.pixelSize)

                text: qsTr("Courses I Want to Attend")
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

                model: __userModel
                delegate: LumenCard {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    _iconSource: Constants.iconCourse
                    _text: model.title
                    _helpText: model.code
                    _description: "Course hours: " + model.creditHours

                    _checkBox0.text: "Lab"
                    _checkBox0.checked: model.hasLab
                    _checkBox1.text: "Tutorial"
                    _checkBox1.checked: model.hasTutorial
                    _checkBox2.text: "Lecture"
                    _checkBox2.checked: model.hasLecture
                    _editable: _editMode

                    onDeleteInvoked: {
                        __userModel.removeCourseRequest(model.index)
                    }

                    width: _cardWidth
                    height: _cardHeight
                }
            }
        }

        // KPIs
        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 1

            spacing: _headerSpacing

            RowLayout {
                TitleWithUnderline {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.maximumHeight: Math.max(contentHeight, font.pixelSize)

                    text: qsTr("Add a Course")
                    color: Constants.colorWhitePure
                    font.bold: true
                    font.pixelSize: Constants.sizeHeader1
                    minimumPixelSize: Constants.sizeHeader6
                    fontSizeMode: Text.Fit
                    wrapMode: Text.WordWrap
                }

                Button {
                    icon {
                        source: Constants.iconEdit
                        color: down ? Constants.colorYellowMain : Constants.colorWhitePure
                    }

                    flat: true
                    background: null
                    onClicked: _editMode = !_editMode
                }
            }

            KPI {
                id: kpi

                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }
    }
}
