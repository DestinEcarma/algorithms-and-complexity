#include "../common/doubly-heighted-node.hpp"
#include "include/helper.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

#define MAX 10

int main() {
    DoublyHNode<int> *head = nullptr;

    srand(69);

    for (int i = 0; i < MAX; i++) {
        int value = rand() % 100;

        cout << "Inserting " << value << endl;

        avl_insert(head, value);
    }

    cout << "BST: " << *head << endl;
    cout << "Head value: " << head->value << endl << endl;

    cout << "Deleting the root node..." << endl;

    avl_delete(head, head->value);

    cout << "BST: " << *head << endl;

    cout << "Head value: " << head->value << endl;

    return 0;
}
