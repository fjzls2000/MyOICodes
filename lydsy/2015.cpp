/**************************************************************
    Problem: 2015
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:188 ms
    Memory:3636 kb
****************************************************************/
 
#include <stdio.h>
#include <queue>
#include <memory.h>
#define Maxm 200010
#define Maxn 50010
int to[Maxm] , next[Maxm] , g[Maxn] , W[Maxm] , ecnt = 0;
int dis[Maxn] ;
bool vis[Maxn];
std::queue<int> q;
 
void Ins(int a,int b,int wi) {
    to[++ecnt] = b;
    next[ecnt] = g[a];
    g[a] = ecnt;
    W[ecnt] = wi;
    /*===============*/
    to[++ecnt] = a;
    next[ecnt] = g[b];
    g[b] = ecnt;
    W[ecnt] = wi;
}
 
void SPFA() {
    /*Init*/
    memset(dis,42,sizeof(dis));
    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    dis[1] = 0;
    q.push(1);
    /*Solve*/
    int dist , head;
    while(!q.empty()) {
        head = q.front();
        dist = dis[head];
        q.pop();
        for(int i=g[head] ; i; i=next[i])
            if(dis[to[i]] > dist + W[i]) {
                dis[to[i]] = dist + W[i];
                if(!vis[to[i]]) {q.push(to[i]);vis[to[i]] = 1;}
            }
        vis[head] = 0;
    }
}
 
int main() {
    int n,m,t,wi,tmp1,tmp2;
    scanf("%d%d%d",&n,&m,&t);
    n++;
    for(int i=1; i<=m; i++) {
        scanf("%d%d%d",&tmp1,&tmp2,&wi);
        Ins(tmp1,tmp2,wi);
    }
    SPFA();
    while(t--) {
        scanf("%d%d",&tmp1,&tmp2);
        printf("%d\n",dis[tmp1] + dis[tmp2]);
    }
    return 0;
}