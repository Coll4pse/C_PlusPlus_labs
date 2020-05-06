#ifndef NOUGHTS_AND_CROSSES_XOPLAYER_H
#define NOUGHTS_AND_CROSSES_XOPLAYER_H
#include "PlayField.h"
#include "TreeNode.h"
#include <vector>

/// Метода selectPlayer нет, т.к. непонятно его применение, кто есть бот можно определить из того кто игрок
/// Собственно в файле с ТЗ в main в конструктор как раз таки подается игрок

class XOPlayer {
public:
    XOPlayer(TreeNode& tree, PlayField::CellStatus player): solveTree(tree), currentNode(&solveTree),
    player(player), bot(player == PlayField::csCross ? PlayField::csNought : PlayField::csCross) {};

    void makeMove(const PlayField::CellPos pos);
    void makeMove();
    const PlayField currentState() const;
    PlayField::FieldStatus fieldStatus() const;

private:
    const TreeNode& solveTree;
    const TreeNode* currentNode;
    const PlayField::CellStatus player;
    const PlayField::CellStatus bot;
};


#endif //NOUGHTS_AND_CROSSES_XOPLAYER_H
