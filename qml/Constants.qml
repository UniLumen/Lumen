pragma Singleton

import QtQuick

QtObject {
    readonly property string appName: "Lumen"
    readonly property string poppinsFont: "Poppins"
    readonly property string backgroundDarkColor: "#282D32"
    readonly property string yellowLandPageColor: "#FCB80A"
    readonly property string whiteLandPageTextColor: "#FFFFFF"
    readonly property string whiteLandPageButtonColor: "#D9D9D9"
    readonly property int editorWindowWidth: Screen.width - 100
    readonly property int editorWindowHeight: Screen.height - 100
    readonly property string yellowLinesImagePath: "qrc:images/lines.svg"
    readonly property string lumenLogoPath: "qrc:images/logo.svg"
    readonly property string manPhotoPath:  "qrc:images/man.svg"

    // Text
    readonly property string mainFont: "Poppins"
    readonly property string dashboardTabText: " Dashboard"
    readonly property string locationsTabText: " Locations"
    readonly property string instructorsTabtext: " Doctors/TAs"
    readonly property string coursesTabText: " Courses"
    readonly property string schedulesTabText: " Schedules"
    // Colors
    readonly property string darkBackgroundColor: "#282D32"
    readonly property string yellowColor: "#FCB80A"
    readonly property string yellowHoverColor: "#C79004"
    readonly property string whiteColor: "#FFFFFF"
    readonly property string blackColor: "#000000"
    // Dimensions
    readonly property int lumenLogoWidth: 188 // Original width divided by 4.8 and approximated
    readonly property int lumenLogoHeight: 65 // Original height divided by 4.8 and approximated
    // Paths/Resources
    readonly property string homePageIconPath: "qrc:/images/home_icon.svg"
    readonly property string locationIconPath: "qrc:/images/location_icon.svg"
    readonly property string moreInfoIconBlackPath: "qrc:/images/more_info_icon_black.svg"
    readonly property string moreInfoIconYellowPath: "qrc:/images/more_info_icon_yellow.svg"
    readonly property string instructorIconPath: "qrc:/images/instructor_icon.svg"
    readonly property string coursesIconPath: "qrc:/images/course_icon.svg"
    readonly property string scheduleIconPath: "qrc:/images/schedule_icon.svg"
    readonly property string addButtonPath: "qrc:/images/addButton.svg"
    readonly property string removeButtonPath: "qrc:/images/removeButton.png"
}
