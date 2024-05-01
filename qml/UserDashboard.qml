import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Lumen

Item {
    property int _headerSpacing: 32
    property int _cardWidth: 150
    property int _cardHeight: 250
    property int _cellMarginX: 15
    property int _cellMarginY: 25

    RowLayout {
        anchors.fill: parent
        spacing: 0

        // Courses
        ColumnLayout {
            Layout.preferredWidth: parent.width * 0.65
            spacing: _headerSpacing

            Text {
                text: qsTr("My Courses")
                color: Constants.foreground
                font.pixelSize: Constants.sizeHeader1
                font.bold: true
                wrapMode: Text.WordWrap
            }

            GridView {
                Layout.fillHeight: true
                implicitWidth: parent.width

                cellWidth: _cardWidth + _cellMarginX
                cellHeight: _cardHeight + _cellMarginY

                clip: true

                model: 10
                delegate: LumenCard {
                    _iconSource: Constants.iconCourse
                    _text: "Course Name"
                    _helpText: "CS50"
                    _description: "Course hours: " + 3

                    width: _cardWidth
                    height: _cardHeight
                }
            }
        }

        // KPIs
        ColumnLayout {
            Layout.fillWidth: true
            spacing: _headerSpacing

            Text {
                text: qsTr("Selection KPIs")
                color: Constants.foreground
                font.pixelSize: Constants.sizeHeader1
                font.bold: true
                wrapMode: Text.WordWrap
            }

            KPI {
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }
    }
}
