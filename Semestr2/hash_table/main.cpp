#include <iostream>

using namespace std;

struct node {
    int val;
    int key;
    node *next;

    node(int value) {
        this->val = value;
        this->next = NULL;
    };
};

struct hash_table {
    node **table;
    int height;

    hash_table(int h) {
        this->height = h;
        this->table = new node *[h];
        for (int i = 0; i < h; ++i) {
            this->table[i] = NULL;
        }
    }

    int hash_key(int value) {
        return value % height;
    }

    void push(int value) {
        node *x = new node(value);
        x->key = hash_key(value);

        if (this->table[x->key] == NULL) {
            this->table[x->key] = x;
        } else {
            node *temp = table[x->key];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = x;
        }
    }

    void pop();

    void see_all() {
        for (int i = 0; i < height; ++i) {
            node *x = table[i];
            cout << i << " : ";
            while (x != NULL) {
                cout << x->val << " ";
                x = x->next;
            }
            cout << endl;
        }
    }
};

int main() {
    hash_table *ht = new hash_table(20);
    ht->push(23);
    ht->push(123);
    ht->push(54);
    ht->see_all();
    return 0;
}