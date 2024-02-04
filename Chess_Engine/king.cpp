#ifndef CH_PIECE_H
#define CH_PIECE_H
#include "piece.cpp"
#endif
/**
 * King: moves one step in any direction
*/
class King : public Piece{
    private:
        bool canMoveTo(std::pair<int,int>& dest){
            bool result;
            std::pair<int,int> pos = this->getPos();
            int x_dif=abs(dest.first-pos.first)
                ,y_dif=abs(dest.second-pos.second);
            if(x_dif<=1&&y_dif<=1)
                result = true;
            else 
                result = false;
            return result;
        }
    public:
        King(Color color,std::pair<int,int>pos) : Piece(color,pos){
            this->piece_tag='K';
        }
        
        
};