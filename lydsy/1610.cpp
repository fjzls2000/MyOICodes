/**************************************************************
    Problem: 1610
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:20 ms
    Memory:9116 kb
****************************************************************/
 
#include <iostream>
#include <algorithm>
#include <math.h>
#define eps 1e-8
using namespace std;
const int Maxn = 1001;
const int Maxm = 1000001;
double x[Maxn] , y[Maxn] , slop[Maxm];
int main() {
    int n , cnt = 0 , flag = 0;
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>x[i]>>y[i];
    }
    for(int i=1; i<=n; ++i)
        for(int j=i+1; j<=n; ++j) {
            if(fabs(x[i] - x[j]) < eps) {
                flag = 1;
                continue;
            }
            slop[++cnt] = (y[i]-y[j])/(x[i]-x[j]);
        }
    sort(slop+1,slop+cnt+1);
    int m = 1;
    for(int i=2; i<=cnt; ++i)
        if(fabs(slop[i] - slop[m]) > eps)
            slop[++m] = slop[i];
    cout<<m+flag;
}