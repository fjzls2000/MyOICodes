/**************************************************************
    Problem: 1650
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:76 ms
    Memory:1212 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
int L , n , m , ans , a[100010];
 
bool check(int x) {
    int lst = 1 , ret = 0;
    for(int i=2; i<=n; ++i) {
        if(a[i] - a[lst] >= x)
            lst = i;
        else
            ++ret;
    }
    return ret <= m;
}
 
int main() {
    scanf("%d%d%d",&L,&n,&m);
    for(int i=1; i<=n; ++i) {
        scanf("%d",&a[i]);
    }
    a[++n] = 0; a[++n] = L;
    std::sort(a+1,a+n+1);
    int l = 1 , r = 214748374;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) ans = mid , l = mid + 1;
        else r = mid - 1;
    }
    printf("%d",ans);
}