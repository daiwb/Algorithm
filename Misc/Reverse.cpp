#include <iostream>
using namespace std;

class node {
public:
    int val;
    node *next;
    node() {}
};

void reverse(node *pt) {
    node *T = NULL;
    node *P = pt;
    node *N = P->next;

    while (true) {
        P->next = T;
        T = P;
        P = N;
        if (N == NULL) break;
        N = N->next;
    }
}

void travel(node *pt) {
    while (pt != NULL) {
        cout << pt->val << endl;
        pt = pt->next;
    }
}

int main() {
    node *root = new node();
    node *node1 = new node();
    node *node2 = new node();
    node *node3 = new node();
    node *node4 = new node();

    node4->val = 4;
    node4->next = NULL;

    node3->val = 3;
    node3->next = node4;

    node2->val = 2;
    node2->next = node3;

    node1->val = 1;
    node1->next = node2;

    root->val = 0;
    root->next = node1;;

    reverse(root);
    travel(node4);
    
    return 0;
}
