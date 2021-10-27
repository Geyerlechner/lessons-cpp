#include <iostream>
#include <cassert>
#include <assert.h>

int aufsummierenFor( int x )
{
    int left = 0;
    int right = 0;

   // 1 2 3 4 5
   // 1 3 6 10 15
    for ( auto i = 0; i < x; i++ )
    {   
        right = (left + right + 1);
        left = (left + 1);
        std::cout << right << " | ";
    }
    std::cout << std::endl;
    return right;
}
int aufsummierenWhile( int x )
{
    return 0;
}

int aufsummierenRecursion( int x )
{
    if(x == 0) 
       return 0;

    return x + aufsummierenRecursion(x-1);
}

int main()
{
    // aufsummierenFor( 5 ); 
   // int links = 0;
   // int rechts = 0;
   // int summe;

   //// 1 2 3 4 5
   //// 3 6 10 15
   // for ( auto i = 0; i < 5; i++ )
   // {   
   //     rechts = (links + rechts + 1);
   //     links = (links + 1);
   //     summe = links + rechts;
   // }
   //    std::cout << "Summe: " <<  rechts;

   // aufsummierenFor(5);
  
    assert( aufsummierenFor( 5 ) == 15 );
    assert( aufsummierenFor( 8 ) == 36 );
    assert( aufsummierenFor( 10 ) == 55 );
    //assert( aufsummierenWhile( 5 ) == 15 );
    //assert( aufsummierenRecursion( 5 ) == 15 );
}
