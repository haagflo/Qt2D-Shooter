import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 500
    height: 500

    Rectangle{
        id: rectangle1
        anchors.fill: parent

        Column {
            id: column1
            x: 150
            y: 50
            width: 174
            height: 142
            transformOrigin: Item.Center
            anchors.verticalCenterOffset: 0
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenterOffset: 0
            spacing: 12
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                id: play
                text: qsTr("Play")
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Button {
                id: highscore
                text: qsTr("Highscore")
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Button {
                id: quit
                text: qsTr("Quit")
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

    }


}

