#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cmath>
#include <random>
#include <chrono>

using namespace std;

struct TEXT{
public:
   static const string menuTxt;
};

const string TEXT::menuTxt = "\n=========================================\n \
1 -> Zlicz ilosc znakow w pliku txt\n \
2 -> Analizator leksykalny\n \
3 -> Obliczanie n tego wyrazu ciagu Fibonacciego\n \
4 -> Reurencyjne obliczanie n tego wyrazu ciagu Fibonacciego\n \
5 -> Miejsca zerowe funkcji kwadratowej\n \
6 -> Oblicza silnia\n \
7 -> Symuluje rzut kostka\n \
8 -> Zamknij program\nWybor: ";

void zad1();
void zad2();
void zad3();
void zad4();
void zad5();
void zad6();
void zad7();
int fibonnaciRec(int l);
int silnia(int i);

void zad1(){
    fstream file;
    char c;
    int count = 0;
    file.open("file.txt", ios::in);
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

    file.open("file.txt", ios::in);
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
    double kost = 0;
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
