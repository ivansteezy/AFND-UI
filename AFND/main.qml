import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import Qt.labs.platform 1.0

Window {
    visible: true
    width: 1000
    height: 800
    title: qsTr("AFND")

    GridLayout {
        anchors.margins: 10
        id : grid
        anchors.fill: parent
        rows    : 12
        columns : 12

        property double colMulti : grid.width / grid.columns
        property double rowMulti : grid.height / grid.rows

        function prefWidth(item){
            return colMulti * item.Layout.columnSpan
        }
        function prefHeight(item){
            return rowMulti * item.Layout.rowSpan
        }


        Flickable {
            Layout.rowSpan   : 10
            Layout.columnSpan: 8
            Layout.preferredWidth  : grid.prefWidth(this)
            Layout.preferredHeight : grid.prefHeight(this)

            TextArea.flickable: TextArea {
                id: fileContent
                font.pixelSize: 18
                wrapMode: Text.WordWrap
                text: "Hola"
            }
            ScrollBar.vertical: ScrollBar{}
        }

        Rectangle {
            Layout.rowSpan   : 5
            Layout.columnSpan: 4
            Layout.preferredWidth  : grid.prefWidth(this)
            Layout.preferredHeight : grid.prefHeight(this)

            GridLayout {
                columns: 2
                rows: 3
                anchors.fill: parent

                Label {
                    Layout.columnSpan: 2
                    Layout.rowSpan: 1
                    font.pixelSize: 22
                    text: "Ruta del archivo"
                }

                TextInput {
                    id: filePath
                    Layout.columnSpan: 2
                    Layout.rowSpan: 1
                    width: 190
                }

                Button {
                    Layout.columnSpan: 1
                    Layout.rowSpan: 1
                    Layout.fillWidth: true
                    text: "Abrir"
                    onClicked: {
                        fileDialog.open()
                    }
                }

                Button {
                    Layout.columnSpan: 1
                    Layout.rowSpan: 1
                    Layout.fillWidth: true

                    text: "Cargar"
                    onClicked: {
                        afndVw.GetFileTextFromReader()
                    }
                }
            }
        }

        Image {
            Layout.rowSpan   : 5
            Layout.columnSpan: 4
            Layout.preferredWidth  : grid.prefWidth(this)
            Layout.preferredHeight : grid.prefHeight(this)

            source: "/media/images/afnd.png"
        }

        Rectangle {
            Layout.rowSpan : 2
            Layout.columnSpan : 8
            Layout.preferredWidth  : grid.prefWidth(this)
            Layout.preferredHeight : grid.prefHeight(this)
            ColumnLayout {
                height: parent.height
                width: parent.width
                anchors.verticalCenter: parent.verticalCenter
                Label{
                    text: "Coincidencias de la palabra web"
                    font.pixelSize: 22
                }

                Label{
                    text: "Coincidencias de la palabra e-bay"
                    font.pixelSize: 22
                }
            }
        }

        Rectangle {
            id: blueRect
            Layout.rowSpan: 2
            Layout.columnSpan: 4
            Layout.preferredWidth  : grid.prefWidth(this)
            Layout.preferredHeight : grid.prefHeight(this)

            Button {
                width: parent.width / 2
                height: parent.width / 6

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                text: "Buscar"

                onClicked: {

                }
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.currentFile)
            afndVw.filePathString = fileDialog.currentFile
        }
        onRejected: {
            console.log("Canceled")
        }
    }

    Connections {
        target: afndVw
        onFileAsStringChanged:{
           fileContent.text = afndVw.fileAsString
        }
        onFilePathStringChanged:{
           filePath.text = afndVw.filePathString
        }
    }
}


