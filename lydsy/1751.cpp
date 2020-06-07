/**************************************************************
    Problem: 1751
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:4 ms
    Memory:1252 kb
****************************************************************/
 
#include <stdio.h>
const int ss[2][8] = {-1,-1,-1 , 0,0 , 1,1,1  ,  -1,0,1 , -1,1 , -1,0,1};
 
int map[101][101];
 
void kill(int x,int y) {
    map[x][y] = 0;
    for(int i=0; i<8; i++)
        if(map[x+ss[0][i]][y+ss[1][i]])
            kill(x+ss[0][i],y+ss[1][i]);
}
 
int main() {
    int n , m , ans = 0 , ch;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            while(ch = getchar() , ch != '.' && ch != 'W');
            map[i][j] = ch == 'W';
        } 
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(map[i][j]) {
                kill(i,j);
                ans++;
            }
    printf("%d",ans);
}
/*
10 12
 
W........WW.
 
.WWW.....WWW
 
....WW...WW.
 
.........WW.
 
.........W..
 
..W......W..
 
.W.W.....WW.
 
W.W.W.....W.
 
.W.W......W.
 
..W.......W.
*/