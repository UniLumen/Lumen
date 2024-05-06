import QtQuick
import QtQuick.Layouts

Item {
    RowLayout {
        anchors {
            fill: parent
            margins: 24
        }

        LumenLogo {
            Layout.fillHeight: true
            Layout.maximumWidth: (sourceSize.width/sourceSize.height) * height
        }
    }
}
