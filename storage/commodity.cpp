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
	 ID = 0;
	 this->name = name;
	 this->price = price;
	 this->create_at = create_at;
	 this->update_at = update_at;
	 this->description = description;
}


  
 int Commodity::getID(){
	 return ID;
 }

 char * Commodity::getName(){
	 return name;
 }
 
 int Commodity::getPrice(){
	 return price;
 }


Commodity::~Commodity(void)
{

}


void Commodity::print(){
	std::cout<<"id="<<ID<<"\t"<<"name="<<name<<"\tprice="<<price<<"\t"<<"create_at="<<create_at<<"\t"<<"update_at="<<update_at;
	std::cout<<"\t"<<"description="<<description<<std::endl;
}
