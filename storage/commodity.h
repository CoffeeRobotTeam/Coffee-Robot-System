#pragma once
class Commodity
{
public:
	Commodity();
	Commodity(char *name, unsigned int price, unsigned long create_at, unsigned long update_at, char *description);
	Commodity(unsigned int id, char *name, unsigned int price, unsigned long create_at, unsigned long update_at, char *description);
	~Commodity(void);
	bool insert();
	void print();


private:
	unsigned int ID;
	char *name;
	unsigned int price;
	unsigned long create_at, update_at;
	char *description;
};

