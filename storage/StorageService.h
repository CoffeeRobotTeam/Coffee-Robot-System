#pragma once
#include "commodity.h"
#include "data.h"

class StorageService
{
public:
	StorageService();
	~StorageService(void);
	Commodity *getCommodityByID(int id);
	bool insertCommodity(char *name, unsigned int price, unsigned long create_at, unsigned long update_at, char *description);

private:
	Data *d;
	
};

