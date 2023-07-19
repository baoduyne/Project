#include<iostream>
#include<windows.h>
#include<ctime>
#include<cstdlib>
#include<conio.h>

using namespace std;

struct point 
{
    int x,y;
    int x0,y0;
};

void gotoxy(int x,int y)
{
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD a={x,y};
  SetConsoleCursorPosition(h,a);

}

void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;
 
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

int main()
{
SetWindowSize(16,25);
ShowScrollbar(0);
RESET :

srand(time(0));
point snake[100];
point huongdi;

int score = 0;
int xp,yp;
int random = rand() %10 +1;
xp = rand() %10 +1 ;
yp = rand() %10 +1 ;

huongdi.x = 0;
huongdi.y = 0;
int size = 1;
snake[0].x=5;
snake[0].y=5;
int keyo=0;


while(true)
{
    for(int i = 1 ; i<15 ; i++)
    { gotoxy(i,0);
      cout<<"--";
      gotoxy(0,i);
      cout<<"|"<<endl;
      gotoxy(i,15);
      cout<<"--";
      gotoxy(15,i);
      cout<<"|"<<endl;
    }


    gotoxy(1,18);
    cout<<"SCORE : "<<score;
   gotoxy(xp,yp);
   cout<<"O";
backdoor:
  if(kbhit())
  {
   
   char key = getch();
   if(key == 'a'){if (keyo==1||keyo==3){goto backdoor;} else{huongdi.x --; huongdi.y=0; keyo = 1;}}
   if(key == 's'){if (keyo==2||keyo==4){goto backdoor;} else{huongdi.y ++; huongdi.x= 0; keyo = 2 ;}}
   if(key == 'd'){if (keyo==3||keyo==1){goto backdoor;} else{huongdi.x ++; huongdi.y = 0; keyo= 3 ;}}
   if(key == 'w'){if (keyo==4||keyo==2){goto backdoor;} else{huongdi.y --; huongdi.x = 0; keyo = 4 ;}}
  }

for(int i = 0 ; i<size ; i++)
{ 
if( i == 0)
{
  snake[0].x0=snake[0].x;snake[0].y0=snake[0].y;
  snake[0].x = snake[0].x + huongdi.x;
  snake[0].y = snake[0].y + huongdi.y; 
   gotoxy(snake[0].x,snake[0].y);
   cout<<"o";
}
else{
snake[i].x0=snake[i].x;snake[i].y0 = snake[i].y;
snake[i].x = snake[i-1].x0; snake[i].y = snake[i-1].y0;

gotoxy(snake[i].x,snake[i].y);
cout<<"*";

if(snake[0].x==snake[i].x && snake[0].y == snake[i].y)
{ gotoxy(1,22);
  cout<<"GAME OVER!!";
  system("pause");
  goto RESET;
}
}
for(int i = 0 ; i<15 ; i++)
{if(snake[0].x==0 && snake[0].y==i)
{gotoxy(1,22);
  cout<<"GAME OVER!!";
  system("pause");
  goto RESET;}

if(snake[0].x==i && snake[0].y==0)
  {gotoxy(1,22);
  cout<<"GAME OVER!!";
  system("pause");
  goto RESET;}

if(snake[0].x==15 && snake[0].y==i)
{
  gotoxy(1,22);
  cout<<"GAME OVER!!";
  system("pause");
  goto RESET;
}
if(snake[0].x==i && snake[0].y==15)
{
  gotoxy(1,22);
  cout<<"GAME OVER!!";
  system("pause");
  goto RESET;
}
} 
}


if(snake[0].x == xp && snake[0].y==yp) {

random = rand()%10+1;

xp=random;
yp=random;
size++;
score++;
}


Sleep(500);
system("cls");

}


}