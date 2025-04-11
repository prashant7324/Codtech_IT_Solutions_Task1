#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "example.txt";
    string data;

    // 1. Create and write to a file
    ofstream writeFile(filename);  // This will create the file and open it for writing
    if (writeFile.is_open()) {
        writeFile << "This is the first line.\n";
        writeFile << "This is the second line.\n";
        writeFile.close();
        cout << "File created and data written successfully.\n";
    } else {
        cerr << "Unable to open file for writing.\n";
    }

    // 2. Append data to the file
    ofstream appendFile(filename, ios::app);  // Open in append mode
    if (appendFile.is_open()) {
        appendFile << "This is an appended line.\n";
        appendFile.close();
        cout << "Data appended successfully.\n";
    } else {
        cerr << "Unable to open file for appending.\n";
    }

    // 3. Read data from the file
    ifstream readFile(filename);
    if (readFile.is_open()) {
        cout << "\nContents of the file:\n";
        while (getline(readFile, data)) {
            cout << data << endl;
        }
        readFile.close();
    } else {
        cerr << "Unable to open file for reading.\n";
    }

    return 0;
}
