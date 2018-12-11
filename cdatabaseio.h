#ifndef CDATABASEIO_H
#define CDATABASEIO_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include "common.h"
#include <qvector.h>

class QSqlTableModel;

class CDatabaseIO:public QObject
{
public:
    CDatabaseIO(QObject *parent = nullptr);
    int getGoods(QVector<Goods>& goods);
    int getGoods(int type,bool isSell=true);

private:
    QSqlDatabase  m_database;
	QSqlTableModel *m_pTableModel = nullptr;
    bool m_isOpne=true;

};

#endif // CDATABASEIO_H
