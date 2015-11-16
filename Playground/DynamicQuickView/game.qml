import QtQuick 2.0

Item {
    visible: true
    width: 800
    height: 600

    Image {
        id: image1
        fillMode: Image.Stretch
        anchors.fill: parent
        source: "background.png"
    }

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

}

