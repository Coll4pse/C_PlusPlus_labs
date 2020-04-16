#include <iostream>
#include <cstdlib>
#include "BinaryTree.h"

// Степанов М. О. РИ-280017

void insertMiddleElement(BinaryTree& tree, const int* arrStart, int length){
    if (length == 1)
        tree.insert(*arrStart);
    else if (length == 2) {
        tree.insert(*arrStart);
        tree.insert(*(arrStart + 1));
    }
    else {
        tree.insert(*(arrStart + length / 2));
        insertMiddleElement(tree, arrStart, length / 2 );
        insertMiddleElement(tree, arrStart + length / 2 + 1, length % 2 == 0 ? length / 2 - 1 : length / 2);
    }
}

BinaryTree* createMinimalBST(const int* arrStart, int endIndex) {
    auto tree = new BinaryTree();
    insertMiddleElement(*tree, arrStart, endIndex + 1);
    return tree;
}

int main() {
    int evenArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    BinaryTree* treeByEvenArr = createMinimalBST(evenArr, 9);
    delete treeByEvenArr;

    int oddArr[] = {35, 52, 100, 235, 500, 900, 1000, 1001, 753999};
    BinaryTree* treeByOddArr = createMinimalBST(oddArr, 8);
    delete treeByOddArr;

    system("pause");
}
