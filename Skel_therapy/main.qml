import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Window 2.12
import skelpointloader 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Item {
        id: view_control
        width: parent.width
        height: parent.height
    }

    Connections {
        target: SkelPointLoader
        onSend_pos_data: {
//            skel_control_img.x = x;
//            skel_control_img.y = y;
//            idx = i;
            console.log("signal?")
        }
    }
}
