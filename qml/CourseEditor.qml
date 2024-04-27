import QtQuick
import QtQuick.Layouts


Rectangle{
    id: root
    anchors.fill: parent
    color: Constants.screenBackground
    Item{
        anchors.fill: parent

        GridView{
            id: gView
            width: parent.width*3/5
            height: parent.height*1.5
            cellWidth: gView.width/4
            cellHeight: gView.cellWidth*1.5

            model:5

            delegate: CardTemplate{
                cardTitle: "Lorem eipsum dollor sit amet"
                content1: "this is content 1"
            }

        }
    }
}

