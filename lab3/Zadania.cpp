#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cmath>
#include <random>
#include <chrono>
#include <vector>
#include <map>

using namespace std;

struct TEXT{
public:
   static const string menuTxt;
   std::map<int, string> menu;
   TEXT(){
   this->menu[1] = "Sortowanie przez proste wstawianie\n";
   this->menu[2] = "Sortowanie przez wstawianie polowkowe\n";
   this->menu[3] = "Sortowanie szybkie";
   this->menu[4] = "Zamknij program\n";
   }
};

const string TEXT::menuTxt = "\n=========================================\n \
1 -> Procedura przesiewania\n \
2 -> Sortowanie stogowe\n \
3 -> Sortowanie przez proste wybieranie\n \
4 -> Sortowanie babelkowe\n \
5 -> Sortowanie mieszane\n \
6 -> Sortowanie metoda Shella\n \
7 -> Zamknij program\nWybor: ";

void wyswielt(int * tab);
void przesiewanie(int * tab, int p, int q);
void sortowanieStogowe(int * tab, int size);
void sortuj(int *a, int q, int p);
void sortowanieszybkie(int *a, int n);

void wyswietl(int *tab, int size){
	for (int i =0; i<size;i++){
		std::cout<< tab[i] <<std::endl;
	}
}

void przesiewanie(int *tab, int p, int q){
	int i, j, x;
	i = q;
	j = 2*i;
	x = tab[i];

	while (j < p){
		if(j<p){
			if(tab[j] < tab[j+1])
				j += 1;

			if(x >= tab[j])
				goto stop;

			tab[i] = tab[j];
			i = j;
			j = 2*i;
		}
	}
	stop: tab[i] = x;
}

void sortowanieStogowe(int *tab, int size){
	int q, p, x;

	q = size/2;
	p = size-1;

	while (q>0){
		q -= 1;
		przesiewanie(tab, p, q);
	};

	while (p>0){
		x = tab[0];
		tab[0] = tab[p];
		tab[p] = x;
		p -= 1;
		przesiewanie(tab, p, q);
	};
}

void sortuj(int *tab, int q, int p) {
	int i, j, x, w;
	i = q;
	j = p;
	x = tab[(q+p)/2];

	while (i <= j){
		while (tab[i] < x) {
			++i;
		}
		while (x < tab[j]) {
			--j;
		}
		if (i <= j) {
			w = tab[i];
			tab[i] = tab[j];
			tab[j] = w;

			++i;
			--j;
		}
	}

	if (q < j) {
		sortuj(tab, q, j);
	}
	if (i < p) {
		sortuj(tab, i, p);
	}
}

void sortowanieszybkie(int *a, int n) {
	sortuj (a, 0, n-1);
}

int main(){
	int tab[SIZE] = {0,2,1,4,3,8,6,7,5,9};
	wyswietl(tab,SIZE);

	/*
	std::cout<< "\n===\n" << std::endl;
	sortowanieStogowe(tab, SIZE);
	wyswietl(tab,SIZE);
	/**/

	std::cout<< "\n===\n" << std::endl;
	sortowanieszybkie(tab, SIZE);
	wyswietl(tab,SIZE);
	/*
	*/

return 0;
}
