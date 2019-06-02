#include <iostream>

using namespace std;

// NAJDŁUŻSZY WSPÓLNY PODCIAG

char A[] = {'a', 'l', 'i', 'b', 'a', 'b', 'a'}; // <- po lewej
char B[] = {'k', 'a', 'l', 'i', 'm', 'a', 'm', 'b', 'a'}; // u góry

int n = sizeof(A) / sizeof(char);
int m = sizeof(B) / sizeof(char);


int **lcs = new int *[n + 1];

void long_common() {
    for (int i = 0; i < n + 1; ++i) {
        lcs[i] = new int[m + 1];
    }
    for (int i = 0; i <= n; ++i) {
        lcs[i][0] = 0;
    }
    for (int i = 0; i <= m; ++i) {
        lcs[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i - 1] == B[j - 1])
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }

    }
}


int **lev = new int *[n + 1];

void lev_lenght() {
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
            if (A[i - 1] == B[i - 1])
                cost = 0;
            else
                cost = 1;

            lev[i][j] = min(1 + lev[i][j - 1], min(1 + lev[i - 1][j], cost + lev[i - 1][j - 1]));
        }
    }
}

int main() {
    lev_lenght();

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

//    int i = n;
//    int j = m;
//    char tab[20];
//    int id = lcs[i][j];
//    while (i > 0 && j > 0) {
//        if(A[i-1] == B[j-1]){
//            tab[id-1] = A[i-1];
//            id--;
//            i--;
//            j--;
//        }
//        else{
//            if(lcs[i-1][j] > lcs[i][j-1]){
//                i--;
//            }
//            else{
//                j--;
//            }
//        }
//    }
//    for (int l = 0; l < lcs[n][m]; ++l) {
//        cout << tab[l];
//    }


    return 0;
}