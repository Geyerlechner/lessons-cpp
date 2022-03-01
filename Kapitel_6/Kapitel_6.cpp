#include <iostream>
#include "../std_lib_facilities.h"

double expression();
double primary();
double get_value(string s);
double term();

const char quit = 'q';  //t.kind == quit bedeutet, dass t ein Verlassen-Token ist
const char print = ';'; //t.kind == print bedeutet, dass t ein Ausgeben-Token ist
const char let = 'L';  // Deklaration-Token
const string declkey = "let"; // Schlüsselwort für Deklaration
const char name = 'a'; // Name-Token
const string prompt = "> "; // prompt anzeige
const string result = "= "; //zeigt an, dass danach ein Ergebnis folgt

struct Token {
	char kind;		// Welche Kategorie von Token
	double value;	// für Zahlen: ein Wert
	string name;
	Token(char ch) : kind(ch), value(0) {} // erstelle ein Token aus einem char
	Token(char ch, double val) : kind(ch), value(val) {} // erstelle ein Token aus einem char und einem double
	Token(char ch, string n) :kind(ch), name(n) {}
};

class Token_stream {
public:
	Token_stream();			// erstelle einen Token_stream, der aus cin liest
	Token get();			// lies ein Token ein (get() ist anderswo definiert)
	void putback(Token t);  // lege ein Token zurück
	void ignore(char c);	// verwirf Zeichen bis und einschließlich des nächsten Vorkommens von C
private: 
	bool full;				// befindet sich ein Token im Puffer?
	Token buffer;			// hier legen wir ein Token ab, das mit putback() zurückgestellt wurde
};

class Variablen {

public: 
	string name;
	double value;
	Variablen(string n, double v) :name(n), value(v){ }
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

	break;
    default:
        error("Bad token");
    }
}

Token_stream::Token_stream() : full(false), buffer(0) // kein Token im Puffer
{
}

Token Token_stream::get()
{
	// gibt es bereits ein fertiges Token?
	// Token aus dem Puffer entfernen
	if(full){ full = false; return buffer; }
	char ch;	// beachten Sie, das >> Whitespace-Zeichen wie 
	cin >> ch;	// Leerzeichen, Zeilenumbruch, Tabulatorzeichen etc. überspringt
	const char number = '8';

	switch(ch){
	case print: // für "Ausgeben"
	case quit:	// für "Verlassen"
	case '!':	// für "Fakulätsoperator
	case ',':
	case '(': 
	case ')': 
	case '-': 
	case '*': 
	case '/': 
	case '%':
	case '+':
	case '{': 
	case 's': //sqrt
	case 'p': //pow
	case '}':
		return Token(ch);	// jedes Zeichen repräsentiert sich selbst
	case '.':
	case '0': 
	case '1': 
	case '2': 
	case '3': 
	case '4':
	case '5': 
	case '6': 
	case '7': 
	case '8':
	case '9':
	{
		cin.putback(ch); // lege die Ziffer zurück in den Eigabestream
		double val;
		cin >> val;
		return Token(number, val); // '8' repräsentiert "eine Zahl"
	}
	default:
		if( isalpha(ch) ){
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
			cin.unget();
			if( s == declkey ) return Token(let); // Schlüsselwort für Deklarationen
			return Token(name,s);
		}
		error("Ungueltiges Token \n");
	}
}

void Token_stream::ignore(char c)
{
	// c repräsentiert die gesuchte Token-Kategorie

	//erster Blick in den Puffer
	if(full && c == buffer.kind)
	{ full = false;
		return;
	}
	full = false;

	//jetzt die Eingabe durchsuchen:
	char ch = 0;
	while(cin >> ch) if(ch == c ) return;
}

vector<Variablen> var_table;

void Token_stream::putback(Token t)
{
	buffer = t;	 // kopiere t in den Puffer
	full = true; // Puffer ist jetzt voll
}

Token_stream ts; //liefert get() und putback() 

