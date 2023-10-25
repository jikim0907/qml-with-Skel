import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.12
import skelpointloader 1.0

Window {
    width: 600
    height: 338
    visible: true
    title: qsTr("Hello World")
    Rectangle{
        id: rec
        width:20
        height:20
//            x:SkelPointLoader.key_px
//            y:SkelPointLoader.key_py
        x:0
        y:0
        visible: true
        color: "black"

        Component.onCompleted: {
            console.log("create REC")
        }

        onXChanged: {
            console.log("CHANGE")
        }
      }

    Connections{
        target: SkelPointLoader
        onSendPosData:{
            rec.x = x
            rec.y = y
            console.log(rec.x)
            console.log(rec.y)

        }
    }
}
