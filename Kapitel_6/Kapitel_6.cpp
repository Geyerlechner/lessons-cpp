#include <iostream>
#include "../std_lib_facilities.h"



class Token {
public:	
	char kind;	// Welche Kategorie von Token
	double value; // f�r Zahlen: ein Wert
	Token(char ch) : kind(ch), value(0) {} // erstelle ein Token aus einem char
	Token(char ch, double val) : kind(ch), value(val) {} // erstelle ein Token aus einem char und einem double
};

// get_token() // liest Zeichen ein und zerlegt sie in Token
// expression() // Ausdruck-Regel; behandelt + und - ruft term() und get_token() auf
// term() //Term-Regel; behandelt *, / und % auf
// primary() // Faktor-Regel; behandelt Zahlen und Klammern ruft, expression() und get_token() auf


int main()
{

	//cout << "Geben Sie bitte einen Ausdruck ein (wir unterstuetzen +, -, * und /):";
	//int lval = 0;
	//int rval;
	//char op;
	//cin >> lval;
	//
	//if(!cin) error("Kein erster Operand");
	//
	//while( cin>>op ){
	//
	//	if(op != 'x') cin>>rval;
	//	if(!cin) error("kein zweiter Operand");
	//
	//	switch(op){
	//	case '+':
	//		lval += rval;
	//		break;
	//	case '-':
	//		lval -= rval;
	//		break;
	//	case '*':
	//		lval *= rval;
	//		break;
	//	case '/':
	//		lval /= rval;
	//		break;
	//	default: 
	//		cout << "Ergebnis: " << lval << '\n';
	//		keep_window_open();
	//		return 0;
	//	}
	//}
	//
	//error("ungueltiger Ausdruck");

}
