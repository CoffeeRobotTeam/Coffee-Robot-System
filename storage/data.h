#pragma once
#pragma comment(lib, "libmysql")
#include <winsock2.h>
#include "include\mysql.h"
#include <vector>
#include <string>


class Data{

public:
	~Data();
	Data(char *user_name, char * user_pw, char *db);
	void select(std::string select_str, std::vector<char **> *r);
	unsigned int rows_number();
	unsigned int fields_number();
	bool insert(std::string insert_str);

private:
	MYSQL_RES *mysql_res;
	MYSQL mysql;
	char *user_name;
	char *user_pw;
	char *db;
};

