#include "bishop.cpp"
#include "rook.cpp"

/**
 * Queen walks like a bishop + rook
*/
class Queen : public Bishop, public Rook {
private:
    using Bishop::canMoveTo;  // Bring the canMoveTo function from Bishop into the Queen scope
    using Rook::canMoveTo;    // Bring the canMoveTo function from Rook into the Queen scope
    bool canMoveTo(std::pair<int, int>& dest) override {
        // Call the canMoveTo functions from Bishop and Rook
        return Bishop::canMoveTo(dest) || Rook::canMoveTo(dest);
    }
public:
    Queen(Color color, std::pair<int, int> pos) : Bishop(color, pos), Rook(color, pos) {
        this->piece_tag = 'Q';
    }

    
};