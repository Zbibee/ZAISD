#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cmath>
#include <random>
#include <chrono>
#include <stdexcept>
#include <typeinfo>
#include <cmath>
#include <vector>

#include "Zadania.cpp"

/*
Author: Zbibee
You must use minimum -sdk=c++0x (aka c++11), because i use default_random_engine
*/
using namespace std;

enum Menu{
    Zad1,
    Zad2,
    Zad3,
    Zad4,
    Zad5,
    Zad6,
    Zad7,
    Quit,
    AnotherOption
};

Menu choiceOption(string input);
void printVector(vector<int> v);

int main()
{
    vector<int> v;
    bool loop = true;
    int i = 0;
    string s;
    struct TEXT text;
    int sizeVec = 10,
        beginVec = 0,
        endVec = 100;
    int tab[4];

    while(loop){
        cout << text.menuTxt;
		cin >> s;
		cin.ignore();

		//v = randomVector(sizeVec, beginVec, endVec);
        //printVector(v);

		switch (choiceOption(s)){
		case Zad1:

			cout << endl << "	=====	ZADANIE " << s << "	=====" <<endl;
			v = randomVector(sizeVec, beginVec, endVec);
            printVector(v);
	 		zad1(v, v.size());
	 		break;
		case Zad2:
			cout << endl << "	=====	ZADANIE " << s << "	====="<<endl;
	 		zad2(v, sizeVec);
	 		break;
		case Zad3:
			cout << endl << "	=====	ZADANIE " << s << "	====="<<endl;
	 		zad3(v, sizeVec);
	 		break;
		/*
		case Zad4:
			cout << endl << "	=====	ZADANIE " << s << "	====="<<endl;
	 		zad4();
	 		break;
		case Zad5:
			cout << endl << "	=====	ZADANIE " << s << "	====="<<endl;
	 		zad5();
	 		break;
		case Zad6:
			cout << endl << "	=====	ZADANIE " << s << "	====="<<endl;
	 		zad6();
	 		break;
	 	case Zad7:
			cout << endl << "	=====	ZADANIE " << s << "	====="<<endl;
	 		zad7();
	 		break;
		*/
		case Quit:
			loop = false;
	 		break;
		default:
			cout<< "Nie poprawna odpowiedz!" <<endl;
			break;
		}
	}
    return 0;
}

Menu choiceOption(string input){
    if( input == "1" ) return Zad1;
    if( input == "2" ) return Zad2;
    if( input == "3" ) return Zad3;
    if( input == "4" ) return Zad4;
    if( input == "5" ) return Zad5;
    if( input == "6" ) return Zad6;
    if( input == "7" ) return Zad7;
    if( input == "8" ) return Quit;
    return AnotherOption;
}

void printVector(vector<int> v){
    cout<<  "Vector: ";
    for(int i: v){
       cout<< i << " | " ;
    }
    cout<< endl;
}
