/**************************************************************
    Problem: 1599
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:16 ms
    Memory:1288 kb
****************************************************************/
 
#include <iostream>
using namespace std;
int n , m , p , ans = 0;
const int Maxn = 101;
int cnt[Maxn];
int main() {
    cin>>n>>m>>p;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            for(int k=1; k<=p; ++k) {
                ++cnt[i+j+k];
            }
    for(int i=3; i<Maxn; ++i)
        if(cnt[i] > cnt[ans])
            ans = i;
    cout<<ans;
}