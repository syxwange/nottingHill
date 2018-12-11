import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick 2.11
import QtQuick.Layouts 1.11

import qt.nottingHill 1.0

ApplicationWindow
{
    id:mainWindow
    visible: true
    width: 1024
    height: 600
    title: qsTr("Notting Hill")

	
    property Component orderView: null
	
    CNottingHill
    {
        id:nottingHill
    }
	
    Rectangle
    {
        anchors.fill: parent
        color: 'teal'
        opacity:0.05

    }
	
    RowLayout {
        id: layout
        anchors.fill: parent
		

        ListView
        {
            id:tableList			
            Layout.minimumWidth: 100
            Layout.preferredWidth: 150
            Layout.maximumWidth: 300
            Layout.minimumHeight: 50
            Layout.preferredHeight: 100
            Layout.maximumHeight: parent.height
            Layout.fillHeight: true
            Layout.fillWidth: true			
			delegate: Text {
            text: name
        }
            Rectangle
            {
                anchors.fill: parent
                color: 'teal'
                opacity:0.04

            }

        }

        Rectangle {
            id:order
            color: 'teal'
            Layout.fillWidth: true
            Layout.minimumWidth: 50
            Layout.preferredWidth: 100
            Layout.maximumWidth: 200
            Layout.minimumHeight: 50
            Layout.preferredHeight: 100
            Layout.maximumHeight: 200
            //Layout.alignment: Qt.AlignCenter
            radius: 5
            Text {
                anchors.centerIn: parent
                text:"点 单"
                font.family:"微软雅黑"
                color: "white"
            }			
			
            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                   mainWindow.orderView = Qt.createComponent("orderUI.qml")
                    if(mainWindow.orderView.status ===Component.Ready)
                    {
						nottingHill.getGoods()						
                        mainWindow.orderView.createObject(mainWindow,{wineModel:nottingHill.goodsList,nametext:"sss"})
				     }
					
                }

            }
        }
        Rectangle {
            id:purchase
            color: 'teal'
            Layout.fillWidth: true
            Layout.minimumWidth: 50
            Layout.preferredWidth: 100
            Layout.maximumWidth: 200
            Layout.minimumHeight: 50
            Layout.preferredHeight: 100
            Layout.maximumHeight: 200
            radius: 5
            Text {
                anchors.centerIn: parent
                text: "货 物"
                font.family:"微软雅黑"
                color: "white"
            }
        }

        Rectangle {
            color: 'teal'
            Layout.fillWidth: true
            Layout.minimumWidth: 50
            Layout.preferredWidth: 100
            Layout.maximumWidth: 200
            Layout.minimumHeight: 50
            Layout.preferredHeight: 100
            Layout.maximumHeight: 200
            radius: 5
            Layout.rightMargin:10
            Text {
                anchors.centerIn: parent
                text:"财 务"
                font.family:"微软雅黑"
                color: "white"
            }
        }
		
    }  
}
