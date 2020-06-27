/*
    原理很简单，就是把文字先转wstring(长字符的字符串，可以表示中文)，设置setlocale(LC_ALL, "zh_CN.UTF-8")后，用iswpunct(ch)判断标点隔断，隔断后再转回string。
    转回string以后毕竟是char，最大也就127。
    我们有16种切噜字母：cheru_set = L"切卟叮咧哔唎啪啰啵嘭噜噼巴拉蹦铃"，把一个char按二进制前面一半后面一半，拆分成两半以后两边都是小于16(10)的数字。
      比如大写字母C ： 67(10) = 00100011(2)可以拆分成 0100 0011 --> 4,3，那么就可以用哔(cheru_set[4])咧(cheru_set[3]) 来表示字母C。
    另外我们发现切噜语的每段话以切为开头，所以我们在每段话前面加上切即可。
    所以段落 “ C " 翻译为切噜语就是 “ 切哔咧 ”。
        段落 “ 600-650w ” 翻译为切噜语就是 “ 切啪咧切咧切咧-切啪咧唎咧切咧啰啰 ”。
    原版py细节处理的方式和我的不大一样，是直接encode，decode，不知道是不是这个原因导致出现中文的翻译不同的情况。
    
    一时兴起写的，写完发现貌似要使用unsigned来处理，不然会出现负数不方便&。毕竟我们是强行把wstring的中文转成string，具体细节我懒得调了，回头再说吧。
*/
#include <iostream>
#include <codecvt>
#include <fstream>
#include <string>
#include <locale>
#include <vector>
using namespace std;
#define changeword(a) (x ? cheru2word(a) : word2cheru(a))
wstring_convert<codecvt_utf8<wchar_t>> conv;

wstring cheru_set = L"切卟叮咧哔唎啪啰啵嘭噜噼巴拉蹦铃";
vector<string> output;

string s;

wstring word2cheru(wstring st) {
    if(st.empty()) return L"";
    string str = conv.to_bytes(st);
    wstring ans = L"切";
    for(char ch : str) {
        ans.push_back(cheru_set[ch & 0xf]);
        ans.push_back(cheru_set[(ch>>4) & 0xf]);
    }
    return ans;
}

wstring cheru2word(wstring str) {
    if(str[0] != cheru_set[0] || str.size() < 2) return str;
    string ans = "";
    for(int i=1; i<cheru_set.size(); i+=2) {
        wchar_t ch1 = str[i], ch2 = str[i+1];
        int x,y;
        for(x=0; x<16; x++)
            if(ch2 == cheru_set[x]) break;
        for(y=0; y<16; y++)
            if(ch1 == cheru_set[y]) {
                x = x<<4 | y;
                break;
            }
        ans.push_back(x);
    }
    return conv.from_bytes(ans);
}

int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");

    int x;
    cin>>x;

    while(getline(cin, s)) {
        wstring ws = conv.from_bytes(s);
        wstring nws;
        for(wchar_t ch : ws) {
            if(!iswpunct(ch) && !iswspace(ch)) nws.push_back(ch);
            else {
                output.push_back( conv.to_bytes( changeword(nws)) );
                output.push_back( conv.to_bytes(ch) );
                nws.clear();
            }
        }
        if(!nws.empty()) {
            output.push_back( conv.to_bytes( changeword(nws) ) );
            nws.clear();
            output.push_back("\n");
        }
    }

    for(int i=0; i<output.size(); i++)
        cout<<output[i];
    
    return 0;
}
