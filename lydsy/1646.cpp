/**************************************************************
    Problem: 1646
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:16 ms
    Memory:10076 kb
****************************************************************/
 
#include <iostream>
using namespace std;
const int Maxn = 1000001;
int n , x , h , t , q[Maxn] , qt[Maxn];
bool vis[Maxn];
int main() {
    cin>>q[1]>>x;
    int mx = max(q[1] , x) + 2;
    h = t = 1;
    while(h <= t) {
        int nt = qt[h] , now = q[h];
        h++;
        if(vis[now]) continue;
        vis[now] = 1;
        if(now == x) {
            cout<<nt;
            break;
        }
        if(now+1 < mx && !vis[now+1]) {
            q[++t] = now+1;
            qt[t] = nt + 1;
        }
        if(now > 0 && !vis[now-1]) {
            q[++t] = now-1;
            qt[t] = nt + 1;
        }
        if(now + now < mx && !vis[now+now]) {
            q[++t] = now+now;
            qt[t] = nt + 1;
        }
    }
}