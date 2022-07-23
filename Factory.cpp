// == Output ==
// Car 1) Hatchback, 2) Sedan
// 1
// Hatchback
//
// Car 1) Hatchback, 2) Sedan
// 2
// Sedan

#include <iostream>

// =================================================
class Car
{
public:
	virtual void print() const = 0;
};

class Hatchback : public Car
{
public:
	void print() const override
	{
		std::cout << "Hatchback\n";
	}
};

class Sedan : public Car
{
public:
	void print() const override
	{
		std::cout << "Sedan\n";
	}
};

// =================================================
class Factory
{
public:
	Car* getCar( const int car )
	{
		if ( 1 == car )
		{
			return ( new Hatchback() ); 
		}
		return ( new Sedan() );
	}
};

// =================================================
int main()
{
	std::cout << "Car 1) Hatchback, 2) Sedan\n";
	int input;
	std::cin >> input;

	Factory f;
	Car* obj = f.getCar( input );
	obj->print();
	delete obj;
}
