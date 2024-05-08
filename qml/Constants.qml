pragma Singleton

import QtQuick

QtObject {
    // Text
    readonly property string appName: "Lumen"

    readonly property string fontPoppins: "Poppins"
    readonly property string textEditorPageTitle: "Editor's POV"
    readonly property string textDashboardTab: " Dashboard"
    readonly property string textLocationsTab: " Locations"
    readonly property string textInstructorsTab: " Doctors/TAs"
    readonly property string textCoursesTab: " Courses"
    readonly property string textSchedulesTab: " Schedules"
    // Colors
    readonly property string colorBackground: "#282D32"
    readonly property string colorYellowMain: "#FCB80A"
    readonly property string colorYellowEditorPageHover: "#C79004"
    readonly property string colorWhitePure: "#FFFFFF"
    readonly property string colorBlackPure: "#000000"
    readonly property string colorWhiteLandPageButton: "#D9D9D9"
    readonly property color colorRed: "#9C2321"
    // Dimensions
    readonly property int widthDefault: Screen.width - 100
    readonly property int heightDefault: Screen.height - 100
    // Assets
    readonly property string imageYellowLines: "qrc:/images/yellow_lines.svg"
    readonly property string imageLumenLogo: "qrc:/images/lumen_logo.svg"
    readonly property string imageLandPageMan: "qrc:/images/land_page_man.svg"
    readonly property string iconHome: "qrc:/images/home_icon.svg"
    readonly property string iconLocation: "qrc:/images/location_icon.svg"
    readonly property string iconInfoBlack: "qrc:/images/more_info_icon_black.svg"
    readonly property string iconInfoYellow: "qrc:/images/more_info_icon_yellow.svg"
    readonly property string iconInstructor: "qrc:/images/instructor_icon.svg"
    readonly property string iconCourse: "qrc:/images/course_icon.svg"
    readonly property string iconSchedule: "qrc:/images/schedule_icon.svg"
    readonly property url iconKpi: "qrc:/images/icon_kpi.svg"
    readonly property url iconEdit: "qrc:/images/icon_edit.svg"
    readonly property url iconRemove: "qrc:/images/icon_remove.svg"

    readonly property int sizeHeader1: 32
    readonly property int sizeHeader2: 24
    readonly property int sizeHeader3: 18
    readonly property int sizeHeader4: 16
    readonly property int sizeHeader5: 14
    readonly property int sizeHeader6: 10

    readonly property int sizePrimaryText: 16
    readonly property int sizeSecondaryText: 14

    readonly property size sizeHuge: Qt.size(64, 64)
    readonly property size sizeLarge: Qt.size(32, 32)
    readonly property size sizeNormal: Qt.size(24, 24)
    readonly property size sizeSmall: Qt.size(16, 16)
}
