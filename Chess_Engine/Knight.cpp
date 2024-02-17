#ifndef CH_PIECE_H
#define CH_PIECE_H
#include "piece.cpp"
#endif
/**
 * Bishop walks in diagonals only
*/
class Knight : public Piece{
    private:
        
    public:
        Knight(Color color,std::pair<int,int>pos) : Piece(color,pos){
            this->piece_tag='K';
        }
        Knight(){
            
        }
        bool canMoveTo(std::pair<int,int>& dest){
            bool result = false;
            std::pair<int,int> pos = this->getPos();
            int x_dif=abs(dest.first-pos.first)
                ,y_dif=abs(dest.second-pos.second);
            if((x_dif==2&&y_dif==1)||(x_dif==1&&y_dif==2))
                result = true;
            return result;
        }
        
};