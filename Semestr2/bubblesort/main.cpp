#include <iostream>

using namespace std;
void see_all(int tab[], int n);

void bubble_sort(int tab[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (tab[i] < tab[j])
                swap(tab[i], tab[j]);
        }
    }
}

void insertion_sort(int tab[], int n) {
    for (int i = 1; i < n; ++i) {
        int j = i - 1;
        int x = tab[i];
        while (j >= 0 && tab[j] > x) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = x;
    }
}


void selection_sort(int tab[], int n) {
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (tab[j] < tab[min])
                min = j;
        }
        swap(tab[min], tab[i]);
    }
}


int partition(int tab[], int p, int r) {
    int x = tab[r];
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (tab[j] < x) {
            i++;
            swap(tab[j], tab[i]);
        }
    }
    swap(tab[i + 1], tab[r]);

    return i + 1;
}

void quicksort(int tab[], int p, int r) {
    if (p < r) {
        int q = partition(tab, p, r);
        quicksort(tab, p, q - 1);
        quicksort(tab, q + 1, r);

    }
}

void merge(int tab1[], int n1, int tab2[], int n2, int tab3[]) {
    int i = 0;
    int j = 0;
    while (i < n1 || j < n2) {
        if (i == n1) {
            tab3[i + j] = tab2[j];
            j++;
        } else if (j == n2) {
            tab3[i + j] = tab1[i];
            i++;

        } else if (tab1[i] < tab2[j]) {
            tab3[i + j] = tab1[i];
            i++;
        } else {
            tab3[i + j] = tab2[j];
            j++;
        }
    }
}

void mergesort(int tab[], int n) {
    if (n <= 1)
        return;

    int *tab2 = new int[n];
    for (int i = 0; i < n; ++i) {
        tab2[i] = tab[i];
    }

    int half = n / 2;
    mergesort(tab2, half);
    mergesort(tab2 + half, n-1);
    merge(tab2, half, tab2 + half, n - half, tab);

}

void see_all(int tab[], int n) {
    cout << "Tablica: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << tab[i] << endl;
    }
}

int main() {
    int tab[11] = {5, 12, 1, 2, 123, 45, 32, 12, 1, 13, 3};
    int n = 11;
    mergesort(tab, n);
    see_all(tab, n);
    return 0;
}