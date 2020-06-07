/**************************************************************
    Problem: 1067
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:260 ms
    Memory:4416 kb
****************************************************************/
 
#include <iostream>
#include <cstdio>
using namespace std;
struct data{int ly,ry,mx,know;}tr[200001];
int n,m;
void build(int k,int l,int r)
{
     if(l==r){scanf("%d%d",&tr[k].ly,&tr[k].mx);tr[k].ry=tr[k].ly;tr[k].know=1;return;}
     int mid=(l+r)>>1;
     build(k<<1,l,mid);build(k<<1|1,mid+1,r);
     tr[k].know=(tr[k<<1].know&&tr[k<<1|1].know);
     if(tr[k<<1].ry+1!=tr[k<<1|1].ly)tr[k].know=0;
     tr[k].ly=tr[k<<1].ly;tr[k].ry=tr[k<<1|1].ry;
     tr[k].mx=max(tr[k<<1].mx,tr[k<<1|1].mx);
 }
int get(int k,int x)
{    
    if(tr[k].ly==tr[k].ry)
    {
        if(tr[k].ly!=x)return 0;                
        else return tr[k].mx;
                        }
    if(x<=tr[k<<1].ry)return get(k<<1,x);
    else if(x>=tr[k<<1|1].ly)return get(k<<1|1,x);
    return 0;
}
int ask(int k,int x,int y,int num)
{
    bool f=0;
    if(x<tr[k].ly){f=1;x=tr[k].ly;}
    if(tr[k].ly==x&&tr[k].ry==y)
    {
                  if(tr[k].mx>=num)return 0;
                  else if(tr[k].know&&!f)return 1;
                  else return 2;
                  }
    if(y<=tr[k<<1].ry)
    {         
         return ask(k<<1,x,y,num);
     }
    else if(x>=tr[k<<1|1].ly)
    {
         return ask(k<<1|1,x,y,num);
     }
    else
    {
         int t1=ask(k<<1,x,tr[k<<1].ry,num);
         int t2=ask(k<<1|1,tr[k<<1|1].ly,y,num);
         if(!t1||!t2)return 0;
         else if(tr[k<<1].ry+1!=tr[k<<1|1].ly)return 2;
         else return 1;
     } 
}
int getnext(int k,int x)
{
    int l=tr[k].ly,r=tr[k].ry;
    if(l==r)return tr[k].ly;
    if(x<tr[k<<1].ry)return getnext(k<<1,x);
    else return getnext(k<<1|1,x);
}
int getlast(int k,int x)
{
    int l=tr[k].ly,r=tr[k].ry;
    if(l==r)return tr[k].ly;
    if(x>tr[k<<1|1].ly)return getlast(k<<1|1,x);
    else return getlast(k<<1,x);
} 
int main()
{
    scanf("%d",&n);
    build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
            int l,r;
            scanf("%d%d",&l,&r);
            if(r<l){printf("false\n");continue;}
            int lnum=get(1,l),rnum=get(1,r);
            if(!lnum&&!rnum)printf("maybe\n");
            else
            {
            int s=getnext(1,l),t=getlast(1,r);
            if(!lnum)
            {
                if(s>t||r==t){printf("maybe\n");continue;}
                int f=ask(1,s,t,rnum);
                if(f==0)printf("false\n");
                else printf("maybe\n");
            }
            else if(!rnum)
            {
                if(s>t||l==s){printf("maybe\n");continue;}
                int f=ask(1,s,t,lnum);
                if(f==0)printf("false\n");
                else printf("maybe\n");
            }
            else
            {
                if(rnum>lnum){printf("false\n");continue;}
                if(s>t){
                     if(l+1==r) printf("true\n");
                     else printf("maybe\n");
                     continue;
                     }
                int f=ask(1,s,t,rnum);
                if(f==0)printf("false\n");
                else if(f==1)
                {
                    if(l+1==s&&r-1==t)printf("true\n");
                    else printf("maybe\n");
                }
                else if(ask(1,s,t,rnum)==2)printf("maybe\n");
                else printf("false\n");
            }
        }
    }
    return 0;
}