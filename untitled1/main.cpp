#include <iostream>

using namespace std;

struct node{
    node *parent;
    node *left;
    node *right;
    int key;
    node(){
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};

struct bst{
    node *root;
    bst(){
        root = NULL;
    }
    void insert(int key){
        node *temp = new node;
        temp->key = key;

        node *y = NULL;
        node *x = this->root;
        while(x != NULL){
            y = x;
            if(temp->key < x->key)
                x = x->left;
            else
                x = x->right;
        }
        temp->parent = y;
        if(y == NULL)
            this->root = temp;
        else if(temp->key < y->key)
            y->left = temp;
        else
            y->right = temp;

    }
    void inorder(node *x){
        if(x != NULL){
            inorder(x->left);
                cout << x->key << endl;
            inorder(x->right);
        }
    }
    void minimum(node *x){
        if(x->left != NULL)
            minimum(x->left);
        else
            cout << "MIN: "<< x->key << endl;
    }
    void maximum(node *x){
        while(x->right != NULL)
            x = x->right;
        cout << "MAKSIMUM: " << x->key << endl;
    }
    void successor(node *x){
        if(x->right != NULL )
            this->minimum(x->right);
        else{
            node *y = x->parent;
            while( y != NULL and x == y->right){
                x = y;
                y = y->parent;
            }
            cout << y->key << endl;
        }
    }

    void predessor(node *x){
        if(x->left != NULL)
            this->maximum(x->left);
        else{
            node *y = x->parent;
            while(y != NULL and y == x->parent->left){
                x = y;
                y = y->parent;
            }
            cout << "POPRZEDNIK: " << y->key << endl;
        }
    }

};



int main() {
    bst *tree = new bst;
    tree->insert(23);
    tree->insert(12);
    tree->insert(54);
    tree->insert(121);
    tree->insert(33);

    return 0;
}