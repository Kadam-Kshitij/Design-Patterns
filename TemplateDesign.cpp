// == Output ==
// Foo
// Hoo
// Goo1
//
// Foo
// Hoo2
// Goo2

//====================================================
#include <iostream>

class Base
{
public:
	void Steps()
	{
		foo();
		hoo();
		goo();
	}

	void foo()
	{
		std::cout << "Foo\n";
	}

	virtual void goo() = 0;

	virtual void hoo()
	{
		std::cout << "Hoo\n";
	}
};


//====================================================
class Derived1 : public Base
{
public:
	void goo() override
	{
		std::cout << "Goo1\n";
	}
};

class Derived2 : public Base
{
public:
	void goo() override
	{
		std::cout << "Goo2\n";
	}

	void hoo() override
	{
		std::cout << "Hoo2\n";
	}
};

//====================================================
int main()
{
	Base* o1 = new Derived1();
	Base* o2 = new Derived2();

	o1->Steps();
	std::cout << "\n";
	o2->Steps();
}
