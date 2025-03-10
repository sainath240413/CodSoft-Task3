#include<iostream>
#include<cstdlib>
#include<conio.h>
#define SIZE 3
using namespace std;
void clear_screen();
void print_board(char board[SIZE][SIZE]);
int check_winner(char board[SIZE][SIZE]);
void player_move(char board[SIZE][SIZE],char player_1,char player_2);
char player_1='X',player_2='O';
int player1=0,player2=0,draw=0;
void reset_board(char board[SIZE][SIZE]);
//main function
int main(){
    char board[SIZE][SIZE]={
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    // input_difficulty();
    print_board(board);
    player_move(board,player_1,player_2);
    
}

//reset board
void reset_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

//player move
void player_move(char board[SIZE][SIZE],char player_1,char player_2){
    int turn=0;
    int x,y;
    while(1){
        if(turn%2==0){
            cout<<"Player 1's turn"<<endl;
            cout<<"Enter the row and column number: ";
            cin>>x>>y;
            if(x<1 || x>3 || y<1 || y>3 || board[x-1][y-1]!=' '){
                cout<<"Invalid move. Please try again."<<endl;
                continue;
            }
            board[x-1][y-1]=player_1;
        }
        else{
            cout<<"Player 2's turn"<<endl;
            cout<<"Enter the row and column number: ";
            cin>>x>>y;
            if(x<1 || x>3 || y<1 || y>3 || board[x-1][y-1]!=' '){
                cout<<"Invalid move. Please try again."<<endl;
                continue;
            }
            board[x-1][y-1]=player_2;
        }
        turn++;
        print_board(board);
        check_winner(board);
        if(check_winner(board)==1){
            cout<<"Player 1 wins."<<endl;
            player1++;
            break;
        }
        else if(check_winner(board)==2){
            cout<<"Player 2 wins."<<endl;
            player2++;
            break;
        }
        else if(check_winner(board)==3){
            cout<<"Game draw."<<endl;
            draw++;
            break;
        }
    }
    cout<<"Do you want to play again? (y/n): ";
    char ch;
    cin>>ch;
    if(ch=='y' || ch=='Y'){
        reset_board(board);
        print_board(board);
        player_move(board,player_1,player_2);
    }
    else{
        cout<<"Thank you for playing."<<endl;
    }
}

//check winner
int check_winner(char board[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' '){
            if(board[i][0]=='X'){
                return 1;
            }
            else{
                return 2;
            }
        }
    }
    for(int i=0;i<SIZE;i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' '){
            if(board[0][i]=='X'){
                return 1;
            }
            else{ 
                return 2;
            }
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' '){
        if(board[0][0]=='X'){
            return 1;
        }
        else{
            return 2;
        }
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' '){
        if(board[0][2]=='X'){
            return 1;
        }
        else{
            return 2;
        }
    }
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(board[i][j]==' '){
                return 0;
            }
        }
    }
    return 3;
}

//print board
void print_board(char board[SIZE][SIZE]){
    clear_screen();
    cout<<"Score -> Player 1:"<<player1<<", Player 2:"<<player2<<", Draw:"<<draw<<endl;
    cout<<"tic-tac-toe"<<endl<<endl;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            cout<<" "<<board[i][j]<<" ";
            if(j<SIZE-1){
                cout<<"|";
            }
        }
        cout<<endl;
        if(i<SIZE-1){
            cout<<"---+---+---"<<endl;
        }
    }
    cout<<endl;
}

//clear screen
void clear_screen(){
    system("cls");  
}
