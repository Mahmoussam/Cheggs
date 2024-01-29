#include <iostream>
#include <string.h>
#include "Color.h"
using namespace std;

/**
 * Piece class represents parent class for all chess pieces
 * 
*/
class Piece{
    private:
        Color color;
        char piece_tag;
        pair<int,int> pos;// x,y coordinates ,zero based
    protected:
        //abstract method, children must implement!
        virtual bool canMoveTo(pair<int,int>&)=0;
    public:
        /**
         * Piece constructor: sets color and initial position
         * Children must set piece_tag according
        */
        Piece(Color color,pair<int,int>pos){
            this->color = color;
            this->pos = pos;
        }
        
        bool moveTo(pair<int,int>dest){
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
};

int main(){
    
    
    return 0;
}