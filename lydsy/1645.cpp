/**************************************************************
    Problem: 1645
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:332 ms
    Memory:7072 kb
****************************************************************/
 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
#define inf 10000000000
using namespace std;
inline ll read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int x[40005],y[40005],val[40005],disc[80005];
struct seg{int l,r,mx,tag;}t[320005];
int find(int x)
{
    int l=1,r=2*n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(disc[mid]<x)l=mid+1;
        else if(disc[mid]==x)return mid;
        else r=mid-1;
    }
}
void pushdown(int k)
{
    if(t[k].l==t[k].r)return;
    int tag=t[k].tag;t[k].tag=0;
    if(tag)
    {
        t[k<<1].tag=max(t[k<<1].tag,tag);
        t[k<<1|1].tag=max(t[k<<1|1].tag,tag);
        t[k<<1].mx=max(t[k<<1].mx,tag);
        t[k<<1|1].mx=max(t[k<<1|1].mx,tag);
    }
}
void build(int k,int l,int r)
{
    t[k].l=l;t[k].r=r;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void update(int k,int x,int y,int val)
{
    pushdown(k);
    int l=t[k].l,r=t[k].r;
    if(l==x&&y==r)
    {
        t[k].tag=val;t[k].mx=max(t[k].mx,val);
        return;
    }
    int mid=(l+r)>>1;
    if(y<=mid)update(k<<1,x,y,val);
    else if(x>mid)update(k<<1|1,x,y,val);
    else
    {
        update(k<<1,x,mid,val);update(k<<1|1,mid+1,y,val);
    }
}
int query(int k,int x)
{
    pushdown(k);
    int l=t[k].l,r=t[k].r;
    if(l==r)return t[k].mx;
    int mid=(l+r)>>1;
    if(x<=mid)return query(k<<1,x);
    else return query(k<<1|1,x);
}
int main()
{
    n=read();build(1,1,n<<1);
    for(int i=1;i<=n;i++)
    {
        x[i]=read(),y[i]=read(),val[i]=read();
        disc[(i<<1)-1]=x[i];disc[i<<1]=y[i];
    }
    sort(disc+1,disc+(n<<1)+1);
    for(int i=1;i<=n;i++)
        x[i]=find(x[i]),y[i]=find(y[i]);
    for(int i=1;i<=n;i++)
    {
        update(1,x[i],y[i]-1,val[i]);
    }
    ll ans=0;
    for(int i=1;i<2*n;i++)
    {
        ans+=(ll)query(1,i)*(disc[i+1]-disc[i]);
    }
    printf("%lld",ans);
    return 0;
}