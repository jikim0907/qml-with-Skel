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
               img.visible = true;
               SkelPointLoader.mth_clicked();
            }
        }
    }
    Image{
        id: img
        width:10
        height:10
        x:362
        y:80
        source:"qrc:/data/rt_input_image.jpeg"
        visible: false
    }
    Connections{
        target: SkelPointLoader
        onSendPosData:{
            img.x = x
            img.y = y
        }
    }
}
