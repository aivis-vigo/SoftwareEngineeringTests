/*
 * Write C++ function (only function not the whole program) to process one-
    way linked list of int. Already created non-empty linked list is supplied as pointer to
    the first element.

    C1[5]. Function incDecOdd, which increases by 1 negative odd numbers, but decreases
    by 1 positive odd numbers. E.g., {-2,3,-7,-4,5}→{-2,2,-6,-4,4}
 */

#include <iostream>
#include <list>

using namespace std;

void increaseDecrease(list<int> &lst) {
    for (int & number : lst) {
        // Get a reference to the current element through the iterator
        if (number < 0 && number % 2 != 0) {
            number++;
        }
        if (number > 0 && number % 2 != 0) {
            number--;
        }
    }
}

void displayList(list<int> &lst) {
    for (int number: lst) {
        cout << number << " ";
    }
}

int main() {
    list<int> list;

    int value[5] = {-2, 3, -7, -4, 5};

    for (int i = 4; i > -1; i--) {
        list.push_front(value[i]);
    }

    increaseDecrease(list);

    displayList(list);

    return 0;
}