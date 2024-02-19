#ifndef CH_PAWN_H
#define CH_PAWN_H
#include "pawn.cpp"
#endif

#ifndef CH_BISHOP_H
#define CH_BISHOP_H
#include "bishop.cpp"
#endif

#ifndef CH_ROOK_H
#define CH_ROOK_H
#include "rook.cpp"
#endif

#ifndef CH_QUEEN_H
#define CH_QUEEN_H
#include "queen.cpp"
#endif

#ifndef CH_KING_H
#define CH_KING_H
#include "king.cpp"
#endif

#ifndef CH_KNIGHT_H
#define CH_KNIGHT_H
#include "knight.cpp"
#endif

#ifndef CH_PIECE_H
#define CH_PIECE_H
#include "piece.cpp"
#endif

class Board{
    private:
        // chess board as 2D array of pieces
        Piece *board[8][8];
        void place_white_pieces();
        void place_black_pieces();
        
    public:
        ~ Board();
        void init_board(){
            //clear all pointers on the board
            memset(board,0,sizeof(board));
            place_white_pieces();
            place_black_pieces();
        }
        bool move(std::pair<int,int>,std::pair<int,int>);
        void show_board();
        /*
            Checks if piece is white
            throws Exception (int: 13) if no piece exists 
        */
        bool is_piece_white(std::pair<int,int>);
        
};
void Board :: place_white_pieces(){
    for(int i=0;i<8;i++){
        board[1][i]=new Pawn(Color::WHITE,std::make_pair(i,1));
    }
    board[0][0]=new Rook(Color::WHITE,std::make_pair(0,0));
    board[0][1]=new Knight(Color::WHITE,std::make_pair(1,0));
    board[0][2]=new Bishop(Color::WHITE,std::make_pair(2,0));
    board[0][3]=new Queen(Color::WHITE,std::make_pair(3,0));
    board[0][4]=new King(Color::WHITE,std::make_pair(4,0));
            
    board[0][7]=new Rook(Color::WHITE,std::make_pair(7,0));
    board[0][6]=new Knight(Color::WHITE,std::make_pair(6,0));
    board[0][5]=new Bishop(Color::WHITE,std::make_pair(5,0));
    }
void Board :: place_black_pieces(){
    for(int i=0;i<8;i++){
        board[6][i]=new Pawn(Color::BLACK,std::make_pair(i,6));
    }
    board[7][0]=new Rook(Color::BLACK,std::make_pair(0,7));
    board[7][1]=new Knight(Color::BLACK,std::make_pair(1,7));
    board[7][2]=new Bishop(Color::BLACK,std::make_pair(2,7));
    board[7][3]=new King(Color::BLACK,std::make_pair(3,7));
    board[7][4]=new Queen(Color::BLACK,std::make_pair(4,7));
            
    board[7][7]=new Rook(Color::BLACK,std::make_pair(7,7));
    board[7][6]=new Knight(Color::BLACK,std::make_pair(6,7));
    board[7][5]=new Bishop(Color::BLACK,std::make_pair(5,7));
    }
bool Board :: move(std::pair<int,int> from ,std::pair<int,int> to){
    int x,y
        ,x2,y2;
    bool result=false;
    x=from.first;y=from.second;
    x2=to.first;y2=to.second;
    
    Piece* piece_ptr=board[y][x]
        ,*piece2_ptr=board[y2][x2];
    if(piece_ptr==0){
        //empty start-cell or full end-cell
        result = false;
    }
    else if(piece2_ptr!=0&&piece2_ptr->getColor()==piece_ptr->getColor()){//same color pieces can't capture one another!
        result=false;
    }
    else{
        
        result = piece_ptr->moveTo(to);
        if(result){
            //could move piece with success
            //move it on the 2D board
            if(piece2_ptr!=0){
                //deallocate it
                delete piece2_ptr;
            }
            board[y2][x2] = piece_ptr;
            board[y][x] = 0; 
            //to do ,add pawn promotion
            
        }
    }

    return result;
}
void Board :: show_board(){
    std::cout<<"# ";
    for(int i=0;i<8;i++){
        std::cout<<(char)('a'+i)<<"  ";
    }
    std::cout<<std::endl;
    for(int i=7;i>=0;i--){
        std::cout<<i+1<<" ";
        for(int j=0;j<8;j++){
            std::string cell_tag="";
            Piece* piece_ptr=board[i][j];
            if(piece_ptr==0){
                //empty cell
                //odd for white cell, else black cell
                cell_tag = ((i+j)&1?"..":"**");
            }
            else{
                
                cell_tag += (piece_ptr->getColor() == Color::WHITE? "w" : "b");
                cell_tag += piece_ptr->getNameTag();
                  
            }
            std::cout<<cell_tag<<" ";
        }
        std::cout<<std::endl;
        
    }
    std::cout<<"==============================================================="<<std::endl;
}
bool Board :: is_piece_white(std::pair<int,int>pos){
    int x=pos.first,y=pos.second;
    Piece *piece_ptr = board[y][x];
    if(piece_ptr==0){
        throw 13;
    }
    return piece_ptr->getColor()==Color::WHITE;
}
Board::~Board(){
    //Deallocate all pieces on board
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            delete board[i][j];
        }
    }
}