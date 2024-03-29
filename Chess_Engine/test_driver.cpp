#include "pawn.cpp"

#include "queen.cpp"
#ifndef CH_BISHOP_H
#define CH_BISHOP_H
#include "bishop.cpp"
#endif

#ifndef CH_ROOK_H
#define CH_ROOK_H
#include "rook.cpp"
#endif
using namespace std;
void test_pawn_black();
void test_pawn_white();
void test_rook();
void test_bishop();
void test_queen();
int main(){
    test_queen();
}
void test_queen(){
    Queen q(Color::WHITE,{5,4});
    if(!q.moveTo({2,3})){
        cout<<"Illegale move"<<endl;
    }
    cout<<"Moving state : "<<q.moveTo({2,7})<<endl; 
    pair<int,int> pos=q.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
    cout<<"Moving state : "<<q.moveTo({2,0})<<endl; 
    pos=q.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
    cout<<"Moving state : "<<q.moveTo({0,7})<<endl; 
    pos=q.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
}
void test_bishop(){
    Bishop b(Color::WHITE,{5,4});
    if(!b.moveTo({2,3})){
        cout<<"Illegale move"<<endl;
    }
    cout<<"Moving state : "<<b.moveTo({3,6})<<endl; 
    pair<int,int> pos=b.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
    cout<<"Moving state : "<<b.moveTo({7,5})<<endl; 
    pos=b.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
    cout<<"Moving state : "<<b.moveTo({5,4})<<endl; 
    pos=b.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
    
}
void test_rook(){
    Rook rk(Color::WHITE,{3,1});
    if(!rk.moveTo({2,3})){
        cout<<"Illegale move"<<endl;
    }
    cout<<"Moving state : "<<rk.moveTo({3,5})<<endl; 
    pair<int,int> pos=rk.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
    cout<<"Moving state : "<<rk.moveTo({7,5})<<endl; 
    pos=rk.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
    cout<<"Moving state : "<<rk.moveTo({6,7})<<endl; 
    pos=rk.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
    
}
void test_pawn_black(){
    Pawn p(Color::BLACK,{0,7});
    cout<<"Moved state : "<<p.hasMovedYet()<<endl; 
    if(!p.moveTo({1,6})){
        cout<<"Illegale move"<<endl;
    }
    cout<<"Moving state : "<<p.moveTo({0,5})<<endl; 
    pair<int,int> pos=p.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
    cout<<"Moving state : "<<p.moveTo({0,4})<<endl; 
    pos=p.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
    cout<<"Moving state : "<<p.moveTo({0,5})<<endl; 
    pos=p.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
    
}
void test_pawn_white(){
    Pawn p(Color::WHITE,{0,1});
    cout<<"Moved state : "<<p.hasMovedYet()<<endl; 
    if(!p.moveTo({1,6})){
        cout<<"Illegale move"<<endl;
    }
    cout<<"Moving state : "<<p.moveTo({0,2})<<endl; 
    
    pair<int,int> pos=p.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
    cout<<"Moving state : "<<p.moveTo({0,4})<<endl; 
    pos=p.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
    cout<<"Moving state : "<<p.moveTo({2,3})<<endl; 
    pos=p.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
    cout<<"Moving state : "<<p.moveTo({0,3})<<endl; 
    pos=p.getPos();
    cout<<"cur pos : "<<pos.first<<" "<<pos.second<<endl;
}