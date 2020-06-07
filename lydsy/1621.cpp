/**************************************************************
    Problem: 1621
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1288 kb
****************************************************************/
 
#include <iostream>
using namespace std;
int n , k;
int Solve(int x) {
    if(x < k+1 || ((x-k)&1)) return 1;
    return Solve((x-k)/2) + Solve((x-k)/2+k);
}
int main() {
    cin>>n>>k;
    cout<<Solve(n);
} 