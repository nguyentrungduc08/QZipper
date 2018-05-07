import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2
import QtQuick.Controls 1.4
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
                    id : rec1
                    width: parent.width
                    height: 20
                    Rectangle{
                        id: boderFilePath
                        anchors.left: parent.left
                        anchors.top: parent.top
    //                    border.pixelAligned: 1
                        width: parent.width - 100
                        height: 15
                        Text {
                            id: pathText
                            text: qsTr("text")
    //                        anchors.fill: parent
                        }
                    }
                    Button{
                        text: "Choose File"
                        anchors.top: parent.top
                        anchors.left: boderFilePath.right
                        width: 100
                        height: 15
                        onClicked: {
                            fileDialogDecompress.open();
                        }
                    }
                }

                Rectangle {
                    id: rec2
                    anchors.top: rec1.bottom
                    width: parent.width
                    height: 30
                    Button{
                        text: "Extract";
                        width: 100
                        height: 15
                        anchors.centerIn: parent
                        onClicked: {
                            qzipper.slot_Decompression(pathText.text)
                        }
                    }

                }

                FileDialog {
                    id: fileDialogDecompress
                    title: "Please choose a file or folder to compress"
                    folder: shortcuts.home

                    onAccepted: {
                        console.log("You chose: " + fileDialogDecompress.fileUrl);
                        var vpath = fileDialogDecompress.fileUrl.toString();
                        vpath = vpath.replace(/^(file:\/{3})/,"");
                        pathText.text = vpath;
                    }

                    onRejected: {
                        console.log("Canceled")
                    }
                    //Component.onCompleted: visible = false
                }

            }
        }

    }

}
