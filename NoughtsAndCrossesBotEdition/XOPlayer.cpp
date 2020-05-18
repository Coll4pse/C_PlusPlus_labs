#include "XOPlayer.h"
#include <vector>
#include <ctime>

void XOPlayer::makeMove(const PlayField::CellPos pos) {
    if (currentNode->value()[pos] == PlayField::csEmpty) {
        for (int i = 0; i < currentNode->childCount(); i++) {
            TreeNode &child = (*currentNode)[i];
            if (child.value()[pos] == player) {
                currentNode = &child;
                return;
            }
        }
    }
    throw "Invalid move!";
}

void XOPlayer::makeMove() {
    float maxPercentage = 0;
    std::vector<TreeNode*> maxChildren;

    srand(time(nullptr));

    for (int i = 0; i < currentNode->childCount(); i++) {
        TreeNode& child = (*currentNode)[i];

        float percentage = ((float)(bot == PlayField::csCross ? child.getScore().CrossesWin : child.getScore().NoughtsWin) +
                child.getScore().Draws) / child.getScore().totalScore();

        if (percentage == maxPercentage) {
            maxChildren.push_back(&child);
        }
        if (percentage > maxPercentage) {
            maxPercentage = percentage;
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