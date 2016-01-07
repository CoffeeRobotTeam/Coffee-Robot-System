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
		t->insert();
		 
	}
	return 0;
}

int test(int argc, char** argv) {
	char* user_name = "root";
	char* user_pw = "";
	char* db_name = "coffee_robot";
	MYSQL obj_sql;
	mysql_init(&obj_sql);
	if(mysql_real_connect(&obj_sql, NULL, user_name, user_pw, db_name, 0, NULL, 0)){
		cout<< " the connection is successful!" << endl;
	}else{
		int error_code = 0;
		error_code = mysql_errno(&obj_sql);
		cout<<"Error code:" << error_code << endl;
		const char * error_msg = mysql_error(&obj_sql);
		cout<< error_msg << endl; 
	}

	mysql_query(&obj_sql, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文
	int ret = 0;
	string sql_cmd;
	sql_cmd = "select * from commodity";
	ret = mysql_real_query(&obj_sql, sql_cmd.c_str(), sql_cmd.length());
	cout << "ret= " << ret << endl;

	MYSQL_RES *res_ptr = NULL;
	res_ptr = mysql_store_result(&obj_sql);
	if(res_ptr){
		cout<< "row_nums = " <<(unsigned long)mysql_num_rows(res_ptr) << endl;
	}
	mysql_free_result(res_ptr);

	MYSQL_ROW sqlrow = NULL;
	MYSQL_FIELD *fields = NULL;
	 
	
    fields = mysql_fetch_fields(res_ptr);
	unsigned int num_fields = mysql_num_fields(res_ptr);
	cout<<"num_fields ="<<num_fields<<endl;

	
	while(sqlrow=mysql_fetch_row(res_ptr))//获取具体的数据
	{
		cout<<sqlrow[1]<<endl;
		printf("\n");
	}

	mysql_close(&obj_sql);
	system("pause");
	return 0;
}