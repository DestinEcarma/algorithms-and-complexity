#include "../common/doubly-node.hpp"
#include "include/helper.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

#define MAX 10

int main() {
    DoublyNode<int> *head = nullptr;

    srand(69);

    for (int i = 0; i < MAX; i++) {
        int value = rand() % 100;

        cout << "Inserting " << value << endl;

        bst_insert(head, value);
    }

    cout << "BST: " << head->to_string() << endl;
    cout << "Head value: " << head->value << endl << endl;

    cout << "Deleting the root node..." << endl;

    bst_delete(head, head->value);

    cout << "BST: " << head->to_string() << endl;

    cout << "Head value: " << head->value << endl;

    return 0;
}
