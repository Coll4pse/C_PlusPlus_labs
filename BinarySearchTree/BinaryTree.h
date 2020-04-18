#ifndef BINARYSEARCHTREE_BINARYTREE_H
#define BINARYSEARCHTREE_BINARYTREE_H

#include "TreeNode.h"

class BinaryTree {
public:
    BinaryTree() = default;

    BinaryTree(const int value): m_root(new TreeNode(value)) {}

    ~BinaryTree() { delete m_root; }

    void insert(const int value) { insert(value, m_root); }

    TreeNode* search(const int value) const { return search(value, m_root); }
private:
    void insert(const int value, TreeNode* const node);

    TreeNode* search(const int value, TreeNode* const node) const;

    TreeNode* m_root = nullptr;
};


#endif //BINARYSEARCHTREE_BINARYTREE_H
