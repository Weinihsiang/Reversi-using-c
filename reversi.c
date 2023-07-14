/**
* @file reversi.c
* @author <Winnie Hsiang>
* @brief This file is used for APS105 Lab 8. 2023W version
* @date 2023-03-14
*
*/
// DO NOT REMOVE THE FOLLOWING LINE
#if !defined(TESTER_P1) && !defined(TESTER_P2)
// DO NOT REMOVE THE ABOVE LINE
//#include "reversi.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
// DO NOT REMOVE THE FOLLOWING LINE
#endif
// DO NOT REMOVE THE ABOVE LINE
bool positionInBounds(int n, int row, int col){
      if(row>=n ||col>=n ||row<0||col<0)  return false;
  else  return true;  
}

int checksecond(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
  char opponent;
  if(deltaRow==0&&deltaCol==0) return 0;
    if(colour == 'B') opponent = 'W';
    else opponent = 'B';
  int first = row +deltaRow;
  int second = col + deltaCol, count1 = 0;
  if(positionInBounds(n,first,second)&&board[first][second]==opponent){
    count1++;
  while(positionInBounds(n,first,second)){
    first+=deltaRow;
    second+=deltaCol;
    if(board[first][second]==opponent){
      count1++;
    }
    else if(board[first][second]==colour){
      return count1;
    }
    else return 0;
  }
  }
  return 0;
}

void flipthecolor(char arr[][26],char color, char row, char col,int num){
arr[row-'a'][col-'a']=color;
        for(int deltaRow = -1; deltaRow<=1; deltaRow++){
          for(int deltaCol = -1; deltaCol<=1;deltaCol++){
            int times = checksecond(arr, num, row-'a', col-'a', color, deltaRow, deltaCol);
           if(times>0){            
             int first = row-'a' +deltaRow;
             int second = col-'a' + deltaCol;
             for(int i = 0;i<times;i++){               
               arr[first][second]=color;
               first+=deltaRow;
               second+=deltaCol;
             }            
           }
              }
            }        
          } 

bool checkMove(char collor,char move1, char move2, int wavailble[][2],int Bavailble[][2], int wc, int bc){
  if(collor=='B'){
    for(int i = 0; i<bc;i++){
      if(Bavailble[i][0]== move1-'a'){
        if(Bavailble[i][1]== move2-'a') return true;
      }
    }
  }
  else if(collor=='W'){
     for(int i = 0; i<wc;i++){
      if(wavailble[i][0]==move1-'a'){
        if(wavailble[i][1]==move2-'a') 
          return true;
      }
    }
  }
  return false;
}

void printBoard(char board[][26], int n){
  printf("  ");
  for(int j = 1; j<n+1;j++){
    printf("%c", j+96);
  }
  printf("\n");
    
    for(int i = 0;i<n;i++){
      printf("%c ", i+97);
        for(int j = 0; j<n;j++){
         printf("%c", board[i][j]); 
        }
      printf("\n");
      }
    }

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
  //b
  if(colour== 'B' ||colour=='W') return false;
  if(colour=='U'){
    int first = row +deltaRow;
    int second = col + deltaCol, count1 = 0;
  if(positionInBounds(n,first,second)&&board[first][second]=='W'){
    count1++;
  while(positionInBounds(n,first,second)){
    first+=deltaRow;
    second+=deltaCol;
    if(!positionInBounds(n,first,second)) return false;
    else if(board[first][second]=='W'){
      count1++;
    }
    else if(board[first][second]=='B'){
      return count1>0;
    }
    else if(board[first][second]=='U')  return false;
    
  }
  }
  }
  return false;
}

bool checkLegalInDirectionw(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
  //w
    if(colour== 'B' ||colour=='W') return false;
  if(colour=='U'){
    int first = row +deltaRow;
    int second = col + deltaCol, count1 = 0;
  if(positionInBounds(n,first,second)&&board[first][second]=='B'){
    count1++;
  while(positionInBounds(n,first,second)){
    first+=deltaRow;
    second+=deltaCol;
    if(!positionInBounds(n,first,second)) return false;
    else if(board[first][second]=='B'){
      count1++;
    }
    else if(board[first][second]=='W'){
      return count1>0;
    }
    else if(board[first][second]=='U') return false;
    
  }
  }
  }
  return false;
}

