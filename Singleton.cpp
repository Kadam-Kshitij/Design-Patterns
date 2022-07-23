#include <iostream>

//=============================================================
class Base
{
	int val;
	static Base* obj;

    // Make the constructor and copy constructor private
	Base( int x = 0 ) : val{ x }
	{
	}

	Base( const Base& obj )
	{
	}
public:
    // Static function which returns a new instance
	static Base* getInstance( int i )
	{
		if ( obj == NULL )
		{
			obj = new Base( i );
		}
		return obj;
	}

	void deleteInstance()
	{
		delete obj;
		obj = NULL;
	}

	void print() const
	{
		std::cout << "Base " << val << std::endl;
	}
};
Base* Base::obj = NULL;


//=============================================================
int main()
{
	Base* ptr = Base::getInstance( 23 );
	ptr->print();
	ptr->deleteInstance();

	Base* ptr2 = Base::getInstance( 76 );
	ptr2->print();

	Base* ptr3 = Base::getInstance( 9 );
	ptr3->print();
	ptr3->deleteInstance();

	Base* ptr4 = Base::getInstance( 45 );
	ptr4->print();

	// CTE will occur in following cases
	// Base b;
	// Base* p = new Base();
	// Base b = *ptr4;
}
