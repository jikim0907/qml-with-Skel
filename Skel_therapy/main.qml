import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.12
import skelpointloader 1.0
import QtMultimedia 5.12

ApplicationWindow {
    width: 600
    height: 338
    visible: true
    title: qsTr("Hello World")
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

            Component.onCompleted: {
//               headimg.visible = true;
               SkelPointLoader.mth_clicked();
            }
        }
    }

    Image{
        id: headimg
        width:10
        height:10
        x:0
        y:0
        source:"qrc:/data/rt_input_image.jpeg"
//        visible: false
    }

    Image{
        id: lsimg
        width:10
        height:10
        x:0
        y:0
        source:"qrc:/data/rt_input_image.jpeg"
//        visible: false
    }

    Image{
        id: rsimg
        width:10
        height:10
        x:0
        y:0
        source:"qrc:/data/rt_input_image.jpeg"
//        visible: false
    }

    Image{
        id: leimg
        width:10
        height:10
        x:0
        y:0
        source:"qrc:/data/rt_input_image.jpeg"
//        visible: false
    }

    Image{
        id: reimg
        width:10
        height:10
        x:0
        y:0
        source:"qrc:/data/rt_input_image.jpeg"
//        visible: false
    }


    Image{
        id: lwimg
        width:10
        height:10
        x:0
        y:0
        source:"qrc:/data/rt_input_image.jpeg"
//        visible: false
    }

    Image{
        id: rwimg
        width:10
        height:10
        x:0
        y:0
        source:"qrc:/data/rt_input_image.jpeg"
//        visible: false
    }

    Image{
        id: lhimg
        width:10
        height:10
        x:0
        y:0
        source:"qrc:/data/rt_input_image.jpeg"
//        visible: false
    }

    Image{
        id: rhimg
        width:10
        height:10
        x:0
        y:0
        source:"qrc:/data/rt_input_image.jpeg"
//        visible: false
    }

    Image{
        id: lkimg
        width:10
        height:10
        x:0
        y:0
        source:"qrc:/data/rt_input_image.jpeg"
//        visible: false
    }

    Image{
        id: rkimg
        width:10
        height:10
        x:0
        y:0
        source:"qrc:/data/rt_input_image.jpeg"
//        visible: false
    }

    Image{
        id: laimg
        width:10
        height:10
        x:0
        y:0
        source:"qrc:/data/rt_input_image.jpeg"
//        visible: false
    }

    Image{
        id: raimg
        width:10
        height:10
        x:0
        y:0
        source:"qrc:/data/rt_input_image.jpeg"
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
        }
        onRightShoulderPosition:{
            reimg.x = x
            reimg.y = y
        }
        onLeftElbowPosition:{
            leimg.x = x
            leimg.y = y
        }
        onRightElbowPosition:{
            reimg.x = x
            reimg.y = y
        }
        onLeftWristPosition:{
            lwimg.x = x
            lwimg.y = y
        }
        onRightWristPosition:{
            rwimg.x = x
            rwimg.y = y
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
