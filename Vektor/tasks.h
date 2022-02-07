#pragma once
#include "std_lib_facilities.h"



int tasks_1()
{

	Cout << "Erfolg!\n";
	cout << "Erfolg!\n;
	cout << "Erfolg" << !\n;
	cout << success << endl;

	string res = 7; vector<int> v(10); v[5] = res; cout << "Erfolg!\n";
	vector<int> v(10); v[5] = 7; cout << "Erfolg!\n";
	if( cond ) cout << "Erfolg!\n"; else cout << "Erfolg!\n";
	if( cond ) cout << "Erfolg!\n"; else cout << "Fehlschlag!\n";
	bool c = false; if( c ) cout << "Erfolg!\n"; else cout << "Fehlschlag!\n";

	string s = "Affe"; boo c = "Narr" < s; if(c) cout << "Erfolg!\n";
	string s = "Affe"; if(s == "Narr")  cout << "Erfolg!\n";
	string s = "Affe"; if(s == "Narr")  cout << "Erfolg!\n";
	string s = "Affe"; if(s+"Narr") cout << "Erfolg!\n";

	vector<char> v(5); for (int i = 0; 0 < v.size(); i++); cout << "Erfolg!\n";
	vector<char> v(5); for (int i = 0; i <= v.size(); i++); cout << "Erfolg!\n";

	string s = "Erfolg!\n"; for (int i = 0; i < 6; i++) cout << s[i];
	if(true) then cout "Erfolg!\n"; else cout << "Fehlschlag!\n";
	int x = 2000; char c = x; if(c==2000) cout << "Erfolg!\n";
	
	string s = "Erfolg!\n"; for (int i = 0; i < 10; i++) cout << s[i];
	vector<char> v(5); for (int i = 0; i <= v.size(); i++); cout << "Erfolg!\n";
	int i = 0; int j = 9; while(i<10) ++j; if(j<i) cout << "Erfolg!\n";
	int x = 2; double d = 5 /(x-2); if(d==2*x+0.5) cout << "Erfolg!\n";
	string<char> s= "Erfolg!\n"; for(int i = 0; i <= 10; i++) cout << s[i];
	int i = 0; while(1<10) ++j; if(j<i) cout << "Erfolg!\n";
	int x = 4; double d = 5/(x-2); if(d=2*x+0.5) cout << "Erfolg!\n";
	cin << "Erfolg!\n";

	try 
	{	

		keep_window_open();
	}
	catch( exception& e )
	{
		std::cerr << "Hoppla: unbekannte Ausnahme!\n";
		keep_window_open();
	}
	catch (...)
	{
		std::cerr << "Hoppla: unbekannte Ausnahme!\n";
		keep_window_open();
		return 2;
	}

}