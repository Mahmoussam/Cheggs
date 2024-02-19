
#ifndef CH_PIECE_H
#define CH_PIECE_H
#include "piece.cpp"
#endif

#include "board.cpp"
class Engine{
    private:
        Board board;
        bool white_turn=true;
    public:
        Engine();
        /*
        * Convert chess board coordinates to x,y coordinates
        */
        std::pair<int,int> coord_to_xy(char *); 
        bool move(char *coord_from,char *coord_to);
        void show_board(){
            board.show_board();
        }
        bool is_white_turn(){
            return white_turn;
        }
};
Engine::Engine(){
    board.init_board();
}
std::pair<int,int> Engine::coord_to_xy(char *coord){
    int file = *coord - 'a'
        ,row=*(coord+1)-'0'-1;//zero based
    return std::make_pair(file,row);
}
bool Engine::move(char *coord_from,char *coord_to){
    std::pair<int,int>pos1 = coord_to_xy(coord_from)
        ,pos2 = coord_to_xy(coord_to);
    //check if turn allows moving this piece
    try{
        if(board.is_piece_white(pos1)!=white_turn)
            return false;
    }catch(int err_code){
        return false;
    }
    //attempt to make a move
    if(board.move(pos1,pos2)){
        

        white_turn = !white_turn;
        return true;
    }
    else{
        return false;
    }
}
