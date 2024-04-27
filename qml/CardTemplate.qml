import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQml



Rectangle{
    id: template
    property string cardTitle
    property url iconPath
    // to set up the content is from the gridView
    // note1: the content should be used in order so that no gaps appear in the cards
    // (ie dont set content 3 before setting content 2)
    // note2: the strings still take space even if they were not set and are invisible
    property string content1
    property string content2
    property string content3
    readonly property GridView __view: GridView.view

    color: "blue"
    width: __view.cellWidth
    height: __view.cellHeight

    Item{
        anchors{
            fill: parent
            topMargin: 0.05*parent.height
            bottomMargin: 0.05*parent.height
            leftMargin: 0.05*parent.width
            rightMargin: 0.05*parent.width
        }


        RoundButton{
            id: removeButton
            background: Rectangle{
                radius: 360
                color: Constants.cancelRed
            }
            width: parent.width/5
            height: removeButton.width

            anchors{
                right: parent.right
                top: parent.top
            }
        }

        Rectangle{
            id: cardIcon
            width: parent.width/5
            height: removeButton.width
            color: "red"

            anchors{
                left: parent.left
                top: parent.top
            }
        }

        Text{
            id: mainText
            width: parent.width
            anchors{
                top: cardIcon.bottom
                left: parent.left
                topMargin: 0.1*parent.height
            }
            font.pointSize: 0.1*parent.width
            font.weight: Font.ExtraBold
            font.capitalization: Font.Capitalize
            wrapMode: Text.Wrap
            text: cardTitle
        }

        ColumnLayout{
            id: contentCol
            anchors{
                top: mainText.bottom
                bottom: parent.bottom
            }
            width:parent.width


            Text {
                id: contentTxt1
                text: content1
                Layout.alignment: Qt.AlignVCenter
                font.pointSize: 0.06*parent.width
                wrapMode: Text.Wrap
                Layout.maximumWidth: parent.width
            }

            Text {
                id: contentTxt2
                text: content2
                Layout.alignment: Qt.AlignVCenter
                font.pointSize: 0.06*parent.width
                wrapMode: Text.Wrap
                Layout.maximumWidth: parent.width
            }

            Text {
                id: contentTxt3
                text: content3
                Layout.alignment: Qt.AlignVCenter
                font.pointSize: 0.06*parent.width
                wrapMode: Text.Wrap
                Layout.maximumWidth: parent.width
            }
        }
    }
}
