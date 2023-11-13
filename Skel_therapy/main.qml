import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.12
import skelpointloader 1.0
import QtMultimedia 5.12

ApplicationWindow {
    width: 1080
    height: 9200
    visible: true
    title: qsTr("Hello World")
    color:"black"
    property string formattedIdx: ""
    property int i : 0
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

    Timer {
        id: myTimer
        interval: 30 // 1000 milliseconds = 1 second
        running: true
        repeat: true // Set to true if you want the timer to repeat

        onTriggered: {

            var idx = i.toString();
            formattedIdx = "000".substring(idx.length) + idx;
            console.log(formattedIdx)
            i++;
            if(i==300){
                i=0;
                    }
        }
    }
    Image{
        id: headimg
        width:200
        height:200
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: lsimg
        width:200
        height:200
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: rsimg
        width:200
        height:200
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: leimg
        width:200
        height:200
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: reimg
        width:200
        height:200
        source:"qrc:/data/1.JPG"
//        visible: false
    }


    Image{
        id: lwimg
        width:200
        height:200
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: rwimg
        width:200
        height:200
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: lhimg
        width:200
        height:200
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: rhimg
        width:200
        height:200
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: lkimg
        width:200
        height:200
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: rkimg
        width:200
        height:200
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: laimg
        width:200
        height:200
        source:"qrc:/data/1.JPG"
//        visible: false
    }

    Image{
        id: raimg
        width:200
        height:200
        source:"qrc:/data/1.JPG"
//        visible: false
    }

//    Image{
//        id: bulkimg
//        x:headimg.x
//        y:headimg.y + 200
//        z:-1
//        width: lsimg.x-rsimg.x+10
//        height: lhimg.y -lsimg.y+10
//        source:"qrc:/data/1.JPG"
//        source:"file://mnt/hgfs/share/20231107_Therapy_seq/11_Therapy_body_looping/11_Therapy_body_looping_"+formattedIdx+".png"
//        visible: false
//    }



    Connections{
        target: SkelPointLoader

        onHeadPosition:{
            headimg.x = x
            headimg.y = y
            headimg.source = "file://mnt/hgfs/share/20231107_Therapy_seq/11_Therapy_head_looping/11_Therapy_head_looping_"+formattedIdx+".png"
        }
        onLeftShoulderPosition:{
            lsimg.x = x
            lsimg.y = y
            lsimg.rotation = rot
            console.log(rot)
            lsimg.source = "file://mnt/hgfs/share/20231107_Therapy_seq/11_Therapy_shoulder_looping/11_Therapy_shoulder_looping_"+formattedIdx+".png"
        }
        onRightShoulderPosition:{
            rsimg.x = x
            rsimg.y = y
            rsimg.rotation = rot
            console.log(rot)
            rsimg.source = "file://mnt/hgfs/share/20231107_Therapy_seq/11_Therapy_shoulder_looping/11_Therapy_shoulder_looping_"+formattedIdx+".png"
        }
        onLeftElbowPosition:{
            leimg.x = x
            leimg.y = y
            leimg.rotation = rot
            leimg.source = "file://mnt/hgfs/share/20231107_Therapy_seq/11_Therapy_arm_looping/11_Therapy_arm_looping_"+formattedIdx+".png"
        }
        onRightElbowPosition:{
            reimg.x = x
            reimg.y = y
            reimg.rotation = rot
            reimg.source = "file://mnt/hgfs/share/20231107_Therapy_seq/11_Therapy_arm_looping/11_Therapy_arm_looping_"+formattedIdx+".png"
        }
        onLeftWristPosition:{
            lwimg.x = x
            lwimg.y = y
            lwimg.rotation = rot
            lwimg.source = "file://mnt/hgfs/share/20231107_Therapy_seq/11_Therapy_hand_looping/11_Therapy_hand_looping_"+formattedIdx+".png"
        }
        onRightWristPosition:{
            rwimg.x = x
            rwimg.y = y
            rwimg.rotation = rot
            rwimg.source = "file://mnt/hgfs/share/20231107_Therapy_seq/11_Therapy_hand_looping/11_Therapy_hand_looping_"+formattedIdx+".png"
        }
        onLeftHipPosition:{
            lhimg.x = x
            lhimg.y = y
            lhimg.source = "file://mnt/hgfs/share/20231107_Therapy_seq/11_Therapy_arm_looping/11_Therapy_arm_looping_"+formattedIdx+".png"
        }
        onRightHipPosition:{
            rhimg.x = x
            rhimg.y = y
            rhimg.source = "file://mnt/hgfs/share/20231107_Therapy_seq/11_Therapy_arm_looping/11_Therapy_arm_looping_"+formattedIdx+".png"
        }
        onLeftKneePosition:{
            lkimg.x = x
            lkimg.y = y
            lkimg.source = "file://mnt/hgfs/share/20231107_Therapy_seq/11_Therapy_arm_looping/11_Therapy_arm_looping_"+formattedIdx+".png"
        }
        onRightKneePosition:{
            rkimg.x = x
            rkimg.y = y
            rkimg.source = "file://mnt/hgfs/share/20231107_Therapy_seq/11_Therapy_arm_looping/11_Therapy_arm_looping_"+formattedIdx+".png"
        }
        onLeftAnklePosition:{
            laimg.x = x
            laimg.y = y
            laimg.source = "file://mnt/hgfs/share/20231107_Therapy_seq/11_Therapy_arm_looping/11_Therapy_arm_looping_"+formattedIdx+".png"
        }
        onRightAnklePosition:{
            raimg.x = x
            raimg.y = y
            raimg.source = "file://mnt/hgfs/share/20231107_Therapy_seq/11_Therapy_arm_looping/11_Therapy_arm_looping_"+formattedIdx+".png"
        }
    }
}
