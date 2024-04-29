pragma Singleton

import QtQuick

QtObject {
    readonly property string appName: "Lumen"
    readonly property string poppinsFont: "Poppins"
    readonly property string yellowLandPageColor: "#FCB80A"
    readonly property string whiteLandPageTextColor: "#FFFFFF"
    readonly property string whiteLandPageButtonColor: "#D9D9D9"
    readonly property string manPhotoPath: "qrc:images/land_page_man.svg"
    readonly property string backgroundDarkColor: "#282D32"
    readonly property int editorWindowWidth: Screen.width - 100
    readonly property int editorWindowHeight: Screen.height - 100
    readonly property string yellowLinesImagePath: "qrc:/images/yellow_lines.svg"
    readonly property string lumenLogoPath: "qrc:/images/lumen_logo.svg"
    readonly property int lumenLogoWidth: 226
    readonly property int lumenLogoHeight: 78
}
