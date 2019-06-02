#include <iostream>

using namespace std;

// NAJDŁUŻSZY WSPÓLNY PODCIAG

char A[] = {'s', 'p', 'o', 'r', 't', 'y'};
char B[] = {'s', 'o', 'r', 't'};

int n = sizeof(A) / sizeof(char);
int m = sizeof(B) / sizeof(char);


int **lev = new int *[n + 1];


int levenstein() {
    for (int i = 0; i < n + 1; ++i) {
        lev[i] = new int[m + 1];

    }
    for (int i = 0; i <= n; ++i) {
        lev[i][0] = i;
    }
    for (int i = 0; i <= m; ++i) {
        lev[0][i] = i;
    }
    int cost = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i - 1] == B[j - 1])
                cost = 0;
            else
                cost = 1;

            lev[i][j] = min(1 + lev[i - 1][j],
                            min(1 + lev[i][j - 1],
                                cost + lev[i - 1][j - 1])
            );
        }
    }

    return lev[n][m];
}


int main() {
    levenstein();

    cout << endl << endl;
    cout << "Levenstein:" << lev[n][m] << endl << endl;

    bool a = true;
    // Wyświetlenie tablicy
    cout << "    : ";
    for (int k = 0; k < m; ++k) {
        cout << B[k] << " ";
    }
    cout << endl;
    for (int i = 0; i <= n; ++i) {
        if (a)
            cout << "  : ";
        else
            cout << A[i - 1] << " : ";
        for (int j = 0; j <= m; ++j) {
            cout << lev[i][j] << " ";
        }
        a = false;
        cout << endl;

    }


    delete[] lev;
    return 0;
}