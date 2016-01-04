#include<iostream>
#include <Eigen/Dense>
#include<vector>
using namespace Eigen;
using namespace std;
#define PI 3.141592653
 class POINT
{
	public:
	    double x, y;
	    string name;
	    POINT(){
		};
		POINT(double xx,double yy){
			x=xx;
	    	y=yy;
		};
	    POINT(string nam,double xx,double yy){
	    	name=nam;
	    	x=xx;
	    	y=yy;
		}
		POINT(const POINT &p){
			name=p.name;
			x=p.x;
			y=p.y;
		}
		POINT operator =(const POINT &pt)
	    {
	    	POINT ptt(pt);
	    	return ptt;
		}
		void copyto(POINT &p);
		void get_cin_point(void);
	    void display();
	    void rotate(double &angle);
	    void move(Vector2d &vec);
};
class Frame
{
	public:
		string name;
	    Vector2d vector_X;
	    Vector2d vector_Y;
	    POINT origin;
	    Frame(){
		}
	    Frame(string nam,Vector2d &vx,Vector2d &vy,POINT &oripoint)
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
	    	//origin=oripoint;
	    	oripoint.copyto(origin);
		}
		Frame(const Frame &fr)
		{
			name=fr.name;
			vector_X=fr.vector_X;
			vector_Y=fr.vector_Y;
			origin=fr.origin;
		}
	    Frame operator =(const Frame &fr)
	    {
	    	Frame fra(fr);
	    	return fra;
		}
};
class Joint
{
	public:
	double x,y,theta;
    double thetamin,thetamax,thetazero;
	Joint(){
	}
	Joint(double xx,double yy,double thetaa,double thetaminn,double thetamaxx,double thetazeroo)
	{
		x=xx;
		y=yy;
		theta=thetaa;
		thetamin=thetaminn;
		thetamax=thetamaxx;
		thetazero=thetazeroo;
	}
	CopyTo(Joint &jt)
	{
		jt.x=x;
		jt.y=y;
		jt.theta=theta;
		jt.thetamin=thetamin;
		jt.thetamax=thetamax;
		jt.thetazero=thetazero;
	}
};
class Robot
{
   public:
        double length1,length2;	
        Joint joint1,joint2;
        Frame JointFrame,WorldFrame;
        vector<Frame> fv;
        Robot(){
		}
	    Robot(double l1,double l2,Joint jt1,Joint jt2,Frame JF,Frame WF)
	    {
	      	length1=l1;
	      	length2=l2;
	        jt1.CopyTo(joint1);
	        jt2.CopyTo(joint2);
	        JointFrame=JF;
	        WorldFrame=WF;  
		}
		void TaskFrameCreate(const Frame &tf);
        void PTPMove(const Frame &fr,const POINT &pt); 
        void RobotShow(void);
        void ToJoint();
 		void JointTo();
 };
// class Solver
// {
// 	public:
// 		//friend void PTPMove(Frame &fr,POINT &pt);
// 		void ToJoint(Robot &myrobot);
// 		void JointTo(Robot &myrobot);
// };

