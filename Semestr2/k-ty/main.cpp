#include <iostream>

using namespace std;

void see_all(int tab[], int n) {
    cout << "Tablica: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << tab[i] << endl;
    }
}

int parent(int n) {
    return n / 2;
}

int left_l(int n) {
    return (2 * n) + 1;
}

int right_r(int n) {
    return (2 * n) + 2;
}

void heapify(int tab[], int x, int n) {

    int left = left_l(x);
    int right = right_r(x);
    int largest = x;
    if (left < n && tab[left] > tab[largest])
        largest = left;
    if (right < n && tab[right] > tab[largest])
        largest = right;
    if (largest != x) {
        swap(tab[x], tab[largest]);
        heapify(tab, largest, n);
    }

}

void build_heap(int tab[], int n) {
    for (int i = n - 1; i >= 0; --i) {
        heapify(tab, i, n);
    }
}

void heapsort(int tab[], int n) {
    build_heap(tab, n);
    for (int i = n - 1; i > 0; --i) {
        swap(tab[0], tab[i]);
        heapify(tab, 0, i);
    }
}

void increase(int tab[], int x, int val) {
    tab[x] = val;
    int p = parent(x);
    while(p > 0 && tab[p] < tab[x]){
        swap(tab[p], tab[x]);
        x = p;
        p = parent(x);
    }

}

int max(int tab[], int n){
    int x = tab[0];
    swap(tab[0], tab[n-1]);
    heapify(tab,0,n);

}

void k_ty(int tab[], int n, int k){
    build_heap(tab,n);
    for (int i = n-1; i > 0 ; --i) {
        if(k == 0) break;
        swap(tab[0], tab[i]);
        heapify(tab,0, i);
        k--;
    }
}


int main() {
    int tab[13] = {12, 1, 2, 5, 21, 32, 21, 4, 322, 23, 11, 122, 99};
    int n = 13;
    int k =2;
    k_ty(tab, n, k);
    cout << "K-ty największy element: " << tab[n-k] << endl;
    see_all(tab, n);
    return 0;
}