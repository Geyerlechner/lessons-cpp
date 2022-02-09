#include <iostream>
#include "../std_lib_facilities.h"

int main()
{
	cout << "Geben Sie bitte einen Ausdruck ein (wir unterstuetzen +, -, * und /):";
	int lval = 0;
	int rval;
	char op;
	cin >> lval;
	
	if(!cin) error("Kein erster Operand");

	while( cin>>op ){
	
		if(op != 'x') cin>>rval;
		if(!cin) error("kein zweiter Operand");

		switch(op){
		case '+':
			lval += rval;
			break;
		case '-':
			lval -= rval;
			break;
		case '*':
			lval *= rval;
			break;
		case '/':
			lval /= rval;
			break;
		default: 
			cout << "Ergebnis: " << lval << '\n';
			keep_window_open();
			return 0;
		}
	}

	error("ungueltiger Ausdruck");

}
