//
//  timhuangxogame.hpp
//  xogame
//
//  Created by 呈澤 林 on 2017/8/21.
//  Copyright © 2017年 呈澤 林. All rights reserved.
//

#ifndef timhuangxogame_hpp
#define timhuangxogame_hpp
#include <iostream>
#include <stdlib.h>
#include <ctime>
#endif /* timhuangxogame_hpp */
using namespace std;

////////////////////可以記錄第i步走在哪///////////////////////////////////////////
class recording{
public:
    int move[10] = {0,0,0,0,0,0,0,0,0,0};
};


char x = 'x'; char o ='o';

////////////////////操作棋盤的地方///////////////////////////////////////////////
class tableview{
public:
    int winnerplayer = 0;
    int stepcout = 0;
    bool endcondition;
    char table[10] = "012345678";
    void show();
    bool endgame(tableview&);
    void xmove(tableview&,int);
    void omove(tableview&,int);
    void move(tableview&,int);
    void chooseplayer(int);
};

void tableview::show(){
    cout<<"____"<<endl;
    for(int i=0;i<10;i++){
        cout << table[i];
        if((i-2)%3 == 0){
            cout << endl;}
    }
    cout<<"____"<<endl;
}

bool tableview::endgame(tableview& A){                        ////////////結束遊戲結束的條件
    // x win
    if(A.table[0]  == 'x' & A.table[1] == 'x' & A.table[2] == 'x'){
        A.endcondition = 1;A.winnerplayer = 1;
    }
    else if(A.table[3]  == 'x' & A.table[4] == 'x' & A.table[5] == 'x'){
        A.endcondition = 1;A.winnerplayer = 1;
    }
    else if(A.table[6]  == 'x' & A.table[7] == 'x' & A.table[8] == 'x'){
        A.endcondition = 1;A.winnerplayer = 1;
    }
    else if(A.table[0]  == 'x' & A.table[3] == 'x' & A.table[6] == 'x'){
        A.endcondition = 1;A.winnerplayer = 1;
    }
    else if(A.table[1]  == 'x' & A.table[4] == 'x' & A.table[7] == 'x'){
        A.endcondition = 1;A.winnerplayer = 1;
    }
    else if(A.table[2]  == 'x' & A.table[5] == 'x' & A.table[8] == 'x'){
        A.endcondition = 1;A.winnerplayer = 1;
    }
    else if(A.table[0]  == 'x' & A.table[4] == 'x' & A.table[8] == 'x'){
        A.endcondition = 1;A.winnerplayer = 1;
    }
    else if(A.table[2]  == 'x' & A.table[4] == 'x' & A.table[6] == 'x'){
        A.endcondition = 1;A.winnerplayer = 1;
    }
    // o win
    else if(A.table[0]  == 'o' & A.table[1] == 'o' & A.table[2] == 'o'){
        A.endcondition = 1;A.winnerplayer = 2;
    }
    else if(A.table[3]  == 'o' & A.table[4] == 'o' & A.table[5] == 'o'){
        A.endcondition = 1;A.winnerplayer = 2;
    }
    else if(A.table[6]  == 'o' & A.table[7] == 'o' & A.table[8] == 'o'){
        A.endcondition = 1;A.winnerplayer = 2;
    }
    else if(A.table[0]  == 'o' & A.table[3] == 'o' & A.table[6] == 'o'){
        A.endcondition = 1;A.winnerplayer = 2;
    }
    else if(A.table[1]  == 'o' & A.table[4] == 'o' & A.table[7] == 'o'){
        A.endcondition = 1;A.winnerplayer = 2;
    }
    else if(A.table[2]  == 'o' & A.table[5] == 'o' & A.table[8] == 'o'){
        A.endcondition = 1;A.winnerplayer = 2;
    }
    else if(A.table[0]  == 'o' & A.table[4] == 'o' & A.table[8] == 'o'){
        A.endcondition = 1;A.winnerplayer = 2;
    }
    else if(A.table[2]  == 'o' & A.table[4] == 'o' & A.table[6] == 'o'){
        A.endcondition = 1;A.winnerplayer = 2;
    }
    
    // 和局
    else if(A.table[0]  != '0' & A.table[1] != '1' & A.table[2] != '2' &
            A.table[3]  != '3' & A.table[4] != '4' & A.table[5] != '5' &
            A.table[6]  != '6' & A.table[7] != '7' & A.table[8] != '8'){
        A.endcondition = 1;A.winnerplayer = 3;
    }
    
    if (A.winnerplayer == 1){
        cout << "x is winner" << endl;
    }
    else if(A.winnerplayer == 2){
        cout << "o is winner" << endl;
    }
    else if(A.winnerplayer == 3){
        cout << "和局"<<endl;
    }
    return A.endcondition;
}

void tableview::xmove(tableview& A,int a){
    if (isdigit(A.table[a])){
        A.table[a] = 'x';
        A.stepcout++;}
    else
        cout << "已輸入"<<endl;
}

void tableview::omove(tableview& A,int a){
    if (isdigit(A.table[a])){
        A.table[a] = 'o';
        A.stepcout++;}
    else
        cout << "已輸入"<<endl;;
}

void tableview::move(tableview& A,int a){
    if (isdigit(A.table[a])){
        if (A.stepcout%2 == 0){
            omove(A,a);
            endgame(A);
            A.show();
            if(A.endcondition != 1)
                cout<<"move x"<<endl;
        }
        else{
            xmove(A,a);
            endgame(A);
            A.show();
            if(A.endcondition != 1)
                cout<<"move o"<<endl;
        }
    }
}


