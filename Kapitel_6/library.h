#pragma once

// My Code

class Token {
public:	
	char kind;	// Welche Kategorie von Token
	double value; // für Zahlen: ein Wert
	Token(char ch) : kind(ch), value(0) {} // erstelle ein Token aus einem char
	Token(char ch, double val) : kind(ch), value(val) {} // erstelle ein Token aus einem char und einem double
};

// ---------------------------------------------------------------------------------------------------------------//

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

class Token_stream {
public:
    Token get();                // get a Token
    void putback(Token t);      // put a token back
private:
    bool full { false };        // is there a Token in the buffer?
    Token buffer {'0'};         // here is where putback() stores a Token
};

void Token_stream::putback(Token t)
{
    buffer = t;                 // copy t to buffer
    full = true;                // buffer is now full
};


Token Token_stream::get()
    // ex 2 - added '{' & '}'
    // ex 3 - added '!'
{
    if (full) {             // do we already have a Token?
        full = false;       // remove Token from buffer
        return buffer;
    }

    char ch;
    cin >> ch;              // note that >> skips whitespace

    switch (ch) {
        case ';':           // for "print"
        case 'q':           // for "quit"
        case '(': case ')': case '{': case '}': case '!':
        case '+': case '-': case '*': case '/':
            return Token { ch };
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            {
                cin.putback(ch);    // put digit back into input stream
                double val;
                cin >> val;
                return Token { '8', val };  // let '8' represent a number
            }
        default:
            error("Bad token");
    }
};

Token_stream ts;            // provides get() and putback()