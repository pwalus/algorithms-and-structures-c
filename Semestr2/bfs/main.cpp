#include <iostream>

using namespace std;

//BFS - reprezentacja grafu -> tablicowa z dodatkową tablicą przechowującą ilość sąsiadów danego wierzchołka
// edges, edgescount, visited, queue


int edges[6][6] = {{1, 5},
                   {},
                   {1, 3},
                   {4},
                   {1, 5},
                   {1, 2}};

int edgescount[6] = {2, 0, 2, 1, 2, 2};

int visited[6];

int n = 6;

int dist[6];

/*
 * KOLEJKA
 */

struct node {
    int value;
    node *next;

    node(int val) {
        this->next = NULL;
        this->value = val;
    }
};

struct Q {
    node *first;
    int count;

    void push(int key) {
        node *temp = new node(key);
        node *x = this->first;
        if (x == NULL) {
            this->first = temp;
        } else {
            while (x->next != NULL) {
                x = x->next;
            }
            x->next = temp;
        }
        this->count++;

    }

    int pop() {
        node *x = this->first;
        this->first = this->first->next;
        return x->value;
    }

    int empty() {
        int x = this->count;
        this->count--;
        return x;
    }
};

void bfs(Q *que, int v) {
    dist[v] = 0;
    que->push(v);
    while (que->empty() > 0) {
        int s = que->pop();
        for (int i = 0; i < edgescount[s]; ++i) {
            int q = edges[s][i];
            if (dist[q] == -1) {
                dist[q] = 1 + dist[s];
                que->push(q);
            }
        }
    }
}

void see_all(int tab[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << tab[i] << endl;
    }
}

int main() {
    for (int i = 0; i < n; ++i) {
        dist[i] = -1;
    }
    Q *qu = new Q;
    qu->first = NULL;
    bfs(qu, 0);
    see_all(dist, n);


    return 0;
}