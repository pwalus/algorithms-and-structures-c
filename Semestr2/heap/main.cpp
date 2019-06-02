#include <iostream>

using namespace std;

void see_all(int tab[], int n) {
    cout << "Tablica: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << tab[i] << endl;
    }
}

int partition(int tab[], int p, int r) {
    int x = tab[r];
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (tab[j] <= x) {
            i++;
            swap(tab[i], tab[j]);
        }
    }
    swap(tab[i+1], tab[r]);
    return i+1;
}

void quicksort(int tab[], int p, int r) {
    if (p < r) {
        int q = partition(tab, p, r);
        quicksort(tab, p, q - 1);
        quicksort(tab, q + 1, r);
    }

}

void zliczenie(int A[], int n, int B[], int C[]){

    for (int i = 0; i < 322; ++i) {
        C[i] = 0;
        B[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        C[A[i]]++;
    }
    for (int i = 1; i < 322; ++i) {
        C[i] = C[i-1] + C[i];
    }
    for (int i = n-1; i > 0; --i) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

}


int main() {
    int tab[13] = {12, 1, 2, 5, 21, 32, 21, 4, 322, 23, 11, 122, 99};
    int n = 13;
    int *B = new int [322];
    int *C = new int [322];
    zliczenie(tab, n, B, C);
    see_all(B, n);
    return 0;
}