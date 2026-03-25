#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int currentplayer;
char currentmarker;

char board1[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
string name[3];

bool checkplace(int x)
{
    int row = (x - 1) / 3;
    int col = (x - 1) % 3;
    if(board[row][col] !='X' && board[row][col] !='O')
    {
        board[row][col]=currentmarker;
        return true;
    }
    else
    {return false;}
}

void Displayboard1()
{

    cout<<"\n         ---------- User Manual For Position ----------\n\n";
    cout<<"\n    "<<board1[0][0]<<" | "<<board1[0][1]<<" | "<<board1[0][2]<<"\n";
    cout<<"   ---|---|---\n";
    cout<<"    "<<board1[1][0]<<" | "<<board1[1][1]<<" | "<<board1[1][2]<<"\n";
    cout<<"   ---|---|---\n";
    cout<<"    "<<board1[2][0]<<" | "<<board1[2][1]<<" | "<<board1[2][2]<<"\n\n";
    

}
void Displayboard()
{

    cout<<"\n    "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<"\n";
    cout<<"   ---|---|---\n";
    cout<<"    "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"\n";
    cout<<"   ---|---|---\n";
    cout<<"    "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<"\n\n";
    

}
int win()
{
    for(int i=0;i<3;i++)
    {
    if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][1]=='X')
    {return currentplayer;}
    if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][1]=='O')
    {return currentplayer;}
    }
    for(int i=0;i<3;i++)
    {
    if(board[0][i]==board[1][i] && board[i][1]==board[2][i] && board[i][1]=='X')
    {return currentplayer;}
    if(board[0][i]==board[1][i] && board[i][1]==board[2][i] && board[i][1]=='O')
    {return currentplayer;}
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]=='X')
    {
        return currentplayer;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]=='O')
    { 
        return currentplayer;
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]=='O')
    {
        return currentplayer;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]=='X')
    { 
        return currentplayer;
    }
    return 0;
}
void swap_player_marker()
{
    if (currentmarker=='X')
    {
        currentmarker='O';
    }
    else{currentmarker='X';}
    if(currentplayer==1)
    {
        currentplayer=2;
    }
    else
    {
        currentplayer=1;
    }
}
void game()
{
    cout<<"First Player Name : ";
    cin>>name[1];
    cout<<"Second Player Name : ";
    cin>>name[2];
    char marker;
    marker='X';

    currentplayer=1;
    currentmarker=marker;
    Displayboard1();
    int player_win;
    for(int i=0;i<9;i++)
    {
        cout<<"Its "<<name[currentplayer]<<"'s turn Enter Your Position : ";
        int pos;
        cin>>pos;
        if(pos<1 || pos>9)
        {
            cout<<"invalid moves\n";
            i--;
            continue;
        }
        if(!checkplace(pos))
        {
            cout<<"invalid moves\n";
            i--;
            continue;
        }
        Displayboard();
        player_win=win();
        if(player_win==1)
        {
            cout<<name[1]<<" won\n";
            break;
        }
        if(player_win==2)
        {
            cout<<name[2]<<" won\n";
            break;
        }
        swap_player_marker();
    }
    if(player_win==0)
    {
        cout<<"Its a Tie\n";
    }



}
int main(void)
{
    cout<<"\n\n\n       ------ Welcome to this game -------\n\n\n";
    game();
    return 0;
}
