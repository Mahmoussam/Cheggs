#ifndef CH_PIECE_H
#define CH_PIECE_H
#include "piece.cpp"
#endif
/**
 * Rook: moves in same file or rank
*/
class Rook : public Piece{
    private:
        bool canMoveTo(std::pair<int,int>& dest){
            bool result = false;
            std::pair<int,int> pos = this->getPos();
            if(pos.first==dest.first || pos.second==dest.second)
                result = true;

            return result;
        }
    public:
        Rook(Color color,std::pair<int,int>pos) : Piece(color,pos){
            this->piece_tag='R';
        }
        
        
};