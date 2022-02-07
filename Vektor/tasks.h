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