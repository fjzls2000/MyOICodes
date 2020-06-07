/**************************************************************
    Problem: 1677
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:40 ms
    Memory:5196 kb
****************************************************************/
 
#include <iostream>
using namespace std;
const int Maxn = 1000010;
int f[Maxn];
int main() {
    int n;
    cin>>n;
    f[1] = 1;
    for(int i=2; i<=n; ++i) {
        if(i&1) {
            f[i] = f[i-1];
        }
        else {
            f[i] = f[i-1] + f[i>>1];
            f[i] %= 1000000000;
        }
    }
    cout<<f[n];
}