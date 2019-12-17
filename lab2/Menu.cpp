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
#include <sstream>

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
    Quit,
    AnotherOption
};

Menu choiceOption(string input);
//void printVector(vector<int> v);
string retStringMenu(map<int, string> m);
void printTab(int * tab, int sizeTab, string text);

int main()
{
    //vector<int> v;

    bool loop = true;
    int i = 0;
    string s, t;
    struct TEXT text;
    t= retStringMenu(text.menu);
    //cout<< t << endl;
    int sizeTab = 12,
        beginRange = 0,
        endRange = 120;
    //int tab[sizeTab];
    //delete[] tab;

    int *tab;
    //delete[] tab1;
    //std::default_random_engine random_generator(std::chrono::steady_clock::now().time_since_epoch().count());
    //std::uniform_int_distribution<int> distribution(beginRange, endRange);

    //for(int i=0; i< sizeTab; i++){
    //    tab[i] = distribution(random_generator);
    //}
    while(loop){
        //cout << text.menuTxt;
        cout << t;
		cin >> s;
		cin.ignore();
        tab = randomTabInt(sizeTab, beginRange, endRange);

		switch (choiceOption(s)){
		case Zad1:
			cout << endl << "	=====	ZADANIE " << s << "	=====" <<endl;
			cout<< text.menu[stoi(s)] <<endl;
			printTab(tab, sizeTab, "Przed: ");
            zad1(tab, sizeTab);
            printTab(tab, sizeTab, "Po   : ");
	 		break;
		case Zad2:
			cout << endl << "	=====	ZADANIE " << s << "	====="<<endl;
	 		cout<< text.menu[stoi(s)] <<endl;
	 		printTab(tab, sizeTab, "Przed: ");
            zad2(tab, sizeTab);
            printTab(tab, sizeTab, "Po   : ");
	 		break;
		case Zad3:
			cout << endl << "	=====	ZADANIE " << s << "	====="<<endl;
	 		cout<< text.menu[stoi(s)] <<endl;
	 		printTab(tab, sizeTab, "Przed: ");
            zad3(tab, sizeTab);
            printTab(tab, sizeTab, "Po   : ");
	 		break;
		case Zad4:
			cout << endl << "	=====	ZADANIE " << s << "	====="<<endl;
            cout<< text.menu[stoi(s)] <<endl;
            printTab(tab, sizeTab, "Przed: ");
            zad4(tab, sizeTab);
            printTab(tab, sizeTab, "Po   : ");
	 		break;
		case Zad5:
			cout << endl << "	=====	ZADANIE " << s << "	====="<<endl;
            cout<< text.menu[stoi(s)] <<endl;
            printTab(tab, sizeTab, "Przed: ");
            zad5(tab, sizeTab);
            printTab(tab, sizeTab, "Po   : ");
	 		break;
		case Zad6:
			cout << endl << "	=====	ZADANIE " << s << "	====="<<endl;
            cout<< text.menu[stoi(s)] <<endl;
            printTab(tab, sizeTab, "Przed: ");
            zad6(tab, sizeTab);
            printTab(tab, sizeTab, "Po   : ");
	 		break;
		case Quit:
			loop = false;
	 		break;
		default:
			cout<< "Nie poprawna odpowiedz!" <<endl;
			break;
		}
	}
	//delete[] tab;
    return 0;
}

Menu choiceOption(string input){
    if( input == "1" ) return Zad1;
    if( input == "2" ) return Zad2;
    if( input == "3" ) return Zad3;
    if( input == "4" ) return Zad4;
    if( input == "5" ) return Zad5;
    if( input == "6" ) return Zad6;
    if( input == "7" ) return Quit;
    return AnotherOption;
}
/*6

void printVector(vector<int> v){
    cout<<  "Vector: ";
    for(int i: v){
       cout<< i << " | " ;
    }
    cout<< endl;
}*/
void printTab(int * tab, int sizeTab, string text){
    cout<< text;
    for(int i=0; i<sizeTab; i++){
       cout<< tab[i] << " | " ;
    }
    cout<< endl;
}

string retStringMenu(map<int, string> m){
    string retVal = "\n=========================================\n";
    char c[33];
    stringstream ss;
    for(int i=1; i<= m.size(); i++){
        ss << " " << i << " -> " << m[i];
    }
    //retVal += ss.str() +
    return retVal + ss.str() + "Wybor: ";
}
