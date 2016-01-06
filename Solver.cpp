#include "Solver.h"
JointFrame Solver::ToJoint(Point ptaim)
{
	double t1,t2;
	bool flag[4]={false};
	bool flag1=false;
	double theta[4][2];
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
		theta[2][0]=t1-t2;
		if(theta[2][0]*180/PI<theta1max&theta[2][0]*180/PI>theta1min){
			theta[2][1]=atan2(jt_end_y-length1*sin(theta[2][0]),jt_end_x-length1*cos(theta[2][0]));
			if(theta[2][1]*180/PI<theta2max&theta[2][1]*180/PI>theta2min){
				if(abs(jt_end_x-length1*cos(theta[2][0])-length2*cos(theta[2][1]))<0.01&abs(jt_end_y-length1*sin(theta[2][0])-length2*sin(theta[2][1]))<0.01)
				{
				  flag[2]=true;
				}			
			}
		}
		theta[3][0]=-t1-t2;
		if(theta[3][0]*180/PI<theta1max&theta[3][0]*180/PI>theta1min){
			theta[3][1]=atan2(jt_end_y-length1*sin(theta[3][0]),jt_end_x-length1*cos(theta[3][0]));
			if(theta[3][1]*180/PI<theta2max&theta[3][1]*180/PI>theta2min){
				if(abs(jt_end_x-length1*cos(theta[3][0])-length2*cos(theta[3][1]))<0.01&abs(jt_end_y-length1*sin(theta[3][0])-length2*sin(theta[3][1]))<0.01)
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
				double theta1=theta[i][0];
				double theta2=theta[i][1];
				JointFrame jf(theta1,theta2);
				return jf;   //待改进，应择优输出 
//				cout<<"第"<<cnt<<"种解为：";
//				cout<<"关节1转角"<< theta[i][0]*180/PI;
//		        cout<<"关节2转角"<< theta[i][1]*180/PI<<endl;	
			} 
		}
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
