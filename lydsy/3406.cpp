/**************************************************************
    Problem: 3406
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:36 ms
    Memory:2520 kb
****************************************************************/
 
#include <iostream>
#include <stdio.h>
#define inf 233333333
using namespace std;
const int Maxn = 110;
const int Maxq = 100010;
int n , m , x , y , ch;
int mp[Maxn][Maxn];//存一个点最快被草占领的时间，-1表示是石头 
int qx[Maxq] , qy[Maxq] , qt[Maxq];//存队列
int h , t;//队列的开始/结尾 
bool vis[Maxn][Maxn];//由于是bfs所以到一个点肯定是最短路 
const int ss[2][8] = { {1 , 0 , -1 , 0 , 1 , 1 , -1 , -1 } , {0 , 1 , 0 , -1 , 1 , -1 , 1 , -1 } };//八联通 
int main() {
    cin>>m>>n>>y>>x;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j) {
        while(ch = getchar() , ch != '.' && ch !='*');
        if(ch == '.')
            mp[i][j] = inf;
        else
            mp[i][j] = -1;
    }
    /*以上为初始化*/
    h = 1 ; t = 1;
    x = n - x + 1; 
    qx[1] = x;
    qy[1] = y;
    qt[1] = 0;
    while(h <= t) { 
        int nx = qx[h] , ny = qy[h] , nt = qt[h];
        h++;
        if(vis[nx][ny]) continue;//如果访问过就continue 
        if(mp[nx][ny] == -1) continue;//如果是石头就continue 
        vis[nx][ny] = 1;//标记为走过 
        mp[nx][ny] = nt;//记录走到这个点的时间 
        for(int i=0; i<8; ++i) {
            int x = nx+ss[0][i] , y = ny+ss[1][i];
            if(x <= 0 || x > n || y <= 0 || y > m) continue;//如果八联通合法就丢进队 
            qx[++t] = x;
            qy[t] = y;
            qt[t] = nt + 1;
        }
    }
    /*以上为bfs*/
    int ans = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            //cout<<mp[i][j]<<"\t";
            ans = max(ans , mp[i][j]);
        }//puts("") 
    }
    /*以上为统计答案*/
    cout<<ans;
}