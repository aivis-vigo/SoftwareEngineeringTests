/*
 * C2[9]. Function deleteFirstEvenBeforeOdd, which removes from the list the first even
    number directly followed by an odd number. E.g. {2,3,8,4,5}→{3,8,4,5};
    {2,4,8,6,5}→{2,4,8,5}; {2,4,8,6,-2}→{2,4,8,6,-2} (nothing deleted, only even
    numbers); {1,3,5,9}→{1,3,5,9} (nothing deleted, only odd numbers)
 */

#include <iostream>

using namespace std;

struct node {
    int data = 0;
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

    node *removeFirstEvenBeforeOdd(node *start) {
        node* current = start;
        node* prev = nullptr;

        while (current != nullptr && current->next != nullptr) {
            if (current->data % 2 == 0 && current->next->data % 2 != 0) {
                if (prev == nullptr) {
                    // If the first element is even followed by odd
                    start = current->next;
                    current->next = nullptr;
                    return start;
                } else {
                    // linking list skipping over the unwanted value
                    prev->next = current->next;
                    // returning link with new order
                    return start;
                }
            }

            prev = current;
            current = current->next;
        }

        return start;
    }
};

int main() {
    int numbers[5] = {2, 4, 8, 6, 5};

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

    list = list->removeFirstEvenBeforeOdd(list);

    cout << "After: " << endl;
    list->display();

    return 0;
}