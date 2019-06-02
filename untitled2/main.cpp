#include <iostream>

using namespace std;

struct node{
    int val;
    node *next;
    node *rep;
    node(){
        next = NULL;
        rep = this;
    }
};


node *make_set(int val){
    node *temp = new node;
    temp->val = val;
    return temp;
}

node *find_set(node *x){
    return x->rep;
}

node *union_set(node *x, node *y){
    if(x->rep == y->rep){
        cout << "Już są w tym samym zbiorze" << endl;
        return x->rep;
    }

    node *temp = x->rep;
    while(temp != NULL){
        temp->rep = y->rep;
        temp = temp->next;
    }

}

int main(){
    node **tab = new node*[10];
    for (int i = 0; i < 10; ++i) {
        tab[i] = make_set(i);
    }

    union_set(tab[2], tab[3]);
    union_set(tab[3], tab[4]);
    union_set(tab[2], tab[5]);
//    union_set(tab[2], tab[4]);

    node *x = tab[3]->rep;
    while(x->next != NULL){
        cout << x->val << endl;
        x = x->next;
    }

    return 0;
}