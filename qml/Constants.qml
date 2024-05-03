pragma Singleton

import QtQuick

QtObject {
    // Text
    readonly property string appName: "Lumen"
    readonly property string poppinsFont: "Poppins"
    readonly property string editorWelcomeText: "Editor's POV"
    // Colors
    readonly property string darkBackgroundColor: "#282D32"
    readonly property string yellowColor: "#FCB80A"
    readonly property string yellowHoverColor: "#C79004"
    readonly property string whiteColor: "#FFFFFF"
    readonly property string blackColor: "#000000"
    readonly property string whiteLandPageButtonColor: "#D9D9D9"
    // Dimensions
    readonly property int editorWindowWidth: Screen.width - 100
    readonly property int editorWindowHeight: Screen.height - 100
    readonly property int lumenLogoWidth: 200 // Original width divided by 4.5 and approximated
    readonly property int lumenLogoHeight: 69 // Original height divided by 4.5 and approximated
    // Paths/Resources
    readonly property string yellowLinesImagePath: "qrc:/images/yellow_lines.svg"
    readonly property string lumenLogoPath: "qrc:/images/lumen_logo.svg"
    readonly property string homePageIconPath: "qrc:/images/home_icon.svg"
    readonly property string locationIconPath: "qrc:/images/location_icon.svg"
    readonly property string moreInfoIconBlackPath: "qrc:/images/more_info_icon_black.svg"
    readonly property string moreInfoIconYellowPath: "qrc:/images/more_info_icon_yellow.svg"
    readonly property string instructorIconPath: "qrc:/images/instructor_icon.svg"
    readonly property string coursesIconPath: "qrc:/images/course_icon.svg"
    readonly property string scheduleIconPath: "qrc:/images/schedule_icon.svg"
    readonly property string manPhotoPath: "qrc:images/land_page_man.svg"
}
