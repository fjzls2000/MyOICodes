/**************************************************************
    Problem: 1624
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:48 ms
    Memory:5240 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
using namespace std;
const int Maxn = 1001;
const int Maxm = 10001;
int a[Maxm] , mp[Maxn][Maxn];
int main() {
    int n , m;
    cin>>n>>m;
    for(int i=1; i<=m; ++i) {
        cin>>a[i];
    }
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            cin>>mp[i][j];
 
    for(int k=1; k<=n; ++k)
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j) {
                if(mp[i][j] > mp[i][k] + mp[k][j])
                    mp[i][j] = mp[i][k] + mp[k][j];
            }
 
    int ans = 0;
    for(int i=2; i<=m; ++i)
        ans += mp[a[i-1]][a[i]];
    cout<<ans;
}