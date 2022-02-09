#include <iostream>
#include "../std_lib_facilities.h"

int main()
{
	cout << "Geben Sie bitte einen Ausdruck ein (wir unterstuetzen + und -): ";
	int lval = 0;
	int rval = 0;
	char op;
	int res;

	cin >> lval >> op >> rval;

	if( op == '+' )
		res = lval + rval;  // Addition
	else if( op == '-' ) 
		res = lval - rval; // Subtraktion

	cout << "Ergebnis: " << res << '\n';

	keep_window_open();

}