// Faktor-Regel; behandelt Zahlen und Klammern ruft, expression() und get_token() auf
double primary()
{
	Token t = ts.get();
	const char number = '8';
	switch(t.kind){
	case '(': 
	{	double d = expression();
		t = ts.get();
		if( t.kind != ')' ) error("')' erwartet");
		return d;
	}
	case ',': return primary();
	case '-':
		return - primary();
	case '+':
		return primary();
	case 's': {
		double d = primary();
		
		if(d <= 0){ cout << "Negativ"; return 0; } 
		else{ return sqrt(d); }
	}
	break;
	case 'p':
	{
		//double i1 = narrow_cast<double>(left);
		//double i2 = narrow_cast<double>(term());
		double d = expression();
		cout << " T: " << d << endl;
		cout << "P: " << primary(); 
		return pow(primary(), d);
	}	
	break;
	case number: // wir verwenden '8' zur Repräsentation
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("Primary erwaret");
	}
}

bool is_declared(string var) // ist var bereits in var_table?
{
	for (int i = 0; i < var_table.size(); i++)
		if(var_table[i].name == var) return true;
	return false;
}

double define_name(string var, double val)
{
	if(is_declared(var)) error(var, " doppelt deklariet");
	var_table.push_back(Variablen(var, val));
	return val;
}

double declaration() // angenommen, wir haben "let" gesehen, behandle: name = ausdruck, deklariere ein Variable names "name" mit dem Anfangswert "ausdruck"
{
	Token t = ts.get();
	if(t.kind != name) error("die Deklaration erwartet einen Namen");
	string var_name = t.name;

	Token t2 = ts.get();
	if(t2.kind != '=') error("= fehlt in der Deklaration von ", var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch(t.kind){
	case let:
		return declaration();
	default:
		ts.putback(t);
	return expression();
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
		case 'p':
		{
			int i1 = narrow_cast<int>(left);
			int i2 = narrow_cast<int>(term());
			return pow(i1, i2);
		}
		break;
		case ',': 
		{	double d = primary();
			//cout << "Left " << left << endl;
			//cout << "P: " << primary() << endl;
			
			t = ts.get();
		}
		break;

		case '!':
		{
			int lval = left;
			for (int i = left - 1; i > 0; i--) lval = lval * i;		
			cout << lval;
			return lval;
		}
			
			return 1;
		break;

		case '%':
		{ 
			int i1 = narrow_cast<int>(left);
			int i2 = narrow_cast<int>(term());
			if(i2 == 0) error("%: Division durch null");
			return i1 % i2;
			t = ts.get();
		 break;
		}	
		default: 
			ts.putback(t); // lege t zurück in Token-Stream	
			return left;
		}
	}
}


double get_value(string s) // liefet den Wert der Variablen mit dem Namen zurück
{
	for (int i = 0; i < var_table.size(); i++)
		if(var_table[i].name == s) return var_table[i].value;
	error("get: nicht definierte Variable ", s);
}

void set_value(string s, double d) // weist der Variablen mit dem Namen s den Wert d zu
{
	for (int i = 0; i < var_table.size(); i++)
	{
		if(var_table[i].name == s){
			var_table[i].value = d;
		return;	
		}
	}
	error("set: nicht definierte Variable ", s);
}

// Ausdruck-Regel; behandelt + und - ruft term() und get_token() auf
double expression()
{
	double left = term(); // lies einen Term und werte ihn aus
	Token t = ts.get(); // lies das nächste Token ein

	while(true){
		switch(t.kind){		// stelle fest, welcher Art das Token ist
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


void clean_up_mess()
{
	ts.ignore(print);
}

void calculate() // Schleife zur Auswertung der Ausdrücke
{
	while(cin){
		try {
			cout << prompt;
			Token t = ts.get();

			while(t.kind == print) t = ts.get();
			if(t.kind == quit) return;
			ts.putback(t);
			cout << result << statement() << endl;
		}catch(exception &e)
		{
			cerr << e.what() << endl; // Fehlermeldung ausgeben
			clean_up_mess();
		}
	}
}

int main()
{

	try {
	   //Name vordefinieren:
//	   define_name("pi", 3.1415926535);
//	   define_name("e", 2.7182818284);
	   calculate();
	   keep_window_open();
	   return 0;
	}
	catch(exception &e){
	
		cerr << e.what() << endl;
		keep_window_open("~~");
		return 1;
	}
	catch(...){
		cerr << "Ausnahme \n";
		keep_window_open("~~");
		return 2;	
	}
}
