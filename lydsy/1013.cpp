/**************************************************************
    Problem: 1013
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:4 ms
    Memory:1292 kb
****************************************************************/
 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define eps 1e-6
using namespace std;
int n;
double f[21],a[21][21];
double sqr(double x){return x*x;}
void ini()
{
    scanf("%d",&n); 
    for(int i=1;i<=n;i++)scanf("%lf",&f[i]);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
       {
           double t;
           scanf("%lf",&t);
           a[i][j]=2*(t-f[j]);
           a[i][n+1]+=sqr(t)-sqr(f[j]); 
       }
}
bool gauss()
{
     int now=1,to;double t;
     for(int i=1;i<=n;i++)
     {
         for(to=now;to<=n;to++)if(fabs(a[to][i])>eps)break;
         if(to>n)continue;
         if(to!=now)for(int j=1;j<=n+1;j++)
            swap(a[to][j],a[now][j]);
         t=a[now][i];
         for(int j=1;j<=n+1;j++)a[now][j]/=t;
         for(int j=1;j<=n;j++)
             if(j!=now)
             {
             t=a[j][i];
             for(int k=1;k<=n+1;k++)
                a[j][k]-=t*a[now][k];
                }
         now++;
     }
     for(int i=now;i<=n;i++)
        if(fabs(a[i][n+1])>eps)return 0;
     return 1;
}
int main()
{
    ini();
    gauss();
    for(int i=1;i<=n-1;i++)
        printf("%.3lf ",a[i][n+1]);
    printf("%.3lf\n",a[n][n+1]);
    return 0;
}