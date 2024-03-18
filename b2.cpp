/*
 * B2[9]. Function removeExtraAdjacentSpaces, which rewrites the text of f to another file
 * the way all extra adjacent spaces are removed (any sequence of spaces is replaced by
 * one space). E.g. (* denotes space) “*alpha*beta***gamma*******delta” →
 * “*alpha*beta*gamma*delta”
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string removeExtraAdjacentSpace(string &line) {
    string result;
    bool is_space = false;

    for (char character: line) {
        if (character == ' ') {
            if (!is_space) {
                result += character;
                is_space = true;
            }
        } else {
            result += character;
            is_space = false;
        }
    }

    return result;
}

int main() {
    ifstream input_file;
    ofstream output_file;
    string input_path = "/your/path/to/file";
    string output_path = "/your/path/to/file";
    string current_line;

    input_file.open(input_path);
    output_file.open(output_path);

    getline(input_file, current_line);

    while (input_file) {
        string processed_line = removeExtraAdjacentSpace(current_line);

        output_file << processed_line << endl;

        getline(input_file, current_line);
    }

    input_file.close();
    output_file.close();

    return 0;
}