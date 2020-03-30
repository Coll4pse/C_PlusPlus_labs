#include <iostream>
#include "TreeNode.h"
#include "PlayField.h"

/// Степанов М. О. РИ-280017

void inspectTree(TreeNode& node, int (&results)[3]) {
    if (node.isTerminal()) {
        switch (node.value()) {
            case PlayField::fsCrossesWin:
                results[0]++;
                break;
            case PlayField::fsNoughtsWin:
                results[1]++;
                break;
            case PlayField::fsDraw:
                results[2]++;
                break;
            default:
                assert(false);
        }
        return;
    }

    auto emptyPoses = node.getEmptyCells();

    for (int i = 0; i < emptyPoses.size(); i++)
    {
        node.addChild(*(emptyPoses.at(i)));
        inspectTree((node[i]), results);
    }
}

int main() {
    TreeNode root = TreeNode();
    std::vector<PlayField::CellPos> startPoses;

    std::cout << "Игровое поле и соотвествующие координаты:   " << std::endl <<
    "_(0,0)_|_(0,1)_|_(0,2)_\n_(1,0)_|_(1,1)_|_(1,2)\n_(2,0)_|_(2,1)_|_(2,2)_" << std::endl;

    for(int i = 0; i < 3; i++)
        for (int j = 0; j < 3; ++j) {
            PlayField::CellPos pos = PlayField::CellPos(i, j);
            root.addChild(pos);
            startPoses.push_back(pos);
        }

    for (int i = 0; i < 9; i++) {
        int results[3] = {0, 0, 0};
        inspectTree((root[i]), results);
        std::cout << "Для первого хода на координаты (" << startPoses.at(i).getX() << ", "
        << startPoses.at(i).getY() << ") :" << std::endl;
        std::cout << "Побед: " << results[0] << std::endl;
        std::cout << "Поражений: " << results[1] << std::endl;
        std::cout << "Ничьих: " << results[2] << std::endl;
    }

    return  0;
}
