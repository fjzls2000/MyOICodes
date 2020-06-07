/**************************************************************
    Problem: 1233
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:276 ms
    Memory:2852 kb
****************************************************************/
 
#include <iostream>
using namespace std;
const int Maxn = 100010;
int n , sum[Maxn] , h , t , q[Maxn] , f[Maxn] , g[Maxn];
int main() {
    cin>>n;
    sum[0] = 0;
    for(int i=1; i<=n; ++i) {
        int j;
        cin>>j;
        sum[i] = sum[i-1] + j;
    }
    h = t = 1;
    q[1] = n + 1;
    for(int i=n; i; --i) {
        //sum[q[h+1] - 1] - sum[i-1] >= f[q[h+1]] £º Èç¹ûÎÒÄÜÐÂ½¨Ò»²ã 
        while(h < t && sum[q[h+1] - 1] - sum[i-1] >= f[q[h+1]]) ++h;
        f[i] = sum[q[h] - 1] - sum[i-1];
        g[i] = g[q[h]] + 1;
        while(h < t && f[i] - sum[i-1] < f[q[t]] - sum[q[t] - 1]) --t;
        // J < K Ê± gj ¿Ï¶¨»á²»±È gkÁÓ
        //Èô s[j-1] - f[j] >= s[k-1] - f[k]Ê±£¬j¿Ï¶¨±ÈkÓÅ£¬ËùÒÔÌÞ³ýk  
        q[++t] = i;
    }
    cout<<g[1];
}