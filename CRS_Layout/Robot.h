#ifndef ROBOT_H
#define ROBOT_H

#include<iostream>
#include<vector>
#include "Frame.h" 
#include "Joint.h"
#include "Solver.h"

class Robot 
{
   private:
        double length1,length2;	
        Joint joint1,joint2;
        Frame WorldFrame;
        vector<Frame> fv;
		JointFrame jointframe;
		
        Solver solver;
    public:
        Robot(){
		}
	    Robot(const double &l1,const double &l2,const Joint &jt1,const Joint &jt2,const Frame &wf)
	    {
	      	length1=l1;
	      	length2=l2;
			joint1 = jt1;
			joint2 = jt2;
			WorldFrame = wf;
			jointframe.settheta1(joint1.gettheta());
			jointframe.settheta2(joint2.gettheta());
			solver.solverinit(l1, l2, joint1.getthetamax(), joint1.getthetamin(), joint2.getthetamax(), joint2.getthetamin()); //初始化robot对应的求解器 
		}
		void TaskFrameCreate(const Frame &tf);
        void PTPMove(Frame &fr,Point &pt); 
        void RobotShow(void);
        inline double getlength1(void)
        {
        	return this->length1;
		}
		inline double getlength2(void)
        {
        	return this->length2;
		}
		inline Joint getjoint1(void)
        {
        	return this->joint1;
		}
		inline Joint getjoint2(void)
        {
        	return this->joint2;
		}
		inline JointFrame getjointframe(void)
		{
			return this->jointframe;
		}
		inline void setjoint1(const Joint &jt)
		{
			this->joint1=jt;
			jointframe.settheta1(joint1.gettheta()); //同步更新关节坐标系
		} 
		inline void setjoint2(const Joint &jt)
		{
			this->joint2=jt;
			jointframe.settheta2(joint2.gettheta());  //同步更新关节坐标系
		}

		inline Point getjointframe_angle(void)
		{
			Point JointFrame_angle(joint1.gettheta(), joint2.gettheta());
			return JointFrame_angle;
		}
		void setlength1(double &L1)
		{
			length1 = L1;
			solver.setlength1(length1);
		}
		void setlength2(double &L2)
		{
			length2 = L2;
			solver.setlength2(length2);
		}
 };

#endif
