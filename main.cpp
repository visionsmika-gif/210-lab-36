#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

int main() {
    IntBinaryTree BST;      // Note: the class IntBinaryTree has been modified to hold string values rather than ints
    const string FILE_NAME = "codes.txt";
    
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
    
    BST.displayPostOrder();


    /*
    // Test inserting nodes
    BST.insertNode("Test String 1");
    BST.insertNode("Test String 2");
    BST.insertNode("Test String 3");

    // Test displays
    cout << "Inorder:\n";
    BST.displayInOrder();
    cout << "Preorder:\n";
    BST.displayPreOrder();
    cout << "Postorder:\n";
    BST.displayPostOrder();

    // Test find nodes
    if (BST.searchNode("Test String 3")) {
        cout << "Test String 3 found\n";
    }
    else {
        cout << "Test String 3 not found\n";
    }

    // Test removing nodes
    cout << "Removing Test String 3:\n";
    BST.remove("Test String 3");
    if (BST.searchNode("Test String 3")) {
        cout << "Test String 3 found\n";
    }
    else {
        cout << "Test String 3 not found\n";
    }
    */

    return 0;
}