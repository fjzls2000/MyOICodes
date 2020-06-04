/**************************************************************
    Problem: 1024
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:12 ms
    Memory:1288 kb
****************************************************************/
 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#define ll long long 
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int x,y,n;
double dfs(int k,double x,double y)
{
    if(k==1)return max(x/y,y/x);
    double ans=1e30;
    for(int i=1;i<=k/2;i++)
    {
        double tx=x*i/k,ty=y*i/k;
        ans=min(ans,max(dfs(i,tx,y),dfs(k-i,x-tx,y)));
        ans=min(ans,max(dfs(i,x,ty),dfs(k-i,x,y-ty)));
    }
    return ans;
}
int main()
{
    x=read();y=read();n=read();
    printf("%.6lf",dfs(n,x,y));
    return 0;
}