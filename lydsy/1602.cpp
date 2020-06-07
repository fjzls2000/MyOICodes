/**************************************************************
    Problem: 1602
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:52 ms
    Memory:5196 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
using namespace std;
 
const int Maxn = 100010;
const int Maxm = 200010;
int to[Maxm] , next[Maxm] , w[Maxm] , g[Maxn] , dep[Maxn] , ed[Maxn] , ecnt = 0 , ans , fa[Maxn];
 
void ins(int a , int b , int wi) {
    to[++ecnt] = b;
    next[ecnt] = g[a];
    g[a] = ecnt;
    w[ecnt] = wi;
}
 
void dfs(int x) {
    dep[x] = dep[fa[x]] + 1;
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa[x]) continue;
        fa[to[i]] = x;
        dfs(to[i]);
        ed[to[i]] = w[i];
    }
}
 
int main() {
    int n , q , tmpa,tmpb,wi;
    cin>>n>>q;
    for(int i=1; i<n; ++i) {
        cin>>tmpa>>tmpb>>wi;
        ins(tmpa,tmpb,wi);
        ins(tmpb,tmpa,wi);
    }
    dfs(1);
 
/*  for(int i=1; i<=n; ++i) {
        cout<<i<<" : fa:"<<fa[i]<<" , ed:"<<ed[i]<<endl;
    }*/
 
     
    while(q--) {
        cin>>tmpa>>tmpb;
        ans = 0;
        if(dep[tmpa] < dep[tmpb]) {
            swap(tmpa,tmpb);
        }
        while(dep[tmpa] > dep[tmpb]) {
            ans += ed[tmpa];
            tmpa = fa[tmpa];
        }
        while(tmpa != tmpb) {
            ans += ed[tmpa];
            ans += ed[tmpb];
            tmpa = fa[tmpa];
            tmpb = fa[tmpb];
        }cout<<ans<<endl;
    }
}