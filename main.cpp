#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

/* INSTRUCTIONS:
This project contains the same dataset we used in Lab 25: codes comprised of letters and digits. It also contains the class definition file for the IntBinaryTree class.

Modify the class to process the codes found in the codes.txt file, which are strings, rather than integers.

Write a program that creates and populates a BST from these records.

Add interactive, menu-driven functionality to add, delete, search, and modify records.

Milestones to document with your commits, in addition to 10-minute commits (commit must read 'Milestone n' where n is the milestone number):

Project is set up and running using the provided files.
Code modification from int to strings is complete, and your code exercises this for testing.
Your code successfully creates a BST from the records and outputs it using the method of your choosing.
Your code's menu is functional.*/

int main() {
    IntBinaryTree BST;      // Note: the class IntBinaryTree has been modified to hold string values rather than ints

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

    return 0;
}