#ifndef CDBIO_H
#define CDBIO_H

#include <QObject>
#include <QSqlDatabase>
#include "cgoods.h"

class QSqlTableModel;

class CDbIO : public QObject
{
    Q_OBJECT
public:
    explicit CDbIO(QObject *parent = nullptr);
    bool open();

    int getGoods(QList<CGoods *>& goods);

signals:

public slots:

private:
    QSqlDatabase m_db;
    QSqlTableModel *m_model=nullptr;	
};

#endif // CDBIO_H
