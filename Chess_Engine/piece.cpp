#include <iostream>
#include <string.h>
#include "Color.h"


/**
 * Piece class represents parent class for all chess pieces
 * 
*/
class Piece{
    private:
        
    protected:
        Color color;
        char piece_tag;
        std::pair<int,int> pos;// x,y coordinates ,zero based
        //abstract method, children must implement!
        /**
         * Check whether a piece can move to specific destination
        */
        virtual bool canMoveTo(std::pair<int,int>&)=0;
    public:
        /**
         * Piece constructor: sets color and initial position
         * Children must set piece_tag according
        */
        Piece(Color color,std::pair<int,int>pos){
            this->color = color;
            this->pos = pos;
        }
        
        bool moveTo(std::pair<int,int>dest){
            
            
            if(this->canMoveTo(dest)){
                
                this->pos=dest;
                return true;
            }
            else 
                return false;
        }
        Color getColor(){
            return this->color;
        }
        char getNameTag(){
            return this->piece_tag;
        }
        /**
         * getPos: return copy of current position of piece
        */
        std::pair<int,int> getPos(){
            return this->pos;
        }
};

