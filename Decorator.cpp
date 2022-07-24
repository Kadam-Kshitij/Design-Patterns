// == Output ==
// x = 23, y = 56
// x = 23, y = 56, alpha = 0.5
// x = 23, y = 56, alpha = 0.5, z = 5

//===========================================================
#include <iostream>

class Point
{
public:
	virtual void print() const = 0;
};

class ThreeDPoint : public Point
{	
	int x;
	int y;
public:
	ThreeDPoint( int a, int b ) : x{ a }, y{ b }
	{
	}

	void print() const override
	{
		std::cout << "x = " << x << ", y = " << y;
	}
};

//===========================================================
class Decorator : public Point
{
protected:
	Point* ptr;
public:
	Decorator( Point* p ) : ptr{ p } 
	{
	}
};

class Alpha : public Decorator
{
	float alpha;
public:
	Alpha( float a, Point* p ) : Decorator{ p }, alpha{ a }
	{
	}

	void print() const override
	{
		ptr->print();
		std::cout << ", alpha = " << alpha;
	}
};

class PointZ : public Decorator
{
	int z;
public:
	PointZ( int a, Point* p ) : Decorator{ p }, z{ a }
	{
	}

	void print() const override
	{
		ptr->print();
		std::cout << ", z = " << z;
	}
};

//===========================================================
int main()
{
	Point* point = new ThreeDPoint( 23, 56 );
	point->print();
	std::cout << std::endl;

	Point* point2 = new Alpha( 0.5, point );
	point2->print();
	std::cout << std::endl;

	Point* point3 = new PointZ( 5, point2 );
	point3->print();
	std::cout << std::endl;
}
