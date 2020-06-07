/**************************************************************
    Problem: 1612
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:40 ms
    Memory:1300 kb
****************************************************************/
 
#include <iostream>
using namespace std;
const int Maxn = 101;
const int Maxm = 10001;
bool mp[Maxn][Maxn];
int n , m , a , b , ans = 0;
int main() {
    cin>>n>>m;
    while(m--) {
        cin>>a>>b;
        mp[a][b] = 1;
    }
    for(int k=1; k<=n; ++k)
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                if(mp[i][k] && mp[k][j])
                    mp[i][j] = 1;
    for(int i=1; i<=n; ++i) {
        int cnt = 1;
        for(int j=1; j<=n; ++j)
            if(i == j)
                continue;
            else
                cnt += mp[i][j]|mp[j][i];
        if(cnt == n)
            ++ans;
    }
    cout<<ans;
}