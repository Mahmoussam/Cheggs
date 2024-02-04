#ifndef CH_PIECE_H
#define CH_PIECE_H
#include "piece.cpp"
#endif
/**
 * Can move 2 steps forward if hasn't been moved yet
 * Generally can only move 1 step forward
 * gets promoted to Queen if reaches last rank
*/
class Pawn : public Piece{
    private:
        bool moved_yet;
        bool canMoveTo(std::pair<int,int>& dest){
            bool result;
            
            std::pair<int,int> cur_pos=this->getPos();
            if(dest.first!=cur_pos.first)
                //must be on same File/column
                result = false;
            else{
                int distance=dest.second-cur_pos.second;
                if(this->getColor()==Color::BLACK){
                    distance *=-1;     
                }
                if(distance==1||(distance==2&&!this->hasMovedYet()))
                        result = true;
                    else 
                        result = false;  
            }
            
            return result;
        }
        void set_moved(){
            this->moved_yet=true;
        }
    public:
        Pawn(Color color,std::pair<int,int>pos) : Piece(color,pos){
            this->piece_tag='P';
            this->moved_yet=false;
        }
        bool hasMovedYet(){
            return this->moved_yet;
        }
        bool moveTo(std::pair<int,int>dest){
            
            bool res = Piece::moveTo(dest);
            
            if(res){
                this->set_moved();
            }
            return res;
        }
};