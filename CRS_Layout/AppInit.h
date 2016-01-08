#include "Robot.h"
#include "Coffee.h"

void AppInit(void)
{
	//myrobot��ʼ��
	const double l1 = 300, l2 = 500;
	Vector2d WF_vx(1, 0), WF_vy(0, 1);
	Point wf_origin("wf_origin", 0, 0);
	Joint jt1(0, 0, 0, -180, 180, 0), jt2(l1, 0, 0, -180, 180, 0);
	Frame WF("wf", WF_vx, WF_vy, wf_origin);
	Robot myRobot(l1, l2, jt1, jt2, WF);
	//coffee��ʼ��
	Position mycuppos(400, 600);
	Cup mycup(Middle, mycuppos);//Ĭ���еȱ���,λ�ã�400,600��
	CoffeeAddMaterial myaddmaterial(false, false);//Ĭ��ʲô������
	CoffeeKinds mycoffeekind = kindA;//Ĭ�Ͽ�������A
	Coffee mycoffee(mycup, myaddmaterial, mycoffeekind);
}