#ifndef CH_PIECE_H
#define CH_PIECE_H
#include "piece.cpp"
#endif

#ifndef CH_BISHOP_H
#define CH_BISHOP_H
#include "bishop.cpp"
#endif

#ifndef CH_ROOK_H
#define CH_ROOK_H
#include "rook.cpp"
#endif

/**
 * Queen walks as rook + bishop
*/
class Queen : public Piece{
    private:
        Bishop bishop_;
        Rook rook_;
        bool canMoveTo(std::pair<int,int>& dest){
            bool result;
            if(rook_.canMoveTo(dest) || bishop_.canMoveTo(dest))
                result = true;
            else
                result = false;
            return result;
        }

    public:
        Queen(Color color,std::pair<int,int>pos) : Piece(color,pos){
            this->piece_tag='Q';
            bishop_ = Bishop(color,pos);
            rook_ = Rook(color,pos);
        }
        bool moveTo(std::pair<int,int>dest){
            
            
            if(this->canMoveTo(dest)){
                
                this->pos=dest;
                bishop_.setPos(dest);
                rook_.setPos(dest);
                return true;
            }
            else 
                return false;
        }
        
};