/*
 * B1[5]. Function countExtraAdjacentSpaces, which counts excessive spaces (any
 * sequence of spaces of length n contains n-1 excessive spaces). E.g. (* denotes
 * space), “alpha***beta**gamma” → 3
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countExtraAdjacentSpaces(string &line) {
    int extra_spaces = 0;
    int consecutive_spaces = 0;

    for (char character: line) {
        if (character == ' ') {
            consecutive_spaces++;
        } else {
            extra_spaces += max(0, consecutive_spaces - 1);
            consecutive_spaces = 0;
        }
    }

    return extra_spaces;
}

int main() {
    ifstream input_file;
    string input_path = "/Users/Aivis/CLionProjects/SoftwareEngineeringTests/with_spaces.txt";
    string current_line;

    input_file.open(input_path);
    getline(input_file, current_line);

    while (input_file) {
        int extra_spaces = countExtraAdjacentSpaces(current_line);
        cout << "Adjacent spaces in line: " << extra_spaces << endl;

        getline(input_file, current_line);
    }

    input_file.close();

    return 0;
}
