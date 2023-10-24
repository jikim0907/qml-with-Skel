import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.12
import skelpointloader 1.0

Window {
    width: 300
    height: 280
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
            x:SkelPointLoader.key_px
            y:SkelPointLoader.key_py
            visible: true
            color: "black"

            Component.onCompleted: {
                console.log("create REC")
            }
            onXChanged: {
                           console.log("rec.x changed to", x);
                       }
          }
        }
//    Connections{
//        target: SkelPointLoader
//        function onSendPosData(x,y){
//            rec.x = x
//            rec.y = y
//            console.log(rec.x)
//            console.log(rec.y)

//        }
//    }
}
