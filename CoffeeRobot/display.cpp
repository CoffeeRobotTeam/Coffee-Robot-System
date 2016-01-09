#include "display.h"
extern Robot myrobot;
void JointDisplay(JointFrame prejointfr,JointFrame nowjointfr)
{  
	static const int div_display = 10;
	JointFrame jointshow(prejointfr);
	double delta1 = (nowjointfr.gettheta1() - prejointfr.gettheta1()) / div_display;
	double delta2 = (nowjointfr.gettheta2() - prejointfr.gettheta2()) / div_display;
	for (int i = 1; i <= div_display; i++)
	{
		jointshow.settheta1(prejointfr.gettheta1() + i*delta1);
		jointshow.settheta2(prejointfr.gettheta2() + i*delta2);
		cout << jointshow.gettheta1()*180/PI<<"  ";
		cout << jointshow.gettheta2()*180/PI<<endl;
		 //ÑÓÊ±
	}
}
