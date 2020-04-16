#ifndef NOUGHTS_AND_CROSSES_TREENODE_H
#define NOUGHTS_AND_CROSSES_TREENODE_H

#include "PlayField.h"
#include <vector>

//
// Created by Михаил on 28.03.2020.
//

class TreeNode{
public:
    TreeNode() = default;

    TreeNode(const PlayField playField);

    ~TreeNode();

    bool isTerminal() const;

    void addChild(TreeNode* child);

    int childCount() const;

    const PlayField& value() const;

    TreeNode& operator[](const int index) const;

private:
    int childQty() const;

    const PlayField playField;
    TreeNode *parent = nullptr;
    std::vector<TreeNode*> children;
};

#endif //NOUGHTS_AND_CROSSES_TREENODE_H
