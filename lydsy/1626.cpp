/**************************************************************
    Problem: 1626
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:828 ms
    Memory:16928 kb
****************************************************************/
 
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int Maxn = 1001;
const int Maxm = 1000002;
int x[Maxn] , y[Maxn] , fa[Maxn];
struct Edge {
    int a , b;
    double w;
} e[Maxm];
bool cmp(Edge a , Edge b) { return a.w < b.w; }
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }
 
int main() {
    int n , m , ta , tb;
    cin>>n>>m;
    for(int i=1; i<=n; ++i)
        cin>>x[i]>>y[i] , fa[i] = i;
    while(m--) {
        cin>>ta>>tb;
        fa[find(ta)] = find(tb);
    }
    m = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=i+1; j<=n; ++j) {
            if(find(i) != find(j)) {
                e[++m].a = i;
                e[m].b = j;
                e[m].w = sqrt(((double)(x[i]-x[j])) * (x[i]-x[j]) + ((double)(y[i]-y[j])) * (y[i]-y[j]));
            }
        }
    }
    double ans = 0;
    std::sort(e+1,e+m+1,cmp);
    for(int i=1; i<=m; ++i) {
        if(find(e[i].a) != find(e[i].b)) {
            fa[fa[e[i].a]] = fa[e[i].b];
            ans += e[i].w;
        }
    }
    printf("%.2lf\n", ans);
}