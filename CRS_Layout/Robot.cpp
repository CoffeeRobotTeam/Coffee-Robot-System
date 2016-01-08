#include "stdafx.h"
#include "Robot.h"
#include "math.h"
#include "Solver.h"
void Robot::TaskFrameCreate(const Frame &tf)
{
	fv.push_back(tf);
}
void Robot::PTPMove(Frame &fr,Point &pt)
{
 Vector2d vectorx=fr.getVector_X();
 double theta=atan2(vectorx[1],vectorx[0]);
 Point origin;
 fr.getorigin().copyto(origin); 
 double x=origin.getx()+pt.getx()*cos(theta)-pt.gety()*sin(theta);
 double y=origin.gety()+pt.getx()*sin(theta)+pt.gety()*cos(theta);
 //更新joint2的笛卡尔坐标 
 joint2.setx(x);
 joint2.sety(y);
 //求解关节角度
 Point ptaim(x,y);
 JointFrame jt=solver.ToJoint(ptaim);
 //更新joint1、joint2的关节坐标 
 joint1.settheta(jt.gettheta1());
 joint2.settheta(jt.gettheta2());
  //更新joint1的笛卡尔坐标 
 joint1.setx(length1*cos(joint1.gettheta()));
 joint1.sety(length2*sin(joint1.gettheta()));

}

void Robot::RobotShow(void){
	//cout<<"关节1转角"<< joint1.gettheta()*180/PI;
	//cout<<"关节2转角"<< joint2.gettheta()*180/PI;
	//cout<<"关节1坐标("<<joint1.getx()<<","<<joint1.gety()<<")";
	//cout<<"关节2坐标("<<joint2.getx()<<","<<joint2.gety()<<")"<<endl;	
}
