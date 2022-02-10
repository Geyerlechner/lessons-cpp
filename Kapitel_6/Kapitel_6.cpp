#include <iostream>
#include "../std_lib_facilities.h"

double expression();

class Token {
public:	
	char kind;	// Welche Kategorie von Token
	double value; // für Zahlen: ein Wert
	Token(char ch) : kind(ch), value(0) {} // erstelle ein Token aus einem char
	Token(char ch, double val) : kind(ch), value(val) {} // erstelle ein Token aus einem char und einem double
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

Token get_token()    // read a token from cin (not my Code)
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

Token_stream::Token_stream() : full(false), buffer(0) // kein Token im Puffer
{
}

Token Token_stream::get()
{
	if(full){			// gibt es bereits ein fertiges Token?
		full = false;	// Token aus dem Puffer entfernen
		return buffer;
	}

	char ch;	// beachten Sie, das >> Whitespace-Zeichen wie 
	cin >> ch;	// Leerzeichen, Zeilenumbruch, Tabulatorzeichen etc. überspringt
				
	switch(ch){
	case ';': // für "Ausgeben"
	case 'q': // für "Verlassen"
	case '(': case ')': case '-': case '*': case '/': case '%':
	case '+': case '{': case '}':
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

void Token_stream::putback(Token t)
{
	buffer = t;	 // kopiere t in den Puffer
	full = true; // Puffer ist jetzt voll
}

Token_stream ts; //liefert get() und putback() 

// Faktor-Regel; behandelt Zahlen und Klammern ruft, expression() und get_token() auf
double primary()
{
	Token t = get_token();
	switch(t.kind){
	case '(': 
	{	double d = expression();
		t = ts.get();
		if( t.kind != ')' ) error("')' erwartet");
		return d;
	}
	case '8': // wir verwenden '8' zur Repräsentation
		return t.value;
	default:
		error("Faktor erwaret");
	}
}

//Term-Regel; behandelt *, / und % auf
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

// Ausdruck-Regel; behandelt + und - ruft term() und get_token() auf
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
