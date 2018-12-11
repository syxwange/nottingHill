#include "cnottinghill.h"

CNottingHill::CNottingHill(QObject *parent) : QObject(parent)
{
	//CGoods* p = new CGoods;
	//p->setName("aaaa");
	//m_goodsList.append(p);
	//p = new CGoods;
	//p->setName("bbbb");
	//m_goodsList.append(p);
}


int CNottingHill::order(int n)
{
    return 0;
}

int CNottingHill::destine(int n)
{
    return 0;
}

int CNottingHill::checkout(int n)
{
    return 0;
}

int CNottingHill::viewBill(int n)
{
    return 0;
}

int CNottingHill::modifyBill(int n)
{
    return 0;
}


void CNottingHill::getGoods()
{
	m_dbIO.open();
    m_dbIO.getGoods(m_goodsList);	
}
