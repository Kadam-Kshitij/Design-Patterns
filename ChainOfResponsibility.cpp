// == Output ==
// Handler1 can handle request

// Handler1 cannot handle request
// Handler2 can handle request

// Handler1 cannot handle request
// Handler2 cannot handle request
// Handler3 can handle request

// Handler1 cannot handle request
// Handler2 cannot handle request
// Handler3 cannot handle request

//========================================================
#include <iostream>

class Base
{
protected:
	Base* next;
	const int req;

public:
	Base( const int& x ) : req{ x }, next{ nullptr }
	{
	}

	virtual void handle( int request ) const = 0;

	void setNext( Base* ptr )
	{
		next = ptr;
	}

	bool canHandle( int request ) const
	{
		return ( req == request );
	}
};

//========================================================
class Handler1 : public Base
{
public:
	Handler1() : Base{ 1 }
	{
	}

	void handle( int request ) const override
	{
		if ( canHandle( request ) )
		{
			std::cout << "Handler1 can handle request\n\n";
		}
		else
		{
			std::cout << "Handler1 cannot handle request\n";
			if ( next != nullptr )
			{
				next->handle( request );
			}
		}
	}
};

class Handler2 : public Base
{
public:
	Handler2() : Base{ 2 }
	{
	}

	void handle( int request ) const override
	{
		if ( canHandle( request ) )
		{
			std::cout << "Handler2 can handle request\n\n";
		}
		else
		{
			std::cout << "Handler2 cannot handle request\n";
			if ( next != nullptr )
			{
				next->handle( request );
			}
		}
	}
};

class Handler3 : public Base
{
public:
	Handler3() : Base{ 3 }
	{
	}

	void handle( int request ) const override
	{
		if ( canHandle( request ) )
		{
			std::cout << "Handler3 can handle request\n\n";
		}
		else
		{
			std::cout << "Handler3 cannot handle request\n";
			if ( next != nullptr )
			{
				next->handle( request );
			}
		}
	}
};

//========================================================
int main()
{
	Base* b1 = new Handler1();
	Base* b2 = new Handler2();
	Base* b3 = new Handler3();

	b1->setNext( b2 );
	b2->setNext( b3 );
	b3->setNext( NULL );

	int request = 1;
	b1->handle( request );

	request = 2;
	b1->handle( request );

	request = 3;
	b1->handle( request );

	request = 4;
	b1->handle( request );

	delete b1;
	delete b2;
	delete b3;
}
