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
   std::map<int, string> menu;
   TEXT(){
   this->menu[1] = "Sortowanie przez proste wstawianie\n";
   this->menu[2] = "Sortowanie przez wstawianie polowkowe\n";
   this->menu[3] = "Sortowanie przez proste wybieranie\n";
   this->menu[4] = "Sortowanie babelkowe\n";
   this->menu[5] = "Sortowanie mieszane\n";
   this->menu[6] = "Sortowanie metoda Shella\n";
   this->menu[7] = "Sortowanie stogowe\n";
   this->menu[8] = "Sortowanie szybkie  metoda rekurencyjna\n";
   this->menu[9] = "Zamknij program\n";
   }
};

vector <int> randomVector(int sizeTab, int beginRange, int endRange);
int* randomTabInt(int sizeTab, int beginRange, int endRange);
void zad1(int * tab, int sizeTab);
void zad2(int *tab, int sizeTab);
void zad3(int *tab, int sizeTab);
void zad4(int *tab, int sizeTab);
void zad5(int *tab, int sizeTab);
void zad6(int *tab, int sizeTab);
void zad7(int * tab, int size);
void zad8(int *a, int n);
void przesiewanie(int * tab, int p, int q);
void sortuj(int *a, int q, int p);

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
    q=0;
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
		q = k+1;//+1
		for (j=q; j<=p; j++) {
			if (tab[j-1] > tab[j]) {
				obj = tab[j-1];
				tab[j-1] = tab[j];
				tab[j] = obj;
				k=j;
			}
		}
		p = k-1;//-1;//-1
	} while (q < p);
}

void zad6(int *tab, int sizeTab){
    const int t = 4;
    int i, j, k, s, x;
    int h[4] = {1,3,7,15};//9,5,3,1};

    for(int m=0; m<t; m++) { // <=
    	k = h[m]; // k=9
    	s = -k;   // s = -9 //-k
    	//stapsize = s
        //s<=N-1
    	for (i = k; i < sizeTab; i++) {// 10 ->12 //s-> k
    		x = tab[i]; //x =tab[9]
    		j = i-k;    //j = 9-9 = 0

    		if (s==0) {
    			s = -k;
    			s = s+1;
    			tab[s] = x;
			}
			while (x < tab[j] && j>=0) { //tab[0]
				tab[j+k]=tab[j]; //tab[9] = tab[0]
				j = j-k;// j = -9
			}
			tab[j+k] = x; //tab[0] = tab[9]
		}
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

void zad7(int *tab, int size){
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

void zad8(int *a, int n) {
	sortuj (a, 0, n-1);
}


int* randomTabInt(int sizeTab, int beginRange, int endRange){
int* tab = new int[sizeTab];
std::default_random_engine random_generator(std::chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> distribution(beginRange, endRange);

for(int i=0; i< sizeTab; i++){
    tab[i] = distribution(random_generator);
}
return tab;
}
