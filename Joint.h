#ifndef JOINT_H
#define JOINT_H
class Joint
{
	private:
		double x,y,theta;
	    double thetamin,thetamax,thetazero;
    public:
		Joint(){
		}
		Joint(double xx,double yy,double thetaa,double thetaminn,double thetamaxx,double thetazeroo)
		{
			x=xx;
			y=yy;
			theta=thetaa;
			thetamin=thetaminn;
			thetamax=thetamaxx;
			thetazero=thetazeroo;
		}
		CopyTo(Joint &jt)
		{
			jt.x=x;
			jt.y=y;
			jt.theta=theta;
			jt.thetamin=thetamin;
			jt.thetamax=thetamax;
			jt.thetazero=thetazero;
		}
		inline double getx(void)
		{
			return this->x;
		}
		inline double gety(void)
		{
			return this->y;
		}
		inline double gettheta(void)
		{
			return this->theta;
		}
		inline double getthetamin(void)
		{
			return this->thetamin;
		}
		inline double getthetamax(void)
		{
			return this->thetamax;
		}
		inline double getthetazero(void)
		{
			return this->thetazero;
		}
		inline void setx(const double &xx)
		{
			this->x=xx;
		}
		inline void sety(const double &yy)
		{
			this->y=yy;
		}
		inline void settheta(const double &thetaa)
		{
			this->theta=thetaa;
		}
};

#endif
