#include "Robot.h"
#include "math.h"
void Robot::TaskFrameCreate(const Frame &tf)
{
	fv.push_back(tf);
}
void Robot::PTPMove(const Frame &fr,const POINT &pt)
{
 double theta=atan2(fr.vector_X[1],fr.vector_X[0]);
 joint2.x=fr.origin.x+pt.x*cos(theta)-pt.y*sin(theta);
 joint2.y=fr.origin.y+pt.x*sin(theta)+pt.y*cos(theta);
 cout<<"末端关节坐标("<<joint2.x<<","<<joint2.y<<")"<<endl;
 ToJoint();
}
void Robot::ToJoint()
{
	double t1,t2;
	bool flag[4]={false};
	bool flag1=false;
	double theta[4][2];
	int cnt=0;
	double a=((pow(joint2.x,2)+pow(joint2.y,2))+(pow(length1,2)-pow(length2,2)))/(2*length1*sqrt(pow(joint2.x,2)+pow(joint2.y,2))); 
	if(a<-1|a>1) flag1=false;
	else{                               //多解性 
		t1=acos(a);//acos默认取值 0~PI
		t2=atan2(joint2.y,joint2.x);
		theta[0][0]=t1+t2;
		if(theta[0][0]*180/PI<joint1.thetamax&theta[0][0]*180/PI>joint1.thetamin){
			theta[0][1]=atan2(joint2.y-length1*sin(theta[0][0]),joint2.x-length1*cos(theta[0][0]));
			if(theta[0][1]*180/PI<joint2.thetamax&theta[0][1]*180/PI>joint2.thetamin){
				if(abs(joint2.x-length1*cos(theta[0][0])-length2*cos(theta[0][1]))<0.01&abs(joint2.y-length1*sin(theta[0][0])-length2*sin(theta[0][1]))<0.01)
				{
				  flag[0]=true;
				}			
			}
		}
		theta[1][0]=-t1+t2;
		if(theta[1][0]*180/PI<joint1.thetamax&theta[1][0]*180/PI>joint1.thetamin){
			theta[1][1]=atan2(joint2.y-length1*sin(theta[1][0]),joint2.x-length1*cos(theta[1][0]));
			if(theta[1][1]*180/PI<joint2.thetamax&theta[1][1]*180/PI>joint2.thetamin){
				if(abs(joint2.x-length1*cos(theta[1][0])-length2*cos(theta[1][1]))<0.01&abs(joint2.y-length1*sin(theta[1][0])-length2*sin(theta[1][1]))<0.01)
				{
					flag[1]=true;
				}			
			}
		}
		theta[2][0]=t1-t2;
		if(theta[2][0]*180/PI<joint1.thetamax&theta[2][0]*180/PI>joint1.thetamin){
			theta[2][1]=atan2(joint2.y-length1*sin(theta[2][0]),joint2.x-length1*cos(theta[2][0]));
			if(theta[2][1]*180/PI<joint2.thetamax&theta[2][1]*180/PI>joint2.thetamin){
				if(abs(joint2.x-length1*cos(theta[2][0])-length2*cos(theta[2][1]))<0.01&abs(joint2.y-length1*sin(theta[2][0])-length2*sin(theta[2][1]))<0.01)
				{
				  flag[2]=true;
				}			
			}
		}
		theta[3][0]=-t1-t2;
		if(theta[3][0]*180/PI<joint1.thetamax&theta[3][0]*180/PI>joint1.thetamin){
			theta[3][1]=atan2(joint2.y-length1*sin(theta[3][0]),joint2.x-length1*cos(theta[3][0]));
			if(theta[3][1]*180/PI<joint2.thetamax&theta[3][1]*180/PI>joint2.thetamin){
				if(abs(joint2.x-length1*cos(theta[3][0])-length2*cos(theta[3][1]))<0.01&abs(joint2.y-length1*sin(theta[3][0])-length2*sin(theta[3][1]))<0.01)
				{
				  flag[3]=true;  
				}			
			}
		}
		for(int i=0;i<4;i++)
		{
			if(flag[i]==true) {
				flag1=true;
				cnt++;
				joint1.theta=theta[i][0];
				joint2.theta=theta[i][1];
				cout<<"第"<<cnt<<"种解为：";
				cout<<"关节1转角"<< theta[i][0]*180/PI;
		        cout<<"关节2转角"<< theta[i][1]*180/PI<<endl;	
			} 
		}
	}
	
	if(flag1==false) cout<<"无法达到指定位置"<<endl; 
}

void Robot::JointTo()
{
   joint2.x=length1*cos(joint1.theta)+length2*cos(joint2.theta);
   joint2.y=length1*sin(joint1.theta)+length2*sin(joint2.theta);    
}
void Robot::RobotShow(void){
//	cout<<"关节1转角"<< joint1.theta*180/PI;
//	cout<<"关节2转角"<< joint2.theta*180/PI;
//	cout<<"末端关节坐标("<<joint2.x<<","<<joint2.y<<")"<<endl;	
}
void POINT::copyto(POINT &p){
	p.name=name;
	p.x=x;
	p.y=y;
}
