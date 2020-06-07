/**************************************************************
    Problem: 1229
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:264 ms
    Memory:2040 kb
****************************************************************/
 
#include <iostream>
#include <deque>
#define inf 233333333
using namespace std;
const int Maxn = 100010;
int n , t1 , t2 , c1 , c2 , tc , d[Maxn] , sum;
deque<pair<int,int> >sl,qk,tmp;
int f(int x) {
    sl.clear();
    qk.clear();
    tmp.clear();
    int ans = (tc - c2)*x;
    sl.push_back(make_pair(0,x));
    for(int i=1; i<=n; ++i) {
        while(!tmp.empty() && i-tmp.front().first >= t1)
            qk.push_back(tmp.front()) , tmp.pop_front();
        while(!qk.empty() && i-qk.front().first >= t2)
            sl.push_back(qk.front()) , qk.pop_front();
        int T = d[i];
        while(T > 0) {
            if(!sl.empty()) {
                if(sl.back().second > T) {
                    sl.back().second-=T;
                    ans += T*c2;
                    T=0;
                }
                else {
                    T -= sl.back().second;
                    ans += sl.back().second*c2;
                    sl.pop_back();
                }
            }
            else {
                if(!qk.empty()) {
                    if(qk.back().second>T) {
                        qk.back().second -= T;
                        ans += T*c1;
                        T = 0;
                    }
                    else {
                        T -= qk.back().second;
                        ans += qk.back().second*c1;
                        qk.pop_back();
                    }
                }
                else return inf;
            }
        }
        tmp.push_back(make_pair(i,d[i]));
    }
    return ans;
}
int main() {
    cin>>n>>t1>>t2>>c1>>c2>>tc;
    for(int i=1; i<=n; ++i) {
        cin>>d[i];
        sum += d[i];
    } 
    if(t1 > t2) swap(t1,t2) , swap(c1,c2);
    if(c1 < c2) c2 = c1;
    int l = 0 , r = sum;
    while(1) {
        if(r - l <= 5) {
            int t = f(l);
            for(int i=l+1; i<r; ++i) t = min(t , f(i));
            cout<<t;
            return 0;
        }
        int x = l + (r-l)/2 , y = l+2*(r-l)/3;
        int fx = f(x) , fy = f(y);
        if(fx != inf && fx <= fy) r = y;
        else l = x;
    }
}