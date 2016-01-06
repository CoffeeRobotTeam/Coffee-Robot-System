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
        Solver solver;
    public:
        Robot(){
		}
	    Robot(double l1,double l2,Joint jt1,Joint jt2,Frame WF)
	    {
	      	length1=l1;
	      	length2=l2;
	        jt1.CopyTo(joint1);
	        jt2.CopyTo(joint2);
	        WorldFrame=WF;  
	        solver.solverinit(l1,l2,jt1.getthetamax(),jt1.getthetamin(),jt2.getthetamax(),jt2.getthetamin()); //初始化robot对应的求解器 
		}
		void TaskFrameCreate(Frame &tf);
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
		inline void setjoint1(Joint &jt)
		{
			this->joint1=jt;
		} 
		inline void setjoint2(Joint &jt)
		{
			this->joint2=jt;
		}
 };

#endif
