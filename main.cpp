//
//  main.cpp
//  xogame
//
//  Created by 呈澤 林 on 2017/8/6.
//  Copyright © 2017年 呈澤 林. All rights reserved.
//

#include<iostream>
#include<cstring>
#include"timhuangxogame.hpp"
using namespace std;


int main(){
    cout << "開始執行程式"<<endl;;
    tableview A;
    while (A.endcondition == 0)
    {
        if (A.stepcout %2 == 0)
        {
            if(A.stepcout == 0)
                A.move (A,4);
            else
            {
                virtal Bv;
                tableview B;
                B = A;
                Bv.virtalmove(B);
                A.move(A,Bv.choose(A));
            }
        }
        else if (A.stepcout%2 == 1){
            cout << "電腦下完後棋盤結果如上，換你拉" << endl;
            int playermove;
            cin >> playermove;
            A.move(A, playermove);
        }
    }
}
