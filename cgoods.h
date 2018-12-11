#ifndef CGOODS_H
#define CGOODS_H

#include <QObject>

class CGoods : public QObject
{
    Q_OBJECT
public:
    explicit CGoods(QObject *parent = nullptr);
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChange)
    Q_PROPERTY(float sellPrice READ sellPrice WRITE setSellPrice NOTIFY sellPriceChange)
    Q_PROPERTY(QString picURL READ picURL WRITE setPicURL NOTIFY picURLChange)

    QString name() const {return m_name;}
    void setName(QString str){m_name=str;}
    float sellPrice() const {return m_sellPrice;}
    void setSellPrice(float f){m_sellPrice=f;}
    QString picURL() const {return m_picURL;}
    void setPicURL(QString str){m_picURL=str;}

	
signals:
    void nameChange();
    void sellPriceChange();
    void picURLChange();

public slots:

private:
    QString m_name;
    float m_sellPrice=0;
    QString m_picURL;
    bool m_isSell=true;
    int m_id=0;
    int m_type;
    float m_purchasePrice=0;
    int m_supplier=0;

};

#endif // CGOODS_H
