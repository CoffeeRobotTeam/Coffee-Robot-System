#pragma once
#include "data.h"
class Payment
{
public:
	Payment(void);
	~Payment(void);
	double payWithID(char *no);
	bool insertRecode(char *no, int cid, int num, char * remark);

private:
	Data *d;
};

