#include <iostream>
#include <vector>
#include <ranges>

int main()
{
	std::vector< int > v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for( std::size_t i = 0; i < v.size(); ++i )
		std::cout << v[ i ];
	std::cout << std::endl;

	for( std::vector< int >::iterator iter = v.begin(); iter != v.end(); ++iter )
		std::cout << *iter;
	std::cout << std::endl;

	for( std::vector< int >::reverse_iterator iter = v.rbegin(); iter != v.rend(); ++iter )
		std::cout << *iter;
	std::cout << std::endl;

	for( auto value : v )
		std::cout << value;
	std::cout << std::endl;

	for( auto value : std::ranges::reverse_view( v ) )
		std::cout << value;
	std::cout << std::endl;
}
