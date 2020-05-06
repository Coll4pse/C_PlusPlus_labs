#include "TreeNode.h"
#include "XOPlayer.h"
#include <iostream>
#include <cassert>

/// Степанов М. О. РИ-280017

void inspectTree(TreeNode& node) {
    if (node.isTerminal()) {
        switch (node.value().checkFieldStatus()) {
            case PlayField::fsCrossesWin:
                node.addScore(TreeNode::Score {1, 0, 0});
                break;
            case PlayField::fsNoughtsWin:
                node.addScore(TreeNode::Score {0, 1, 0});
                break;
            case PlayField::fsDraw:
                node.addScore(TreeNode::Score {0, 0, 1});
                break;
            default:
                assert(false);
        }
        return;
    }

    auto emptyPoses = node.value().getEmptyCells();

    for (int i = 0; i < emptyPoses.size(); i++)
    {
        node.addChild(new TreeNode(node.value().makeMove(emptyPoses[i])));
        inspectTree(node[i]);
        node.addScore(node[i].getScore());
    }
}

void printPlayField(const PlayField &field){
    std::cout << std::endl;

    std::cout << "_____________" << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "|";
        for (int j = 0; j < 3; j++) {
            switch (field[PlayField::CellPos(i, j)]) {
                case PlayField::csCross:
                    std::cout << " X |";
                    break;
                case PlayField::csNought:
                    std::cout << " O |";
                    break;
                case PlayField::csEmpty:
                    std::cout << "   |";
                    break;
            }
        }
        std::cout << std::endl << "_____________" << std::endl;
    }
}

void startTreeInspection(TreeNode &root)
{
    std::vector<PlayField::CellPos> startPoses = root.value().getEmptyCells();

    for (int i = 0; i < startPoses.size(); i++) {
        root.addChild(new TreeNode(root.value().makeMove(startPoses[i])));
        inspectTree(root[i]);
    }
}

int main() {
    TreeNode root;
    startTreeInspection(root);

    std::cout << "Select player (0 - Xs, 1 - Os)" << std::endl;
    int sel_player;
    std::cin >> sel_player;

    bool isPlayerMove = sel_player == 0;
    XOPlayer player(root, isPlayerMove ? PlayField::csCross : PlayField::csNought);
    try {
        while (player.fieldStatus() == PlayField::fsNormal) {
            if (isPlayerMove) {
                std::cout << std::endl << "Select cell (0 - 2, 0 - 2)" << std::endl;
                int x, y;
                std::cin >> x >> y;
                auto pos = PlayField::CellPos(x, y);
                player.makeMove(pos);
            } else {
                player.makeMove();
            }
            printPlayField(player.currentState());
            isPlayerMove = !isPlayerMove;
        }

        std::cout << std::endl;
        switch (player.fieldStatus()) {
            case PlayField::fsCrossesWin:
                std::cout << "Crosses win!";
                break;
            case PlayField::fsNoughtsWin:
                std::cout << "Noughts win!";
                break;
            case PlayField::fsDraw:
                std::cout << "It's draw!";
                break;
        }
    }
    catch (const char* msg) {
        std::cout << std::endl << msg;
    }
}
