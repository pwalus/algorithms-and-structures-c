#include <iostream>

using namespace std;

struct Node {
    Node *next;
    int key;
    int value;

    int hash_key(int value, int size);

    Node(int value, int size) {
        this->next = NULL;
        this->value = value;
        this->key = hash_key(value, size);
    }
};

struct HashTable {
    Node **table;
    int size;

    HashTable(int size) {
        this->size = size;
        this->table = new Node *[size];
        for (int i = 0; i < size; ++i) {
            this->table[i] = NULL;
        }
    }
    bool isCorrect(){
        Node **ht = this->table;
        for (int i = 0; i < this->size; ++i) {
            Node *x = ht[i];
            while(x != NULL){
                Node *temp = ht[x->key];
                bool checker = false;
                while(temp != NULL){
                    if(temp->value == x->value)
                        checker = true;
                }
                if(checker == false)
                    return false;
            }
        }
        return true;
    }
};

int Node::hash_key(int value, int size) {
    return value % size;
}

struct BSTNode{
    BSTNode *left, *right;
    int value;
};

void printBST(BSTNode *x){
    if(x){
        printBST(x->left);
        cout << x->value;
        printBST(x->right);
    }
}

void create( int tab[], int n){

    int tablica[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    BSTNode *x = new BSTNode;
    x->value = tablica[n/2];
    for (int i = 0; i < n; ++i) {



    }


}





int main() {



    return 0;
}