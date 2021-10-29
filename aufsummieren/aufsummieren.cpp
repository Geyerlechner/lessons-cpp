#include <iostream>
#include <cassert>
#include <assert.h>

int aufsummierenFor( int x )
{
    int summe = 0;

    for ( auto i = 0; i < x; ++i )
        summe += i + 1;
   
    return summe;
}

int aufsummierenWhile( int x )
{
    int summe = 0;

    while(x > 0){
        summe += x--;
      
    }

    return summe;
}

int aufsummierenRecursion( int x )
{
    if(x == 0) 
       return 0;

    return x + aufsummierenRecursion(x-1);
}

int main()
{

    //assert( aufsummierenFor( 5 ) == 15 );
    //assert( aufsummierenFor( 8 ) == 36 );
    //assert( aufsummierenFor( 10 ) == 55 );
    //
    // assert( aufsummierenWhile( 5 ) == 15 );
    // assert( aufsummierenWhile( 8 ) == 36 );
    // assert( aufsummierenWhile( 10 ) == 55 );

    // assert( aufsummierenRecursion( 5 ) == 15 );
}
