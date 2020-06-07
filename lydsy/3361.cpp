/**************************************************************
    Problem: 3361
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:4 ms
    Memory:2480 kb
****************************************************************/
 
#include <stdio.h>
#include <queue>
 
#define getch() getchar()
inline int F() {register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
 
const int Maxn = 100010;
int to[Maxn] , next[Maxn] , g[Maxn] , ecnt = 0 , dist[Maxn];
bool vis[Maxn];
 
struct node {
    int dist , now;
};
 
bool operator < (node a , node b) {
    return a.dist > b.dist;
}
 
bool operator > (node a , node b) {
    return a.dist < b.dist;
}
 
void ins(int a , int b) {
    to[++ecnt] = b;
    next[ecnt] = g[a];
    g[a] = ecnt;
}
 
std::priority_queue<node> q;
 
int main() {
    int n = F() , m = F() , ans = 0;;
    for(int i=1; i<=m; ++i) {
        int a = F() , b = F();
        ins(a , b);
        ins(b , a);
    }
 
    node a;
    a.now = 1;
    a.dist = 0;
    q.push(a);
    while(!q.empty()) {
        a = q.top();
        q.pop();
        int now = a.now , dis = a.dist;
        if(vis[now]) continue;
        dist[now] = dis;
        vis[now] = 1;
        if(dis > ans) ans = dis;
        for(int i=g[now]; i; i=next[i]) {
            if(!vis[to[i]]) {
                a.now = to[i];
                a.dist = dis + 1;
                q.push(a);
            }
        }
    }printf("%d\n", ans);
}