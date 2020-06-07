/**************************************************************
    Problem: 1877
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:744 ms
    Memory:10188 kb
****************************************************************/
 
#include <stdio.h>
#define INF 21474836
const int Maxn = 1010;
const int Maxm = 400010;
 
int n , m , ecnt = 1 , dis[Maxn] , to[Maxm] , next[Maxm] , g[Maxm] , w[Maxm] , flow[Maxm] , fr[Maxn] , q[Maxm] , s , t , S , T , ans1 , ans2; bool inq[Maxn];
 
void ins(int a , int b , int wi , int flowi) {
    to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; w[ecnt] = wi; flow[ecnt] = flowi;
    to[++ecnt] = a; next[ecnt] = g[b]; g[b] = ecnt; w[ecnt] = -wi; flow[ecnt] = 0;
}
 
void Init() {
    int u , v , t;
    scanf("%d%d",&n,&m);
    S = 1 , T = n+n;
    while(m--) {
        scanf("%d%d%d",&u,&v,&t);
//      printf("%d %d %d\n",u,v,t);
        ins(u+n , v , t , 1);
    }
    for(int i=2; i<n; ++i) ins(i , i+n , 0 , 1);
    ins(S,S+n,0,INF);
    ins(n,T,0,INF);
}
 
bool SPFA() {
    for(register int i=1; i<=n+n; ++i) dis[i] = INF , fr[i] = inq[i] = 0;
    q[s = t = 1] = S; dis[S] = 0;
    while(s <= t) {
        int now = q[s++];
        for(int i=g[now]; i; i=next[i]) {
            if (flow[i] && dis[to[i]] > dis[now] + w[i]) {
                dis[to[i]] = dis[now] + w[i];
                fr[to[i]] = i;
                if(!inq[to[i]]) {inq[to[i]] = 1; q[++t] = to[i];} 
            }//printf("%d %d %d\n",to[i],flow[i],dis[i]);
        }
//      printf("!%d %d!\n",s,t);
        inq[now] = 0;
    }
    return fr[T];
}
 
void mcf() {
    while(SPFA()) {
        int minflow = INF;
        for(register int i=fr[T]; i; i=fr[to[i^1]])
            if(minflow > flow[i]) minflow = flow[i];
        for(register int i=fr[T]; i; i=fr[to[i^1]]) flow[i]-=minflow , flow[i^1]+=minflow;
        ans1+=minflow;
        ans2+=dis[T]*minflow;
    }
}
 
int main() {
    Init();
    mcf();
    printf("%d %d",ans1,ans2);
}