//
// Created by Patryk Waluś on 16.06.2017.
//

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

int n = 6;

int DFS(int v) {
    visited[v] = 1;
    int result = 1;
    for (int i = 0; i < edgescount[v]; ++i) {
        int q = edges[v][i];
        if (visited[q] == 0) {
            result += DFS(q);
        }
    }
    return result;
}


//BFS - reprezentacja grafu -> tablicowa z dodatkową tablicą przechowującą ilość sąsiadów danego wierzchołka
// edges, edgescount, visited, queue

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


int BFS(Q *queue, int v) {
    dist[v] = 0;
    queue->push(v);
    while (queue->empty() != 0) {
        int r = queue->pop();
        for (int i = 0; i < edgescount[r]; ++i) {
            int s = edges[r][i];
            if (dist[s] == -1) {
                queue->push(s);
                dist[s] = dist[r] + 1;
            }
        }
    }
}


int main() {
    for (int i = 0; i < n; ++i) {
        dist[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        visited[i] = 0;
    }

    cout << "DFS: " <<  DFS(0) << endl;


    cout << "BFS: "  << endl;

    Q *queue = new Q;
    queue->count = 0;
    queue->first = NULL;
    BFS(queue, 0);
    cout << dist[0] << endl;
    cout << dist[1]<< endl;
    cout << dist[2]<< endl;
    cout << dist[3]<< endl;
    cout << dist[4]<< endl;
    cout << dist[5]<< endl;



    return 0;
}