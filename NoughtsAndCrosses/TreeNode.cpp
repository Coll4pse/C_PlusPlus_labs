//
// Created by Михаил on 28.03.2020.
//
#include "TreeNode.h"
#include "PlayField.h"

TreeNode::TreeNode(): playField(PlayField()){
    previousNode = nullptr;
}

TreeNode::TreeNode(TreeNode *previous, PlayField playField): playField(playField) {
    previousNode = previous;
}

bool TreeNode::isTerminal() {
    return childQty() == 0 && childCount() == 0;
}

int TreeNode::childQty() {
    return value() == PlayField::fsNormal ? (int)playField.getEmptyCells().size() - childCount() : 0;
}

void TreeNode::addChild(PlayField::CellPos pos) {
    assert(childQty() != 0);
    auto newNode = new TreeNode(this, playField.makeMove(&pos));
    nextNodes.push_back(newNode);
}

TreeNode& TreeNode::operator[](int index) {
    return *nextNodes.at(index);
}

int TreeNode::childCount() {
    return nextNodes.size();
}

const PlayField::FieldStatus TreeNode::value() {
    return playField.checkFieldStatus();
}

std::vector<PlayField::CellPos*> TreeNode::getEmptyCells() {
    return playField.getEmptyCells();
}