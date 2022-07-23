// == Output ==
// Hatchback Petrol
// Sedan Petrol
// Hatchback Diesel
// Sedan Diesel

#include <iostream>

// =================================================
class Hatchback
{
public:
	virtual void print() const = 0;
};

class HatchbackPetrol : public Hatchback
{
public:
	void print() const override
	{
		std::cout << "Hatchback Petrol\n";
	}
};

class HatchbackDiesel : public Hatchback
{
public:
	void print() const override
	{
		std::cout << "Hatchback Diesel\n";
	}
};

// =================================================
class Sedan
{
public:
	virtual void print() const = 0;
};

class SedanPetrol : public Sedan
{
public:
	void print() const override
	{
		std::cout << "Sedan Petrol\n";
	}
};

class SedanDiesel : public Sedan
{
public:
	void print() const override
	{
		std::cout << "Sedan Diesel\n";
	}
};

// =================================================
class AbstractFactory
{
public:
	virtual Hatchback* getHatchback() const = 0;
	virtual Sedan* getSedan() const = 0;
};

class AbstractFactoryPetrol : public AbstractFactory
{
public:
	Hatchback* getHatchback() const
	{
		return ( new HatchbackPetrol() );
	}
	Sedan* getSedan() const
	{
		return ( new SedanPetrol() );
	}
};

class AbstractFactoryDiesel : public AbstractFactory
{
public:
	Hatchback* getHatchback() const
	{
		return ( new HatchbackDiesel() );
	}
	Sedan* getSedan() const
	{
		return ( new SedanDiesel() );
	}
};

// =================================================
int main()
{
	Hatchback* hb;
	Sedan* se;

	AbstractFactory* fact = new AbstractFactoryPetrol;
	hb = fact->getHatchback();
	hb->print();
	se = fact->getSedan();
	se->print();

	AbstractFactory* fact2 = new AbstractFactoryDiesel;
	hb = fact2->getHatchback();
	hb->print();
	se = fact2->getSedan();
	se->print();
}
