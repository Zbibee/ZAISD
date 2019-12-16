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
int* randomTabInt(int sizeTab, int beginRange, int endRange);
void zad1(int * tab, int sizeTab);
void zad2(int *tab, int sizeTab);
void zad3(int *tab, int sizeTab);
void zad4(int *tab, int sizeTab);
void zad5(int *tab, int sizeTab);
void zad6(int *tab, int sizeTab);
//void zad7();


void zad1(int *tab, int sizeTab){
    int j=0, k=0;
	for(int i = 1; i <sizeTab; i++){
		k = tab[i];
		j = i -1;
		while(j>=0 && k < tab[j]){
			tab[j+1] = tab[j];
			--j;
		}
		tab[j+1] = k;
	}
}

void zad2(int *tab, int sizeTab){
    int i, j, q, p, m, k;
	for (i=1;i<sizeTab;i++) {
		k = tab[i];
		q = 0;
		p = i-1;
		while (q<=p) {
			m = (q+p)/2;
			if (k < tab[m]) {
				p = m-1;
			} else {
				q = m+1;
			}
		}
		for (j=i-1; j>=q; j--) {
			tab[j+1] = tab[j];
		}
		tab[q] = k;
	}
}

void zad3(int *tab, int sizeTab){
int i, j, z, k;
	//Point k;

	for (i=0; i<=sizeTab-1; i++) {
		z = i;
		k = tab[i];
		for (j=i+1; j<sizeTab; j++) {
			if (tab[j] < k) {
				z=j;
				k=tab[j];
			}
		}
		tab[z]=tab[i];
		tab[i]=k;
	}
}

void zad4(int *tab, int sizeTab){
    int i,j,x;
    for(i=1; i<sizeTab; i++){
        for(j=sizeTab; j>=i; j--){
            if(tab[j-1] > tab[j]){
                swap(tab[j-1], tab[j]);
            }
        }
}
}
void zad5(int *tab, int sizeTab){
    int j,k,q,p,x, obj;
    q=1;
    p=sizeTab;
    k=sizeTab;

    do {
    	for (j=p; j>=q; j--) {
    		if (tab[j-1] > tab[j]) {
    			obj=tab[j-1];
    			tab[j-1]=tab[j];
    			tab[j]=obj;
    			k=j;
			}
		}

		q = k+1;

		for (j=q; j<=p; j++) {
			if (tab[j-1] > tab[j]) {
				obj = tab[j-1];
				tab[j-1] = tab[j];
				tab[j] = obj;

				k=j;
			}
		}

		p = k-1;

	} while (q <= p);


}

void zad6(int *tab, int sizeTab){
    const int t = 4;
    int i, j, k, s, x;
    int h[4] = {9,5,3,1};

    for(int m=0; m<t; m++) {
    	k = h[m];
    	s = -k;

    	for (i = k+1; i < sizeTab; i++) {
    		x = tab[i];
    		j = i-k;

    		if (s==0) {
    			s = -k;
    			s = s+1;
    			tab[s] = x;
			}
			while (x < tab[j]) {
				tab[j+k]=tab[j];
				j = j-k;
			}
			//
		}
		tab[j+k] = x;
	}
}

/*
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
}*/
int* randomTabInt(int sizeTab, int beginRange, int endRange){
int* tab = new int[sizeTab];
std::default_random_engine random_generator(std::chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> distribution(beginRange, endRange);

for(int i=0; i< sizeTab; i++){
    tab[i] = distribution(random_generator);
}
//for(int i: v){
    //    cout<< i << endl;
  //  }
return tab;
}
