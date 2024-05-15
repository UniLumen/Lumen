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
    property bool _editorMode: true

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

                text: "Locations"
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

                model: __locationModel
                delegate: LumenCard {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    _iconSource: Constants.iconLocation
                    _text: model.name
                    _description: "Building: " + model.building +
                                  "\nFloor: " + model.floor

                    onDeleteInvoked: {
                        __locationModel.removeLocationRequest(model.index)
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

                text: "Add Location"
                color: Constants.colorWhitePure
                font.bold: true
                font.pixelSize: Constants.sizeHeader1
                minimumPixelSize: Constants.sizeHeader6
                fontSizeMode: Text.Fit
                wrapMode: Text.WordWrap
            }


            LumenRectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                implicitHeight: cLayout.implicitHeight + 2 * cLayout.anchors.margins

                GridLayout {
                    id: cLayout

                    anchors {
                        fill: parent
                        margins: 0.05 * parent.width
                    }

                    columns: 2

                    TextField {
                        id: locationName

                        Layout.fillWidth: true
                        Layout.columnSpan: 2

                        placeholderText: "Name"
                    }

                    ComboBox {
                        id: floorCombo

                        Layout.fillWidth: true

                        displayText: "Floor #: " + currentValue
                        model: [1, 2, 3, 4]
                    }

                    ComboBox {
                        id: buildingCombo

                        Layout.fillWidth: true

                        displayText: "Building: " + currentValue
                        model: ["Faculty Building", "Genedy"]
                    }

                    TextField {
                        id: descriptionText

                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.columnSpan: 2

                        placeholderText: "Description"
                    }

                    RoundButton {
                        id: addButton

                        Layout.columnSpan: 2
                        Layout.fillWidth: true
                        Layout.preferredHeight: Constants.sizeHuge.height

                        background: Image {
                            id: addImage
                            source: Constants.iconAdd
                            fillMode: Image.PreserveAspectFit
                            mipmap: true
                        }

                        onClicked: {
                            if (locationName.displayText.trim() !== "") {
                                __locationModel.createLocationRequest(locationName.displayText, buildingCombo.currentValue, floorCombo.currentValue, descriptionText.displayText)
                            }
                        }
                    }
                }
            }
        }
    }
}
