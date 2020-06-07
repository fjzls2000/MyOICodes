/**************************************************************
    Problem: 1597
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:356 ms
    Memory:6760 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 200010;
int n;
struct node
{
    long long x , y;
} a[Maxn];
void unique() {
    int m = 1;
    for(int i=2; i<=n; ++i) {
        while(m && a[i].y >= a[m].y) {
            --m;
        }
        a[++m] = a[i];
    }n = m;
}
long long f[Maxn];
int q[Maxn];
bool cmp(node a , node b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
double slop(int x , int y) {
    return (double)(f[y] - f[x]) / (a[x+1].y - a[y+1].y);
}
int main() {
    cin>>n;
    for(int i=1; i<=n; ++i)
        cin>>a[i].x>>a[i].y;
    std::sort(a+1,a+n+1,cmp);
    unique();
//  for(int i=1; i<=n; ++i) { cout<<a[i].x<<"  "<<a[i].y<<endl; }// f[i] = min{ f[j] + a[j+1].y*a[i].x}
    int h = 1 , t = 1 ;
    for(int i=1; i<=n; ++i) {
        while(h < t && slop(q[h],q[h+1]) < a[i].x) ++h;
        f[i] = f[q[h]] + a[q[h]+1].y*a[i].x;
        while(h < t && slop(q[t],i) < slop(q[t-1],q[t])) --t;
        q[++t] = i;
    }
    cout<<f[n];
    return 0;
}