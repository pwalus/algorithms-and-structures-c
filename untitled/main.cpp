#include <iostream>
#include <time.h>
#include <stdlib.h>


using namespace std;

struct node {
    node *next;
    node *prev;
    int key;

    node() {
        next = NULL;
        prev = NULL;
    }
};

struct list {
    node *head;
    node *tail;

    list() {
        head = NULL;
        tail = NULL;
    }

    void see_all();

    void see_back();

    void push_head(int key);

    void push_tail(int key);

    void pop_head();

    void pop_tail();

    void search(int key);
};

void list::see_all() {
    node *x = this->head;
    if (x == NULL) cout << "Lista jest pusta" << endl;
    else {
        cout << "Lista od przodu: " << endl;
        while (x != NULL) {
            cout << x->key << endl;
            x = x->next;
        }
    }
}

void list::see_back() {
    node *x = this->tail;
    if (x == NULL) cout << "Lista jest pusta" << endl;
    else {
        cout << "Lista od tyłu: " << endl;
        while (x != NULL) {
            cout << x->key << endl;
            x = x->prev;
        }
    }
}

void list::push_head(int key) {
    node *temp = new node;
    temp->key = key;

    if (this->head == NULL and this->tail == NULL) {
        this->head = temp;
        this->tail = temp;
        return;
    }

    temp->next = this->head;
    this->head->prev = temp;
    this->head = temp;

}

void list::push_tail(int key) {
    node *temp = new node;
    temp->key = key;

    if (this->head == NULL and this->tail == NULL) {
        this->head = temp;
        this->tail = temp;
        return;
    }

    temp->prev = this->tail;
    this->tail->next = temp;
    this->tail = temp;

}

void list::pop_head() {
    node *x = this->head;

    this->head->next->prev = NULL;
    this->head = this->head->next;
    cout << "USUWAM : " << x->key << endl;
    delete (x);
}


void list::pop_tail() {
    node *x = this->tail;

    this->tail->prev->next = NULL;
    this->tail = this->tail->prev;
    cout << "USUWAM : " << x->key << endl;
    delete (x);
}

void list::search(int key) {
    node *temp = this->head;
    int i = 1;
    while (temp != NULL and temp->key != key) {
        temp = temp->next;
        i++;
    }

    if (temp != NULL && temp->key == key)
        cout << "Znaleziono klucz: " << key << " na pozycji: " << i << endl;
    else
        cout << "Nie ma takiego klucza w liscie" << endl;
}


int parent(int x) {
    return x / 2;
}

int left(int x) {
    return (2 * x) + 1;
}

int right(int x) {
    return (2 * x) + 2;
}

void heapify(int tab[], int n, int k) {
    int l = left(k);
    int r = right(k);
    int max = k;
    if (l < n and tab[l] > tab[max])
        max = l;
    if (r < n and tab[r] > tab[max])
        max = r;
    if (max != k) {
        swap(tab[k], tab[max]);
        heapify(tab, n, max);
    }
}

void build_heap(int tab[], int n) {

    int x = parent(n - 1);
    for (int i = x; i >= 0; i--) {
        heapify(tab, n, i);
    }
}

void heap_sort(int tab[], int n) {
    for (int i = n - 1; i > 0; i--) {
        swap(tab[0], tab[i]);
        heapify(tab, i, 0);
    }


}

void see_all(int tab[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << tab[i] << endl;
    }
}

void insert(int tab[], int x, int key) {

    tab[x] = key;
    while (x > 0 and tab[parent(x)] < tab[x]) {
        swap(tab[x], tab[parent(x)]);
        x = parent(x);
    }

}


int hash_key(int key) {
    return key % 10;
}

struct hash_table {
    int length;
    node **arr;

    hash_table(int length) {
        this->length = length;
        this->arr = new node *[length];
        for (int i = 0; i < length; ++i) {
            this->arr[i] = NULL;
        }
    }

    void see_tab();

    void insert(int key);

    void key_delete(int key);

    bool search(int key);
};

void hash_table::see_tab() {
    node **arr = this->arr;
    for (int i = 0; i < this->length; ++i) {
        while (arr[i] != NULL) {
            cout << "INDEKS: " << i << " - " << arr[i]->key << endl;
            arr[i] = arr[i]->next;
        }
    }
}

void hash_table::insert(int key) {
    int h_key = hash_key(key);

    if (this->search(key)) {
        cout << "ELEMENT JUŻ SIĘ ZNAJDUJE!" << endl;
        return;
    }

    node *x = new node;
    x->key = key;

    if (this->arr[h_key] == NULL) {
        this->arr[h_key] = x;
        return;
    }

    node *arr = this->arr[h_key];
    while (arr->next != NULL) {
        arr = arr->next;
    }
    x->prev = arr;
    arr->next = x;
}


bool hash_table::search(int key) {
    int h_key = hash_key(key);
    node *x = this->arr[h_key];
    while (x != NULL) {
        if (x->key == key)
            return true;
        else
            x = x->next;
    }

    return false;

}

void hash_table::key_delete(int key) {
    int h_key = hash_key(key);
    if (!this->search(key)) {
        return;
    }

    node *x = this->arr[h_key];
    while (x->next != NULL and x->key != key) {
        x = x->next;
    }

    if (x->prev == NULL and x->next == NULL) this->arr[h_key] = NULL;
    else if (x->prev == NULL) {
        this->arr[h_key] = x->next;
        this->arr[h_key]->prev = NULL;
    } else if (x->next == NULL) {
        x->prev->next = NULL;
    } else {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }


}


struct slNode {
    int key;
    int level;
    slNode **next;

    slNode(int key, int level) {
        this->key = key;
        this->level = level;
        next = new slNode *[level];
    }
};

struct skipList {
    slNode *first;
    slNode *last;
    int maxLevel = 10;

    skipList() {
        first = new slNode(0, maxLevel);
        last = new slNode(10000, maxLevel);

        for (int i = 0; i < this->maxLevel; ++i) {
            this->first->next[i] = this->last;
        }
    }

    int gen_level() {
        int i = 1;
        while ((rand() % 100) < 50) i++;
        if (i < maxLevel) return i;
        else return maxLevel;
    }

    void push(int key) {
        slNode *x = new slNode(key, gen_level());
        slNode *temp = this->first;
        for (int i = maxLevel - 1; i > x->level - 1; i--) {
            while (temp->next[i]->key < key)
                temp = temp->next[i];
        }

        for (int j = x->level - 1; j >= 0; --j) {
                while (temp->next[j]->key < key) {
                temp = temp->next[j];
            }
            x->next[j] = temp->next[j];
            temp->next[j] = x;
        }
    }

    bool find(int key) {
        slNode *x = this->first;
        for (int i = this->maxLevel - 1; i > 0; --i) {
            while (x->next[i]->key < key)
                x = x->next[i];
        }

        if (x->next[0]->key == key)
            return true;
        else
            return false;
    }

    void pop(int key) {
        slNode *x = this->first;

        for (int i = maxLevel - 1; i > 0; --i) {
            while (x->next[i]->key < key) {
                x = x->next[i];
            }
        }
        for (int j = x->level - 1; j >= 0; --j) {
            x->next[j] = x->next[j]->next[j];
        }
    }
};

int main() {

    srand(time(NULL));
    skipList *SL = new skipList;
    SL->push(4);
    SL->push(2);
    SL->push(8);
    SL->push(1);
    SL->push(3);
    SL->pop(3);

    return 0;
}