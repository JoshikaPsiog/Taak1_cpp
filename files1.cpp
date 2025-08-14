#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//this is write fuction
void copyFileContents(const string &srcFile, const string &destFile) {
    ifstream source(srcFile);
    ofstream destination(destFile);

    if (!source.is_open()) {
        cout << "Error: cannot open " << srcFile << endl;
        return;
    }
    if (!destination.is_open()) {
        cout << "Error: cannot open " << destFile << endl;
        return;
    }

    string line;
    while (getline(source, line)) {
        destination << line << endl;
    }
    cout << destFile << " is copied" << endl;
}

// this is the read function
void readFile(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Cannot open " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        
    }
}

int main() {
    ifstream files1("files1.csv");

    if (files1.is_open()) {
        readFile("files1.csv");
        files1.seekg(0, ios::end);

        if (files1.tellg() == 0) {
            cout << "files1 is empty" << endl;
            return 0;
        } else {
            files1.seekg(0, ios::beg);
        }
    } else {
        cout << "files1 does not exist" << endl;
        return 0;
    }
    files1.close();

    ofstream files2("files2.csv", ios::app); // open for writing/appending

    if (files2.is_open()) {
        files2.seekp(0, ios::end);
        if (files2.tellp() == 0) {
            cout << "files2 is empty" << endl;
            copyFileContents("files1.csv", "files2.csv");
        }
    } else {
        cout << "files2 is not found" << endl;
        ofstream createFile("files2.csv");
        cout << "file2 is created" << endl;
        createFile.close();
        copyFileContents("files1.csv", "files2.csv");
    }

    return 0;
}
