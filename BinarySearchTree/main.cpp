#include <iostream>
#include <cassert>
#include "BinaryTree.h"

// Степанов М. О. РИ-280017

void insertMiddleElement(BinaryTree& tree, const int* const arrStart, const int length) {
    if (length == 0)
        return;

    tree.insert(*(arrStart + length / 2));
    insertMiddleElement(tree, arrStart, length / 2);
    insertMiddleElement(tree, arrStart + length / 2 + 1, length % 2 == 0 ? length / 2 - 1 : length / 2);
}

BinaryTree* createMinimalBST(const int* const arrStart, const int startIndex, const int  endIndex) {
    auto tree = new BinaryTree();
    insertMiddleElement(*tree, arrStart + startIndex, endIndex - startIndex + 1);
    return tree;
}

int main() {
    int evenArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    BinaryTree* treeByEvenArr = createMinimalBST(evenArr, 0, 9);
    assert(treeByEvenArr->search(10));
    assert(treeByEvenArr->search(6));
    assert(!treeByEvenArr->search(0));
    delete treeByEvenArr;

    int oddArr[] = {35, 52, 100, 235, 500, 900, 1000, 1001, 753999};
    BinaryTree* treeByOddArr = createMinimalBST(oddArr, 0, 8);
    assert(treeByOddArr->search(1001));
    assert(treeByOddArr->search(35));
    assert(!treeByOddArr->search(152));
    delete treeByOddArr;
}
