/**************************************************************
    Problem: 3388
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:292 ms
    Memory:20824 kb
****************************************************************/
 
#include <iostream>
const int Maxn = 510;
const int Maxn2 = 250010;
using namespace std;
 
int n , m , ncnt , mp[Maxn][Maxn] , scc[Maxn][Maxn] , in[Maxn2] , out[Maxn2];
 
void dfs(int x , int y) {
    if(scc[x][y]) return;
    scc[x][y] = ncnt;
    if(x<n && mp[x+1][y] == mp[x][y]) dfs(x+1,y);
    if(x>0 && mp[x-1][y] == mp[x][y]) dfs(x-1,y);
    if(y<m && mp[x][y+1] == mp[x][y]) dfs(x,y+1);
    if(y>0 && mp[x][y-1] == mp[x][y]) dfs(x,y-1);
}
 
int main() {
    ncnt = 0;
    cin>>m>>n;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            cin>>mp[i][j];
        }
    }
/*  for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            cout<<mp[i][j];
        }cout<<endl;
    }*/
 
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(!scc[i][j]) {
                ++ncnt;
                dfs(i,j);
            }
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) {
            if(i < n && scc[i][j] != scc[i+1][j]) {
                if(mp[i][j] > mp[i+1][j]) {
                    in[scc[i+1][j]] = out[scc[i][j]] = 1;
                }
                else {
                    in[scc[i][j]] = out[scc[i+1][j]] = 1;
                }
            }
            if(j < m && scc[i][j] != scc[i][j+1]) {
                if(mp[i][j] > mp[i][j+1]) {
                    in[scc[i][j+1]] = out[scc[i][j]] = 1;
                }
                else {
                    in[scc[i][j]] = out[scc[i][j+1]] = 1;
                }
            }
        }
    int ans1 = 0 , ans2 = 0;
    if(ncnt != 1) {
        for(int i=1; i<=ncnt; ++i) {
            if(!in[i]) ++ans1;
            if(!out[i]) ++ans2;
        }
    }
//  cout<<ncnt<<endl;
    if(ans1 < ans2) ans1 = ans2;
    cout<<ans1;
}