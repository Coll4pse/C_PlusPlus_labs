#ifndef NOUGHTS_AND_CROSSES_XOPLAYER_H
#define NOUGHTS_AND_CROSSES_XOPLAYER_H
#include "PlayField.h"
#include "TreeNode.h"
#include <vector>

class XOPlayer {
public:
    XOPlayer(TreeNode& tree, PlayField::CellStatus player): currentNode(&tree), player(player),
    bot(player == PlayField::csCross ? PlayField::csNought : PlayField::csCross) {};

    void makeMove(const PlayField::CellPos pos);
    void makeMove();
    const PlayField currentState() const;
    PlayField::FieldStatus fieldStatus() const;
private:
    bool containsPlayerMove(const PlayField::CellPos pos) const;

    const TreeNode* currentNode;
    const PlayField::CellStatus player;
    const PlayField::CellStatus bot;
    std::vector<PlayField::CellPos> playerMoves;
};


#endif //NOUGHTS_AND_CROSSES_XOPLAYER_H
