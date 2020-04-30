#ifndef NOUGHTS_AND_CROSSES_TREENODE_H
#define NOUGHTS_AND_CROSSES_TREENODE_H

#include "PlayField.h"
#include <vector>
#include "Score.h"

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

    const Score& getScore() const { return  possibleWays; }

    void addScore(Score otherScore) { possibleWays + otherScore;}

private:
    int childQty() const;

    const PlayField playField = PlayField();

    TreeNode *parent = nullptr;

    std::vector<TreeNode*> children;

    Score possibleWays;
};

#endif //NOUGHTS_AND_CROSSES_TREENODE_H
