import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 800
    height: 600
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

        TextArea {
            color: 'red'
            Layout.rowSpan   : 10
            Layout.columnSpan: 8
            Layout.preferredWidth  : grid.prefWidth(this)
            Layout.preferredHeight : grid.prefHeight(this)
            font.pixelSize: 18
        }

        Rectangle {
            color : 'pink'
            Layout.rowSpan   : 5
            Layout.columnSpan: 4
            Layout.preferredWidth  : grid.prefWidth(this)
            Layout.preferredHeight : grid.prefHeight(this)
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
                    text: "Hola mundl"
                    font.pixelSize: 22
                }

                Label{
                    text: "Hola mundl"
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
                    afndVw.PrintData()
                }
            }
        }
    }
}