int makeMove(char board[26][26], int n, char turn, int *row, int *col) {
  //printf("%d%d\n",*row,*col );
  {
  int count = 0;
        for(int deltaRow = -1; deltaRow<=1; deltaRow++){
          for(int deltaCol = -1; deltaCol<=1;deltaCol++){
            int times = checksecond(board, n, *row, *col, turn, deltaRow, deltaCol);
           if(times>0){            
             int first = *row +deltaRow;
             int second = *col + deltaCol;
             for(int i = 0;i<times;i++){           
               count++;
               first+=deltaRow;
               second+=deltaCol;
             }            
           }
              }
            } 
  return count;
          }  
  
}
int Wining(char board[26][26],int n){
  int white=0, black=0;
  for(int i = 0; i<n;i++){
    for(int j = 0;j<n;j++){
      if(board[i][j]=='W') white++;
      else if(board[i][j]=='B')black++;
    }
  }
  if(black==white) return 0;
  else if(black>white) return 1;
  else return -1;
}
//*******************************************************
// Note: Please only put your main function below
// DO NOT REMOVE THE FOLLOWING LINE
#ifndef TESTER_P2
// DO NOT REMOVE THE ABOVE LINE

int main(void) {
// Write your own main function here
  int num;
  printf("Enter the board dimension: ");
  scanf(" %d", &num);
  char arr[26][26];   
  for(int i = 0;i<num;i++){
        for(int j = 0; j<num;j++){
            arr[i][j] = 'U';
          if(i == num/2-1 && j == num/2-1)
            arr[i][j] = 'W';
          else if(i == num/2 && j == num/2)
            arr[i][j] = 'W';
          else if(i == num/2 && j == num/2-1)
            arr[i][j] = 'B';
          else if(i == num/2-1 && j == num/2)
            arr[i][j] = 'B';
        }
    }  

  char computer;
  printf("Computer plays (B/W): ");
  scanf(" %c", &computer);
  printBoard(arr, num);
  char move1,move2;
  bool happy=true, sad;
  
while(happy){
  char player;
  if(computer=='W') player='B';
  else player='W';
  
  //white AVAILBLE MOVE
  int wavailble[20][2];//1
  int wavailblecount= 0;//1
  int wmeow = 0;//1
  
  int w2availble[20][2];
  int w2availblecount= 0;
  int w2meow=0;

  
  for(int row = 0; row<num;row++){
      for(int col = 0; col<num;col++){
        for(int deltaRow = -1; deltaRow<=1; deltaRow++){
          int countagain =wavailblecount;
          for(int deltaCol = -1; deltaCol<=1;deltaCol++){
            if(checkLegalInDirectionw(arr, num, row, col, arr[row][col], deltaRow, deltaCol)&&arr[row][col]=='U'){
                wmeow++;
                w2availble[wavailblecount][0]= row;
                w2availble[wavailblecount][1]= col;
                wavailblecount++;
              break;              
            }        
          }
          if(countagain<wavailblecount)  break;
        }
      }
    }


  
  //black AVAILBLE MOVE
  int bmeow = 0;
  int Bavailble[20][2];
  int Bavailblecount= 0;

  int b2availble[20][2];
  int b2availblecount= 0;
  int b2meow=0;
  
  for(int row = 0; row<num;row++){
      for(int col = 0; col<num;col++){
        for(int deltaRow = -1; deltaRow<=1; deltaRow++){
          int countagain = Bavailblecount;
          for(int deltaCol = -1; deltaCol<=1;deltaCol++){       
            if(checkLegalInDirection(arr, num, row, col, arr[row][col], deltaRow, deltaCol)&&arr[row][col]=='U'){
                bmeow++;
                Bavailble[Bavailblecount][0]= row;
                Bavailble[Bavailblecount][1]= col;
                Bavailblecount++;
              break;              
            }        
          }
          if(countagain<Bavailblecount)  break;
        }
      }
    }
if(bmeow==0&&wmeow==0) break;
else if(bmeow==0) printf("B player has no vaild move.\n");
else if(computer=='B'){
  char oh1,oh2;
    int highest = 0;
    for(int iamtired = 0; iamtired<bmeow;iamtired++){
      int move3 = makeMove(arr, num, computer, &Bavailble[iamtired][0], &Bavailble[iamtired][1]);
      if(move3>highest){
    highest = move3;
    oh1 = Bavailble[iamtired][0]+'a';
    oh2 = Bavailble[iamtired][1]+'a';
  } 
    }
    printf("Computer places B at %c%c.\n",oh1,oh2);

    if(checkMove(computer,oh1,oh2,wavailble,Bavailble,wavailblecount,Bavailblecount)){
      flipthecolor(arr,computer,oh1,oh2,num);
      printBoard(arr, num);
  }
}
else{
  printf("Enter move for colour %c (RowCol): ", player);//player == B
  scanf(" %c %c", &move1, &move2);
      
  if(checkMove(player,move1,move2,wavailble,Bavailble,wavailblecount,Bavailblecount)){
      flipthecolor(arr,player,move1,move2,num);
      printBoard(arr, num);
  }
  else{
    printf("Invalid move.\n%c player wins.",computer);
    return 0;
  }
}

  //white AVAILBLE MOVE

  for(int row = 0; row<num;row++){
      for(int col = 0; col<num;col++){
        for(int deltaRow = -1; deltaRow<=1; deltaRow++){
          int countagain =w2availblecount;
          for(int deltaCol = -1; deltaCol<=1;deltaCol++){
            if(checkLegalInDirectionw(arr, num, row, col, arr[row][col], deltaRow, deltaCol)&&arr[row][col]=='U'){
                w2meow++;
                w2availble[w2availblecount][0]= row;
                w2availble[w2availblecount][1]= col;
                w2availblecount++;
              break;              
            }        
          }
          if(countagain<w2availblecount )  break;
        }
      }
    }

  //black availble

  //black AVAILBLE MOVE

  for(int row = 0; row<num;row++){
      for(int col = 0; col<num;col++){
        for(int deltaRow = -1; deltaRow<=1; deltaRow++){
          int countagain = Bavailblecount;
          for(int deltaCol = -1; deltaCol<=1;deltaCol++){       
            if(checkLegalInDirection(arr, num, row, col, arr[row][col], deltaRow, deltaCol)&&arr[row][col]=='U'){
                b2meow++;
                b2availble[b2availblecount][0]= row;
                b2availble[b2availblecount][1]= col;
                b2availblecount++;
              break;              
            }        
          }
          if(countagain<b2availblecount)  break;
        }
      }
    }

  
  if(b2meow==0&&w2meow==0) break;
  else if(w2meow==0)printf("W player has no valid move.\n");
  else if(computer =='W'){
    
    char oh1,oh2;
    int highest = 0;
    for(int iamtired = 0; iamtired<w2meow;iamtired++){
      int move3 = makeMove(arr, num, computer, &w2availble[iamtired][0], &w2availble[iamtired][1]);
      if(move3>highest){
    highest = move3;
    oh1 = w2availble[iamtired][0]+'a';
    oh2 = w2availble[iamtired][1]+'a';
  } 
    }
    printf("Computer places W at %c%c.\n",oh1,oh2);

    if(checkMove(computer,oh1,oh2,w2availble,b2availble,w2availblecount,b2availblecount)){
      flipthecolor(arr,computer,oh1,oh2,num);
      printBoard(arr, num);
  }

    
  }
  else{
    printf("Enter move for colour %c (RowCol): ", player);
    scanf(" %c %c", &move1, &move2);
      
    if(checkMove(player,move1,move2,w2availble,b2availble,w2availblecount,b2availblecount)){
      flipthecolor(arr,player,move1,move2,num);
      printBoard(arr, num);
    }
    else{
    printf("Invalid move.\n%c player wins.",computer);
    return 0;
    }
  }
  if(b2meow==0&&w2meow==0) break;
}
  
  int whowins= Wining(arr,num);
  if(whowins==1) printf("B player wins.");
  else if(whowins==-1)printf("W player wins.");
  else  printf("Draw!");

return 0;
}
// DO NOT REMOVE THE FOLLOWING LINE
#endif
// DO NOT REMOVE THE ABOVE LINE
//*******************************************************