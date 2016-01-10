#include "stdafx.h"
#include "Solver.h"
JointFrame Solver::ToJoint(Point ptaim, JointFrame jointframe)
{
	JointFrame PreJointFrame(jointframe);
	double t1,t2;
	bool flag[2]={false};
	bool flag1=false;
	double theta[2][2];
	double temptheta1[2], temptheta2[2];
	int cnt=0;
	double jt_end_x=ptaim.getx();
	double jt_end_y=ptaim.gety();
	double a=((pow(jt_end_x,2)+pow(jt_end_y,2))+(pow(length1,2)-pow(length2,2)))/(2*length1*sqrt(pow(jt_end_x,2)+pow(jt_end_y,2))); 
	if(a<-1|a>1) flag1=false;
	else{                               //多解性 
		t1=acos(a);//acos默认取值 0~PI
		t2=atan2(jt_end_y,jt_end_x);
		theta[0][0]=t1+t2;
		if(theta[0][0]*180/PI<theta1max&theta[0][0]*180/PI>theta1min){
			theta[0][1]=atan2(jt_end_y-length1*sin(theta[0][0]),jt_end_x-length1*cos(theta[0][0]));
			if(theta[0][1]*180/PI<theta2max&theta[0][1]*180/PI>theta2min){
				if(abs(jt_end_x-length1*cos(theta[0][0])-length2*cos(theta[0][1]))<0.01&abs(jt_end_y-length1*sin(theta[0][0])-length2*sin(theta[0][1]))<0.01)
				{
				  flag[0]=true;
				}			
			}
		}
		theta[1][0]=-t1+t2;
		if(theta[1][0]*180/PI<theta1max&theta[1][0]*180/PI>theta1min){
			theta[1][1]=atan2(jt_end_y-length1*sin(theta[1][0]),jt_end_x-length1*cos(theta[1][0]));
			if(theta[1][1]*180/PI<theta2max&theta[1][1]*180/PI>theta2min){
				if(abs(jt_end_x-length1*cos(theta[1][0])-length2*cos(theta[1][1]))<0.01&abs(jt_end_y-length1*sin(theta[1][0])-length2*sin(theta[1][1]))<0.01)
				{
					flag[1]=true;
				}			
			}
		}

		if (flag[0] == true&&flag[1]==false)
		{
			 flag1 = true;
			 JointFrame jf(theta[0][0], theta[0][1]);
			 return jf;
		}
		else if (flag[0] == false && flag[1] == true) 
		{
			flag1 = true;
			JointFrame jf(theta[1][0], theta[1][1]);
			return jf;
		}
		else if (flag[0] == true && flag[1] == true) //选择转动较小的方案进行控制
		{
			flag1 = true;
			double delta1 = abs(theta[0][0] - PreJointFrame.gettheta1()) + abs(theta[0][1] - PreJointFrame.gettheta2());
			double delta2 = abs(theta[1][0] - PreJointFrame.gettheta1()) + abs(theta[1][1] - PreJointFrame.gettheta2());
			if (delta1 <= delta2) 
			{
				JointFrame jf(theta[0][0], theta[0][1]); return jf;
			}
			else 
			{
				JointFrame jf(theta[1][0], theta[1][1]); return jf;
			}
			
		}
		else flag1 = false;	
	}
	
	if(flag1==false) cout<<"无法达到指定位置"<<endl; 
	
}

Point Solver::JointTo(JointFrame jf)
{
   double theta1=jf.gettheta1();
   double theta2=jf.gettheta2();
   double x=length1*cos(theta1)+length2*cos(theta2);
   double y=length1*sin(theta1)+length2*sin(theta2); 
   Point ptaim(x,y);
   return ptaim;
}
