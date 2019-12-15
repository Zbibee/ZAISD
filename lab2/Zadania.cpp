#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cmath>
#include <random>
#include <chrono>
#include <vector>

using namespace std;

struct TEXT{
public:
   static const string menuTxt;
};

const string TEXT::menuTxt = "\n=========================================\n \
1 -> Sortowanie przez proste wstawianie\n \
2 -> Sortowanie przez wstawianie polowkowe\n \
3 -> Sortowanie przez proste wybieranie\n ";
/*
4 -> Reurencyjne obliczanie n tego wyrazu ciagu Fibonacciego\n \
5 -> Miejsca zerowe funkcji kwadratowej\n \
6 -> Oblicza silnia\n \
7 -> Symuluje rzut kostka\n \
8 -> Zamknij program\nWybor: ";
*/
vector <int> randomVector(int sizeTab, int beginRange, int endRange);
void zad1(vector<int> v, int sizeTab);
void zad2(vector<int> v, int sizeTab);
void zad3(vector<int> v, int sizeTab);

/*
void zad4();
void zad5();
void zad6();
void zad7();
*/

void zad1(vector<int> v, int sizeVec){
    int j, k;
	for(int i = 2; i <sizeVec; i++){
		k = v.at(i);
		j = i -1;
		while(k < v.at(j)){
			v.at(j+1) = v.at(j);
			j = j-1;
		}
		v.at(j+1) = k;
	}

	for(int i : v){
        cout << i <<endl;
	}
}

void zad2(vector<int> v, int sizeVec){

}

void zad3(vector<int> v, int sizeVec){

}
/*
void zad4(){

}



void zad5(){


}

void zad6(){

}


void zad7(){

}
*/

vector <int> randomVector(int sizeVec, int beginRange, int endRange){

vector <int> v;
std::default_random_engine random_generator(std::chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> distribution(beginRange, endRange);

while(sizeVec > 0){
    v.push_back(distribution(random_generator));
    sizeVec--;
}
//for(int i: v){
    //    cout<< i << endl;
  //  }
return v;
}
