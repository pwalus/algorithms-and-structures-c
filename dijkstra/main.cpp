#include <iostream>

using namespace std;

// KOLEJKA PRIORYTETOWA

struct node {
    int value;
    int prior;
    node *next;

    node(int value, int prior) {
        this->value = value;
        this->prior = prior;
        this->next = NULL;
    }
};

struct queue {
    node *first;
    int length;

    queue() {
        this->first = NULL;
        this->length = 0;
    }

    void push(int v, int p) {
        node *temp = new node(v, p);
        node *x = this->first;
        if (x == NULL) {
            this->first = temp;
        } else {
            while (x->next != NULL && x->prior < p) {
                x = x->next;
            }
            if (this->first == x) {
                this->first = temp;
                temp->next = x;
            } else {
                temp->next = x->next;
                x->next = temp;
            }
        }
        this->length++;

    }

    int pop() {
        int x = this->first->value;
        this->first = this->first->next;
        this->length--;
        return x;
    }

    int empty() {
        return this->length;
    }

    void see() {
        node *x = this->first;
        while (x != NULL) {
            cout << "W: " << x->value << "\tP:  " << x->prior << endl;
            x = x->next;
        }
    }
};

int edges[6][6] = {
        {1, 4},
        {2},
        {3, 5},
        {1},
        {5},
        {0, 3}
};

int edgescount[6] = {2,
                     1,
                     2,
                     1,
                     1,
                     2};

int edgesweight[6][6] = {
//       0 1 2 3 4 5
        {0, 3, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 3, 0, 1},
        {0, 3, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2},
        {6, 0, 0, 1, 0, 0}
};

int visited[6];

int d[6];
int p[6];

int n = 6;
int s;
int active;
int weight;

void dijkstra(queue *Q, int start = 0) {
    for (int i = 0; i < n; ++i) {
        visited[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        d[i] = 99999;
        p[i] = NULL;
    }
    d[start] = 0;
    Q->push(start, 0);
    while (Q->empty() != 0) {
        s = Q->pop();
        if (visited[s] == 1) continue;

        for (int i = 0; i < edgescount[s]; ++i) {
            active = edges[s][i];
            weight = d[s] + edgesweight[s][active];
            if (d[active] > weight) {
                d[active] = weight;
                p[active] = s;
                Q->push(active, weight);
            }
        }

    }

}

int main() {
    queue *Q = new queue;
    dijkstra(Q, 0);


    cout << "DISTANCE:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << d[i] << "\t";
    }
    cout << endl;

    cout << "PRZODEK:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << p[i] << "\t";
    }
    cout << endl;

    return 0;
}