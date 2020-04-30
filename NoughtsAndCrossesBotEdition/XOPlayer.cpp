#include "XOPlayer.h"
#include <cassert>

void XOPlayer::makeMove(const PlayField::CellPos pos) {
    for (int i = 0; i < currentNode->childCount(); i++) {
        TreeNode& child = (*currentNode)[i];
        if (child.value()[pos] == player && !containsPlayerMove(pos)) {
            currentNode = &child;
            playerMoves.push_back(pos);
            return;
        }
    }
    assert(false);
}

void XOPlayer::makeMove() {
    int max = 0;
    TreeNode* maxChild;
    for (int i = 0; i < currentNode->childCount(); i++) {
        TreeNode& child = (*currentNode)[i];

        int sum = (bot == PlayField::csCross ? child.getScore().CrossesWin : child.getScore().NoughtsWin) +
                child.getScore().Draws;

        if (sum > max) {
            max = sum;
            maxChild = &child;
        }
    }
    currentNode = maxChild;
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