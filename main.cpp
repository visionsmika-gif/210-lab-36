#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

// Functions for the menu.
int getUserChoice();
void insertRecord(IntBinaryTree& BST);
void deleteRecord(IntBinaryTree& BST);
void modifyRecord(IntBinaryTree& BST);
void displayBST(const IntBinaryTree& BST);

int main() {
    IntBinaryTree BST;                      // Note: the class IntBinaryTree has been modified to hold string values rather than ints.
    const string FILE_NAME = "codes.txt";
    
    // Populate the BST using the file.
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

    // Print a menu to add, delete, search, and modify records.
    int userChoice;
    do {
        userChoice = getUserChoice();
        cin.ignore();
        if (userChoice == 1) {          // [1] Insert a node
            insertRecord(BST);
        }
        else if (userChoice == 2) {     // [2] Delete a node
            deleteRecord(BST);
        }
        else if (userChoice == 3) {     // [3] Modify a node
            modifyRecord(BST);
        }
        else if (userChoice == 4) {     // [4] Display BST
            displayBST(BST);
        }
        cout << "\n";
    } while (userChoice != 0);          // [0] Quit

    return 0;
}

// Function to print a menu of choices and return the user's choice (an int).
int getUserChoice() {
    int userChoice;
    cout << "BST Menu:\n";
    cout << "[1] Insert a record\n";
    cout << "[2] Delete a record\n";
    cout << "[3] Search for a record\n";
    cout << "[4] Modify a record\n";
    cout << "[5] Display BST\n";
    cout << "[0] Quit\n";

    // Prompt the user for a choice and validate it.
    do {
        cout << "Choice --> ";
        cin >> userChoice;
        if (userChoice < 0 || userChoice > 5) {
            cout << "ERROR: Invalid choice. Please enter a number between 0-5.\n";
        }
    } while (userChoice < 0 || userChoice > 5);

    return userChoice;

}

// Function to insert a new record to the BST.
void insertRecord(IntBinaryTree& BST) {
    // Prompt the user for a value to insert.
    string val;
    cout << "Enter a string value to insert: ";
    getline(cin, val);
    BST.insertNode(val);
    cout << val << " successfully inserted!\n";
}

// Function to delete a record from the BST.
void deleteRecord(IntBinaryTree& BST) {
    // Prompt the user for a value to delete.
    string val;
    cout << "Enter a string value to delete: ";
    getline(cin, val);

    // Delete the value if it exists in the BST; otherwise delete nothing.
    if (BST.searchNode(val)) {
        BST.remove(val);
        cout << val << " successfully deleted!\n";
    }
    else {
        cout << "Could not find " << val << ". Nothing deleted.\n";
    }
}

// Function to modify a record from the BST.
// It deletes an existing record and inserts a new one.
void modifyRecord(IntBinaryTree& BST) {
    // Prompt the user for a value to modify.
    string oldVal;
    cout << "Enter a string value to modify: ";
    getline(cin, oldVal);

    // If the value exists in the BST, delete it and prompt for a new value; otherwise modify nothing.
    if (BST.searchNode(oldVal)) {
        BST.remove(oldVal);
        
        cout << "Enter the new string value: ";
        string newVal;
        getline(cin, newVal);

        BST.insertNode(newVal);
        cout << newVal << " successfully inserted!\n";
    }
    else {
        cout << "Could not find " << oldVal << ". Nothing modified.\n";
    }
}

// Function to display the BST.
// It displays in inorder, preorder, or postorder, according to the user's choice.
void displayBST(const IntBinaryTree& BST) {
    // Allow the user to choose between inorder, preorder, or postorder.
    int userChoice;
    cout << "\nEnter which display mode to use:\n";
    cout << "[1] Inorder\n";
    cout << "[2] Preorder\n";
    cout << "[3] Postorder\n";
    // Validate the user's choice.
    do {
        cout << "Choice --> ";
        cin >> userChoice;
        if (userChoice < 1 || userChoice > 3) {
            cout << "ERROR: Invalid choice. Please enter a number between 1-3.\n";
        }
    } while (userChoice < 1 || userChoice > 3);
    // Display according to the user's choice.
    if (userChoice == 1) {
        BST.displayInOrder();
    }
    else if (userChoice == 2) {
        BST.displayPreOrder();
    }
    else if (userChoice == 3) {
        BST.displayPostOrder();
    }
}