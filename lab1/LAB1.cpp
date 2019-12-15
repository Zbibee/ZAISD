#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
void zad1();
void zad2();
void zad3();
void zad4();
void zad5();
void zad6();
void p(int i);
int fibonnaciRec(int l);

int main()
{
	bool loop = true;
	int i = 0;
	
	
	
	while(loop){
		cout << endl << "========================================="<< endl
		<< "1 -> Zlicz ilosc znakow w pliku txt" <<endl
		<< "2 -> Analizator leksykalny" <<endl
		<< "3 -> Obliczanie n–tego wyrazu ci¹gu Fibonacciego" <<endl
		<< "4 -> Reurencyjne obliczanie n–tego wyrazu ci¹gu Fibonacciego" <<endl
		<< "5 -> Miejsca zerowe funkcji kwadratowej" <<endl
		<< "6 -> Zamknij program" << endl;
	
		cout<< "Wybor: ";
		cin >> i;
		cin.ignore();
		switch (i){
		case 1:
			cout << endl << "	=====	ZADANIE " << i << "	=====" <<endl; 
	 		zad1();
	 		break;
		case 2:
			cout << endl << "	=====	ZADANIE " << i << "	====="<<endl;
	 		zad2();
	 		break;
		case 3:
			cout << endl << "	=====	ZADANIE " << i << "	====="<<endl; 
	 		zad3();
	 		break;
		case 4:
			cout << endl << "	=====	ZADANIE " << i << "	====="<<endl; 
	 		zad4();
	 		break;
		case 5:
			cout << endl << "	=====	ZADANIE " << i << "	====="<<endl; 
	 		zad5();
	 		break;
		case 6:
			loop = false;
	 		break;
		default:
			cout<< "Nie poprawna odpowiedz!" <<endl;
			
		}
	
	} /*
	cout<< "	=====	ZADANIE 	" << i << "		=====" ;
 	zad1();
 	zad2();
 	zad3();
 	zad4();
 	zad5();*/
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
    system("PAUSE");
}

void zad3(){
	int number, a=0, b=0, c=0;
	cout<< "Podaj ktora liczba ciagu fibonacciego" <<endl;
	cin >> number;
	cin.ignore();
	a = 1;
	b = 1;
	cout<< "a = " << a <<endl;
	cout<< "b = " << b <<endl;
	cout<< "liczba = " << number <<endl;
	if (number <= 2)
		cout<< "Wynik: " << a <<endl;
	else{
		for(int i = 3; i <= number; i ++){
			c = a+b;
			a = b;
			b = c;
		}
		cout<< "Wynik: " << c <<endl;
	}	
}

void zad4(){
	int number;
	cout<< "Podaj ktora liczba ciagu fibonacciego chcesz otrzymac: " <<endl;
	cin >> number;
	cin.ignore();
	fibonnaciRec(number);

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


	


