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
	Token get();			// lies ein TOken ein (get() ist anderswo definiert)
	void putback(Token t);  // lege ein Token zurück
private: 
	bool full;				// befindet sich ein Token im Puffer?
	Token buffer;			// hier legen wir ein Token ab, das mit putback() zurückgestellt wurde
};


void Token_stream::putback(Token t)
{
	buffer = t;	 // kopiere t in den Puffer
	full = true; // Puffer ist jetzt voll
}

Token Token_stream::get()
{
	if(full){  // gibt es bereits ein fertiges Token?
			   // Token aus dem Puffer entfernen
		full = false;
		return buffer;
	
	}

	char ch;
	ch >> ch;	// beachten Sie, das >> Whitespace-Zeichen wie 
				// Leerzeichen, Zeilenumbruch, Tabulatorzeichen etc. überspringt

	switch(ch){
	case ';': // für "Ausgeben"
	case 'q': // für "Verlassen"
	case '(': case ')': case '-': case '*': case '/': case '%':
		return Token(ch);	// jedes Zeichen repräsentiert sich selbst
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch); // lege die Ziffer zurück in den Eigabestream
		double val;
		cin >> val;
		return Token('8', val); // '8' repräsentiert "eine Zahl"
	}
	default:
		error("Ungueltiges Token");
	}

}


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
