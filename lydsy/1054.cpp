/**************************************************************
    Problem: 1054
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:36 ms
    Memory:11512 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
using namespace std;
struct node { int a[5][5] , step; } q[100010];
const int ss[2][4] = {1,0,-1,0 , 0,1,0,-1};
int h , t , ch;
bool vis[65536];
int hash(node now) {
    int k=1,s=0;
    for(int i=1;i<=4;i++)
       for(int j=1;j<=4;j++)
          {s+=k*now.a[i][j];k<<=1;}
    return s;
}
int main() {
    for(int i=1; i<=4; ++i)
        for(int j=1; j<=4; ++j) {
            while(ch = getchar() , ch!='0'&&ch!='1');
            q[1].a[i][j] = ch-'0';
        }
    node aaa;
    for(int i=1; i<=4; ++i)
        for(int j=1; j<=4; ++j) {
            while(ch = getchar() , ch!='0'&&ch!='1');
            aaa.a[i][j] = ch-'0';
        }
    int ed = hash(aaa);
    if(hash(q[1]) == ed) {puts("0");return 0;}
    else vis[hash(q[1])] = 1;
    h = t = 1;
    while(h <= t) {
        node now = q[h++]; ++now.step;
        for(int i=1; i<=4; ++i)
        for(int j=1; j<=4; ++j)
            if(now.a[i][j])
            for(int k=0; k<4; ++k) {
                int x = i+ss[0][k] , y = j+ss[1][k];
                if(now.a[x][y] || x>4 || x<1 || y>4 || y<1) continue;
                swap(now.a[x][y] , now.a[i][j]);
                int tmp = hash(now);
                if(!vis[tmp]) {
                    vis[tmp] = 1;
                    if(tmp == ed) {
                        printf("%d\n", now.step); return 0;
                    }
                    q[++t] = now;
                }
                swap(now.a[x][y] , now.a[i][j]);
            }
    }
}