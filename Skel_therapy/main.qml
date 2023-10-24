import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.12
import skelpointloader 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Item {
        id: root
        width: parent.width
        height: parent.height
        Rectangle{
            id: rec
            width:20
            height:20
            x:200
            y:200
            visible: true
            color: "black"
            }
        }
    Connections{
        target: SkelPointLoader
        function onSendPosData(x,y){
            rec.x = x
            rec.y = y
            rec.update()
        }
    }
}
