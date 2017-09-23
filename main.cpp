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
                cout << Bv.choose(A) << "________________999999999999999" << endl;
                A.move(A,Bv.choose(A));
            }
        }
        else if (A.stepcout%2 == 1){
            A.show();
            cout << "換你拉" << endl;
            int playermove;
            cin >> playermove;
            A.move(A, playermove);
            A.show();
        }
    }
}
