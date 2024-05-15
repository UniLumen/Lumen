import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    implicitWidth: Constants.widthDefault
    implicitHeight: Constants.heightDefault

    Text {
        id: myOptimizedSchedulesTitle
        text: "My Optimized Schedules"
        anchors{
            top: parent.top
            topMargin: 100
            left: parent.left
        }
        font {
            family: Constants.fontPoppins
            pixelSize: 45
            weight: Font.ExtraBold
        }
        color: Constants.colorWhitePure
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

    OptimizeNewScheduleCard {id : optimizeNewScheduleCard}

    GridView {
        anchors {
            top: myOptimizedSchedulesTitle.bottom
            topMargin: 40
            left: myOptimizedSchedulesTitle.left
            bottom: parent.bottom
            right: optimizeNewScheduleCard.left
            rightMargin: 100
        }

        cellWidth: 280
        cellHeight: 380

        clip: true

        model: __optimizedSchedulesModel
        delegate: OptimizedScheduleCard {
            id: optimizedScheduleCard
            _title: "Schedule " + (model.index + 1)
            _selectedGroupText: "Selected Group: " + model.selectedGroup
            _selectedSectionText: "Selected Section: " + model.selectedSection
            _daysToAttendText: "Days to attend: " + model.numberOfDaysToAttend
            _attendsInSaturday: model.saturdayAttendance
            _attendsInSunday: model.sundayAttendance
            _attendsInMonday: model.mondayAttendance
            _attendsInTuesday: model.tuesdayAttendance
            _attendsInWednesday: model.wednesdayAttendance
            _attendsInThursday: model.thursdayAttendance

            onDeleteInvoked: {
                __optimizedSchedulesModel.removeOptimizedSchedule(model.index)
            }
        }
    }
}
