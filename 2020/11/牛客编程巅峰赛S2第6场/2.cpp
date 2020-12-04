#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回符合题意的最长的子串长度
     * @param x string字符串 
     * @return int整型
     */
    int string2(int K, string s) {
        int ans = INT_MIN; 
        int i;
        for (i = 0; i < 26;++i) {
            sort(s.begin(), s.end(), [&](const char&a, const char&b) -> bool {
                    return abs(a-'a'-i) < abs(b-'a'-i);
                    });
            int cans = 0,ck = K;
            for(int j = 0;j<s.size()&&ck>=0;++j) {
                if (s[j]-'a' == i) {
                    ++cans;
                } else {
                    ck -= abs(s[j]-'a'-i);
                    if(ck>=0) ++cans;
                }
            }
            ans=max(ans,cans);
        }
        return ans;
    }
};
int main() {
    auto s = new Solution();
    cout<<s->string2(10,"acesxd")<<endl;
    return 0;
}
