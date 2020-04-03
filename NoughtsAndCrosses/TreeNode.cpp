#include "TreeNode.h"
#include "PlayField.h"

//
// Created by Михаил on 28.03.2020.
//

TreeNode::TreeNode(TreeNode *parent, PlayField playField): playField(playField), parent(parent) {}

bool TreeNode::isTerminal() {
    return value().checkFieldStatus() != PlayField::fsNormal;
}

int TreeNode::childQty() const {
    return parent == nullptr ? 9 : parent->childQty() - 1;
}

void TreeNode::addChild(TreeNode* child) {
    assert(childQty() > childCount());
    children.push_back(child);
}

TreeNode& TreeNode::operator[](int index) {
    return *children[index];
}

int TreeNode::childCount() const {
    return children.size();
}

const PlayField& TreeNode::value() {
    return playField;
}