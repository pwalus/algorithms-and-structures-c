#include <iostream>

using namespace std;

void binary_search(int tab[], int l, int p, int search) {
    if(l > p){
        cout << "Nie znaleziono"<< endl;
        return;
    }

    int half = (l + p) / 2;
    if(tab[half] == search){
        cout << "Znaleziono: " << search << endl;
        return;
    }

    if (search > tab[half])
        binary_search(tab, half+1, p, search);
    else
        binary_search(tab, l, half-1, search);

}

void see_all(int tab[], int n) {
    cout << "Tablica: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << tab[i] << endl;
    }
}

int main() {
    int tab[20] = {1, 3, 4, 5, 12, 14, 16, 54, 222, 333, 1312, 1444, 1500, 1666, 4545};
    int n = 15;
    binary_search(tab, 0, n, 321312);
    see_all(tab, n);
    return 0;
}