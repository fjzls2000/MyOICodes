#include <stdio.h>
#include <iostream>
using std::max;
int n , m , k;
bool check(int mid) {
    long long l = k-mid+1 , r = k+mid-1;
    long long sum = 1+mid; sum *= mid; sum -= mid;
    if(l < 1) {
        l = -l + 1;
        l = (1+l) * l / 2;
        sum -= l;
    }
    if(r > n) {
        r -= n;
        r = (1+r) * r / 2;
        sum -= r;
    }
    return sum <= m-n;
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    int l = 0 , r = m-n , ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) ans = mid , l = mid + 1;
        else r = mid - 1;
    }printf("%d\n",ans+1);
}