#include "pawn.cpp"
using namespace std;
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
int main(){
    test_pawn_white();
}