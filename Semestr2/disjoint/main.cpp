#include <iostream>

using namespace std;

int tab[20];
int n = 20;

void make_set() {
    for (int i = 0; i < n; ++i) {
        tab[i] = i;
    }
}

int find_set(int i) {
    return tab[i];
}

void make_union(int a, int b) {
    int xa = find_set(a);
    int xb = find_set(b);
    if (xa != xb) {
        for (int i = 0; i < n; ++i) {
            if (tab[i] == xb) {
                tab[i] = xa;
            }
        }
    } else{
        cout << "Już jest w zbiorze" << endl;
    }
}

void see_all(int tab[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << i << " : " <<tab[i] << endl;
    }
}

int main() {
    make_set();
    make_union(2, 4);
    make_union(2, 6);
    make_union(2, 15);
    make_union(2, 13);
    make_union(2, 19);
    make_union(1, 3);
    make_union(1, 5);
    make_union(1, 10);
    make_union(1, 2);


    see_all(tab, n);
    return 0;
}