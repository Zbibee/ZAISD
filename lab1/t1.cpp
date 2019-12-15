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
    SomethingElse
};

void zad1();
void zad2();
void zad3();
void zad4();
void zad5();
void zad6();
void zad7();
int fibonnaciRec(int l);
int silnia(int i);
Menu choiceOption(string input);

int main()
{
	bool loop = true;
	int i = 0;
    string s;
	while(loop){
		cout << endl << "========================================="<< endl
		<< "1 -> Zlicz ilosc znakow w pliku txt" <<endl
		<< "2 -> Analizator leksykalny" <<endl
		<< "3 -> Obliczanie n tego wyrazu ciagu Fibonacciego" <<endl
		<< "4 -> Reurencyjne obliczanie n tego wyrazu ciagu Fibonacciego" <<endl
		<< "5 -> Miejsca zerowe funkcji kwadratowej" <<endl
		<< "6 -> Oblicza silnia" <<endl
		<< "7 -> Symuluje rzut kostka" <<endl
		<< "8 -> Zamknij program" << endl;

		cout<< "Wybor: ";
		cin >> s;
		cin.ignore();

		switch (choiceOption(s)){
		case Zad1:
			cout << endl << "	=====	ZADANIE " << s << "	=====" <<endl;
	 		zad1();
	 		break;
		case Zad2:
			cout << endl << "	=====	ZADANIE " << s << "	====="<<endl;
	 		zad2();
	 		break;
		case Zad3:
			cout << endl << "	=====	ZADANIE " << s << "	====="<<endl;
	 		zad3();
	 		break;
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

void zad1(){
    fstream file;
    char c;
    int count = 0;
    file.open("TestZS.txt", ios::in);
    if(file.good() == true){
		while(!file.eof()){
        	file.get(c);
        	count ++;
    	}
	}
	file.close();
	cout<< "Liczba znakow w pliku wynosi " << count <<endl;
}

void zad2(){
    fstream file;
    char c;
    int counter = 0;

    file.open("TestZS.txt", ios::in);
    if(file.good() == true){
        while(!file.eof()){
        	file.get(c);
	        while (int(c)== int(' ')){
	        	counter = 0;
	        	file.get(c);
			}

	       	if( counter == 0){
		       	if ((int('a')<= int(c) & int(c) <= int('z')) || (int('A')<= int(c) & int(c) <= int('Z'))){
					cout<< c << " : " << "slowo" <<endl;
				}
				else if(int('0')<= int(c) & int(c) <= int('9')){
				cout<< c << " : " << "liczba" <<endl;
				}
				else{
					cout<< c << " : " << "znak specjalny" <<endl;
				}
				counter ++;
	        }
    	}
        file.close();
    }
}

void zad3(){
	int number, a=0, b=0, c=0;
	cout<< "Podaj ktora liczba ciagu fibonacciego" <<endl;
	cin >> number;
	cin.ignore();
	a = 1;
	b = 1;
	if (number <= 2)
		cout<< "Wynik: " << a <<endl;
	else{
		for(int i = 3; i <= number; i ++){
			c = a+b;
			a = b;
			b = c;
		}
		cout<< number << " liczba ciagu fibbonaciego wynosi: " << c <<endl;
	}
}

void zad4(){
	int number = 0;
	cout<< "Podaj ktora liczba ciagu fibonacciego chcesz otrzymac: " <<endl;
	cin >> number;
	cin.ignore();
	cout<< number << " liczba ciagu fibbonaciego wynosi: " << fibonnaciRec(number) <<endl;

}

int fibonnaciRec(int l){
	if (l <= 2 ){
		return 1;
	}
	else{
		return fibonnaciRec(l -1) + fibonnaciRec(l - 2);
	}
}

void zad5(){
	double x1, x2, delta, a, b, c;
	cout<< "podaj wspolczynniki wielomianu kwadratowego a b c:" <<endl;
	cin >> a;
	cin.ignore();

	cin >> b;
	cin.ignore();

	cin >> c;
	cin.ignore();

	if(a == 0)
		cout<< "to nie jest funkcja kwadratowa" <<endl;
	else
		delta = pow(b,2) - (4 *a*c);
		cout<< "Delta: " << delta  <<endl;
		if(delta > 0){
			x1 = ((-b) - sqrt(delta))/(2*a);
			x2 = ((-b) + sqrt(delta))/(2*a);
			cout << "x1: " << x1 <<endl;
			cout << "x2: " << x2 <<endl;
		}
		else{
			x1 = (-b) / (2*a);
			cout << "x1: " << x1 <<endl;
		}
}

void zad6(){
	int n=0;
	cout<< "Program wylicza silnia z danej liczby n" <<endl
		<< "Podaj wartosc n:";
	cin >> n;
	cin.ignore();
	cout<< "Silnia z liczby " << n << " wynosi " << silnia(n) <<endl;
	silnia(n);
}

int silnia(int i){
	if(i == 0){
		return 1;
	}
	else{
		return i * silnia(i-1);
	}
}

void zad7(){
    string tmp;
    double r = 0;
	string c = "";

    cout<< "Program symuluje rzut kostka" <<endl;
	while(!(kost >= 4 && fmod(kost,1.0) == 0.0)){
		cout<< "Ilu scienna kostka chcesz grac?: ";
		cin >> tmp;
		cin.ignore();

        try{
            kost = std::stod(tmp);
            if(kost < 4 )
                cout<< "Kosta musi miec przynajmniej 4 sciany" <<endl;
            if(fmod(kost,1.0) != 0)
                cout<< "Liczba scian musibyc liczba calkowica dodatnia" << endl;
        }catch(const std::invalid_argument& e){
            cout<< "Kosta musi miec przynajmniej 4 sciany" <<endl;
        }
	}

	while( c != "q" && c !="Q"){
        std::default_random_engine random_generator(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> distribution(1, kost);
        cout<< "Wylosowano liczbe: " << distribution(random_generator) <<endl;
		cout<< "Aby zakonczyc wybierz q, aby losowac kolejna liczbe wybierz dowolna zmienna"<<endl;
		cin >> c;
		cin.ignore();
	}

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
    return SomethingElse;
}


