/*
 * Write C++ function (only function not the whole program) to process one-
    way linked list of int. Already created non-empty linked list is supplied as pointer to
    the first element.

    C1[5]. Function incDecOdd, which increases by 1 negative odd numbers, but decreases
    by 1 positive odd numbers. E.g., {-2,3,-7,-4,5}→{-2,2,-6,-4,4}
 */

#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
public:
    node(int x) : data(x), next(nullptr) {}

    ~node() {
        if (next != nullptr) delete next;
    }

    node *insert(int value) {
        node *head = new node(value);
        head->next = this;
        return head;
    }

    void display() {
        cout << data << " ";
        if (next != nullptr) next->display();
    }

    node *increaseDecrease() {
        node *list = this;

        while (list->next != nullptr) {
            if (list->data < 0 & list->data % 2 != 0) {
                list->data++;
            }

            if (list->data > 0 & list->data % 2 != 0) {
                list->data--;
            }

            list = list->next;
        }

        return this;
    }
};

int main() {
    int numbers[5] = {-2, 3, -7, -4, 5};

    node *list;
    bool first = true;

    for (int i = 4; i > -1; i--) {
        if (first) {
            list = new node(numbers[i]);
            first = false;
        } else {
            list = list->insert(numbers[i]);
        }
    }

    cout << "Before: " << endl;
    list->display();
    cout << endl;

    list = list->increaseDecrease();

    cout << "After: " << endl;
    list->display();

    return 0;
}