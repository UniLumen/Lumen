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
}
