#include "TreeNode.h"
#include "PlayField.h"

#include <cassert>

//
// Created by Михаил on 28.03.2020.
//

TreeNode::TreeNode(const PlayField playField): playField(playField) {}

TreeNode::~TreeNode() {
    for (auto node: children)
        delete node;
}

bool TreeNode::isTerminal() const {
    PlayField::FieldStatus status = value().checkFieldStatus();
    assert(status != PlayField::fsInvalid);
    return status == PlayField::fsDraw || status == PlayField::fsCrossesWin || status == PlayField::fsNoughtsWin;
}

int TreeNode::childQty() const {
    return (parent ? parent->childQty() - 1 : PlayField::fieldDim * PlayField::fieldDim);
}

void TreeNode::addChild(TreeNode* child) {
    assert(childQty() > childCount());
    child->parent = this;
    children.push_back(child);
}

TreeNode& TreeNode::operator[](const int index) const{
    return *children[index];
}

int TreeNode::childCount() const {
    return children.size();
}

const PlayField& TreeNode::value() const {
    return playField;
}