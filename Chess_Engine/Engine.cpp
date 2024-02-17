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
class Engine{
    private:
        // chess board as 2D array of pieces
        Piece *board[8][8];
    public:
        Engine(){
            //init board
        }
        void print_board();
        std::pair<int,int> coord_to_xy(int x,int y); 
};