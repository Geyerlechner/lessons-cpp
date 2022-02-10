#include <iostream>
#include "../std_lib_facilities.h"

// get_token() // liest Zeichen ein und zerlegt sie in Token
// expression() // Ausdruck-Regel; behandelt + und - ruft term() und get_token() auf
// term() //Term-Regel; behandelt *, / und % auf
// primary() // Faktor-Regel; behandelt Zahlen und Klammern ruft, expression() und get_token() auf

double expression();

class Token {
public:	
	char kind;	// Welche Kategorie von Token
	double value; // für Zahlen: ein Wert
	Token(char ch) : kind(ch), value(0) {} // erstelle ein Token aus einem char
	Token(char ch, double val) : kind(ch), value(val) {} // erstelle ein Token aus einem char und einem double
};

Token get_token()    // read a token from cin
{
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
 //not yet   case ';':    // for "print"
 //not yet   case 'q':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/': 
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}

double primary()
{
	Token t = get_token();
	switch(t.kind){
	case '(': 
	{	double d = expression();
		t = get_token();
		if( t.kind != ')' ) error("')' erwartet");
		return d;
		
	}
	case '8': // wir verwenden '8' zur Repräsentation
		return t.value;
	default:
		error("Faktor erwaret");
	}
}

double term()
{
	double left = primary();
	Token t = get_token();
	while(true){
		switch(t.kind){
		case '*':
			left *= primary();
			t = get_token();
		break;
		case '/':
		{
			double d = primary();
			if(d == 0) error("Division durch null");
			left /= d;
			t = get_token();
			break;
		}
		break;

		default: return left;
		}
	}
}

double expression()
{
	double left = term(); // lies einen Term und werte ihn aus
	Token t = get_token();		// lies das nächste Token ein

	switch(t.kind){				// stelle fest, welcher Art das Token ist
	case '+': 
		left += term(); // werte Term aus und addiere
		t = get_token();
		break;
	case '-': 
		left -= term(); // werte Term aus und subtrahiere
		t = get_token();
		break;
	default: return left;			 // liefere den Wert des Ausdrucks zurück 
	}
}


int main()
{

	try {
		while(cin)
			cout << "=" << expression() << '\n';
		keep_window_open();

	}
	catch(exception &e){
		cerr << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch(...){
		cerr << "Ausnahme \n";
		keep_window_open();
		return 2;
	}

}
