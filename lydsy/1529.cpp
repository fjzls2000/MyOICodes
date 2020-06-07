/**************************************************************
    Problem: 1529
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1592 ms
    Memory:9596 kb
****************************************************************/
 
#include <stdio.h>
const int Maxn = 1000010;
int to[Maxn] , ru[Maxn] , n;
bool vis[Maxn];
 
void Del(int x) {
    ru[x] = 0;
    while(ru[x] <= 0 && !vis[x]) {
        vis[x] = 1;
        ru[to[x]]--;
        x = to[x];
    }
}
 
void Init() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&to[i]) , ru[to[i]]++;
}
 
void Solve() {
    for(int i=1; i<=n; i++)
        if(ru[i] <= 0 && !vis[i]) Del(i);
}
 
void End() {
    int ans = 0;
    for(int i=1; i<=n; i++)
        if(!vis[i]) Del(i) , ans++;
    printf("%d",ans);
}
 
int main() {
    Init();
    Solve();
    End();
}