#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n = 0, p = 0, y = 0;
    void add(string& x, int i) {
        if (x[i] == 'n') ++n;
        if (x[i] == 'p') ++p;
        if (x[i] == 'y') ++y;
    }
    void sub(string& x, int i) {
        if (x[i] == 'n') --n;
        if (x[i] == 'p') --p;
        if (x[i] == 'y') --y;
    }
    bool check() {
        return n && p && y;
    }
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回符合题意的最长的子串长度
     * @param x string字符串 
     * @return int整型
     */
    int Maximumlength(string x) {
        n=p=y=0;
        // write code here
        int i = 0, j = 1; // j 没走过
        add(x, 0);
        int n = x.size(), ans = 1;
        while(j<n) {
            add(x, j);
            while(check() && i < j) {
                sub(x, i);
                ++i;
            }
            //cout<<"i:"<<i<<" j:"<<j<<endl;
            ans = max(ans, j-i+1);
            ++j;
        }
        return ans;
    }
};
int main() {
    auto s = new Solution();
    //cout<<s->Maximumlength("abcdefghijklmn")<<endl;
    //cout<<s->Maximumlength("ynp")<<endl;
    cout<<s->Maximumlength("ypknnbpiyc")<<endl;
    return 0;
}
