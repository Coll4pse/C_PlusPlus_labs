#include <iostream>
#include "TreeNode.h"
#include "PlayField.h"
#include "Score.h"

/// Степанов М. О. РИ-280017

void inspectTree(TreeNode& node, Score &score) {
    if (node.isTerminal()) {
        switch (node.value().checkFieldStatus()) {
            case PlayField::fsCrossesWin:
                score.CrossesWin++;
                break;
            case PlayField::fsNoughtsWin:
                score.NoughtsWin++;
                break;
            case PlayField::fsDraw:
                score.Draws++;
                break;
            default:
                assert(false);
        }
        return;
    }

    auto emptyPoses = node.value().getEmptyCells();

    for (int i = 0; i < emptyPoses.size(); i++)
    {
        auto child = new TreeNode(node.value().makeMove(emptyPoses[i]));
        node.addChild(child);
        inspectTree(node[i], score);
        delete child;
    }
}

void printPlayField(PlayField::CellPos pos, Score score){
    std::cout << std::endl;

    std::cout << "_____________" << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "|";
        for (int j = 0; j < 3; j++) {
            if (pos.getX() == i && pos.getY() == j)
                std::cout << " X |";
            else
                std::cout << "   |";
        }

        std::cout << std::endl << "_____________" << std::endl;
    }
    std::cout << "Побед: " << score.CrossesWin << std::endl;
    std::cout << "Поражений: " << score.NoughtsWin << std::endl;
    std::cout << "Ничьих: " << score.Draws << std::endl;
}

void startTreeInspection()
{
    auto root = TreeNode();
    std::vector<PlayField::CellPos> startPoses = root.value().getEmptyCells();

    for (int i = 0; i < 9; i++) {
        Score score = Score();
        auto child = new TreeNode(root.value().makeMove(startPoses[i]));
        root.addChild(child);
        inspectTree(root[i], score);
        delete child;
        printPlayField(startPoses[i], score);
    }

    delete &root;
}

int main() {
    startTreeInspection();
}
