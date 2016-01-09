#ifndef COFFEE_H
#define COFFEE_H
#include <vector>
#include <iostream>
#include <cstring>
#include "math.h"
#include "Frame.h"
#include"stdio.h"
using namespace std;

class Cup
{
	private:
	string size;
	int number;
	public:
		inline string getsize(){
			return this->size;	
		}
		inline int getnumber(){
				return this->number;
		}
			inline void setsize(){
			
		}
		inline void setnumber(){
			
		}
	
};

class Coffee
{
  private:
  string taste;
  double temperature;
  double price;//(初始化应置0)
  string volumn;
  Point position;
  Cup cup0;
  public:
  	inline  void setposition(Point &p){
  	 this->position.setpoint(p.getx(),p.gety());
	  }
  inline string gettaste(){
  	return this->taste;
  }
  inline	void settaste(string str){
  	this->taste.assign(str);
  	
  	
  	
  }
  inline	double gettemperature(){
  	return this->temperature;	
  }
  inline	void settemperature(double tp){
  	this->temperature=tp;
  	
  }
  inline  void setvolumn(Cup &cup0)
  {
  		this->volumn.assign(cup0.getsize());
  	
  }
  inline	void setprice(){
  	if (this->taste=="Machiatto"&&this->cup0.getsize()=="large") this->price=10;
  	if (this->taste=="Machiatto"&&this->cup0.getsize()=="middle") this->price=8;
  	
  	if (this->taste=="Machiatto"&&this->cup0.getsize()=="small") this->price=6;
  	if (this->taste=="Americano"&&this->cup0.getsize()=="large") this->price=9;
  		if (this->taste=="Americano"&&this->cup0.getsize()=="middle") this->price=7;
  			if (this->taste=="Americano"&&this->cup0.getsize()=="small") this->price=5;
  			if (this->taste=="Flat white"&&this->cup0.getsize()=="large") this->price=11;
  			if (this->taste=="Flat white"&&this->cup0.getsize()=="middle") this->price=9;
  			if (this->taste=="Flat white"&&this->cup0.getsize()=="small") this->price=7;
			if (this->taste=="Caffè Latte"&&this->cup0.getsize()=="large") this->price=10;	
			if (this->taste=="Caffè Latte"&&this->cup0.getsize()=="middle") this->price=7;
			if (this->taste=="Caffè Latte"&&this->cup0.getsize()=="small") this->price=5;
			if (this->taste=="Cappuccino"&&this->cup0.getsize()=="large") this->price=12;
			if (this->taste=="Cappuccino"&&this->cup0.getsize()=="middle") this->price=10;
			if (this->taste=="Cappuccino"&&this->cup0.getsize()=="small") this->price=8;
			if (this->taste=="CafeMocha"&&this->cup0.getsize()=="large") this->price=10;
			if (this->taste=="CafeMocha"&&this->cup0.getsize()=="middle") this->price=8;
			if (this->taste=="CafeMocha"&&this->cup0.getsize()=="small") this->price=6;
  	
  }
  inline	void showprice(){
  	//鼠标点击不同咖啡时，显示对应不同价格 
  }
  
 inline	double getprice(){
 	
  return this->price;
  }
  	   	
	
};

 class  pay
 {
 	private:
 		double totalmoney;//(初始化应置0)
 		double givenmoney;
 		double charge;
 		Coffee coffee0;
 	public:
 	  inline double gettotalmoney(){
 	  	totalmoney+=coffee0.getprice();
 	  	return this->totalmoney;
	   }	
	  inline double getcharge(){
	  	this->charge=this->givenmoney-this->gettotalmoney();
	   	return this->charge;
	   	
	   }
	     inline double setgivenmoney(double gm){
	     	this->givenmoney=gm;
	   	return this->givenmoney;
	   	
	   }	
 	
 };
#endif
