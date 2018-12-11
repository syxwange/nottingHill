#pragma once
#include <qstring.h>

struct Goods
{
	int id;
	QString name;
	bool isSell;
	int type;
	float sellPrice;
	float purchasePrice;
	QString supplier;
	QString picURL;
};