#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

int getUserChoice();

int main() {
    IntBinaryTree BST;      // Note: the class IntBinaryTree has been modified to hold string values rather than ints
    const string FILE_NAME = "codes.txt";
    
    // Populate the BST with file
    ifstream codesFile;
    codesFile.open(FILE_NAME);
    if (!codesFile) {
        cout << "Unable to open the file " << FILE_NAME << ".\n";
        return 1;
    }
    string code;
    while (getline(codesFile, code)) {
        BST.insertNode(code);
    }
    codesFile.close();

    // Create a menu to add, delete, search, and modify records
    int userChoice;
    do {
        userChoice = getUserChoice();


    } while (userChoice != 0);

    return 0;
}

int getUserChoice() {
    int userChoice;
    cout << "BST Menu:\n";
    cout << "[1] Insert a node\n";
    cout << "[2] Search for a node\n";
    cout << "[3] Delete a node\n";
    cout << "[4] Display BST\n";
    cout << "[0] Quit\n";
    cin >> userChoice;

    return userChoice;

}