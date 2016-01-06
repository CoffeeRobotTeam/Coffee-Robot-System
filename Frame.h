#ifndef FRAME_H
#define FRAME_H

#include <vector>
#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
 class Point
{
	private:
		string name;
	    double x,y;
	public: 
	    Point(){
		};
		Point(double xx,double yy){
			x=xx;
	    	y=yy;
		};
	    Point(string nam,double xx,double yy){
	    	name=nam;
	    	x=xx;
	    	y=yy;
		}
		Point(Point &p){
			name=p.name;
			x=p.x;
			y=p.y;
		}
		void copyto(Point &p);
		void get_cin_point(void);
		inline double getx(void)
		{
			return this->x;
		}
		inline double gety(void)
		{
			return this->y;
		}
		inline string getname(void)
		{
			return this->name;
		}
};

class Frame
{
	private:
		string name;
	    Vector2d vector_X;
	    Vector2d vector_Y;
	    Point origin;
	public:
	   
	    Frame(){
		}
	    Frame(string nam,Vector2d &vx,Vector2d &vy,Point &oripoint)
	    {
	    	name=nam;
	    	double a=sqrt(pow(vx[0],2)+pow(vx[1],2));  //化为单位方向向量 
	    	vx[0]=vx[0]/a;
	    	vx[1]=vx[1]/a;
	    	double b=sqrt(pow(vy[0],2)+pow(vy[1],2));  //化为单位方向向量
	    	vy[0]=vy[0]/a;
	    	vy[1]=vy[1]/a;	    	
	    	vector_X=vx;
	    	vector_Y=vy;
            oripoint.copyto(origin);
		}
		Frame(Frame &fr)
		{
			name=fr.getname();
			vector_X=fr.vector_X;
			vector_Y=fr.getVector_Y();
		    fr.getorigin().copyto(origin);
		}
		inline string getname(void)
		{
			return this->name;
		}
		inline Vector2d getVector_X(void)
		{
			return this->vector_X;
		}
		inline Vector2d getVector_Y(void)
		{
			return this->vector_Y;
		}
		inline Point getorigin(void)
		{
			return this->origin;
		}

};
class JointFrame
{
	private:
		double theta1,theta2;
	public:
		JointFrame(){
		}
		JointFrame(double t1,double t2)
		{
			this->theta1=t1;
			this->theta2=t2;
		}
		inline double gettheta1(void)
		{
			return this->theta1; 
		}
		inline double gettheta2(void)
		{
			return this->theta2; 
		}
			
};
#endif
