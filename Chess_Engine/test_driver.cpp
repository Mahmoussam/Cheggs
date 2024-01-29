#include "pawn.cpp"
int main(){
    Pawn p(Color::BLACK,{0,0});
    std::cout<<p.hasMovedYet()<<std::endl;
}