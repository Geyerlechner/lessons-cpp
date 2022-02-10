#include <iostream>
#include "std_lib_facilities.h"
#include <vector>
class Bad_area {}; //Typ, der speziell für das Melden von Fehlern aus area() definiert wurde

int area(int length, int width)
{
	if(length <= 0 || width <= 0) throw Bad_area();

	return length * width;
}

int framed_area(int x, int y) // berechnet die Fläche innerhalb eines Rahmens
{
	const int frame_width = 2;
	if( x-frame_width <= 0 || y-frame_width <= 0 )
		error("area()-Argument in framed_area() ist nicht positiv");
		
	return area(x-frame_width, y-frame_width);
}

void lesson_1()
{

	//Typefehler
	// int x0 = arena(7); //Fehler: nicht deklariete Funktion
	// int x1 = area(7); // Fehler: falsche Anzahl an Argumenten
	// int x2 = area("seven", 2); // Fehler: erstes Argument hat den falschen Typ
	int x = 2;
	int y = 3;
	int z = 2;

	if( x <= 0 || y <= 0 ) error("area()-Argument ist nicht positiv");
	int area1 = area( x, y );
	
	if( z <= 2 )
		error("area()-Argument ist nicht positiv");
	int area2 = framed_area( 1, z );
	
	if( y <= 2 || z <= 2 )
		error("area()-Argument ist nicht positiv");
	int area3 = framed_area( y, z );

}

void lesson_2()
{

	int x = 0;
	int y = 0;
		
	std::cout << "Geben Sie 2 werte ein! X & Y  \nGeben Sie einen wert fuer x ein: " ;
	std::cin >> x;
	std::cout << "Geben Sie einen wert fuer y ein: ";
	std::cin >> y;

	if( x == 0 ){
		std::cout << "Es wurde kein wert fuer x eingeben!";
	}else if ( y == 0 )
	{
		std::cout << "Es wurde kein wert fuer y eingeben!";
	}

}


void tryCatch()
{
	try {
	
		int x = -1;
		int y = 2;
		int z = 4;

		int area1 = area( x, y );
		int area2 = framed_area( 1, z );
		int area3 = framed_area( y, z );
		double ratio = area1/area3;

	}
	catch(Bad_area){
		std::cout << "Hoppla! Ungueltige Argumente fuer area()\n";
	}

}

//class out_of_range {};
//
//	vector<int> v; // ein Vektor für ganze Zahlen
//	int i;
//
//	while (cin>>i) v.push_back(i);		// lies Werte ein
//	for (int i = 0; i <= v.size(); i++) {	// gibt Werte aus
//		std::cout << "v[" << i <<"] == " << v[i] << std::endl; 
//	}
//	catch(out_of_range)
//	{
//		cerr << "Hoppla! Bereichsfehler\n";
//		return 1;
//	}catch(...)
//	{
//		cerr << "Ausnahme: irgendetwas ist schiefgelaufen\n";
//		return 2;
//	}
	

void error(string s1, string s2)
{
	throw runtime_error(s1 + s2);
}


int lesson3()
{
	try {
		int x1  = narrow_cast<int>(2.9); // wirft eine Ausnahme
		int x2  = narrow_cast<int>(2.0); // O.K.
		char c1 = narrow_cast<int>(1066); // wirft eine Ausnahme
		char c2 = narrow_cast<int>(85); // O.K.
		return 0;
	}
	catch( runtime_error& e ){
		cerr << "laufzeitfehler:" << e.what() << "\n";
		keep_window_open();
		return 1;
	}
	catch(...)
	{
		cerr << "hoppla! unbekannte ausnahne!\n";
		keep_window_open();
		return 2; // 2 steht für "fehlgeschlagen"
	}
}
#define SUCCESS "[4] Erfolg!\n"

