import QtQuick
import QtQuick.Controls
import Lumen

ApplicationWindow {
    width: 800
    height: 600
    visible: true
    title: Constants.appName
    color: Constants.screenBackground


    Item{
        width:0.5*parent.width
        height: 0.5*parent.height
        anchors.centerIn: parent

        CourseEditor{
        }
    }



}
