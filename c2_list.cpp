/*
 * C2[9]. Function deleteFirstEvenBeforeOdd, which removes from the list the first even
    number directly followed by an odd number. E.g. {2,3,8,4,5}→{3,8,4,5};
    {2,4,8,6,5}→{2,4,8,5}; {2,4,8,6,-2}→{2,4,8,6,-2} (nothing deleted, only even
    numbers); {1,3,5,9}→{1,3,5,9} (nothing deleted, only odd numbers)
 */

#include <iostream>
#include <list>

using namespace std;

// * - to access the value similarly like in linked list
void removeFirstEvenBeforeOdd(list<int> &lst) {
    auto it = lst.begin();

    while (it != lst.end()) {
        if (*it % 2 == 0) {
            auto next = std::next(it);
            if (next != lst.end() && *next % 2 != 0) {
                lst.erase(it);
                break;
            }
        }
        ++it;
    }
}

void displayList(list<int> &lst) {
    for (int number: lst) {
        cout << number << " ";
    }
}

int main() {
    list<int> list;

    int value[5] = {2, 3, 8, 4, 5};

    for (int i = 4; i > -1; i--) {
        list.push_front(value[i]);
    }

    removeFirstEvenBeforeOdd(list);

    displayList(list);

    return 0;
}