int lesson4()
{

	try 
	{	
		cout << "[1] Erfolg!\n";
		cout << "[2] Erfolg!\n";
		cout << "[3] Erfolg" << "!\n";
		cout << SUCCESS;
		int res = 7; vector<int> v(10); v[5] = res; cout << "[5] Erfolg!\n";
		v[5] = 7; if(v[5] == 7) cout << "[6] Erfolg!\n";
		if( true ) cout << "[7] Erfolg!\n"; else cout << "Fehlschlag!\n";
		bool c = true; if( c ) cout << "[8] Erfolg!\n"; else cout << "Fehlschlag!\n";
		string s = "Affe"; bool cs = "Narr" > s; if(cs) cout << "[9] Erfolg!\n";
		if(s != "Narr")  cout << "[10] Erfolg!\n";
		if(s != "Narr") cout << "[11] Erfolg!\n";
		if("Affe") cout << "[12] Erfolg!\n";
		vector<char> v5(1); for (int i = 0; i < v5.size(); i++) cout << "[13] Erfolg!\n";
		for (int i = 1; i <= v5.size(); i++) cout << "[14] Erfolg!\n";
		s = "[15] Erfolg!\n"; for (int i = 0; i < 14; i++) cout << s[i];
		if(true) cout << "[16] Erfolg!\n"; else cout << "Fehlschlag!\n";
		int x = 2000; int c1 = x; if(c1 == 2000) cout << "[17] Erfolg!\n"; 
		s = "[18] Erfolg!\n"; for (int i = 0; i < 14; i++) cout << s[i];
		vector<int> v1(0); for (int i = 0; i <= v1.size(); i++) cout << "[19] Erfolg!\n"; 
		int i = 0; int j = 0; while(i<10) ++i; if(j<i) cout << "[20] Erfolg!\n"; 
		double x1 = 2; double d = 5 /(x1/2); if( d == 2 *(x1 + 0.5) ) cout << "[21] Erfolg!\n"; 
		// char str[14] = "[22] Erfolg!\n"; for (int i = 0; i < 14; i++) cout << str[i];
		std::basic_string< char > basic_string = "[22] Erfolg!\n"; for (int i = 0; i < basic_string.size(); i++) cout << basic_string[i];
		while(i<10) ++i; if(j<i) cout << "[23] Erfolg!\n";
		double xx = 4; double dd = 5 /( xx - 2 ); if( dd == 2 + 0.5 ) cout << "[24] Erfolg!\n";
		cout << "[25] Erfolg!\n";

		keep_window_open();
	}
	catch( exception& e )
	{
		std::cerr << "Hoppla: unbekannte Ausnahme!\n" << e.what();
		keep_window_open();
	}
	catch (...)
	{
		std::cerr << "Hoppla: unbekannte Ausnahme!\n";
		keep_window_open();
		return 2;
	}

	return 0;
}

void lesson5()
{
	double sum = 0;
	double high_temp = 0;
	double low_temp = 0;
	
	vector<double> value1 { -16.5, -23.2, -24.0, -25.7, -26.1, -18.6, -9.7, -2.4,
								7.5, 12.6, 23.8, 25.3, 28.0, 34.8, 36.7, 41.5, 
								40.3, 42.6, 39.7, 35.4, 12.6, 6.5, -3.7, -14.3 };

	vector<double> value2 { 76.5, 73.5, 71.0, 73.6, 70.1, 73.5, 70.1, 73.5, 77.6, 85.3, 
								 88.5, 91.7, 95.9, 99.2, 99.2, 98.2, 100.6, 106.3, 112.4, 
								 110.2, 103.6, 94.9, 91.7, 88.4, 85.2, 85.4, 87.7 }; 
	
    for (double x : value2)
    {
        if (high_temp == 0 && low_temp == 0) {
            high_temp = x;
            low_temp = x;
        }

        if (x > high_temp) high_temp = x;   // find high
        if (x < low_temp) low_temp = x;     // find low
        sum += x;
    }

	std::cout << "Hoechste Temperatur: " << high_temp << std::endl;
	std::cout << "Niedrigste Temperatur: " << low_temp << std::endl;
	std::cout << "Durschnittstemperatur:" << sum / value2.size() << std::endl;
}

double ctok(double c, int convert)
{
	if( c < -273.15) 
	{
		cout << "Achtung: Der absolute Nullpunkt wurde erreicht!"; 
		return 0; 
	}

	switch(convert){
	case 1:
		return c + 273.15;
		break;
	case 2:
		return c - 273.15;
		break;
	case 3:
		return (c * 9/5) + 32;
		break;
	default:
		cout << "Keine richtige eingabe";
	}

	return 0;
}

