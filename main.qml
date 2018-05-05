import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

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
            ListElement { path: "/home/hydra/Desktop/code" }
            ListElement { path: "/home/hydra/Desktop/code" }
            ListElement { path: "/home/hydra/Desktop/code" }
            ListElement { path: "/home/hydra/Desktop/code" }
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
                        text: qsTr(path)
                    }

                Button {
                    text: "Choose files or folders"
                    anchors.top: listViewPatch.bottom
                    anchors.centerIn: parent
                    }
                }
            }
        }
        Tab {
            title: "decompress"
            Rectangle {

            }
        }

    }

}
