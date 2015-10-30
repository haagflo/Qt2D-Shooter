import QtQuick 2.3
import QtQuick.Window 2.2
import QtMultimedia 5.0

Window {
    visible: true
    width: 800
    height: 600

    Text {
        color: "white"
        text: qsTr("Player 1")
        z: 1
        font.bold: true
        font.pointSize: 15
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.margins: 10
    }

    SoundEffect {
           id: playSound
           source: "ir_begin.wav"
    }

    Image {
        id: image1
        fillMode: Image.Stretch
        anchors.fill: parent
        source: "background.png"


        Image {
            id: shuttle
            x: 319
            y: 132
            width: 100
            height: 100
            clip: false
            focus: true
            source: "shuttle.png"
            Keys.onLeftPressed: rotation = (rotation - 10) % 360
            Keys.onRightPressed: rotation = (rotation + 10) % 360
            Keys.onUpPressed: {
                x = x + Math.sin(rotation * Math.PI/180) * 10
                y = y - Math.cos(rotation * Math.PI/180) * 10
            }
            Keys.onDownPressed:{
                x = x - Math.sin(rotation * Math.PI/180) * 10
                y = y + Math.cos(rotation * Math.PI/180) * 10
            }
            Keys.onSpacePressed:{
                fireball.x = x
                fireball.y = y
                fireball.rotation = (fireball.rotation == shuttle.rotation ? shuttle.rotation -1: shuttle.rotation)
                playSound.play()
            }
        }

        Image{
            id: fireball
            width: 50
            height: 50
            x: -100
            y: -100
            source: "fireball.png"

            Behavior on rotation{
                ParallelAnimation{

                    NumberAnimation{
                        target: fireball; properties: "x"
                        from: fireball.x; to: fireball.x + Math.sin(fireball.rotation * Math.PI/180) * 1000
                        duration: 2000
                    }
                    NumberAnimation{
                        target: fireball; properties: "y"
                        from: fireball.y; to: fireball.y - Math.cos(fireball.rotation * Math.PI/180) * 1000
                        duration: 2000
                    }
                }
            }
        }

    }
}



