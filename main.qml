import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.0

import QZipper 1.0



Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QZipper")

    QZipper {
        id: qzipper
    }

    TabView {
        id: tabView
        width: parent.width
        height: parent.height

        ListModel{
            id: listPath
//            ListElement { path: "/home/Desktop/code" }
//            ListElement { path: "/home/Desktop/code" }
//            ListElement { path: "/home/Desktop/code" }
//            ListElement { path: "/home/Desktop/code" }
        }



        Tab {
            title: "Compress"
            Rectangle {
                width: parent.width
                height: parent.height
                ListView{
                        id: listViewPatch
                        model: listPath

                        width: parent.width
                        height: parent.height * 2 / 3

                        delegate: Text {
                            text: path
                        }
                }
                Button {
                        id: buttonChooseFile
                        text: "Choose files or folders"
                        anchors.top: listViewPatch.bottom

                        onClicked: {
                            fileDialog.open()
                        }

                }

                Button {
                        id: buttonCompess
                        text: "Compress"
                        anchors.top: listViewPatch.bottom
                        anchors.left: buttonChooseFile.right


                        onClicked: {
                            fileDialog.open()
                        }

                }

                FileDialog {
                    id: fileDialog
                    title: "Please choose a file or folder to compress"
                    folder: shortcuts.home

                    selectFolder: true
                    selectMultiple: true

                    onAccepted: {
                        console.log("You chose: " + fileDialog.fileUrl);
                        var vpath = fileDialog.fileUrl.toString();
                        vpath = vpath.replace(/^(file:\/{3})/,"");
                        listPath.append({path:  vpath});

                    }
                    onRejected: {
                        console.log("Canceled")
                    }
                    //Component.onCompleted: visible = false
                }

            }
        }
        Tab {
            title: "decompress"
            Rectangle {
                Rectangle{
                    id: boderFilePath
                    anchors.left: parent.left
                    anchors.top: parent.top
//                    border.pixelAligned: 1
                    width: parent - 30
                    height: 15
                    TextArea {
                        id: pathText
                        text: qsTr("text")
                        anchors.fill: parent
                    }
                }
                Button{
                    text: "Choose File"
                    anchors.top: parent.top
                    anchors.left: boderFilePath.right
                    width: 30
                    height: 15
                }
            }
        }

    }

}
