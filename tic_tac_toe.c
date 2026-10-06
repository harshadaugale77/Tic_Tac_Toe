#include<stdio.h>
#include<unistd.h>
void loading();
void show_board();
void play_game(char arr[]);
void start_game(char ply1[],char ply2[]);
int main()
{
    printf("=================================================================\n");
    printf("----------------------TIC TAC TOE--------------------------------\n");
    printf("=================================================================\n");

    loading();
  
    char choice;
    printf("YOU WANT TO PLAY!!!(Y/S) ? : ");
    scanf("%c",&choice);

    char ply1[10];
    char ply2[10];
    printf("Enter player1 Name:");
    scanf(" %[^\n]",ply1);

    printf("Enter player2 Name:");
    scanf(" %[^\n]",ply2);

    show_board();
    char choice1;
    printf("Continue (Y/N) ? :");
    scanf(" %c",&choice1);
  
    if(choice1>='n' || choice1=='N')
    {
      printf("close the game!!!");
      return 0;
    }
    printf("\n");
    loading();
     
    start_game(ply1,ply2);

}
void loading()
{
    for(int i=0;i<10;i++)
    {
        printf("loading.  \r");
        fflush(stdout);
        usleep(250000);
    
        printf("loading.. \r");
        fflush(stdout);
        usleep(250000);
    
        printf("loading...\r");
        fflush(stdout);
        usleep(250000);
    
       printf("loading...\r");
    }
  printf("\n");
}
void show_board(char arr[])
{
    printf("NOTE : Enter the choice 1-9 to select Box!!\n");
    printf("          _________________________\n");
    printf("          |       |       |       |\n");
    printf("          |   1   |   2   |    3  |\n");
    printf("          |_______|_______|_______|\n");
    printf("          |       |       |       |\n");
    printf("          |   4   |   5   |   6   |\n");
    printf("          |_______|_______|_______|\n");
    printf("          |       |       |       |\n");
    printf("          |   7   |   8   |  9    |\n");
    printf("          |_______|_______|_______|\n");
    
    printf("\n");
      
}
void play_game(char arr[])
{
    printf("\033[H\033[2J\033[3J");
    printf("          _________________________\n");
    printf("          |       |       |       |\n");
    printf("          |   %c   |   %c   |   %c   |\n",arr[0],arr[1],arr[2]);
    printf("          |_______|_______|_______|\n");
    printf("          |       |       |       |\n");
    printf("          |   %c   |   %c   |   %c   |\n",arr[3],arr[4],arr[5]);
    printf("          |_______|_______|_______|\n");
    printf("          |       |       |       |\n");
    printf("          |   %c   |   %c   |   %c   |\n",arr[6],arr[7],arr[8]);
    printf("          |_______|_______|_______|\n");
    
    printf("\n");
      
}
void start_game(char ply1[],char ply2[])
{
   char arr[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
   int pos;
   int turn=0;
   int symbol='X';

   while(turn<9)
   {
    printf("%s [%c] : ",symbol=='X' ? ply1:ply2,symbol);
    scanf("%d",&pos);

    if(pos<1 || pos>9)
    {
        printf("Invalid position!!Enter again..\n");
        continue;
    }
    if(arr[pos-1]=='X' || arr[pos-1]=='O')
    {
       printf("Position is already taken,try again!!\n");
       continue;
    }   
    arr[pos-1]=symbol;
    turn++;

    play_game(arr);

    if((arr[0]==symbol && arr[1]==symbol && arr[2]==symbol)||
       (arr[3]==symbol && arr[4]==symbol && arr[5]==symbol)||
       (arr[6]==symbol && arr[7]==symbol && arr[8]==symbol)||
       (arr[0]==symbol && arr[3]==symbol && arr[6]==symbol)||
       (arr[1]==symbol && arr[4]==symbol && arr[7]==symbol)||
       (arr[2]==symbol && arr[5]==symbol && arr[8]==symbol)||
       (arr[0]==symbol && arr[4]==symbol && arr[8]==symbol)||
       (arr[2]==symbol && arr[4]==symbol && arr[6]==symbol))
       {

        printf("%s [%c] CONGRTATS YOU  WINNER 💕!!!\n",symbol=='X' ? ply1:ply2,symbol);
        return;
       }
       if(symbol=='X')
       {
           symbol='O';
       }
       else
       {
           symbol='X';
       }
       
   }
   if(turn==9)
   {
    printf("TIE!!!!");
   }

}