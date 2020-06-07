/**************************************************************
    Problem: 1327
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:300 ms
    Memory:820 kb
****************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
 
#define getch() getchar()
inline int F() {register int ch; while(ch = getch() , !(ch>='0'&&ch<='3')); return ch - '0'; }
 
inline int max(int a , int b) { return a > b ? a : b ; }
inline int min(int a , int b) { return a < b ? a : b ; }
#define R register
const int c[8][7] = {0,2,6,11,15,20,22 , 1,3,8,12,17,21,23 , 10,9,8,7,6,5,4 , 19,18,17,16,15,14,13 , 23,21,17,12,8,3,1, 22,20,15,11,6,2,0 , 13,14,15,16,17,18,19 , 4,5,6,7,8,9,10};
const int ss[8] = {6,7,8,11,12,15,16,17};
const int la[8] = {5,4,7,6,1,0,3,2};
const int Maxn = 24;
const int Maxq = 1<<Maxn;
int dep , ans[101] , aim;
 
void pull(int *a , int id) {//correct
    int tmp = a[c[id][0]];
    for(int i=6; i>=0; --i) std::swap(tmp , a[c[id][i]]);
}
 
int check(int *a) {
    int cnt[4] = {};
    for(int i=0; i<8; ++i) ++cnt[a[ss[i]]];
    if(cnt[1] == 8 || cnt[2] == 8 || cnt[3] == 8) return -1;
    else return max(cnt[1],max(cnt[2],cnt[3]));
}
 
int dfs(int *s , int d , int lst) {
    if(d > dep) return 0;
    if(dep-d < 8-check(s)) return 0;
    int tmp[Maxn];
    for(int i=0; i<8; ++i) {
        if(lst == la[i]) continue;
        for(int k=0; k<24; ++k) tmp[k] = s[k];
        pull(tmp,i);
        ans[d] = i+'A';
        if(check(tmp) == -1) {
            aim = tmp[7];
            return 1;
        }
        if(dfs(tmp,d+1,i)) return 1;
    }return 0;
}
 
int main() {
    R int a[Maxn];
    while(a[0] = F()) {
        for(int i=1; i<24; ++i) a[i] = F();
        if(check(a) == -1)  printf("No moves needed\n%d\n",a[7]);
        else {
            dep = 1;
            while(!dfs(a , 0 , -1)) ++dep;
            for(int i=0; i<dep; ++i) printf("%c",ans[i]);
            printf("\n%d\n",aim);
        }
    }
}