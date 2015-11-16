import QtQuick 2.0

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
//        fireball.x = x
//        fireball.y = y
//        fireball.rotation = (fireball.rotation == shuttle.rotation ? shuttle.rotation -1: shuttle.rotation)
//        playSound.play()
    }
}


