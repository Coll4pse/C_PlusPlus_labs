#include "XOPlayer.h"
#include <vector>
#include <ctime>

void XOPlayer::makeMove(const PlayField::CellPos pos) {
    for (int i = 0; i < currentNode->childCount(); i++) {
        TreeNode& child = (*currentNode)[i];
        if (child.value()[pos] == player && !containsPlayerMove(pos)) {
            currentNode = &child;
            playerMoves.push_back(pos);
            return;
        }
    }
    throw "Invalid move!";
}

void XOPlayer::makeMove() {
    int maxSum = 0;
    std::vector<TreeNode*> maxChildren;

    srand(time(nullptr));

    for (int i = 0; i < currentNode->childCount(); i++) {
        TreeNode& child = (*currentNode)[i];

        int sum = (bot == PlayField::csCross ? child.getScore().CrossesWin : child.getScore().NoughtsWin) +
                child.getScore().Draws;

        if (sum == maxSum) {
            maxChildren.push_back(&child);
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxChildren.clear();
            maxChildren.push_back(&child);
        }
    }
    currentNode = maxChildren[rand() % maxChildren.size()];
}

PlayField::FieldStatus XOPlayer::fieldStatus() const {
    return currentNode->value().checkFieldStatus();
}

const PlayField XOPlayer::currentState() const {
    return currentNode->value();
}

bool XOPlayer::containsPlayerMove(const PlayField::CellPos pos) const {
    for (auto e: playerMoves)
        if (pos.getX() == e.getX() && pos.getY() == e.getY())
            return true;
    return false;
}