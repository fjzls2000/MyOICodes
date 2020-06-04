/**************************************************************
    Problem: 1619
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:376 ms
    Memory:9692 kb
****************************************************************/
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define inf 0x7fffffff
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,cnt,ans; 
int xx[8]={0,0,1,1,1,-1,-1,-1},yy[8]={1,-1,1,0,-1,1,0,-1}; 
int mp[705][705];
bool mark[705][705];
struct data{int x,y,t;}a[500005];
bool operator<(data a,data b){return a.t>b.t;}
void dfs(int x,int y)
{
    mark[x][y]=1;
    for(int i=0;i<8;i++)
    { 
        int nowx=x+xx[i],nowy=y+yy[i];
        if(nowx<1||nowy<1||nowx>n||nowy>m)continue;
        if(mp[nowx][nowy]<=mp[x][y]&&!mark[nowx][nowy])dfs(nowx,nowy);
    } 
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            ++cnt;
            mp[i][j]=read();
            a[cnt].x=i;a[cnt].y=j;a[cnt].t=mp[i][j];
        }
    sort(a+1,a+cnt+1);
    for(int i=1;i<=cnt;i++)
        if(!mark[a[i].x][a[i].y]){dfs(a[i].x,a[i].y);ans++;}
    printf("%d",ans);
    return 0;
}