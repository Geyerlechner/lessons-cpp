#pragma once
#include "std_lib_facilities.h"



int tasks_1()
{
	// Syntax fehler
	//	Cout << "Erfolg!\n";
	//	cout << "Erfolg!\n;
	//	cout << "Erfolg" << !\n;
	//	cout << success << endl;
	//	string res = 7; vector<int> v(10); v[5] = res; cout << "Erfolg!\n";
	//	if( cond ) cout << "Erfolg!\n"; else cout << "Erfolg!\n";
	//	if( cond ) cout << "Erfolg!\n"; else cout << "Fehlschlag!\n";
	//	string s = "Affe"; boo c = "Narr" < s; if(c) cout << "Erfolg!\n";
	//	string s = "Affe"; if(s == "Narr")  cout < "Erfolg!\n";
	//	string s = "Affe"; if(s+"Narr") cout << "Erfolg!\n";
	//	if(true) then cout "Erfolg!\n"; else cout << "Fehlschlag!\n";	
	//	string<char> s= "Erfolg!\n"; for(int i = 0; i <= 10; i++) cout << s[i];
	//	std::cin << "Erfolg!\n";

	try 
	{	
		// ector<int> v(10); v[5] = 7; cout << "Erfolg!\n"; Richtig!
		// bool c = false; if( c ) cout << "Erfolg!\n"; else cout << "Fehlschlag!\n"; Richtig
		// string s = "Affe"; if(s == "Narr")  cout << "Erfolg!\n"; Richtig
		// vector<char> v(5); for (int i = 0; 0 < v.size(); i++); cout << "Erfolg!\n"; Falsch -> 0 < v.size()
		// vector<char> v(5); for (int i = 0; i <= v.size(); i++); cout << "Erfolg!\n"; Richtig
		// string s = "Erfolg!\n"; for (int i = 0; i < 6; i++) cout << s[i]; Falsch -> Erfolg!\n = 9 Zeichen, gibt aber nur bis zum 6ten zeichen aus
		// int x = 2000; char c = x; if(c==2000) cout << "Erfolg!\n"; Falsch int zu char 
		// string s = "Erfolg!\n"; for (int i = 0; i < 10; i++) cout << s[i]; Falsch out of Range!
		// vector<char> v(5); for (int i = 0; i <= v.size(); i++); cout << "Erfolg!\n"; Richtig
		// int i = 0; int j = 9; while(i<10) ++j; if(j<i) cout << "Erfolg!\n"; Falsch j++ und nicht i++
		// int x = 2; double d = 5 / (x-2); if(d==2*x+0.5) cout << "Erfolg!\n"; Falsch (x-2) = 0 
		// int i = 0; while(1<10) ++j; if(j<i) cout << "Erfolg!\n"; Falsch j = ?
		// int x = 4; double d = 5/(x-2); if(d=2*x+0.5) cout << "Erfolg!\n"; Richtig

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
	default:
		cout << "Keine richtige eingabe";
	}

	return 0;
}

void task_2()
{
	double c = 0;
	double d = 0;
	int e = 0;
	std::string output;

	cin >> d;
	cin >> e;

	double k = ctok(d, e);
	e == 1 ? output = " K" : output = " C";
	cout << k << output << endl;
}