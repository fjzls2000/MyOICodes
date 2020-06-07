/**************************************************************
    Problem: 1593
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:536 ms
    Memory:6760 kb
****************************************************************/
 
#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
struct data{int l,r,m,lm,rm,sum,tag;}t[200001];
void pushup(int k)
{
     if(t[k+k].sum==t[k+k].m)
         t[k].lm=t[k+k].sum+t[k+k+1].lm;
     else t[k].lm=t[k+k].lm;
     if(t[k+k+1].sum==t[k+k+1].m)
         t[k].rm=t[k+k+1].sum+t[k+k].rm;
     else t[k].rm=t[k+k+1].rm;
     t[k].m=max(t[k+k].m,t[k+k+1].m);
     t[k].m=max(t[k].m,t[k+k].rm+t[k+k+1].lm);
}
void pushdown(int k)
{
     int tag=t[k].tag;t[k].tag=0;
     if(t[k].l==t[k].r)return;
     if(tag==1)
     {
          t[k+k].lm=t[k+k].rm=t[k+k].m=t[k+k].sum;
          t[k+k+1].lm=t[k+k+1].rm=t[k+k+1].m=t[k+k+1].sum;
          t[k+k].tag=t[k+k+1].tag=1;
     }
     else if(tag==2)
     {
          t[k+k].lm=t[k+k].rm=t[k+k].m=0;
          t[k+k+1].lm=t[k+k+1].rm=t[k+k+1].m=0;
          t[k+k].tag=t[k+k+1].tag=2;
     }
}
void build(int k,int l,int r)
{
     t[k].l=l;t[k].r=r;
     t[k].lm=t[k].rm=t[k].m=t[k].sum=r-l+1;
     if(l==r)return;
     int mid=(l+r)>>1;
     build(k+k,l,mid);build(k+k+1,mid+1,r);
}
void change(int k,int x,int y,int f)
{
     pushdown(k);
     int l=t[k].l,r=t[k].r;
     if(l==x&&y==r)
     {
         if(f==1)t[k].lm=t[k].rm=t[k].m=t[k].sum;
         else t[k].lm=t[k].rm=t[k].m=0;
         t[k].tag=f;
         return;
     }
     int mid=(l+r)>>1;
     if(mid>=y)change(k+k,x,y,f);
     else if(mid<x)change(k+k+1,x,y,f);
     else
     {
          change(k+k,x,mid,f);
          change(k+k+1,mid+1,y,f);
     }
     pushup(k);
}
int ask(int k,int x)
{
     pushdown(k);
     int l=t[k].l,r=t[k].r,mid=(l+r)>>1;;
     if(l==r)return l;
     if(t[k+k].m>=x)return ask(k+k,x);
     if(t[k+k].rm+t[k+k+1].lm>=x)
         return mid-t[k+k].rm+1;
     return ask(k+k+1,x);
} 
int main()
{
    scanf("%d%d",&n,&m);
    build(1,1,n);
    for(int i=1;i<=m;++i)
    {
        int f,x,y;
        scanf("%d",&f);
        if(f==1)
        {
             scanf("%d",&x);
             if(t[1].m<x)printf("0\n");
             else {int p=ask(1,x);printf("%d\n",p);change(1,p,p+x-1,2);}
        }
        else {scanf("%d%d",&x,&y);change(1,x,x+y-1,1);}
    }
    return 0;
} 