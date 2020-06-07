/**************************************************************
    Problem: 4027
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:3724 ms
    Memory:52800 kb
****************************************************************/
 
#include <stdio.h>
#include <vector>
#include <algorithm>
inline int F() {
    register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 2000010;
std::vector<int> v[Maxn];
int n , m , c[Maxn] , ans = 0;
bool cmp(int x , int y) { return c[x]<c[y]; }
int dfs(int x) {
    for(int i=0; i<v[x].size(); ++i)
        dfs(v[x][i]);
    std::sort(v[x].begin() , v[x].end() , cmp);
    c[x] += v[x].size();
    for(int i=0; i<v[x].size(); ++i) {
        int t = c[v[x][i]];
        if(c[x] + t - 1 <= m) {
            c[x] += t-1;
            ++ans;
        }
        else break;
    }
}
int main() {
    n = F() , m = F();
    for(int i=0; i<n; ++i)
        c[i] = F();
    for(int i=0; i<n; ++i) {
        int tmp = F();
        for(int j=1; j<=tmp; ++j)
            v[i].push_back(F());
    }
    dfs(0);
    printf("%d\n", ans);
}