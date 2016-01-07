// storage.cpp : 定义控制台应用程序的入口点。
//

#pragma comment(lib, "libmysql")
#include "stdafx.h"
#include <iostream>
#include<string>
#include <winsock2.h>
#include "include\mysql.h"
#include "data.h"
#include "commodity.h"
#include<vector>
#include "StorageService.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int _tmain(int argc, char** argv){
	string s = "select * from commodity";
	char* user_name = "root";
	char* user_pw = "";
	char* db_name = "coffee_robot";
	Data *d = new Data(user_name, user_pw, db_name);
	vector<char **> v;
	d->select(s, &v);
	unsigned int nums_row = d->rows_number(); 
	unsigned int fields_row = d->fields_number();
	cout<<"row = "<<v.size()<<endl;
	for(int i =0; i < v.size(); i++){
		Commodity *t = new Commodity(atoi(*(v[i])), *(v[i] + 1), atoi(*(v[i]+2)), atoi(*(v[i]+3)), atoi(*(v[i]+4)), *(v[i]+5));
		t->print();
		/*char a[300];*/
		//t->insert(a);
	}
	StorageService *sd = new StorageService();
	
	Commodity *c = sd->getCommodityByID(20003);
	c->print();
	return 0;
}

 