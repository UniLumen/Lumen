import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Lumen

Item {
    property int _headerSpacing: 32
    property int _cardWidth: 170
    property int _cardHeight: 270
    property int _cellMarginX: 15
    property int _cellMarginY: 25
    property real _splitValue: 0.5
    property bool _editMode: false

    LumenLogo {
        id: lumenLogo
    }

    UserTabBar {
        id: tabBar
        anchors {
            left: lumenLogo.right
            right: parent.right
            bottom: lumenLogo.bottom
            leftMargin: 20
            bottomMargin: -8
        }
    }

    RowLayout {
        anchors {
            top:  lumenLogo.bottom
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

                text: qsTr("My Courses")
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

                    text: qsTr("Selection KPIs")
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
