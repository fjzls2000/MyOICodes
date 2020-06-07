/**************************************************************
    Problem: 2763
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:6168 ms
    Memory:3800 kb
****************************************************************/
 
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int d[10001][11],head[10001],q[100001][2];
int n,m,k,cnt,st,ed;
bool inq[10001][11];
struct data{int to,next,v;}e[100001];
void ins(int u,int v,int w)
{e[++cnt].to=v;e[cnt].v=w;e[cnt].next=head[u];head[u]=cnt;}
void spfa()
{
    int t=0,w=1;
    memset(d,127/3,sizeof(d));
    q[0][0]=st;q[0][1]=0;
    inq[st][0]=1;d[st][0]=0;
    while(t!=w)
    {
        int now=q[t][0],tmp=q[t++][1];
        if(t==100001)t=0;
        for(int i=head[now];i;i=e[i].next)
        {
            int to=e[i].to;
            if(d[now][tmp]+e[i].v<d[to][tmp])
            {
                d[to][tmp]=d[now][tmp]+e[i].v;
                if(!inq[to][tmp])
                {
                    inq[to][tmp]=1;
                    q[w][0]=to;q[w++][1]=tmp;
                    if(w==100001)w=0;
                }
            }
            if(d[now][tmp]<d[to][tmp+1]&&tmp<k)
            {
                d[to][tmp+1]=d[now][tmp];
                if(!inq[to][tmp+1])
                {
                    inq[to][tmp+1]=1;
                    q[w][0]=to;q[w++][1]=tmp+1;
                    if(w==100001)w=0;
                }
            }
        }
        inq[now][tmp]=0;
    }
    int ans=0x7fffffff;
    for(int i=0;i<=k;i++)
       ans=min(ans,d[ed][i]);
    printf("%d",ans);
}
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&k,&st,&ed);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        ins(u,v,w);ins(v,u,w);
    }
    spfa();
    return 0;
}