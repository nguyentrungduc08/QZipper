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
                Rectangle {
                    id: recCom1
                    width: parent.width
                    height: 50
                    anchors.top: listViewPatch.bottom

                    Button {
                        id: buttonSetArchiveFileName
                        text: "Archive name:"
                        width: parent.width / 4
                        onClicked: {
                            fileDialogSaveArchiveFile.open()
                        }
                    }

                    TextField{
                        id: fileArchiveName
                        width: parent.width
                        anchors.top: buttonSetArchiveFileName.bottom
                        text: "path to save"
                    }

                    FileDialog {
                        id: fileDialogSaveArchiveFile
                        title: "Please choose a folder save file archivesss"
                        folder: shortcuts.home

                        selectFolder: true

                        onAccepted: {
                            console.log("You chose: " + fileDialogSaveArchiveFile.fileUrl);
                            var vpath = fileDialogSaveArchiveFile.fileUrl.toString();
                            vpath = vpath.replace(/^(file:\/{3})/,"");
                            fileArchiveName.text = vpath;

                        }
                        onRejected: {
                            console.log("Canceled")
                        }

                    }

                }



                Button {
                        id: buttonChooseFile
                        text: "Choose files or folders"
                        anchors.top: recCom1.bottom

                        onClicked: {
                            fileDialog.open()
                        }
                }

                Button {
                        id: buttonCompess
                        text: "Compress"
                        anchors.top: recCom1.bottom
                        anchors.left: buttonChooseFile.right


                        onClicked: {
                            qzipper.slot_Compression(listPath.get(0).path, fileArchiveName.text)
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
                            text: qsTr("patch file to extract")
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


                Rectangle{
                    id : rec2
                    anchors.top: rec1.bottom
                    width: parent.width
                    height: 20
                    Rectangle{
                        id: boderFilePathToExtract
                        anchors.left: parent.left
                        anchors.top: parent.top
    //                    border.pixelAligned: 1
                        width: parent.width - 100
                        height: 15
                        Text {
                            id: pathTextToExtract
                            text: qsTr("extract file to")
    //                        anchors.fill: parent
                        }
                    }
                    Button{
                        text: "Choose File"
                        anchors.top: parent.top
                        anchors.left: boderFilePathToExtract.right
                        width: 100
                        height: 15
                        onClicked: {
                            fileDialogFolderToExtract.open();
                        }
                    }
                }

                Rectangle {
                    id: rec3
                    anchors.top: rec2.bottom
                    width: parent.width
                    height: 30
                    Button{
                        text: "Extract";
                        width: 100
                        height: 15
                        anchors.centerIn: parent
                        onClicked: {
                            qzipper.slot_Decompression(pathText.text, pathTextToExtract.text)
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

                }

                FileDialog {
                    id: fileDialogFolderToExtract
                    title: "Please choose a file or folder to compress"
                    folder: shortcuts.home
                    selectFolder: true

                    onAccepted: {
                        console.log("You chose: " + fileDialogFolderToExtract.fileUrl);
                        var vpath = fileDialogFolderToExtract.fileUrl.toString();
                        vpath = vpath.replace(/^(file:\/{3})/,"");
                        pathTextToExtract.text = vpath;
                    }

                    onRejected: {
                        console.log("Canceled")
                    }

                }

            }
        }

    }

}
