// == Output ==
// 23  53  98  10  31  
// ABab  CDcd  EFef  GHgh  IJij

//=========================================================
#include <iostream>
#include <vector>

template< typename T >
class Base;

//=========================================================
template< typename T >
class Iterator
{
	typename std::vector< T >::iterator it;
	Base< T >* bptr;

public:
	Iterator( Base< T >* ptr ) : bptr{ ptr }
	{
	}

	void begin()
	{
		it = bptr->vect.begin();
	}

	bool isEnd()
	{
		return ( bptr->vect.end() == it );
	}

	void next()
	{
		++it;
	}

	T value() const
	{
		return *it;
	}
};

//=========================================================
template< typename T >
class Base
{
	std::vector< T > vect;
public:
	void add( T x )
	{
		vect.push_back( x );
	}

	Iterator< T >* getIterator()
	{
		return ( new Iterator< T >( this ) );
	}

	friend class Iterator< T >;
};

//=========================================================
int main()
{
	Base< int > b;
	b.add( 23 );
	b.add( 53 );
	b.add( 98 );
	b.add( 10 );
	b.add( 31 );

	Iterator< int >* it = b.getIterator();

	for( it->begin(); !( it->isEnd() ); it->next() )
	{
		std::cout << it->value() << "  ";
	}
	std::cout << "\n";

	Base< std::string > b2;
	b2.add( "ABab" );
	b2.add( "CDcd" );
	b2.add( "EFef" );
	b2.add( "GHgh" );
	b2.add( "IJij" );

	Iterator< std::string >* it2 = b2.getIterator();

	for( it2->begin(); !( it2->isEnd() ); it2->next() )
	{
		std::cout << it2->value() << "  ";
	}
	std::cout << "\n";
}
