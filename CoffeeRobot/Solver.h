 #ifndef SOLVER_H
 #define SOLVER_H
 #include "Frame.h" 
 #define PI 3.141592653
 class Solver
 {
 	private:
 		double length1,length2;
 		double theta1max,theta1min,theta2max,theta2min;
 	public:
 		JointFrame ToJoint(Point ptaim);
 		Point JointTo(JointFrame jf);
 		void setlength1(double l1)
 		{
 			length1=l1;
		}
		void setlength2(double l2)
		{
			length2=l2;
		}
		void settheta1max(double t1max)
		{
			theta1max=t1max;
		}
		void settheta1min(double t1min)
		{
			theta1min=t1min;
		}
		void settheta2max(double t2max)
		{
			theta2max=t2max;
		}
		void settheta2min(double t2min)
		{
			theta2min=t2min;
		}
		void solverinit(double l1,double l2,double t1max,double t1min,double t2max,double t2min)
		{
			length1=l1;
			length2=l2;
			theta1max=t1max;
			theta1min=t1min;
			theta2max=t2max;
			theta2min=t2min;
		}
 };
 
 #endif
