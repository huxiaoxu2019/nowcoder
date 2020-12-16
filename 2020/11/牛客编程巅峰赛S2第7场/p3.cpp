// https://ac.nowcoder.com/acm/contest/9886
#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int N = 1e6 + 5;
ULL h[N], p[N];
int P = 131;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 给定一个字符串s，返回具有相同前缀后缀的子串的第二大长度，反之，返回-1即可。
     * @param s string字符串 代表题意中的字符串s
     * @return int整型
     */

    int getHash(int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    int solve(string str) {
        int n=str.size();

        p[0] = 1;
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + str[i-1];
            cout<<"i:"<<i<<" h[i]:"<<h[i]<<endl;
        }

        for (int len=n-1;len>=1;--len) {
            if(getHash(1,len)==getHash(n-len+1,n)) {
                if(str.substr(0,len)==str.substr(n-len,n)) return len;
            }
        }
        return -1;

    }
};
int main() {
    auto s = new Solution();
    cout<<s->solve("ABCDEFABCDEF")<<endl;
    return 0;
}
