//
// Created by Михаил on 28.03.2020.
//

#ifndef NOUGHTS_AND_CROSSES_TREENODE_H
#define NOUGHTS_AND_CROSSES_TREENODE_H

#include "PlayField.h"
#include <vector>

class TreeNode{
public:
    TreeNode();

    bool isTerminal();

    void addChild(PlayField::CellPos pos);

    int childCount();

    const PlayField::FieldStatus value();

    TreeNode& operator[](int index);

    /// Данная функция добавлена по необходимости определять в какую клетку я могу сходить.
    std::vector<PlayField::CellPos*> getEmptyCells();

private:
    const PlayField playField;
    TreeNode *previousNode;
    std::vector<TreeNode*> nextNodes;

    int childQty();

    TreeNode(TreeNode *previous, PlayField playField);
};

#endif //NOUGHTS_AND_CROSSES_TREENODE_H
