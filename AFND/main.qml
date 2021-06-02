import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 800
    height: 600
    title: qsTr("Hello World")

    GridLayout {
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

        Rectangle {
            color : 'red'
            Layout.rowSpan   : 10
            Layout.columnSpan: 8
            Layout.preferredWidth  : grid.prefWidth(this)
            Layout.preferredHeight : grid.prefHeight(this)
        }

        Rectangle {
            color : 'pink'
            Layout.rowSpan   : 5
            Layout.columnSpan: 4
            Layout.preferredWidth  : grid.prefWidth(this)
            Layout.preferredHeight : grid.prefHeight(this)
        }

        Rectangle {
            color : 'black'
            Layout.rowSpan   : 5
            Layout.columnSpan: 4
            Layout.preferredWidth  : grid.prefWidth(this)
            Layout.preferredHeight : grid.prefHeight(this)
        }

        Rectangle {
            id : greenRect
            color : 'green'
            Layout.rowSpan : 2
            Layout.columnSpan : 8
            Layout.preferredWidth  : grid.prefWidth(this)
            Layout.preferredHeight : grid.prefHeight(this)
        }

        Rectangle {
            id: blueRect
            color: 'blue'
            Layout.rowSpan: 2
            Layout.columnSpan: 4
            Layout.preferredWidth  : grid.prefWidth(this)
            Layout.preferredHeight : grid.prefHeight(this)
        }
    }
}