void lesson6()
{
	double c = 0;
	double d = 0;
	int e = 0;
	std::string output;

	cin >> d;
	cin >> e;

	double k = ctok(d, e);

	if( typeid(k).name() != "int") cout << k << " ist kein Integer" << endl;
	
	switch(e)
	{
	case 1:
		output = " K";
		break;
	case 2:
		output = " C";
		break;		
	case 3:
		output = " F";
		break;
	}
	
	
	cout << k << output << endl;
}

void lesson7()
{
	vector<double> iValues;
	vector<double> dValues;

	double number = 0;
	double value = 0;

	cout << "1 Eingabe: ";
	while(std::cin >> number)
	{
		if(number == 0000)
			break;
	
		iValues.push_back(number);
		
		cout << "2 Eingabe: ";
		cin>> number;
		dValues.push_back(number);
		
		cout << "---------------------------------\n";
		cout << "1 Eingabe: ";
	}

	cout << endl;
	cout << "Wie viele Zahlen sollen aufaddiert werden? ";
	cin >> number;

	if(number <= iValues.size() )
	{
		for (int i = 0; i < number; i++)
			cout << "Differenz: " << iValues[i] - dValues[i] << endl;
	}else
	{
		cout << "Es wurden max " << iValues.size() << " Zahlen eingegeben!" << endl;	
	}

	keep_window_open();
}

void lesson8()
{
    int summe = 0;
	int i = 0;

	// 2147450879
	for(;;)
	{	i++;
        summe += i + 1;

		if(summe < 0)
			break;

		cout << summe << endl;
	}

}

void lesson9()
{
	vector<int> value;
	vector<int>::iterator it;
	vector<int> userValue;
	
	int i = 0;
	int generatorNumber;
	int userInput = 0;
	int bull = 0;
	int cows = 0;

	cout << "Geben Sie 4 Zufallszahlen ein!\n";
	for (int i = 1; i < 5; i++)
	{
		cout << i << " Eingabe: "; 
		std::cin >> generatorNumber;
		srand(generatorNumber);
		value.push_back(randint(10));
	}

	system("cls");
	cout << "Ratespiel Bulls and Cows\n";
	cout << "-------------------------\n";
	
	for (int i = 1; i < 5; i++)
	{
		cout << i << " Eingabe: ";
		cin >> userInput;
		userValue.push_back(userInput);
	}

	for(auto animal : userValue)
	{	
		if( value[i++] == animal ) 
		{
			bull++;
		}
		else
		{
		  it = find (value.begin(), value.end(), animal); 
		  if (it != value.end()) cows++;
		}
	}

	cout << "-------------------------\n";
	
	cout << "Geheimzahlen: ";
	for(auto secretNumber : value)
		cout << secretNumber << " ";
	

	cout << "\n-------------------------\n";
	cout << "Win Bulls: " << bull << endl; 
	cout << "Win Cows: " << cows << endl; 
	
	keep_window_open();
	system("cls");
	lesson9();
}

void findWeek(vector<string> &v, vector<int> *number, string &day, int &dayNum)
{
	for(auto var : v)
		if( day == var  ) number->push_back(dayNum);
}


std::string str_tolower(std::string s) {

    std::transform(s.begin(), s.end(), s.begin(), 
		[](unsigned char c){ return std::tolower(c); } );
    
	return s;
}

