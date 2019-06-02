#include <iostream>

using namespace std;

int c[6] = {75, 150, 250, 35, 10, 100};
int m[6] = {7, 8, 6, 4, 3, 9};

int masa = 10;
int n = 6;
int P[7][11];
int Q[7][11];

int knapsack() {
    for (int i = 0; i <= n; ++i) {
        P[i][0] = 0;
    }
    for (int i = 0; i <= masa; ++i) {
        P[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= masa; ++j) {
            if(m[i-1] <= j)
                if(P[i][j - m[i-1]] + c[i-1] > P[i-1][j])
                    P[i][j] = P[i][j - m[i-1]] + c[i-1];
                else
                    P[i][j] = P[i-1][j];
            else
                P[i][j] = P[i-1][j];

        }
    }

    return P[n][n];
}


int main() {
    cout << knapsack() << endl << endl;

    cout << "\t\t";
    for (int i = 1; i <= masa; ++i) {
        cout << i << "\t";
    }
    cout << endl << endl;

    bool cos = true;
    for (int i = 0; i <= n; ++i) {
        if (cos)
            cout << "\t";
        else
            cout << m[i - 1] << "\t";
        for (int j = 0; j <= masa; ++j) {
            cout << P[i][j] << "\t";
        }
        cos = false;
        cout << endl;
    }

// TABLICA Q - id ostatnich przedmiotów
//    cout << endl << endl;
//
//    for (int i = 0; i <= n; ++i) {
//        for (int j = 0; j <= masa; ++j) {
//            cout << Q[i][j] << "\t";
//        }
//        cout << endl;
//    }


    cout << endl << "Id przedmiotów: " << endl;

    int id;
    int w;
    while (masa > 0) {
        id = Q[n][masa];
        cout << id << endl;
        w = m[id-1];
        masa -= w;
    }

    return 0;
}