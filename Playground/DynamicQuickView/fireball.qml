import QtQuick 2.0

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
