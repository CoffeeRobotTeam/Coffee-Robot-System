#include<iostream>
#include <Eigen/Dense>
#include "Robot.h"
#include "Coffee.h"
void AppInit(void)
{
	//myrobot初始化
	const double l1 = 300, l2 = 500;
	Vector2d WF_vx(1, 0), WF_vy(0, 1);
	Point wf_origin("wf_origin", 0, 0);
	Joint jt1(0, 0, 0, -180, 180, 0), jt2(l1, 0, 0, -180, 180, 0);
	Frame WF("wf", WF_vx, WF_vy, wf_origin);
	Robot myRobot(l1, l2, jt1, jt2, WF);
	//coffee初始化
	Position mycuppos(400, 600);
	Cup mycup(Middle, mycuppos);//默认中等杯子,位置（400,600）
	CoffeeAddMaterial myaddmaterial(false,false);//默认什么都不加
	CoffeeKinds mycoffeekind = kindA;//默认咖啡种类A
	Coffee mycoffee(mycup, myaddmaterial, mycoffeekind);
}
 int main(){
	 
	 AppInit();
 	//Point tf1_origin("tf1_origin",400,200),tf2_origin("tf2_origin",100,300),tf3_origin("tf3_origin",200,400); 
 	//Vector2d TF1_vx(0,1),TF1_vy(-1,0),TF2_vx(-1,0),TF2_vy(0,-1),TF3_vx(0,-1),TF3_vy(1,0);
 	//Frame TF1("tf1",TF1_vx,TF1_vy,tf1_origin),TF2("tf2",TF2_vx,TF2_vy,tf2_origin),TF3("tf3",TF3_vx,TF3_vy,tf3_origin);
 	//myRobot.TaskFrameCreate(TF1);
 	//myRobot.TaskFrameCreate(TF2);
 	//myRobot.TaskFrameCreate(TF3);
 	//Point P1(1,2),P2(1,2),P3(1,2),P4(1,2),P5(1,2);
    //myRobot.RobotShow();
 	//myRobot.PTPMove(WF,P2);
 	//myRobot.RobotShow();
 	//myRobot.PTPMove(TF1,P3);
 	//myRobot.RobotShow();
 	//myRobot.PTPMove(TF2,P4);
 	//myRobot.RobotShow();
 	//myRobot.PTPMove(TF3,P5);
 	//myRobot.RobotShow();
 	return 0;
 }

