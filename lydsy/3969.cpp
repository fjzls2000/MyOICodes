/**************************************************************
    Problem: 3969
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:4364 ms
    Memory:8616 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
const int Maxnk2 = 1000010;
int a[Maxnk2] , n , k , nk2;
int choose[Maxnk2];
  
bool check(int x) {
    int cnt = 0 , tot = 0;
    int kk = k<<1;
    for(int i=1; i<=nk2 && cnt<n ; ++i)
        if(a[i+1]-a[i] <= x)
            choose[++cnt] = i++;
      
    if(cnt < n) return false;
      
    int last = nk2+1;
    for(int i=cnt; i; i--) {
        tot+=last-choose[i];
        if(tot < kk) return false;
        else tot-=kk;
        last = choose[i];
    }
    return true;
}
  
int main() {
    scanf("%d%d",&n,&k);
    nk2 = (n*k)<<1;
    for(int i=1; i<=nk2; ++i)
        scanf("%d",&a[i]);
      
    std::sort(a+1,a+nk2+1);
      
    int l = 0 , r = 1000000000 , mid;
      
    while(l<r) {
        mid = (l+r) >> 1;
        if(check(mid)) r = mid;
        else l = mid+1;
    }printf("%d",l);
}