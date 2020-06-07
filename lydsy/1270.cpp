/**************************************************************
    Problem: 1270
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:10188 ms
    Memory:98540 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <memory.h>
using std::min; using std::max;
int map[5001][5001];
int f[5001] , n , HIGH , k , tmp , tt , mmax;
int MMax[5001];
int main() {
    scanf("%d%d%d",&n,&HIGH,&k);
    for(int i=1; i<=n; i++) {
        scanf("%d",&tmp);
        while(tmp--) {
            scanf("%d",&tt);
            map[i][tt]++;
        }
    }
    for(int i=HIGH; i; i--) {
        if(HIGH >= i + k) tt = MMax[i+k];
        else tt = 0;
        for(int j=1; j<=n; j++) {
            f[j] = max(f[j] , tt) + map[j][i];
            MMax[i] = max(MMax[i] , f[j]);
        }
    }printf("%d",MMax[1]);
}