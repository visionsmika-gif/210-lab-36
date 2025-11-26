#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

int getUserChoice();
void insertNode(IntBinaryTree& BST);
void deletNode(IntBinaryTree& BST);

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
        cin.ignore();

        if (userChoice == 1) {          // [1] Insert a node
            insertNode(BST);
        }
        else if (userChoice == 2) {     // [2] Delete a node
            deleteNode(BST);
        }
        else if (userChoice == 3) {     // [3] Modify a node

        }
        else if (userChoice == 4) {     // [4] Display BST

        }

        cout << "\n";
    } while (userChoice != 0);          // [0] Quit

    return 0;
}

int getUserChoice() {
    int userChoice;
    cout << "BST Menu:\n";
    cout << "[1] Insert a node\n";
    cout << "[2] Delete a node\n";
    cout << "[3] Modify a node\n";
    cout << "[4] Display BST\n";
    cout << "[0] Quit\n";
    cin >> userChoice;

    return userChoice;

}

void insertNode(IntBinaryTree& BST) {
    string val;
    cout << "Enter a string value to insert: ";
    getline(cin, val);
    BST.insertNode(val);
    cout << val << " successfully inserted!\n";
}

void deleteNode(IntBinaryTree& BST) {
    string val;
    cout << "Enter a string value to delete: ";
    getline(cin, val);

    if 

    BST.remove(val);
    cout << val << " successfully deleted!\n";
}