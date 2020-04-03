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

    TreeNode(TreeNode *parent, PlayField playField);

    bool isTerminal();

    void addChild(TreeNode* child);

    int childCount() const;

    const PlayField& value();

    TreeNode& operator[](int index);

private:
    int childQty() const;

    const PlayField playField;
    TreeNode *parent = nullptr;
    std::vector<TreeNode*> children;
};

#endif //NOUGHTS_AND_CROSSES_TREENODE_H
