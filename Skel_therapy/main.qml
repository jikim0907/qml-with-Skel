import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.12
import skelpointloader 1.0

ApplicationWindow {

    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Item {
        id: view_control
        width: parent.width
        height: parent.height
        Component.onCompleted: {
        console.log("asdasd")
        }
    }

    Connections {
        target: SPK

        onSendPosData:{

            console.log("ddddddddddddddddd");
        }
    }
}

