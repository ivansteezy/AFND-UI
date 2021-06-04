import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import Qt.labs.platform 1.0

Window {
    visible: true
    width: 1000
    height: 800
    title: qsTr("Automata finito no-determinista")

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
                text: "Carge un archivo..."
            }
            ScrollBar.vertical: ScrollBar{}
        }

        Rectangle {
            Layout.rowSpan   : 5
            Layout.columnSpan: 4
            Layout.preferredWidth  : grid.prefWidth(this)
            Layout.preferredHeight : grid.prefHeight(this)

            ColumnLayout {
                anchors.fill: parent
                spacing: 20
                Label {
                    Layout.preferredWidth: parent.width / 2
                    font.pixelSize: 22
                    text: "Ruta del archivo"
                }

                TextInput {
                    Layout.preferredWidth  : parent.width
                    Layout.preferredHeight: 40

                    id: filePath
                    font.pixelSize: 13
                    wrapMode: Text.WordWrap
                    text: "Ruta del archivo..."
                }
                RowLayout {
                    Layout.fillWidth: true
                    Button {
                        Layout.fillWidth: true
                        text: "Buscar archivo"
                        onClicked: {
                            fileDialog.open()
                        }
                    }

                    Button {
                        Layout.fillWidth: true
                        text: "Cargar archivo"
                        onClicked: {
                            afndVw.GetFileTextFromReader()
                        }
                    }
                }
                Item {
                    Layout.fillHeight: true
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
                    id: webCoincidencesLabel
                    text: "Coincidencias de la palabra web: "
                    font.pixelSize: 22
                }

                Label{
                    id: ebayCoincidencesLabel
                    text: "Coincidencias de la palabra e-bay: "
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
                    afndVw.BeginFind()
                    popup.open()
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
        onWebCoincidencesChanged:{
            webCoincidencesLabel.text = "Coincidencias de la palabra web: " + afndVw.webCoincidences
        }
        onEbayCoincidencesChanged:{
            ebayCoincidencesLabel.text = "Coincidencias de la palabra e-bay: " + afndVw.ebayCoincidences
        }
    }

    Popup {
        id: popup
        x: Math.round((parent.width - width) / 2)
        y: Math.round((parent.height - height) / 2)
        width: parent.width / 2.5
        height: 200
        modal: true
        focus: true

        GridLayout {
            anchors.margins: 10
            anchors.fill: parent

            columns: 12
            rows: 12

            Label {
                Layout.columnSpan: 12
                Layout.rowSpan: 2
                font.pixelSize: 22
                text: "Aviso!"
            }

            Label {
                Layout.columnSpan: 12
                Layout.rowSpan: 5
                text: "Se ha terminado la busqueda!"
            }

            DialogButtonBox {
                Layout.columnSpan: 12
                Layout.rowSpan: 4
                Layout.alignment: Qt.AlignRight
                standardButtons: DialogButtonBox.Ok
                onAccepted: {
                    popup.close()
                }
            }
        }
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent | Popup.CloseOnPressOutside
    }
}


