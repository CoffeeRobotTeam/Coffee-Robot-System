#ifndef COFFEE_H
#define COFFEE_H


enum CupSize{ Big, Middle, Micro };
enum CoffeeKinds { kind1, kind2, kind3 };

typedef struct
{
	CupSize cupsize;
	Point pt;
}Cupsize2Position;
Point MidCupPos(300, 400);
Point MicroCupPos(400, 500);
Point BigCupPos(500, 600);

Point SugarPos(400, 400);
Point MilkPos(450, 450);

Point Coffeekind1Pos(450, 450);
Point Coffeekind2Pos(480, 480);
Point Coffeekind3Pos(500, 500);

class CoffeeAddMaterial
{
    private:
		bool Sugar;
		bool Milk;
    public:
		CoffeeAddMaterial(){
		}
		CoffeeAddMaterial(bool sugar, bool milk)
		{
			Sugar = sugar;
			Milk = milk;
		}
		void setsugar(const bool &sugar)
		{
			Sugar = sugar;
		}
		void setmilk(const bool &milk)
		{
			Milk = milk;
		}

};
class Position
{
	private:
		double x;
		double y;
	public:
		Position(){
		}
		Position(const double &xx, const double &yy)
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
class Cup
{
private:
	CupSize mycupsize;
	Point mycuppos;
public:
	Cup(){
	}
	Cup(const CupSize &cupsize)
	{
		mycupsize = cupsize;
	}
	Cup(const CupSize &cupsize, const Point &cuppos)
	{
		mycuppos = cuppos;
		mycupsize = cupsize;
	}
	void setmycupsize(const CupSize &cupsize)
	{
		mycupsize = cupsize;
	}
	void setmycupsize(const Point &cupposition)
	{
		mycuppos = cupposition;
	}
	CupSize getmycupsize()
	{
		return mycupsize;
	}
	Point getmycuppos()
	{
		return mycuppos;
	}
};
class Coffee
{
private:
	Cup mycup;
	CoffeeAddMaterial mycoffeeaddmaterial;
	CoffeeKinds mycoffeekind;
public:
	Coffee(){
	}
	Coffee(const Cup &cup, const CoffeeAddMaterial &material, const CoffeeKinds &coffeekind)
	{
		mycup = cup;
		mycoffeeaddmaterial = material;
		mycoffeekind = coffeekind;
	}
	void setmycup(const Cup &cup)
	{
		mycup = cup;
	}
	void setmycoffeeaddmaterial(const CoffeeAddMaterial &material)
	{
		mycoffeeaddmaterial = material;
	}
	void setmycoffeekind(const CoffeeKinds &coffeekind)
	{
		mycoffeekind = coffeekind;
	}
	Cup getmycup(void)
	{
		return mycup;
	}
	CoffeeAddMaterial getmycoffeeaddmaterial(void)
	{
		return mycoffeeaddmaterial;
	}
	CoffeeKinds getmycoffeekind(const CoffeeKinds &coffeekind)
	{
		return mycoffeekind;
	}

};
#endif
