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
		Point(const double xx,const double yy){
			x=xx;
	    	y=yy;
		};
	    Point(const string nam,const double xx,const double yy){
	    	name=nam;
	    	x=xx;
	    	y=yy;
		}
		Point(const Point &p){
			name=p.name;
			x=p.x;
			y=p.y;
		}
		Point operator=(const Point &pt)
		{
			this->name = pt.name;//使用pt.getname()会认为改变了pt,不被允许
			this->x = pt.x;
			this->y = pt.y;
			return *this;
		} 
		void copyto(Point &p);
		void get_cin_point(void);
		
		void setx(double &xx)
		{
			x = xx;
		}

		void sety(double &yy){
			y = yy;
		}

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
		Point origin;
	    Vector2d vector_X;
	    Vector2d vector_Y;    
	public:
	   
		Frame(){
		}
		Frame(const string &nam, const Vector2d &vx, const Vector2d &vy, const Point &oripoint)
	    {
	    	name=nam;
			Vector2d vxx,vyy;
	    	double a=sqrt(pow(vx[0],2)+pow(vx[1],2));  //化为单位方向向量 
	    	vxx[0]=vx[0]/a;
	    	vxx[1]=vx[1]/a;
	    	double b=sqrt(pow(vy[0],2)+pow(vy[1],2));  //化为单位方向向量
	    	vyy[0]=vy[0]/a;
	    	vyy[1]=vy[1]/a;	    	
	    	vector_X=vxx;
	    	vector_Y=vyy;
			origin = oripoint;
		}
		Frame(const Frame &fr)
		{
			name=fr.name;
			vector_X=fr.vector_X;
			vector_Y=fr.vector_Y;
			origin = fr.origin;
		}
		Frame operator =(const Frame &fr)
		{
			this->name = fr.name;
			this->origin = fr.origin;
			this->vector_X = fr.vector_X;
			this->vector_Y = fr.vector_Y;
			return *this;
		}
		void Copyto(Frame &fr);
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
		inline void setname(const string &nam)
		{
			name=nam;
		}
		inline void setVector_X(const Vector2d &vec_x)
		{
			vector_X = vec_x;
		}
		inline void setVector_Y(const Vector2d &vec_y)
		{
			vector_Y = vec_y;
		}
		inline void setorigin(const Point &oripoint)
		{
			origin = oripoint;
		}
};
class JointFrame
{
	private:
		double theta1,theta2;
		
	public:
		
		JointFrame(){
		}
		JointFrame(const double &t1,const double &t2)
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
		inline void settheta1(double theta)
		{
			theta1=theta;
		}
		inline void settheta2(double theta)
		{
			theta2 = theta;
		}
				
};
#endif
