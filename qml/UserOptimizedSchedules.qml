import QtQuick

Item {
    implicitWidth: Constants.widthDefault
    implicitHeight: Constants.heightDefault

    TitleWithUnderline {
        id: myOptimizedSchedulesTitle
        text: "My Optimized Schedules"
        anchors{
            top: parent.top
            topMargin: 100
            left: parent.left
        }
    }

    Text {
        id: optimizeNewScheduleTitle
        text: "Optimize a New Schedule"
        font {
            family: Constants.fontPoppins
            pixelSize: 45
            weight: Font.ExtraBold
        }
        color: Constants.colorWhitePure
        width: 350
        anchors{
            top: parent.top
            topMargin: 70
            right: parent.right
            rightMargin: 100
        }
        wrapMode: Text.WordWrap
    }
}
