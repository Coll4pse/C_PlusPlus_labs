#include <iostream>
#include <cstdlib>
#include "BinaryTree.h"

// Степанов М. О. РИ-280017

BinaryTree* createMinimalBST(const int* arrStart, int endIndex) {
    int middleElement = *(arrStart + endIndex / 2);

    auto tree = new BinaryTree(middleElement);

    for (int i = 0; i <= endIndex; i++){
        int element = *(arrStart + i);

        if (element == middleElement)
            continue;

        tree->insert(element);
    }

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
