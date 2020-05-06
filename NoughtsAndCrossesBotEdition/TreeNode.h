#ifndef NOUGHTS_AND_CROSSES_TREENODE_H
#define NOUGHTS_AND_CROSSES_TREENODE_H

#include "PlayField.h"
#include <vector>

//
// Created by Михаил on 28.03.2020.
//

class TreeNode{
public:
    struct Score{
        int totalScore() const { return CrossesWin + NoughtsWin + Draws; }

        void operator+=(const Score otherScore) {
            CrossesWin += otherScore.CrossesWin;
            NoughtsWin += otherScore.NoughtsWin;
            Draws += otherScore.Draws;
        }

        int CrossesWin = 0;
        int NoughtsWin = 0;
        int Draws = 0;
    };

    TreeNode() = default;

    TreeNode(const PlayField playField);

    ~TreeNode();

    bool isTerminal() const;

    void addChild(TreeNode* child);

    int childCount() const;

    const PlayField& value() const;

    TreeNode& operator[](const int index) const;

    const Score& getScore() const { return  possibleWays; }

    void addScore(Score otherScore) { possibleWays += otherScore;}

private:
    int childQty() const;

    const PlayField playField;

    TreeNode *parent = nullptr;

    std::vector<TreeNode*> children;

    Score possibleWays;
};

#endif //NOUGHTS_AND_CROSSES_TREENODE_H
