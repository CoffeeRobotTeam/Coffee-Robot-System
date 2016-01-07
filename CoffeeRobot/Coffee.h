#ifndef COFFEE_H
#define COFFEE_H

enum CupSize{Big,Middle,Small};
enum CoffeeAddMaterial{ Sugar, Milk, None };
class Position
{
	private:
		double x;
		double y;
	public:
		Position(){
		}
		Position(const double &xx,const double &yy)
		{
			x = xx;
			y = yy;
		}
		double getx(void)
		{
			return x;
		}
		double gety(void)
		{
			return y;
		}
		void setx(const double &xx)
		{
			x=xx;
		}
		void sety(const double &yy)
		{
			y=yy;
		}
};
class Coffee
{
private :
	Cup mycup;
	CoffeeAddMaterial mycoffeeaddmaterial;
public:
	Coffee(){
	}
	Coffee(const Cup &cup, const CoffeeAddMaterial &material)
	{
		mycup = cup;
		mycoffeeaddmaterial = material;
	}
	void setmycup(const Cup &cup)
	{
		mycup = cup;
	}
	void setmycoffeeaddmaterial(const CoffeeAddMaterial &material)
	{
		mycoffeeaddmaterial = material;
	}
	Cup getmycup(void)
	{
		return mycup;
	}
	CoffeeAddMaterial getmycoffeeaddmaterial(void)
	{
		return mycoffeeaddmaterial;
	}
	
};
class Cup
{
private:
	CupSize mycupsize;
	Position mycuppos;
public:
	Cup(){
	}
	Cup(const CupSize &cupsize, const Position &cuppos)
	{
		mycuppos = cuppos;
		mycupsize = cupsize;
	}
	void setmycupsize(const CupSize &cupsize)
	{
		mycupsize = cupsize;
	}
	void setmycupsize(const Position &cupposition)
	{
		mycuppos = cupposition;
	}
	CupSize getmycupsize()
	{
		return mycupsize;
	}
	Position getmycuppos()
	{
		return mycuppos;
	}
};

#endif
