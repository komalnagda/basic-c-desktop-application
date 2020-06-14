import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12

Button {
    id: myButton;
    text: "calculate";
    x: parent.height/3;
    highlighted: true;
    Material.background: Material.color(Material.Pink);

    property string objectName: "500"

    signal someSignalName(string buttonId);

    MouseArea {
        id: clickArea
        anchors.fill: parent
        onClicked:
        {
            console.log("Button clicked")
            someSignalName(parent.objectName);
        }
    }
}