void lesson10()
{
	vector<string> Sunday	 = { "Sonntag", "sonntag", "So", "so"		};
	vector<string> Monday	 = { "Montag", "montag", "Mo", "mo"			};
	vector<string> Tuesday	 = { "Dienstag", "dienstag", "Di", "di"		};
	vector<string> Wednesday = { "Mittwoch", "mittwoch", "Mi", "mi"		};
	vector<string> Thursday	 = { "Donnerstag", "donnerstag", "Do", "do"	};
	vector<string> Friday	 = { "Freitag", "freitag", "Fr", "fr"		};
	vector<string> Saturday  = { "Samstag", "samstag", "Sa", "sa"		};		
	
	vector<int> su_num;
	vector<int> mo_num;
	vector<int> tu_num;
	vector<int> we_num;
	vector<int> th_num;
	vector<int> fr_num;
	vector<int> sa_num;

	int su_count = 0;
	int mo_count = 0;
	int tu_count = 0;
	int we_count = 0;
	int th_count = 0;
	int fr_count = 0;
	int sa_count = 0;

	int dayNum;
	std::string day;
	
	cout << "Beenden mit end\n";
	cout << "Wochentag/Anzahl: ";
	while(cin >> day >> dayNum)
	{
		if( day == "end") break;

		findWeek(Sunday,	&su_num, day, dayNum);
		findWeek(Monday,	&mo_num, day, dayNum);
		findWeek(Tuesday,   &tu_num, day, dayNum);
		findWeek(Wednesday, &we_num, day, dayNum);
		findWeek(Thursday,	&th_num, day, dayNum);
		findWeek(Friday,	&fr_num, day, dayNum);
		findWeek(Saturday,	&sa_num, day, dayNum);

		cout << "Wochentag/Zahl: ";
	}

	for(int n : su_num) su_count += n;
	for(int n : mo_num) mo_count += n;
	for(int n : tu_num) tu_count += n;
	for(int n : we_num) we_count += n;
	for(int n : th_num) th_count += n;
	for(int n : fr_num) fr_count += n;
	for(int n : sa_num) sa_count += n;
	
	
	cout << "----------------------------\n";
	cout << "Sunday:  "   << su_count << "\n" <<
			"Monday:  "   << mo_count << "\n" <<
			"Tuesday: "   << tu_count << "\n" <<
			"Wednesday: " << we_count << "\n" <<
			"Thursday: "  << th_count << "\n" << 
			"Friday: "    << fr_count << "\n" <<
			"Saturday: "  << sa_count << "\n";

}

void lesson12()
{

	vector< string > weekdays = { "montag", "dienstag", "mittwoch", "donnerstag", "freitag", "samstag", "sonntag" };
	vector< int > sum_weekdays;
	sum_weekdays.resize( weekdays.size() );
	
	int dayNum;
	
	std::string day;
	
	cout << "Beenden mit end\n";
	cout << "Wochentag/Anzahl: ";
	
	while(cin >> day >> dayNum)
	{
		if( day == "end") break;

	   auto ret = std::find_if(weekdays.begin(), weekdays.end(),
                            [&](const auto &entry) { return entry.find(str_tolower(day)) != std::string::npos; });

	   if(ret != weekdays.end())
	   {
		sum_weekdays[ret - weekdays.begin()] += dayNum;
	   }

		cout << "Wochentag/Zahl: ";
	}

	dayNum = 0;
	for(auto week : weekdays)
	{
		cout << week << " " <<  sum_weekdays.at(dayNum) << endl;
		dayNum++;
	}
}

void lesson12_count_weekdays()
{
	auto toLower = []( std::string s ) 
	{
		std::transform( s.begin(), s.end(), s.begin(), []( auto c ){ return std::tolower(c); } );
		return s;
	};
	auto iStartsWith = [ &toLower ]( const std::string& str, const std::string& match ) 
	{
		auto strLowercase = toLower( str );
		auto matchLowercase = toLower( match );
		return strLowercase.find( matchLowercase ) == std::string::size_type( 0 ); // 0 -> starts with matchLowercase
	};

	vector< string > weekdays = { "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag", "Sonntag" };
	vector< int > sumWeekdays;
	sumWeekdays.resize( weekdays.size() );
	
	std::string endMarker = "end";
	std::cout << "Beenden mit " + endMarker + "\n";

	auto commandHelp = [](){ std::cout << "Wochentag/Anzahl: "; };
	
	commandHelp();
	int dayNum;
	std::string match;
	while( cin >> match >> dayNum )
	{
		if( match == endMarker ) 
			break;

		auto foundWeekday = std::find_if( weekdays.begin(), weekdays.end(), [&]( const auto& weekday ) { return iStartsWith( weekday, match ); });

		if( foundWeekday == weekdays.end() )
			continue;

		int iSumWeekdays = (int)( foundWeekday - weekdays.begin() );
		sumWeekdays[ iSumWeekdays ] += dayNum;
		commandHelp();
	}

	auto iWeekday = 0;
	for( const auto& weekday : weekdays )
	{
		std::cout << weekday << " " <<  sumWeekdays.at( iWeekday ) << std::endl;
		iWeekday++;
	}
}


int main()
{
	 lesson12();
}
