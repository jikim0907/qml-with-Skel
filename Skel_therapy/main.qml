import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.12
import skelpointloader 1.0
import QtMultimedia 5.12

ApplicationWindow {
    width: 1080
    height: 960
    visible: true
    title: qsTr("Hello World")
    color:"black"
    Item {
       id: mediaplay_contorl
       anchors.fill: parent
       MediaPlayer {
           id: mediaPlayer
           source: "qrc:/data/ani.mp4"
           autoPlay: true // 자동 재생 설정

           onStatusChanged: {
               if (status === MediaPlayer.EndOfMedia) {
                   mediaPlayer.stop(); // 동영상 재생 중지
                   mediaPlayer.play(); // 다시 재생
                }
            }
        }
        VideoOutput {
            id: videoOutput
            anchors.fill: parent
            source: mediaPlayer
            fillMode: VideoOutput.Stretch
            visible: false

            Component.onCompleted: {
               SkelPointLoader.mth_clicked();
            }
        }
    }

    Image{
        id: headimg
        width:70
        height:60
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: lsimg
        width:70
        height:60
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: rsimg
        width:70
        height:60
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: leimg
        width:70
        height:60
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: reimg
        width:70
        height:60
        source:"qrc:/data/1.JPG"
//        visible: false
    }


    Image{
        id: lwimg
        width:70
        height:60
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: rwimg
        width:70
        height:60
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: lhimg
        width:70
        height:60
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: rhimg
        width:70
        height:60
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: lkimg
        width:70
        height:60
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: rkimg
        width:70
        height:60
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: laimg
        width:70
        height:60
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: raimg
        width:70
        height:60
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: bulkimg
        x:headimg.x
        y:headimg.y + 60
        z:-1
        width: lsimg.x-rsimg.x+10
        height: lhimg.y -lsimg.y+10
        source:"qrc:/data/1.JPG"
//        visible: false
    }


    Connections{
        target: SkelPointLoader
        onHeadPosition:{
            headimg.x = x
            headimg.y = y
        }
        onLeftShoulderPosition:{
            lsimg.x = x
            lsimg.y = y
            lsimg.rotation = rot
        }
        onRightShoulderPosition:{
            rsimg.x = x
            rsimg.y = y
            rsimg.rotation = rot
        }
        onLeftElbowPosition:{
            leimg.x = x
            leimg.y = y
            leimg.rotation = rot
        }
        onRightElbowPosition:{
            reimg.x = x
            reimg.y = y
            reimg.rotation = rot
        }
        onLeftWristPosition:{
            lwimg.x = x
            lwimg.y = y
            lwimg.rotation = rot
        }
        onRightWristPosition:{
            rwimg.x = x
            rwimg.y = y
            rwimg.rotation = rot
        }
        onLeftHipPosition:{
            lhimg.x = x
            lhimg.y = y
        }
        onRightHipPosition:{
            rhimg.x = x
            rhimg.y = y
        }
        onLeftKneePosition:{
            lkimg.x = x
            lkimg.y = y
        }
        onRightKneePosition:{
            rkimg.x = x
            rkimg.y = y
        }
        onLeftAnklePosition:{
            laimg.x = x
            laimg.y = y
        }
        onRightAnklePosition:{
            raimg.x = x
            raimg.y = y
        }
    }
}
