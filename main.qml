import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Dialogs 1.1

ApplicationWindow {
    minimumHeight: 250
    minimumWidth: 300
    maximumHeight: 250
    maximumWidth: 300
    title: "c++ logics"
    visible: true

    Material.theme: Material.Dark
    Material.accent: Material.color(Material.Pink)

    property int currentIndex: 1

    Column {

            anchors.centerIn: parent
            spacing: 1
            topPadding: 10
            RadioButton {
                text: qsTr("Prime Number");
                onClicked:{
                    currentIndex = 0
                }
            }
            RadioButton {
                text: qsTr("Perfect Number");
                checked: true;
                onClicked:{
                     currentIndex = 1
                }
            }
            RadioButton {
                text: qsTr("Factorial")
                onClicked:{
                     currentIndex = 2
                }
            }
            TextField {
                id: textField1
                width: 250;
                leftPadding: 12;
                font.pointSize: 8;
                font.weight: Font.Medium;
                font.italic: false;
                font.underline: false;
                horizontalAlignment: Text.AlignLeft;
                transformOrigin: Item.Center;
                placeholderText: qsTr("Enter a number")
            }
//            Button {
//                x: parent.height/3;
//                text: qsTr("calculate");
//                flat: false;
//                highlighted: true;
//                onClicked: messageDialog.visible = true;
//                Material.background: Material.color(Material.Pink);
//            }
            CustomButton {
                id: btn
                onSomeSignalName: {
                    console.log("Clicked received from CustomButton.qml, calling slot in C++")
                    console.log("Received btnid: " + buttonId)
                    myButtonHandler.someSlot(textField1.text, currentIndex)
                }
            }

            Connections {
                target: myButtonHandler
                onSomeSignal: {
                    console.log("Received signal from my class with string: " + str)
                    messageDialog.text = str
                    messageDialog.visible = true
                }
            }
    }

    MessageDialog {
        id: messageDialog
        title: "Result"
        text: ""
//        onAccepted: {
//            console.log("And of course you could only agree.")
//            Qt.quit()
//        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
