#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    LL h(string& exp, int s, int e) {
        LL ans = 0;
        if (exp[e] == '#') {
            ans = atol(exp.substr(0, e).c_str());
            return ans;
        }
        char op = exp[e];
        int i = e - 2;
        while (i >= 0) {
            if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '#') break;
            --i;
        }
        LL num1, num2;
        num1 = atoi(exp.substr(i + 1, (e-2)-(i+1)+1).c_str());
        num2 = h(exp, 0, i);
        if (op == '+') {
            ans = num1 + num2;
        } else if (op == '-') {
            ans = num2 - num1;
        } else if (op == '*') {
            ans = num2 * num1;
        }
        cout<<"s:"<<s<<" e:"<<e<<" ans:"<<ans<<endl;
        return ans;
    }
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 给定一个后缀表达式，返回它的结果
     * @param str string字符串
     * @return long长整型
     */
    long long solve(string str) {
        // write code here
        return h(str, 0, str.size() - 1);
    }
};

int main() {
    auto s = new Solution();
    //cout<<s->solve("1#2#-")<<endl;
    //cout<<s->solve("1#1#+")<<endl;
    cout<<s->solve("12#3#-7#+15#*")<<endl;
    return 0;
}
