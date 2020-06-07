/**************************************************************
    Problem: 1085
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1400 ms
    Memory:1288 kb
****************************************************************/
 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T,k;
int ans[5][5]={{1,1,1,1,1},
    {0,1,1,1,1},
    {0,0,2,1,1},
    {0,0,0,0,1},
    {0,0,0,0,0}};
int xx[8]={1,1,-1,-1,2,2,-2,-2};
int yy[8]={2,-2,2,-2,1,-1,1,-1};
int flag=0;
int judge(int a[5][5])
{
     for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
           if(ans[i][j]!=a[i][j])return 0;
     return 1;
}
int eva(int a[5][5],int s)
{
     int v=0;
     for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
           if(a[i][j]!=ans[i][j]){v++;if(v+s>k)return 0;}
     return 1;
 }
void search(int s,int a[5][5],int x,int y)
{
     if(s==k){if(judge(a))flag=1;return;}
     if(flag==1)return;
     for(int i=0;i<8;i++)
     {
             int nowx=x+xx[i],nowy=y+yy[i];
             if(nowx<0||nowx>4||nowy<0||nowy>4)continue;
             swap(a[x][y],a[nowx][nowy]);
             if(eva(a,s))search(s+1,a,nowx,nowy);
             swap(a[x][y],a[nowx][nowy]);
     }
 }
int main()
{
    scanf("%d",&T);
    while(T--)
    {
              int a[5][5];int x,y;
              memset(a,0,sizeof(a));
              for(int i=0;i<5;i++)
              {
                      char ch[10];scanf("%s",ch);
                      for(int j=0;j<5;j++)
                      {
                      if(ch[j]=='*'){a[i][j]=2;x=i;y=j;}
                      else a[i][j]=ch[j]-'0';
                      }
              }
              for(k=1;k<=15;k++)
                 {search(0,a,x,y);if(flag){printf("%d\n",k);break;}}
              if(!flag)printf("-1\n");
              else flag=0;
    }
    return 0;
}