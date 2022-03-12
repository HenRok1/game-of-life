#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

#define P 20

int a[P][P],b[P][P];

int chk(int x, int y)
{
    int i=0;
    if (a[(x+P-1)%P][y]==1) i++;
    if (a[(x+P-1)%P][(y+P-1)%P]==1) i++;
    if (a[(x+P-1)%P][(y+1)%P]==1) i++;
    if (a[x][(y+P-1)%P]==1) i++;
    if (a[x][(y+1)%P]==1) i++;
    if (a[(x+1)%P][(y+P-1)%P]==1) i++;
    if (a[(x+1)%P][y]==1) i++;
    if (a[(x+1)%P][(y+1)%P]==1) i++;
    return i;
}


void gotoxy(short x,short y)///////////???????????
{
   // COORD Coor;
   //  Coor.X=x; Coor.Y=y;
  //  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) ,Coor);
}

int main()
{
    int i,j,t,seed;
   // printf("Enter seed (0 for random seed):");
 //   scanf("%d",&seed);
 //  if (seed==0) srand(time(NULL));
    //    else srand(seed);


    //testttst
 //   system("cls");

    for(i=0;i<P;i++)
        for(j=0;j<P;j++)
        {
            a[i][j]=rand()%2;
            gotoxy(i,j);
            printf("%c",a[i][j]==1?'#':' ');
        }
     ///while (true)                //while (!kbhit())
    {
      //  sleep (150);
        for(i=0;i<P;i++)
            for(j=0;j<P;j++)
            {
                if (t=chk(i,j)==3) b[i][j]=1;
                else if (t==2) b[i][j]=a[i][j];
                else  b[i][j]=0;
            }

        for (i=0; i<P;i++)
            for(j=0; j<P; j++)
            {
                
                gotoxy(i,j);
                printf("%c",b[i][j]==1?'#':' ');
                a[i][j]=b[i][j];
            }
    }
    return 1;
}