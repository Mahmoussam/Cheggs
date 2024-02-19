#ifndef CH_CORE_H
#define CH_CORE_H

#include <iostream>
#include <string.h>
#include "Color.h"

#endif

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
        
    public:
        /**
         * Piece constructor: sets color and initial position
         * Children must set piece_tag according
        */
        Piece(Color color,std::pair<int,int>pos){
            this->color = color;
            this->pos = pos;
        }
        Piece(){
            
        }
        //abstract method, children must implement!
        /**
         * Check whether a piece can move to specific destination
        */
        virtual bool canMoveTo(std::pair<int,int>&)=0;
        /**
         * move the piece to dest location if it is possible
         * a child piece must implmenet `canMoveTo(pair<int,int>)`
        */
        virtual bool moveTo(std::pair<int,int>dest){
            
            
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
        void setPos(std::pair<int,int> pos){
            this->pos = pos;
        }
        /**
         * getPos: return copy of current position of piece
        */
        std::pair<int,int> getPos(){
            return this->pos;
        }
        ~ Piece(){
            std::cout<<"Killing "<<getNameTag()<<std::endl;
        }
};

