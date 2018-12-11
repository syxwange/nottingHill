import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.4

Item
{

	
    id:orderWindow
    anchors.fill: parent
    property alias nametext: name.text
	property alias wineModel: wine.model

    Rectangle
    {
        anchors.fill: parent
        color: "#eeeeee"
    }

    SwipeView
    {
        id: view
        width: parent.width
        height: orderWindow.height - bar.height
        currentIndex: bar.currentIndex
		
        ScrollView
        {
            GridLayout
            {
                anchors.fill: parent
                columns: parseInt(orderWindow.width/100)
                

                Repeater
                {
					id:wine
                    
                    Rectangle
                    {
                        Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
						Layout.leftMargin: 10
                        Layout.topMargin: 10
                        width: 100
                        height: 100
                        color: 'green'
                        Text
                        {
                            anchors.centerIn:  parent
                            color: 'black'
                            text: name
                        }
                    }
                }
            }
        }

        ScrollView
        {
            //ScrollBar.horizontal.interactive:false
            GridLayout
            {
                anchors.fill: parent
                columns: parseInt(orderWindow.width/100)-1
			
                Repeater
                {
                    model: 20
				
                    Rectangle
                    {      
                        Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
						 //Layout.rightMargin: 10
                       // Layout.bottomMargin: 10
						Layout.leftMargin: 10
                        Layout.topMargin: 10
                        width: 100
                        height: 100
                        color: 'green'
                        Text
                        {
                            anchors.centerIn:  parent
                            color: 'black'
                            text: index
                        }
                    }
                }
            }
        }


        ScrollView
        {
            GridLayout
            {
                anchors.fill: parent
                columns: parseInt(orderWindow.width/100)

                Repeater
                {
                    model: 6
                    Rectangle
                    {
                        Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
                        width: 100
                        height: 100
                        color: 'green'
                        Text
                        {
                            anchors.centerIn:  parent
                            color: 'black'
                            text: index
                        }
                    }
                }
            }
        }

        ScrollView
        {


            Rectangle
            {
//                Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
                width: orderWindow.width
                height: orderWindow.height - bar.height
                //anchors.fill: parent
                color: '#eeeeee'
                Text
                {
                    anchors.centerIn:  parent
                    color: 'black'
                    text:"账单"
                }
                Button
                {
                    width: 200
                    height: 100
                    text: "点单回到主界面"
                    anchors.bottom: parent.bottom
                    anchors.horizontalCenter:parent.horizontalCenter
                    anchors.bottomMargin: 100
                    onClicked: {orderWindow.destroy()}
                }
            }

        }


    }


    TabBar {
        id: bar
        width: parent.width
        anchors.bottom: parent.bottom
        currentIndex: view.currentIndex
        TabButton {
            text: qsTr("酒类")			
        }
        TabButton {
            text: qsTr("饮料")
        }
        TabButton {
            text: qsTr("小吃")
        }
        TabButton {
            text: qsTr("账单")
        }
    }

    Text
    {
        anchors.centerIn:parent
        id: name
        text: qsTr("text hahahahahahah")
        color: "red"
    }
}
