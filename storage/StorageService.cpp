#include "stdafx.h"
#include "StorageService.h"


StorageService::StorageService()
{
	this->d = new Data();
}

Commodity *StorageService::getCommodityByID(int id){
	char tmp[300];
	std::string s = "SELECT * FROM commodity WHERE ID = %d limit 1"; 
	sprintf_s(tmp, 300, s.c_str(), id);
	std::cout<<"查询语句为:  "<<tmp<<std::endl;
	std::vector<char **> v;
	std::string s_str;
	s_str.assign(tmp, strlen(tmp));
	d->select(s_str, &v);
	std::cout<<"size="<<v.size()<<std::endl;	
	if(v.size() == 0){
		return NULL;
	}
	Commodity *c = new Commodity(atoi(*(v[0])), *(v[0] + 1), atoi(*(v[0]+2)), atoi(*(v[0]+3)), atoi(*(v[0]+4)), *(v[0]+5));
	return c;
}

bool StorageService::insertCommodity(char *name, unsigned int price, unsigned long create_at, unsigned long update_at, char *description){
	 std::string s = "INSERT INTO commodity (name, price, create_at, update_at, description) VALUES ('%s', %d, %lu, %lu, '%s')";
	 char insert_str[300];
	 sprintf_s(insert_str, 300, s.c_str() , name, price, create_at, update_at, description);
	 std::cout<<"插入语句为:"<<insert_str<<std::endl;
	 return this->d->exec(insert_str);
}


StorageService::~StorageService(void)
{
	delete d;
}
