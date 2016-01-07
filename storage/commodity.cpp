#include "stdafx.h"
#include "commodity.h"


Commodity::Commodity(unsigned int id, char *name, unsigned int price, unsigned long create_at, unsigned long update_at, char *description)
{
	 ID = id;
	 this->name = name;
	 this->price = price;
	 this->create_at = create_at;
	 this->update_at = update_at;
	 this->description = description;
}

Commodity::Commodity(char *name, unsigned int price, unsigned long create_at, unsigned long update_at, char *description){
	 this->name = name;
	 this->price = price;
	 this->create_at = create_at;
	 this->update_at = update_at;
	 this->description = description;
}


 bool Commodity::insert(){
	 std::string s = "INSERT INTO commodity (name, price, create_at, update_at, description) VALUES ('%s', %d, %lu, %lu, '%s')";
	 char insert_str[100];
	 sprintf(insert_str,s.c_str() , name, price, create_at, update_at, description);
	 //std::cout<<"insert_str="<<insert_str<<std::endl;
	 return true;
 }


Commodity::~Commodity(void)
{
}



void Commodity::print(){
	std::cout<<"id="<<ID<<"\t"<<"name="<<name<<"price="<<price<<"\t"<<"create_at="<<create_at<<"\t"<<"update_at="<<update_at;
	std::cout<<"\t"<<"description="<<description<<std::endl;
}
