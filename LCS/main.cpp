#include <iostream>

using namespace std;

// NAJDŁUŻSZY WSPÓLNY PODCIAG

char A[] = {'a', 'l', 'i', 'b', 'a', 'b', 'a'}; // <- po lewej
char B[] = {'k', 'a', 'l', 'i', 'm', 'a', 'm', 'b', 'a'}; // u góry

int n = sizeof(A) / sizeof(char);
int m = sizeof(B) / sizeof(char);


int **lcs = new int *[n + 1];


int longest_common_subsequnce() {
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

int longest_common_subsequnce_recursive(int i, int j) {
    if (i == 0 || j == 0) return 0;
    int r;
    if (A[i-1] == B[j-1])
        r = 1+longest_common_subsequnce_recursive(i - 1, j - 1);
    else
        r = max(longest_common_subsequnce_recursive(i - 1, j), longest_common_subsequnce_recursive(i, j - 1));

    return r;
}


int main() {
    longest_common_subsequnce();

//    lcs ------------> rekurencyjnie
//    cout << longest_common_subsequnce_recursive(n, m);
//    delete[] lcs;
//    return 0;

    cout << endl << endl;
    cout << "Longest common subsequnce:" << lcs[n][m] << endl << endl;

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
            cout << lcs[i][j] << " ";
        }
        a = false;
        cout << endl;

    }

    int x = n, y = m, id = lcs[n][m];
    char C[20];
    while (x > 0 && y > 0) {
        if (A[x - 1] == B[y - 1]) {
            C[id - 1] = A[x - 1];
            id--;
            x--;
            y--;
        } else {
            if (lcs[x - 1][y] > lcs[x][y - 1]) {
                x--;
            } else {
                y--;
            }
        }
    }

    cout << endl;
    for (int l = 0; l < lcs[n][m]; ++l) {
        cout << C[l];
    }


    delete[] lcs;
    return 0;
}