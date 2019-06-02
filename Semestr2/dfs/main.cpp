#include <iostream>

using namespace std;

//DFS - reprezentacja grafu -> tablicowa z dodatkową tablicą przechowującą ilość sąsiadów danego wierzchołka

int edges[6][6] = {{1, 5},
                   {},
                   {1, 3},
                   {4},
                   {1, 5},
                   {1, 2}};

int edgescount[6] = {2, 0, 2, 1, 2, 2};

int visited[6];
int result[6];

int n = 6;

int dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < edgescount[v]; ++i) {
        int q = edges[v][i];
        if (visited[q] == 0) {
            result[q] = 1 + result[v];
            dfs(q);
        }
    }
    return result[v];

}

void see_all(int tab[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << tab[i] << endl;
    }
}

int main() {
    for (int i = 0; i < n; ++i) {
        visited[i] = 0;
        result[i] = 0;
    }
    dfs(0);
    see_all(result, n);
    return 0;
}