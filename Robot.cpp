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
 //����joint2�ĵѿ������� 
 joint2.setx(x);
 joint2.sety(y);
 //���ؽڽǶ�
 Point ptaim(x,y);
 JointFrame jt=solver.ToJoint(ptaim);
 //����joint1��joint2�Ĺؽ����� 
 joint1.settheta(jt.gettheta1());
 joint2.settheta(jt.gettheta2());
  //����joint1�ĵѿ������� 
 joint1.setx(length1*cos(joint1.gettheta()));
 joint1.sety(length2*sin(joint1.gettheta()));

}

void Robot::RobotShow(void){
	//cout<<"�ؽ�1ת��"<< joint1.gettheta()*180/PI;
	//cout<<"�ؽ�2ת��"<< joint2.gettheta()*180/PI;
	//cout<<"�ؽ�1����("<<joint1.getx()<<","<<joint1.gety()<<")";
	//cout<<"�ؽ�2����("<<joint2.getx()<<","<<joint2.gety()<<")"<<endl;	
}
