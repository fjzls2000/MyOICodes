/**************************************************************
    Problem: 1231
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:148 ms
    Memory:11528 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
using namespace std;
inline int abs(int a) { return a < 0 ? -a : a ; }
const int Maxn = 20;
int n , a[Maxn] , limk;
long long f[1<<16][20];
int main() {
    cin>>n>>limk;
    for(int i=0; i<n; ++i)
        cin>>a[i];
    int lim = 1<<n;
    for(int i=1; i<lim; ++i) {
        for(int j=0; j<n; ++j) {
            if(i & (1<<j)) {
                if(i - (1<<j)) {
                    int p = i - (1<<j);
                    for(int k=0; k<n; ++k) {
                        if(p & (1<<k) && abs(a[k] - a[j]) > limk) {
                            f[i][j] += f[p][k];
                        }
                    }
                }
                else {
                    f[i][j] = 1;
                }
            }
        }
    }
    long long ans = 0;
    for(int i=0; i<n; ++i) {
        ans += f[lim-1][i];
    }
    cout<<ans;
}