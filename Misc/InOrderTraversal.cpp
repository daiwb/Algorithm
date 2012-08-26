#include <iostream>
using namespace std;

class node {
public:
    node *l_child;
    node *r_child;
    node *parent;
    int value;
    node() {}
};

// Nonrecursive inorder tree traversal without stack
void InOrderTraversal(node *root) {
    node *prev = NULL;
    node *next = NULL;
    node *current = root;
    while (current != NULL) {
        if (prev == current->parent) {
            prev = current;
            next = current->l_child;
        }
        if ((next == NULL) || (prev == current->l_child)) {
            printf("%d\n", current->value);
            prev = current;
            next = current->r_child;
        }
        if ((next == NULL) || (prev == current->r_child)) {
            prev = current;
            next = current->parent;
        }
        current = next;
    }
}

int main() {
    return 0;
}
