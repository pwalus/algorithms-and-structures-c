//
// Created by Patryk Waluś on 16.06.2017.
//

#include <iostream>

using namespace std;


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


// Sortowanie topologiczne - graf acykliczny - nie potrzeba visited
// edges, edgescount, queue, deg

int edges[6][6] = {{2},
                   {0, 2},
                   {},
                   {0, 1, 4},
                   {1, 2},
                   {0, 4}
};
int edgescount[6] = {1, 2, 0, 3, 2, 2};

int deg[6] = {0, 0, 0, 0, 0, 0};

int result[6];

int n = 6;

int sort_top(Q *queue) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < edgescount[i]; ++j) {
            deg[edges[i][j]]++;
        }
    }

    for (int k = 0; k < n; ++k) {
        if (deg[k] == 0)
            queue->push(k);
    }

    for (int l = 0; l < n; ++l) {
        if( queue->empty() != 0) {
            int s = queue->pop();
            for (int i = 0; i < edgescount[s]; ++i) {
                if (--deg[edges[s][i]] == 0)
                    queue->push(edges[s][i]);
            }
            result[l] = s;
        }

    }

}

int main() {
    Q *queue = new Q;
    queue->count = 0;
    queue->first = NULL;
    sort_top(queue);
    for (int i = 0; i < n; ++i) {
        cout << result[i] << endl;
    }
    return 0;
}