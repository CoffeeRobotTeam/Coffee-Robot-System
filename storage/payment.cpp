#include "stdafx.h"
#include "payment.h"
#include "data.h"
#include "StorageService.h"
#include <time.h>


Payment::Payment(void)
{
	d = new Data();
}


Payment::~Payment(void)
{
	delete d;
}

/***
** 支付功能:根据发的编号结账
***/
double Payment::payWithID(char *no){
	char tmp[300];
	std::string s = "SELECT * FROM recode WHERE no = '%s'"; 
	sprintf_s(tmp, 300, s.c_str(), no);
	std::cout<<"查询语句为:  "<<tmp<<std::endl;
	std::vector<char **> v;
	std::string s_str;
	s_str.assign(tmp, strlen(tmp));
	d->select(s_str, &v);
	std::cout<<"size="<<v.size()<<std::endl;	
	if(v.size() == 0){
		return 0.0;
	}
	double sum = 0.0;
	StorageService *ss = new StorageService();
	for(int i =0; i < v.size(); i++){
		unsigned int cid = atoi(*(v[i]+2));
		Commodity *d = ss->getCommodityByID(cid);
		sum += d->getPrice() * atoi(*(v[i]+3));
	}
	delete ss;
	return sum;
}


bool Payment::insertRecode(char *no, int cid, int num, char * remark){
	time_t tt = time(NULL);
	std::string s = "INSERT INTO recode (no, cid, num, consume_time, remarka) VALUES ('%s', %d, %d, %lu, '%s')";
	 char insert_str[300];
	 sprintf_s(insert_str, 300, s.c_str() , no, cid, num, tt, remark);
	 std::cout<<"插入语句为:"<<insert_str<<std::endl;
	 return this->d->exec(insert_str);
}
