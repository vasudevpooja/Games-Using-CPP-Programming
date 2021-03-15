#include<graphics.h>
#include<iostream>
#include<cstdio>
using namespace std;
struct pawns
{
int position;
int  update;
int sum;
};
struct player
{
struct pawns g[4];
int def;
int colour;
int win;
};
int colour_grid[4]={4,2,14,1};
int arr[2][52]={0};
int shape1_diamond(int);
int  home(int,int,int);
int red_house[2][6];
int green_house[2][6];
int blue_house[2][6];
int yellow_house[2][6];
void house_assigned(void);
void design(void);
int chance(int,int,int );
void play(void);
void shape2_design(int x,int y)
{
line(x-7,y-7,x,y+10);
line(x,y+10,x+7,y-7); 
line(x+7,y-7,x-7,y-7);
line(x-7,y+7,x+7,y+7);
line(x+7,y+7,x,y-10);
line(x,y-10,x-7,y+7);
}
void flood_fill(int x,int y,int colour1,int colour2)
{
int c;
c=getpixel(x,y);
if(c==colour2)
{
setcolor(colour1);
putpixel (x,y,colour1);
flood_fill(x+1,y,colour1,colour2);
flood_fill(x,y+1,colour1,colour2);
flood_fill(x-1,y,colour1,colour2);
flood_fill(x,y-1,colour1,colour2);
}
}
void horizontal(int x,int y,int c)
{
int i=0;
for(i=0;i<5;i++)
{
flood_fill(x+i*30,y,c,0);
}
}
void vertical(int x,int y,int c)
{
int i=0;
for(i=0;i<5;i++)
{
flood_fill(x,y+i*30,c,0);
}
}
void shape3_circle(int x,int y,int c)
{
int r=13;
shape3_circle(x+28,y+28,r);
shape3_circle(x+28,y+28+55,r);
shape3_circle(x+28+55,y+28,r);
shape3_circle(x+28+55,y+28+55,r);
flood_fill(x+28,y+28,c,0);
flood_fill(x+28,y+28+55,c,0);int arr[2][15]={0};
flood_fill(x+28+55,y+28,c,0);
flood_fill(x+28+55,y+28+55,c,0);
}
void path()
{
int i=0,j,k=0;
for (j =0;j<53;j++)
arr[2][j]=0;
for( j=0;j<=15;j++)
{
if(j==6)
{
int m=0,p=0;
for(int l=6;l<19;l++)
{
if(l<=11)
{
arr[i][l]=215;
arr[i+1][l]=185-m*30;
arr[i][l+26]=275;
arr[i+1][l+26]=305+m*30;
m++;
}
else if(l==12)
{
arr[i][l]=245;
arr[i+1][l]=35;
arr[i][38]=245;
arr[i+1][38]=455;
arr[i][51]=35;
arr[i+1][51]=245;
}
else
{
arr[i][l]=275;
arr[i+1][l]=35+p*30;
arr[i][l+26]=215;
arr[i+1][l+26]=455-p*30;
p++;
}}
j+=2;
k+=13;
}
else
{
if(j==15)
{
arr[i][j+10]=455;
arr[i+1][j+10]=245;
}
else
{
arr[i][k]=35+j*30;
arr[i+1][k] = 215;
arr[i][50-k]=35+j*30;
arr[i+1][50-k]=275;
k++;
}
}
}
}
int level_1(int *p)
{
 int i,j=20,k=250,l=10,m=10,co_mo=0,inc=0;
 char c;
 cleardevice();
 while(1){
 setcolor(14);
 settextstyle(1,HORIZ_DIR,5);
 outtextxy(40,100,"WELCOME TO");
 outtextxy(40,150,"LUDO");
 outtextxy(40,200,"MULTIPLAYER");
 settextstyle(0,HORIZ_DIR,0);
 setcolor(15);
 outtextxy(400,400,"Press 'SPACE' to Play.");
  char ch=getch();
 if(ch==' ') break;
 getch();
  }
int main()
{
int m=DETECT;
int n;
struct player person[4];
initgraph(&m,&n,"");
int flag,point=0;
flag=level_1(&point);
design();
path();
house_assigned();
play();
getch();
closegraph();
}
void design(void)
{
int i=0,x,y,j;
setcolor(15);
rectangle(20,20,470,470);
line(200,20,200,470);
line(230,20,230,200);
line(230,290,230,470);
line(290,230,470,230);
line(260,20,260,200);
line(260,290,260,470);
line(290,20,290,470);
line(20,200,470,200);
line(20,230,200,230);
line(290,230,470,230);
line(20,260,200,260);
line(290,260,470,260);
line(20,290,470,290);
line(200,200,290,290);
line(200,290,290,200);
shape2_design(65,215);
shape2_design(215,95);
shape2_design(275,65);
shape2_design(395,215);
shape2_design(425,275);
shape2_design(275,395);
shape2_design(215,425);
shape2_design(95,275);
rectangle(50,50,170,170);
rectangle(55,55,165,165);
rectangle(320,50,440,170);
rectangle(325,55,435,165);
rectangle(50,320,170,440);
rectangle(55,325,165,435);
rectangle(320,320,440,440);
rectangle(325,325,435,435);
for(i=0;i<15;i++)
{
if(i>=6&&i<=9)
continue;
line(20+i*30,200,20+i*30,290);
}
for(i=0;i<15;i++)
{
if(i>=6&&i<=9)
continue;
line(200,20+i*30,290,20+i*30);
}
x=55,y=55;
shape3_circle(x,y,4);
shape3_circle(x+270,y,2);
shape3_circle(x,y+270,1);
shape3_circle(x+270,y+270,14);
flood_fill(235,245,4,0);
flood_fill(245,235,2,0);
flood_fill(245,275,1,0);
flood_fill(275,245,14,0);
flood_fill(21,21,4,0);
flood_fill(291,21,2,0);
flood_fill(21,291,1,0);
flood_fill(291,291,14,0);
flood_fill(56,56,15,0);
flood_fill(56,326,15,0);
flood_fill(326,56,15,0);
flood_fill(326,326,15,0);
flood_fill(51,201,11,0);
flood_fill(201,81,11,0);
flood_fill(261,51,11,0);
flood_fill(381,201,11,0);
flood_fill(411,261,11,0);
flood_fill(261,381,11,0);
flood_fill(201,411,11,0);
flood_fill(81,261,11,0);
horizontal(55,245,4);
horizontal(305,245,14);
vertical(245,55,2);
vertical(245,305,1);
setcolor(4);
}
int chance(int first,int last,int clr)
{
int num=6,temp=0,q,v,w,previous,t=0,t1,t2;
for(q=first;q<=last;q++)
{
if(q==52)
{
last=last-52;
chance(0,last,clr);
q=0;
return 0;
}
t=getpixel(arr[0][q],arr[1][q]);
setcolor(clr);
v=arr[0][q];
w=arr[1][q];
delay(200);
shape3_circle(v,w,12);
flood_fill(v,w,clr,0);
delay(200);
if(t!=clr||q==first){
setcolor(0);
shape3_circle(v,w,12);
flood_fill(v,w,0,clr);
}
}
setcolor(clr);
shape3_circle(v,w,12);
flood_fill(v,w,clr,0);
}
void play()
{
struct player  *person;
int n,k=1;
int num;
printf("\n Number of Player? : ");
scanf("%d",&n);
person = (struct player *)malloc(n*sizeof(struct player));
for(int i =0;i< n;i++)
{
for(int j=0;j<4;j++){
person[i].g[j].position=-1;
person[i].g[j].sum=0;
person[i].g[j].update=1;
}
person[i].win=0;
person[i].def=k;
k+=13;
}
int i=0;
printf ("GAME");
while(1)
{
printf ("\nPlayer-%d ::",i);
int num,run,first,getcl,safejone;
while(1)
{
num = (rand() % 6 ) +1;
printf("\tRoll the Dice: %d :",num);
printf("\n\tYour turn:(Choose your pawn:0,1,2,3)  ::");
scanf("%d",&run);
if( person[i].g[run].update==0)
{
cout<<"Reached home."<<endl;
break;
}
if(num == 6)
{
if(person[i].g[run].position== -1)
{
person[i].g[run].position = person[i].def;
person[i].g[run].sum=0;
}
else{
person[i].g[run].sum+=num;
first = person[i].g[run].position;
getcl=getpixel(arr[0][first+num],arr[1][first+num]);
if(getcl != 0 && getcl != colour_grid[i] && first+num != 1 && first+num != 9 && first+num != 14 && first+num != 22 && first+num != 27 && first+num != 35 && first+num != 40 && first+num !=48  )
{
int l,m;
for( l=0;l<n;l++)
{
if(person[l].colour == getcl)
break;
}
printf(" :: m %d  :",m);
for( m=0 ; m<4;m++)
{ if( person[l].g[m].position == first+num)
break;
}
person[l].g[m].position =-1;
printf("Pawn Number: %d %d",m,l);
flood_fill(arr[0][first+num],arr[1][first+num],0,getcl);
}
printf("sum :%d\n",person[i].g[run].sum);
if(person[i].g[run].sum > 50)
{
person[i].g[run].position=home(colour_grid[i],first,first+num);
if(  person[i].g[run].position == 6)
{cout<<"\t\tOVER"<<endl;    person[i].g[run].update=0;
person[i].win+=1;
}
break;
}
chance(first,(first+num),colour_grid[i]);
person[i].g[run].position = (person[i].g[run].position+num)%52;
}
continue;
}
else{
if(person[i].g[run].position==-1){
printf(" \n\t\t::CAN'T MOVE ::");
break;}
person[i].g[run].sum+=num;
first = person[i].g[run].position;
getcl=getpixel(arr[0][first+num],arr[1][first+num]);
if(getcl != 0 && getcl != colour_grid[i] && first+num != 1 && first+num != 9 && first+num != 14 && first+num != 22 && first+num != 27 && first+num != 35 && first+num != 40 && first+num !=48  )
{
int l=0,m=0;
for( l=0;l<n;l++)
{ if(colour_grid[l] == getcl)
break;
}
for( m=0 ; m<4;m++)
{ if( person[l].g[m].position == first+num)
break;
}
person[l].g[m].position =-1;
flood_fill(arr[0][first+num],arr[1][first+num],0,getcl);
}
if( person[i].g[run].sum >50)
{    printf("  \t \t HOME");

person[i].g[run].position= home(colour_grid[i],first,first+num);
if(  person[i].g[run].position == 6)
{cout<<"\t\tOVER"<<endl;   person[i].g[run].update=0;
person[i].win+=1;
if(person[i].win==4)
{  cout<<"\t\tTHE WINNER IS::"<<i<<"drum roll"<<endl;
return;
}
}
break;
}
chance(first,(first+num),colour_grid[i]);
person[i].g[run].position=(person[i].g[run].position+num)%52;
break;
}
}
i=(i+1)%n;
}
}
int shape1_diamond(int x)
{
int a;
if(x == 4)
a = 51;
else if( x == 2)
a = 12;
else if(x == 14)
a = 25;
else if (x == 1)
a == 38;
return a;
}
void house_assigned()
{
for(int i=0;i<6;i++)
{
red_house[0][i]=65+30*i;
red_house[1][i]=245;
}
for(int i=0;i<6;i++)
{
green_house[0][i]=245;
green_house[1][i]=65+30*i;
}
for(int i=0;i<6;i++)
{
blue_house[0][i]=245;
blue_house[1][i]=425-30*i;
}
for(int i=0;i<6;i++)
{
yellow_house[0][i]=425-30*i;
yellow_house[1][i]=245;
}
}
int home(int clr,int first,int position)
{
int ab,remn,tmp,v,w;
int bdb;
tmp=shape1_diamond(clr);
if(first > 5)
{chance(first,tmp,clr);
bdb=0;
remn=position-tmp;
flood_fill(arr[0][tmp],arr[1][tmp],0,clr);
}
else{
if(position > 6)
{
return first;
}
bdb=first;
remn=position
;
}
switch(clr)
{
case 1:    if(bdb > 0)
{
setcolor(1);
v=blue_house[0][bdb-1];
w=blue_house[1][bdb-1];
shape3_circle(v,w,12);
flood_fill(v,w,1,3);
}
for(ab=bdb;ab<remn;ab++)
{ clr=3;
setcolor(clr);
v=blue_house[0][ab];
w=blue_house[1][ab];
delay(200);
shape3_circle(v,w,12);
flood_fill(v,w,clr,1);
delay(200);
setcolor(1);
shape3_circle(v,w,12);
flood_fill(v,w,1,clr);
}
setcolor(clr);
shape3_circle(v,w,12);
flood_fill(v,w,clr,1);
break;
case 2:    if(bdb > 0)
{
setcolor(2);
v=green_house[0][bdb-1];
w=green_house[1][bdb-1];
shape3_circle(v,w,12);
flood_fill(v,w,2,3);
}
for(ab=bdb;ab<remn;ab++)
{  clr=3;
setcolor(clr);
v=green_house[0][ab];
w=green_house[1][ab];
delay(200);
shape3_circle(v,w,12);
flood_fill(v,w,clr,2);
delay(200);
setcolor(2);
shape3_circle(v,w,12);
flood_fill(v,w,2,clr);
}
setcolor(clr);
shape3_circle(v,w,12);
flood_fill(v,w,clr,2);
break;
case 4:        if(bdb > 0)
{
setcolor(4);
v=red_house[0][bdb-1];
w=red_house[1][bdb-1];
shape3_circle(v,w,12);
flood_fill(v,w,4,3);
}
for(ab=bdb;ab<remn;ab++)
{     clr=3;
setcolor(clr);
v=red_house[0][ab];
w=red_house[1][ab];
delay(200);
shape3_circle(v,w,12);
flood_fill(v,w,clr,4);
delay(200);
setcolor(4);
shape3_circle(v,w,12);
flood_fill(v,w,4,clr);
}
setcolor(clr);
shape3_circle(v,w,12);
flood_fill(v,w,clr,4);
break;
case 14:    if(bdb > 0)
{
setcolor(14);
v=yellow_house[0][bdb-1];
w=yellow_house[1][bdb-1];
shape3_circle(v,w,12);
flood_fill(v,w,14,3);
}
for(ab=bdb;ab<remn;ab++)
{ clr=3;
setcolor(clr);
v=yellow_house[0][ab];
w=yellow_house[1][ab];
delay(200);
shape3_circle(v,w,12);
flood_fill(v,w,clr,14);
delay(200);
setcolor(14);
shape3_circle(v,w,12);
flood_fill(v,w,14,clr);
}
setcolor(clr);
shape3_circle(v,w,12);
flood_fill(v,w,clr,14);
break;
}
return ab;
}
