#include<iostream>
#include <cstdlib>
#include "Chess_Engine/Engine.cpp"
using namespace std;
int main(){
    Engine eng;
    char m1[2],m2[2];
    eng.show_board();
    while(true){
        cout<<(eng.is_white_turn()?"White":"Black")<<"'s turn\nMake a move:"<<endl;
        cin>>m1[0]>>m1[1]>>m2[0]>>m2[1];
        if(eng.move(m1,m2)){
            if(getenv("windir"))//this is windows host os
                system("cls");
            else
                system("clear");
            eng.show_board();
        }else{
            cout<<"Illegal move!"<<endl;
        }
    }
    return 0;
}