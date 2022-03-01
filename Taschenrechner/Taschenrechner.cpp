#include <iostream>
#include "../std_lib_facilities.h"

double expression();


// Funktionen, die den Grammatikregeln entsprechen:
class Token {
public:
	char kind;
	double value;
	Token(char ch) : kind(ch), value(0) {}	// initialisiere t1 so, dass t1.kind = '+'
	Token(char ch, double val) : kind(ch), value(val) {} // initialisiere t2 so, dass t2.kind = '8'
};

class Token_Stream {
public:
	Token_Stream();	// erstelle einen Token_stream, der aus cin liest
	Token get();	// lies ein Token ein
	void putback(Token t); // lege ein Token zur�ck
private:
	bool full; // befindet sich ein Token im Puffer?
	Token buffer; // hier legen wir ein Token ab, das mit putback() zur�ckgestellt wurde
};

Token_Stream::Token_Stream() : full(false), buffer(0) // kein Token im Puffer
{	
}

void Token_Stream::putback(Token t)
{
	if(full) error("putback(): Zurueckstellen nicht mieglich, Puffer voll");
	buffer = t; //kopiere t in den Puffer
	full = true; // Puffer ist jetzt voll
}

Token Token_Stream::get()
{
	if(full) { // gibt es bereits ein fertiges Token?
			   // Token aus dem Puffer entfernen
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch)
	{
	case ';': // f�r "Ausgeben"
	case 'q': // f�r "Verlassen"
	case '(': case ')': case '+': case '-': case '*': case '/': case '%':
		return Token(ch); // jedes Zeichen repr�sentiert sich selbst
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch); // lege die Ziffer zur�ck in den Eingabestream
		double val; 
		cin >> val; // lies ein Gleitkommerzahl
		return Token('8', val); // '8' rep�sentiert "eine Zahl"
	}
	default:
		error("Ungueltiges Token");
	}
}

Token_Stream ts;
 
// liest Zeichen ein und zerlegt sie in Token verwendet cin
Token get_token()    // read a token from cin
{
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
 //not yet   case ';':    // for "print"
 //not yet   case 'q':    // for "quit"
	case ';':
	case 'q':
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

// Faktor-Regel; behandelt Zahlen und Klammern ruft expression() und get_token() auf
double primary()
{
	Token t = ts.get();
	
	switch(t.kind){
	case '(': //behandle '(' Ausdruck ')'
	{
		double d = expression();
		t = ts.get();
		if(t.kind != ')') error("erwartet");
		return d;
	}
	case '8': 
		return t.value;
	default:
		error("Faktor erwaret");

	}
}

// Term-Regel behandelt *, / und % ruft primary() und get_token() auf
double term()
{
	double left = primary();
	Token t = ts.get();

	while(true){
		switch (t.kind){
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
		default:
			ts.putback(t); // stelle t wieder zur�ck in den Token-Stream
			return left;
		}
	}
}

// Ausdruck-Regel; behandelt + und - ruft term() und get_token() auf
double expression()
{
	double left = term(); //lies einen Term und werte ihn aus
	Token t = ts.get(); // liest das n�chste Token aus dem Token-Stream ein
	
	while(true){
	 switch (t.kind)
	 {
	 case '+':
	 	left += term(); // werte Term aus und addiere
		t = ts.get();
		break;
	 case '-':
	 	left -= term(); // werte Temr aus und subtahiere
		t = ts.get();
		break;
 	 default:
		 ts.putback(t);
	 	return left; // Ende: kein weiteren + oder -; Antwort zur�ckliefern
	 }
	}
	
}

int main()
{
	double val = 0;
	try {
		
		while(cin){
		
			Token t = ts.get();

			if(t.kind == 'q') break; // 'q' f�r verlassen
			if(t.kind == ';') // ';' f�r "jetzt ausgeben"
				cout  << "=" << val << '\n';
			else 
				ts.putback(t);
			val = expression();
		}

		keep_window_open();
	
	}catch (exception &e)
	{
		cerr << e.what() << endl;
		keep_window_open();
		return 1;
	}catch(...){
		cerr << "Ausnahme \n";
		keep_window_open();
		return 2;
	}



	//int lval = 0;
	//int rval = 0;
	//char op;
	//cin >> lval;
	//cin >> rval;

	//	Token t1('8', lval);
	//	Token t2('+');
	//	Token t3('8', rval);

		// rVal = 7 + rVal2
		//rVal2 = 9
	


	//for (int i = 0; i < tok.size(); i++)
	//{
	//	if(tok[i].kind == '*'){
	//		cout << tok[i-1].value * tok[i+1].value;
	//		cout << endl;
	//	}
	//	
	//	if(tok[i].kind == '+'){
	//		cout << tok[i-1].value + tok[i+1].value;
	//		cout << endl;
	//	}
	//
	//	if(tok[i].kind == '/'){
	//		cout << tok[i-1].value / tok[i+1].value;
	//		cout << endl;
	//	}
	//	
	//}


	//system("pause");
	//cout << "Geben Sie bitte einen Ausdruck ein (wir unterstuetzen +, -, * und /) \n";
	//cout << "Ausdruck mit x beenden (z.B. 1+2*3x) \n";

	//cin >> lval;

	//if(!cin) error("kein erster Operand");

	//while(cin >> op) {
	// if(op != 'x') cin >> rval;
	// if(!cin) error("kein zweiter Operand");

	//switch(op){
	// case '+':
	//	 lval += rval;
	//	 break;
	// case '-':
	//	 lval -= rval;
	//	 break;
	// case '*':
	//	 lval *= rval;
	//	 break;
	// case '/':
	//	 lval /= rval;
	//	break;
	// default:
	//	 cout << "Ergebnis: " << lval << '\n';
	//	 keep_window_open();
	// }

	//}
	//error("ungueltiger Ausdruck");
}