class virtal : tableview{
public:
    int        scoretable[10][10];                             //記錄分數
    char       mtable[10][10];                                //記憶棋盤
    void       initscoretable();                             //初始化棋盤分數
    void       shows(tableview);                            //展示分數
    void       randommove(tableview&,recording&);            //隨機移動
    void       record(tableview,recording);                  //記錄分數
    void       virtalmove(tableview);                       //執行移動
    void       retable(tableview&);                          //返回棋盤
    void       retable1(tableview&);                         //返回棋盤
    int        retablecondition(tableview);
    int        choose(tableview);
};

void virtal::initscoretable(){
    for(int i=0;i<9;i++)
        for(int j=1;j<9;j++)
            scoretable[i][j] = 0;
}

void virtal::shows(tableview A){
    cout << "第" << A.stepcout << "步的分數" <<endl;
    for(int i=0;i<9;i++)
        cout << scoretable[i][A.stepcout];
    cout << endl;
}

void virtal::randommove(tableview& A,recording& R){
    srand((unsigned)time(0));
    int random = 0;
    do {
        random = rand() % 9;
    } while (scoretable[random][A.stepcout] != 0 || !isdigit(A.table[random]));
    move(A,random);
    R.move[A.stepcout -1] = random;
}

void virtal::record(tableview A, recording R){
    
    if(A.endcondition == 1 && A.stepcout %2 == 0){
        switch (A.winnerplayer) {
            case 1 :{
                scoretable[R.move[A.stepcout-1]][A.stepcout - 1] = 1;          /////lose
                break;}
            case 2 :{
                scoretable[R.move[A.stepcout-1]][A.stepcout - 1] = 3;          /////win
                break;}
            case 3 :{
                scoretable[R.move[A.stepcout-1]][A.stepcout - 1] = 2;
                break;}
            default:
                break;
        }
    }
    if(A.endcondition == 1 && A.stepcout %2 == 1){
        switch (A.winnerplayer) {
            case 1 :{
                scoretable[R.move[A.stepcout-1]][A.stepcout - 1] = 3;
                break;}
            case 2 :{
                scoretable[R.move[A.stepcout-1]][A.stepcout - 1] = 1;
                break;}
            case 3 :{
                scoretable[R.move[A.stepcout-1]][A.stepcout - 1] = 2;
                break;}
            default:
                break;
        }
    }
}


void virtal::retable1(tableview& A){
    for(int i=0;i<9;i++){
        A.table[i] = mtable[i][A.stepcout - 1];
        for(int j=A.stepcout;j<9;j++)
            scoretable[i][j] = 0;
    }
    A.stepcout -= 1;
    A.endcondition = 0;
    A.winnerplayer = 0;
}


//利用下方計算何時回傳分數至上一步，與回傳至上一步的分數
int virtal::retablecondition(tableview A){
    int temp = 1;
    int number = 0;
    int number2 = 0;
    int number3 = 0;
    
    for(int i=0;i<9;i++){
        if(isdigit(A.table[i])){
            temp *= scoretable[i][A.stepcout];
            number++;
        }
    }
    
    while (temp % 3 == 0 && temp !=0) {
        temp = temp /3;
        number3++;
    }
    
    while (temp % 2 == 0 && temp !=0) {
        temp = temp /2;
        number2++;
    }
    
    int number1 = number - number2 - number3;
    
    if (temp == 0)
        return 0;
    else if (9-A.stepcout == number3)
        return 1;
    else if (number1 > 0 )
        return 3;
    else
        return 2;
    
}

int virtal::choose(tableview A){
    int min = 100;
    for(int i=0;i<9;i++){
        if (min > scoretable[i][A.stepcout] && scoretable[i][A.stepcout] != 0)
            min = scoretable[i][A.stepcout];
    }
    
    srand((unsigned)time(0));
    int random = rand()%9;
    while((scoretable[random][A.stepcout] > min) || scoretable[random][A.stepcout] == 0)
        random = rand() % 9;
    return random;
}

void virtal::virtalmove(tableview A){
    recording R;
    initscoretable();
    tableview B;
    B = A;
    
    for(int i=0;i<9;i++)
        mtable[i][B.stepcout] = B.table[i];
    
    
    while (retablecondition(A) == 0){
        while (retablecondition(B) == 0 && retablecondition(A) == 0) {
            while (!B.endcondition) {
                randommove(B,R);
                for(int i=0;i<9;i++)
                    mtable[i][B.stepcout] = B.table[i];
            }
            if(B.endcondition){                                   /////  判定輸贏後，回傳值至scoretable[R.move[B.stepcout-1]][B.stepcout - 1]，
                record(B,R);                                      /////   並使用retable1返回棋盤至B.stepcout-1
                retable1(B);
            }
        }
        
        cout << "retablecondition(B) != 0" <<endl;
        if(A.stepcout != B.stepcout)                              ////假如(retablecondition(B) != 0)時，將其值回傳至上一步的分數，而後將棋盤回覆至上一步
        {
            while (retablecondition(B) != 0 && A.stepcout != B.stepcout){
                scoretable[R.move[B.stepcout-1]][B.stepcout-1] = retablecondition(B);
                retable1(B);
            }
        }
    }
    shows(A);
}
