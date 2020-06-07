/**************************************************************
    Problem: 1634
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:316 ms
    Memory:2856 kb
****************************************************************/
 
#include <iostream>
#include <algorithm>
using namespace std;
 
const int Maxn = 100010;
 
struct cow {
    double d , t;
} a[Maxn];
 
bool cmp(cow a , cow b) {
    return b.d*a.t < b.t*a.d;
}
 
long long ans , tot = 0;
 
int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>a[i].t>>a[i].d;
        tot += a[i].d;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1; i<=n; ++i) {
        tot -= a[i].d;
        ans += tot * a[i].t * 2;
    }
    cout<<ans;
}