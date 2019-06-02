#include <iostream>

using namespace std;

struct node {
    int val;
    node *parent;
    node *left;
    node *right;

    node(int value) {
        this->val = value;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};

struct bst {
    node *root;

    bst(int val) {
        this->root = new node(val);
    }

    node *push(int value) {
        node *x = new node(value);
        node *temp = this->root;
        node *parent = this->root->parent;
        while (temp != NULL) {
            parent = temp;
            if (value < temp->val) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        if (value < parent->val)
            parent->left = x;
        else
            parent->right = x;

        x->parent = parent;
        return x;
    }

    void in_order(node *x) {
        if (x) {
            in_order(x->left);
            cout << x->val << endl;
            in_order(x->right);
        }
    }

    node *search(int value) {
        node *temp = this->root;
        while (temp) {
            if (value == temp->val)
                return temp;
            else if (value < temp->val)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return NULL;
    }

    void min(node *x) {
        while (x->left) {
            x = x->left;
        }
        cout << " ----------- " << x->val << endl;
    }

    void max_node(node *x) {
        while (x->right) {
            x = x->right;
        }
        cout << " ----------- " << x->val << endl;
    }

    void successor(int n) {
        node *x = search(n);
        if (!x)
            return;

        if (x->right != NULL) {
            this->min(x->right);
            return;
        }

        node *parent = x->parent;
        while (parent != NULL && parent->right == x) {
            x = parent;
            parent = x->parent;
        }
        if (parent != NULL)
            cout << "SUCCESSOR: " << parent->val;
    }

    void predessor(int n) {
        node *x = search(n);
        if (!x)
            return;
        if (x->left != NULL) {
            this->max_node(x->left);
            return;
        }
        node *parent = x->parent;
        while (parent != NULL && parent->left == x) {
            x = parent;
            parent = x->parent;
        }
        if (parent != NULL)
            cout << "PREDESSOR: " << parent->val;
    }

    int height(node *x) {
        if(!x){
            return 0;
        }
        return (1 + max(height(x->left), height(x->right)));
    }


};

int main() {
    bst *tree = new bst(25);
    tree->push(4);
    tree->push(2);
    tree->push(7);
    tree->push(43);
    tree->push(28);
    tree->in_order(tree->root);
    tree->predessor(28);
    cout << endl;
    cout << "HEIGHT:" << tree->height(tree->root);
    return 0;
}