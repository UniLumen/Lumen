import QtQuick
import QtQuick.Layouts
Item {
    ColumnLayout{
        anchors.fill: parent
        RowLayout{
            id: tabBar
            anchors.fill: parent
            LumenLogo {
                width: parent.width / 9
                height: parent.height / 15
                anchors{
                    left:parent.left
                    top : parent.top
                    margins: 20
                }
            }
            EditorTabBar{

            }
        }
    }
}
