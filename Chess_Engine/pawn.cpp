#include "piece.cpp"
class Pawn : public Piece{
    private:
        bool moved_yet;
        bool canMoveTo(std::pair<int,int>&){
            //to be completed
        }

    public:
        Pawn(Color color,std::pair<int,int>pos) : Piece(color,pos){
            this->piece_tag='P';
            this->moved_yet=false;
        }
        bool hasMovedYet(){
            return this->moved_yet;
        }
};