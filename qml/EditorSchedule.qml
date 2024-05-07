import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
Item {
    anchors.fill: parent
    ColumnLayout{
        width: parent.width
        spacing: 35
        Layout.margins: 20
        RowLayout{
            id: ediotrTabBar
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 35
            Layout.margins: 20
            LumenLogo {

            }
            EditorTabBar{

            }
        }
        RowLayout{
            id: tabButtons
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 35
            Layout.margins: 20
            TextLandPage {
                Layout.leftMargin: 40
                text: "Schedules Directory"
                font.pointSize: 30
                font.bold: true
            }
            RoundButton{
                id: addButton
                background: Image{
                    id: addImage
                    source: Constants.addButtonPath
                }
                Layout.preferredWidth: parent.width*0.15
                Layout.preferredHeight: addButton.width
                radius: addButton.width/2
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                onClicked:{

                    tabbar.addItem(tabButton.createObject(tabbar))
                    var object = newPage.createObject(layout)
                    console.log(tabbar.currentIndex)
                }
            }
        }
        SchedulesTabs{
            id: tabbar
        }
        Component {
            id: tabButton
            ScheduleTabButton { text: "TabButton" }
        }
        Component {
            id: newPage
            ScheduleTabButton {
                text: "Page"
                background: Rectangle{
                    color: Qt.rgba(Math.random(),Math.random(),Math.random(),1);
                }
                Layout.preferredHeight: 300
                Layout.fillWidth: true
            }
        }
        StackLayout{
            id: layout
            Layout.fillWidth: true
            height: 500
            currentIndex: tabbar.currentIndex
        }
    }
}
