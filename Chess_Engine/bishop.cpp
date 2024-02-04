#ifndef CH_PIECE_H
#define CH_PIECE_H
#include "piece.cpp"
#endif
/**
 * Bishop walks in diagonals only
*/
class Bishop : public Piece{
    private:
        
    public:
        Bishop(Color color,std::pair<int,int>pos) : Piece(color,pos){
            this->piece_tag='B';
        }
        Bishop(){
            
        }
        bool canMoveTo(std::pair<int,int>& dest){
            bool result;
            std::pair<int,int> pos = this->getPos();
            int x_dif=abs(dest.first-pos.first)
                ,y_dif=abs(dest.second-pos.second);
            result = (x_dif==y_dif);
            return result;
        }
        
};