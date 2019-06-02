#include <iostream>

using namespace std;

struct node {
    int key;
    int height;
    node **next;

    node(int key, int height) {
        this->key = key;
        this->height = height;
        this->next = new node *[height];
        for (int i = 0; i < height; ++i) {
            this->next[i] = NULL;
        }
    }
};

struct skip_list {
    node *first;
    node *last;
    int max_height;

    skip_list(int height) {
        this->max_height = height;
        this->first = new node(0, max_height);
        this->last = new node(99999, max_height);
        for (int i = 0; i < height; ++i) {
            this->first->next[i] = this->last;
        }
    }

    int gen_level() {
        int i = 1;
        while ((rand() % 100) < 50) i++;
        if (i < max_height) return i;
        else return max_height;
    }

    void push(int val){
        node *temp = new node(val, this->gen_level());
        node *x = this->first;
        for (int i = this->max_height; i >= temp->height ; --i) {
            while(temp->key > x->next[i]->key){
                x = x->next[i];
            }
        }
        for (int j = temp->height-1; j >= 0 ; --j) {
            while(temp->key > x->next[j]->key){
                x = x->next[j];
            }
            temp->next[j] = x->next[j];
            x->next[j] = temp;
        }
    }

    bool find(int key){
        node *x = this->first;
        for (int i = this->max_height-1; i > 0; --i) {
            while(key > x->next[i]->key)
                x = x->next[i];
        }
        if(x->next[0]->key == key)
            return true;
    }

    void pop(int key){
        node *x = this->first;
        for (int i = this->max_height-1; i > 0; --i) {
            while(key > x->next[i]->key)
                x = x->next[i];
        }

        for (int j = x->height-1; j >= 0 ; --j) {
            x->next[j] = x->next[j]->next[j];
        }
    }


};

int main() {
    srand(time(NULL));
    skip_list *sl = new skip_list(20);
    return 0;
}