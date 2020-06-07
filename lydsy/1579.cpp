/**************************************************************
    Problem: 1579
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:2068 ms
    Memory:5904 kb
****************************************************************/
 
#include <iostream>
#include <queue>
#define inf 2147483647
using namespace std;
struct node {
    int x , dist , k;
};
bool operator < (node a , node b) {
    return a.dist > b.dist;
}
const int Maxm = 200010;
const int Maxn = 10001;
priority_queue<node> q;
int n , m , k , a , b , c , to[Maxm] , next[Maxm] , g[Maxn] , w[Maxm] , ecnt = 0 , dis[Maxn][22];
bool vis[Maxn][22];
void ins(int a , int b , int c) {
    to[++ecnt] = b;
    next[ecnt] = g[a];
    g[a] = ecnt;
    w[ecnt] = c;
}
int main() {
    cin>>n>>m>>k;
    for(int i=1; i<=m; ++i) {
        cin>>a>>b>>c;
        ins(a , b , c);
        ins(b , a , c);
    }
    node tmp;
    tmp.x = 1;
    tmp.dist = 0;
    tmp.k = 0;
    q.push(tmp);
    while(!q.empty()) {
        tmp = q.top();
        q.pop();
        int now = tmp.x , dist = tmp.dist , kk = tmp.k;
        if(vis[now][kk]) continue;
        vis[now][kk] = 1;
        dis[now][kk] = dist;
        for(int i=g[now]; i; i=next[i]) {
            if(!vis[to[i]][kk]) {
                tmp.x = to[i];
                tmp.dist = dist + w[i];
                tmp.k = kk;
                q.push(tmp);
            }
            if(kk<k && !vis[to[i]][kk+1]) {
                tmp.x = to[i];
                tmp.dist = dist;
                tmp.k = kk+1;
                q.push(tmp);
            }
        }
    }
    int ans = inf;
    for(int i=0; i<=k; ++i) {
        ans = min(ans , dis[n][i]);
    }
    cout<<ans;
}