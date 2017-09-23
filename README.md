# xogame


class recording
{
public:
    int move[10] = {0,0,0,0,0,0,0,0,0,0};
};


char x = 'x'; char o ='o';


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


void tableview::show()
{
    cout<<"____"<<endl;
    for(int i=0;i<10;i++){
        cout << table[i];
        if((i-2)%3 == 0){
            cout << endl;}
    }
    cout<<"____"<<endl;
}
