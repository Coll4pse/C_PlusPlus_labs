#include "BinaryTree.h"

TreeNode * BinaryTree::search(const int value, TreeNode* node) const {
    if (!node)
        return node;
    else if (value == node->value())
        return node;
    else if (value < node->value())
        return search(value, node->getLeftNode());
    else
        return search(value, node->getRightNode());
}

void BinaryTree::insert(const int value, TreeNode* node) {
    if (!node)
        m_root = new TreeNode(value);
    else if (value < node->value()) {
        if (node->getLeftNode())
            insert(value, node->getLeftNode());
        else
            node->setLeftNode(new TreeNode(value, node));
    }
    else {
        if (node->getRightNode())
            insert(value, node->getRightNode());
        else
            node->setRightNode(new TreeNode(value, node));
    }
}