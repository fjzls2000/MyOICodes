/**************************************************************
    Problem: 1592
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:132 ms
    Memory:32244 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#define ll long long
#define inf 1e15
using namespace std;
const int Maxn = 2005;
ll ans , f[Maxn][Maxn];
int n , a[Maxn] , b[Maxn] , m;
 
bool cmp(int x , int y) {
    return x > y;
}
 
int abs(int x) {
    return x >= 0 ? x : -x;
}
 
void unique() {
    m = 1;
    for(int i=2; i<=n; ++i) {
        if(b[i] != b[m])
            b[++m] = b[i];
    }
}
 
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    std::sort(b+1,b+n+1);
    unique();
    for(int i=1; i<=n; ++i) f[i][0] = inf; 
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) {
            f[i][j] = min(f[i-1][j]+abs(a[i]-b[j]) , f[i][j-1]);
        }
    ans = f[n][m];
    sort(b+1,b+m+1,cmp);
    for(int i=1; i<=n; ++i) f[i][0] = inf;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) {
            f[i][j] = min(f[i-1][j]+abs(a[i]-b[j]) , f[i][j-1]);
        }
    ans = min(ans , f[n][m]);
    printf("%d",ans);
} 