import QtQuick
import QtQuick.Controls

LumenRectangle {

    property alias _title: cardTitle.text
    property alias _selectedGroupText: selectedGroupText.text
    property alias _selectedSectionText: selectedSectionText.text
    property alias _daysToAttendText: daysToAttendText.text
    property bool _attendsInSaturday;
    property bool _attendsInSunday;
    property bool _attendsInMonday;
    property bool _attendsInTuesday;
    property bool _attendsInWednesday;
    property bool _attendsInThursday;

    signal deleteInvoked

    implicitWidth: 250
    implicitHeight: 350

    Image {
        id: scheduleIcon
        source: Constants.iconScheduleWhite
        anchors {
            left: parent.left
            top: parent.top
            margins: 20
        }
        sourceSize: Constants.sizeLarge
        fillMode: Image.PreserveAspectFit
    }

    Button {
        anchors {
            top: parent.top
            right: parent.right
            margins: 10
        }

        contentItem: Image {
            source: Constants.iconRemove
            fillMode: Image.PreserveAspectFit
        }

        background: null
        onClicked: deleteInvoked()
    }

    Text {
        id: cardTitle
        font {
            family: Constants.fontPoppins
            pixelSize: 35
            weight: Font.DemiBold
        }
        color: Constants.colorBlackPure

        anchors{
            top: scheduleIcon.bottom
            topMargin: 10
            left: scheduleIcon.left
        }
    }

    Row {
        id: daysRow
        spacing: 2

        anchors {
            top: cardTitle.bottom
            topMargin: 8
            left: scheduleIcon.left
        }

        OptimizedScheduleDayRectangle {
            dayName: "SAT"
            color: _attendsInSaturday ? Constants.colorYellowMain : Constants.colorGrayLight
        }

        OptimizedScheduleDayRectangle {
            dayName: "SUN"
            color: _attendsInSunday ? Constants.colorYellowMain : Constants.colorGrayLight
        }

        OptimizedScheduleDayRectangle {
            dayName: "MON"
            color: _attendsInMonday ? Constants.colorYellowMain : Constants.colorGrayLight
        }

        OptimizedScheduleDayRectangle {
            dayName: "TUE"
            color: _attendsInTuesday ? Constants.colorYellowMain : Constants.colorGrayLight
        }

        OptimizedScheduleDayRectangle {
            dayName: "WED"
            color: _attendsInWednesday ? Constants.colorYellowMain : Constants.colorGrayLight
        }

        OptimizedScheduleDayRectangle {
            dayName: "THU"
            color: _attendsInThursday ? Constants.colorYellowMain : Constants.colorGrayLight
        }
    }

    Text {
        id: selectedGroupText
        font {
            family: Constants.fontPoppins
            pixelSize: 20
        }
        color: Constants.colorBlackPure

        anchors{
            top: daysRow.bottom
            topMargin: 30
            left: scheduleIcon.left
        }
    }

    Text {
        id: selectedSectionText
        font {
            family: Constants.fontPoppins
            pixelSize: 20
        }
        color: Constants.colorBlackPure

        anchors{
            top: selectedGroupText.bottom
            topMargin: 10
            left: scheduleIcon.left
        }
    }

    Text {
        id: daysToAttendText
        font {
            family: Constants.fontPoppins
            pixelSize: 20
        }
        color: Constants.colorBlackPure

        anchors{
            top: selectedSectionText.bottom
            topMargin: 10
            left: scheduleIcon.left
        }
    }

    Button {
        text: "view full schedule"

        hoverEnabled: true

        background: Rectangle {
            color: "transparent"
        }

        icon {
            source: Constants.iconMaximize
            color: hovered ? Constants.colorYellowMain : Constants.colorBlackPure
        }

        anchors {
            bottom: parent.bottom
            bottomMargin: 20
            left: scheduleIcon.left
        }

        PointingHandCursor {}
    }
}
