/**************************************************************
    Problem: 4029
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:820 kb
****************************************************************/
 
#include <stdio.h>
inline int min(int a , int b) { return a > b ? b : a ; }
inline int F() {
    register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
int lowbit(int x) {
    int tmp = 1;
    while((x%10) == 0) {
        x/=10;
        tmp*=10;
    }return tmp;
}
int calc(int x) {
    if(!x) return 0;
    while((x%10) == 0) x/=10;
    int a = 0;
    if(x%10 == 5) {
        while(x) x/=10 , ++a;
        return a+a-1;
    }
    else {
        while(x) x/=10 , ++a;
        return a+a;
    }
}
int main() {
    int t = F();
    while(t--) {
        int l = F() , r = F() , mn = 2147483647 , ans = l;
        while(l <= r) {
            int tmp = calc(l);
            if(mn > tmp) mn = tmp , ans = l;
            l += lowbit(l);
        }
        printf("%d\n", ans);
    }
}