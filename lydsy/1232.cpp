/**************************************************************
    Problem: 1232
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:764 ms
    Memory:2544 kb
****************************************************************/
 
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 10010;
const int Maxm = 100010;
struct Edge {
    int a , b , w;
} e[Maxm] ;
bool cmp(Edge a , Edge b) {
    return a.w < b.w;
}
int a[Maxn] , fa[Maxn] , n , m;
int find (int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
} 
int main() {
    int ans = 2147483647;
    cin>>n>>m;
    for(int i=1; i<=n; ++i) {
        cin>>a[i];
        fa[i] = i;
        if(ans > a[i]) ans = a[i];
    }
    for(int i=1; i<=m; ++i) {
        cin>>e[i].a>>e[i].b>>e[i].w;
        e[i].w += e[i].w+a[e[i].a]+a[e[i].b];
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1; i<=m; ++i) {
        if(find(e[i].a) != find(e[i].b)) {
            fa[fa[e[i].a]] = fa[e[i].b];
            ans += e[i].w;
        }
    }
    cout<<ans;
}