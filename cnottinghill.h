#ifndef CNOTTINGHILL_H
#define CNOTTINGHILL_H


#include <QObject>
#include <qlist.h>
#include <QQmlListProperty>
#include "cgoods.h"
#include "cdbio.h"

class CNottingHill : public QObject
{
    Q_OBJECT
public:
    explicit CNottingHill(QObject *parent = nullptr);
    Q_PROPERTY(QQmlListProperty<CGoods> goodsList READ goodsList)
    QQmlListProperty<CGoods> goodsList() {return QQmlListProperty<CGoods>(this, m_goodsList);}

    //�µ�
    //����n:̨λ��
    int order(int n);
    //Ԥ��̨λ
    //����n:̨λ��
    int	destine(int n);
    //����
    //����n:̨λ��
    int checkout(int n);
    //�鿴�˵�
    //����n:̨λ��
    int viewBill(int n);
    //�޸��˵�
    //����n:̨λ��
    int modifyBill(int n);
	//�õ���������
	Q_INVOKABLE void getGoods();

    QList<CGoods*> m_goodsList;
	
signals:

public slots:
private: 	

    CDbIO m_dbIO;
	
};

#endif // CNOTTINGHILL_H
