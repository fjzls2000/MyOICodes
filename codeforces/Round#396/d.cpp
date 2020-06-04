#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <map>
using namespace std;
inline int F() {  register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 200010;
map <string , int> mp;
int n , m , q , fa[Maxn]; string tmp;
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x]));}
void ins(int a , int b) { fa[find(a)] = find(b); }
int main() {
    n = F() , m = F() , q = F();
    for(int i=1; i<=n; ++i) {
        cin>>tmp;
        mp[tmp] = i;
    }
    for(int i=1; i<=n+n; ++i) fa[i] = i;
    for(int i=1; i<=m; ++i) {
        int op = F();
        cin>>tmp;
        int a = mp[tmp];
        cin>>tmp;
        int b = mp[tmp];
        if(op == 1) {
            if(find(a) == find(b)) {
                puts("YES");
            }
            else if(find(a) == find(b+n)) {
                puts("NO");
            }
            else {
                puts("YES");
                ins(a,b); ins(a+n,b+n);
            }
        }
        else {
            if(find(a) == find(b)) {
                puts("NO");
            }
            else if(find(a) == find(b+n)) {
                puts("YES");
            }
            else {
                puts("YES");
                ins(a,b+n);
                ins(b,a+n);
            }
        }
    }
    for(int i=1; i<=q; ++i) {
        cin>>tmp;
        int a = mp[tmp];
        cin>>tmp;
        int b = mp[tmp];
        if(find(a) == find(b)) {
            puts("1");
        }
        else if(find(a) == find(b+n)) {
            puts("2");
        }
        else puts("3");
    }
}