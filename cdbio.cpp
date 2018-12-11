#include "cdbio.h"
#include <QSqlTableModel>
#include <QSqlRecord>

CDbIO::CDbIO(QObject *parent) : QObject(parent)
{


}

bool CDbIO::open()
{
    m_db=QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("nottingHill.db");
    m_model = new QSqlTableModel(this, m_db);
    if(!m_db.open())
        return false;
    return  true;
}

int CDbIO::getGoods(QList<CGoods *> &goods)
{
    m_model->setTable("goods");
    m_model->select();
    auto rowCount = m_model->rowCount();
    CGoods* temp=new CGoods;
    for (int i = 0; i < rowCount; i++)
    {
//		temp.id= m_model->record(i).value(0).toInt();
//		temp.name = m_model->record(i).value(1).toString();
//		temp.isSell = m_model->record(i).value(2).toBool();
//		temp.type = m_model->record(i).value(3).toInt();
//		temp.sellPrice = m_model->record(i).value(4).toFloat();
//		temp.purchasePrice = m_model->record(i).value(5).toFloat();
//		temp.supplier = m_model->record(i).value(6).toInt();
//		temp.picURL = m_model->record(i).value(7).toString();
        temp->setName(m_model->record(i).value(1).toString());
        temp->setPicURL(m_model->record(i).value(7).toString());
        temp->setSellPrice(m_model->record(i).value(4).toFloat());
        goods.append(temp);
    }
    return  0;
}
