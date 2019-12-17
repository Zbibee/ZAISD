
#include <iostream>


bool dia_r[256];
bool dia_l[256];   // tablice z zajêtymi przek¹tnymi
bool col[8];       // tablica z zajêtymi kolumnami
short int chart[8][8];  // tablica z ustawieniami hetmanów
int z[8];
int found = 0;          // licznik znalezionych pozycji
int licznik =0;
int licznik2 =0;
void printResult();
using namespace std;

void printResult(){
    cout<< "Rozwiazanie: " << found << "\t";
    for(int j=0; j<8; j++){
        cout << " | "<< z[j] << " ";
    }
    cout<< " | " <<licznik <<endl;
    licznik2 += licznik;
    licznik = 0;
}

void add_hetman(int row) {
    int i;
    for (i=0; i<8; i++) {
        licznik++;
        if (!((col[i]) || (dia_r[i-row+128]) || (dia_l[row+i+128]))) {
            dia_r[i-row+128] = true;
            dia_l[row+i+128] = true;
            col[i] = true;
            chart[i][row] = row+1;
            z[i] = row +1;
            if (row<7) {
                add_hetman(row+1);
            }
            else {
                found++;
                printResult();
            }

            dia_r[i-row+128] = false;
            dia_l[row+i+128] = false;
            col[i] = false;
            chart[i][row] = 0;
        }
    }
}

int main(void) {
    int i,j;
for (i=0; i<256; i++) {
    dia_r[256] = false;
    dia_l[256] = false;
}

for (i=0; i<8; i++) {
    col[8] = false;
}
for (i=0; i<8; i++) {
    for (j=0; j<8; j++) {
        chart[i][j] = 0;
    }
}
    cout<< "Rozwiazanie: nr ";
    for(int j=1; j<=8; j++){
        cout << " | x" << j;
    }
    cout<< " | N " <<endl ;

    add_hetman(0);
    cout << "Srednia N = " << licznik2/92 <<endl;
return 0;
}
