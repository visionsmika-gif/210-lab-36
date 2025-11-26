#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

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
    
    // Output BST
    BST.displayInOrder();


    return 0;
}