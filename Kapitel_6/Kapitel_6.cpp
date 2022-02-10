#include <iostream>
#include "../std_lib_facilities.h"
#include "library.h"

// get_token() // liest Zeichen ein und zerlegt sie in Token

double expression();

Token_stream::Token_stream() : full(false), buffer(0) // kein Token im Puffer
{
}

class Token_stream {
public: 
	Token_stream();			// erstelle einen Token_stream, der aus cin liest
	Token get();			// lies ein TOken ein
	void putback(Token t);  // lege ein Token zurück
private: 

};

class Token_stream {
public:
	Token_stream();			// erstelle einen Token_stream, der aus cin liest
	Token get();			// lies ein TOken ein (get() ist anderswo definiert)
	void putback(Token t);  // lege ein Token zurück
private: 
	bool full;				// befindet sich ein Token im Puffer?
	Token buffer;			// hier legen wir ein Token ab, das mit putback() zurückgestellt wurde
};


// primary() // Faktor-Regel; behandelt Zahlen und Klammern ruft, expression() und get_token() auf
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

// term() //Term-Regel; behandelt *, / und % auf
double term()
{
	double left = primary();
	Token t = ts.get(); // lies das nächste Token aus dem Token-Stream ein
	while(true){
		switch(t.kind){
		case '*':
			left *= primary();
			t = ts.get();
		break;
		case '/':
		{
			double d = primary();
			if(d == 0) error("Division durch null");
			left /= d;
			t = ts.get();
			break;
		}
		break;

		default: 
			ts.putback(t); // stelle t wieder zurück in den Token-Stream	
			return left;
		}
	}
}

// expression() // Ausdruck-Regel; behandelt + und - ruft term() und get_token() auf
double expression()
{
	double left = term(); // lies einen Term und werte ihn aus
	Token t = ts.get(); // lies das nächste Token ein

	while(true){
	
		switch(t.kind){				// stelle fest, welcher Art das Token ist
		case '+': 
			left += term(); // werte Term aus und addiere
			t = ts.get();
			break;
		case '-': 
			left -= term(); // werte Term aus und subtrahiere
			t = ts.get();
			break;
		default: 
			ts.putback(t);	// stelle t wieder zurück in den Token-Stream	
			return left;	// liefere den Wert des Ausdrucks zurück 
		}	
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
