#include "stdafx.h"
#include "data.h"
#include<iostream>

Data::Data(){
	mysql_init(&mysql);
	this->user_name = "root";
	this->user_pw = "";
	this->db = "coffee_robot";
	this->init();
}


Data::Data(char *user_name, char *user_pw, char *db){
	mysql_init(&mysql);
	this->user_name = user_name;
	this->user_pw = user_pw;
	this->db = db;
	this->init();
	
}

void Data::init(){
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql, NULL, user_name, user_pw, db, 0, NULL, 0)){
		std::cout<< " the connection is successful!" << std::endl;
		mysql_query(&mysql, "SET NAMES GBK"); //设置编码格式,WIN无法显示中文
	}else{
		int error_code = 0;
		error_code = mysql_errno(&mysql);
		std::cout<<"Error code:" << error_code << std::endl;
		const char * error_msg = mysql_error(&mysql);
		std::cout<< error_msg << std::endl; 
	}
}



void Data::select(std::string select_str, std::vector<char **> *r){
	mysql_res = NULL;
	int ret = 0;
	ret = mysql_real_query(&mysql, select_str.c_str(), select_str.length());
	
	mysql_res = mysql_store_result(&mysql);
	if(mysql_res){
		MYSQL_ROW mysql_row = NULL;
		unsigned int num_fields = mysql_num_fields(mysql_res);
		std::cout<<"num_fields = "<<num_fields<<std::endl;
		for(int ii = 0; mysql_row = mysql_fetch_row(mysql_res); ii++){
			 r->push_back(mysql_row);
		}
	} 
}

/**
** insert , update, delete
**/
bool Data::exec(char* insert_str){
	if(mysql_query(&mysql, insert_str)){
		return false;
	}
	return true;
}



Data::~Data(){
	if(mysql_res != NULL){
		mysql_free_result(mysql_res);
	}
	mysql_close(&mysql);
}

unsigned int Data::rows_number(){
	unsigned int rows_num = mysql_num_rows(mysql_res);
	return rows_num;
}

unsigned int Data::fields_number(){
	unsigned int fields_num = mysql_num_fields(mysql_res);
	return fields_num;
}
