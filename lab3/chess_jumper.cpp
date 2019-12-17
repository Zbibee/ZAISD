#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
void start(int x, int y);
const int n = 5, nsq = 25, index = 5, indeks = n;
int i, j;
bool q;
int s[n] =  {0, 1, 2, 3 ,4};
int a[index], b[index];
int h[indeks][indeks];


void probuj(int i, int x, int y, bool& q)
{
    int k, u, v;
    bool q1;
    k = 0;
    do{
        k = k + 1;
        q1 = false;
        u = x + a[k];
        v = y + b[k];
        if(u >= 0 && u<n && v >= 0 && v<n)
        {
            if(h[u][v] == 0)
            {
                h[u][v] = i;
                if(i < nsq)
                {
                    probuj(i+1, u, v, q1);
                    if(!q1)
                        h[u][v] = 0;
                }
                else
                q1 = true;
            }
        }


    }while(!(q1 || k == 8));
    q = q1;
}

int main()
{

    a[1] = 2; b[1] = 1;
    a[2] = 1; b[2] = 2;
    a[3] =-1; b[3] = 2;
    a[4] =-2; b[4] = 1;
    a[5] =-2; b[5] =-1;
    a[6] =-1; b[6] =-2;
    a[7] = 1; b[7] =-2;
    a[8] = 2; b[8] =-1;

    for(int k=0; k<5; k++){
        for(int h=0; h<5; h++){
            start(h, k);
        }
    }

    return 0;
}

void start(int x, int y){

    cout<< "\n--- " << x << " --- " << y << " -------------" <<endl;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            h[i][j] = 0;
    h[x][y] = 1;
    probuj(2, x, y, q);

    if(q){
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(h[i][j] < 10)
                    cout << 0 << h[i][j]<<' ';
                else
                    cout << h[i][j]<<' ';
            }
            cout << endl;
        }
    } else cout << "NIE ISTNIEJE ROZWIAZANIE"<<endl << "-------------------------" <<endl;

}
