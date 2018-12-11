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

    //下单
    //参数n:台位号
    int order(int n);
    //预定台位
    //参数n:台位号
    int	destine(int n);
    //结账
    //参数n:台位号
    int checkout(int n);
    //查看账单
    //参数n:台位号
    int viewBill(int n);
    //修改账单
    //参数n:台位号
    int modifyBill(int n);
	//得到货物数组
	Q_INVOKABLE void getGoods();

    QList<CGoods*> m_goodsList;
	
signals:

public slots:
private: 	

    CDbIO m_dbIO;
	
};

#endif // CNOTTINGHILL_H
