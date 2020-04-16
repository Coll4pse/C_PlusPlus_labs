#ifndef BINARYSEARCHTREE_TREENODE_H
#define BINARYSEARCHTREE_TREENODE_H


class TreeNode {
public:
    TreeNode() = default;

    TreeNode(const int value): m_value(value) {}

    TreeNode(const int value, TreeNode* previousNode): TreeNode(value) { m_previousNode = previousNode; }

    ~TreeNode() {
        delete m_leftNode;
        delete m_rightNode;
    }

    int value() const { return m_value; }

    TreeNode* getLeftNode() { return m_leftNode; }
    void setLeftNode(TreeNode* node) { m_leftNode = node; }

    TreeNode* getRightNode() { return m_rightNode; }
    void setRightNode(TreeNode* node) { m_rightNode = node; }
private:
    const int m_value = 0;
    TreeNode* m_previousNode = nullptr;
    TreeNode* m_leftNode = nullptr;
    TreeNode* m_rightNode = nullptr;
};


#endif //BINARYSEARCHTREE_TREENODE_H
