/**************************************************************
    Problem: 3408
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:40 ms
    Memory:4516 kb
****************************************************************/
 
#include <iostream>
#include <queue>
using namespace std;
const int Maxn = 100010;
const int Maxm = 200010;
 
int n , m , u , v , to[Maxm] , next[Maxm] , last[Maxn] , w[Maxm] , a , b , c , ecnt = 0 , dis[Maxn];
bool vis[Maxn];
 
void ins(int a , int b , int c) {
    to[++ecnt] = b;
    next[ecnt] = last[a];
    last[a] = ecnt;
    w[ecnt] = c;
}
 
struct node {
    int x , dist;
};
bool operator < (node a , node b) {
    return a.dist > b.dist;
}
priority_queue<node> q; 
 
int main() {
    cin>>n>>m>>u>>v;
    for(int i=1; i<=m; ++i) {
        cin>>a>>b>>c;
        ins(a,b,c);
        ins(b,a,c);
    }
    node tmp;
    tmp.x = u;
    tmp.dist = 0;
    q.push(tmp);
    while(!q.empty()) {
        tmp = q.top();
        int now = tmp.x , dist = tmp.dist;
//      cout<<now<<"\t"<<dist<<endl;
        q.pop();
        if(vis[now]) continue;
        vis[now] = 1;
        dis[now] = dist;
        for(int i=last[now]; i; i=next[i]) {
            if(!vis[to[i]]) {
                tmp.x = to[i];
                tmp.dist = dis[now] + w[i];
                q.push(tmp);
            }
        }
    }
    cout<<dis[v]<<endl; 
}