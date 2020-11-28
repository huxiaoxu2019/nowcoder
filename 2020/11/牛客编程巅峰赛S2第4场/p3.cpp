// 交叉乘
// https://ac.nowcoder.com/acm/contest/9475/C
// Topic: 逆元,前缀和,数学
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 多次求交叉乘
     * @param a int整型vector a1,a2,...,an
     * @param query int整型vector l1,r1,l2,r2,...,lq,rq
     * @return int整型vector
     */
    vector<int> getSum(vector<int>& a, vector<int>& query) {
        int n = a.size();
        vector<__int128> sum(n + 1, 0);
        vector<__int128> sum2(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + a[i - 1];
            sum2[i] = sum2[i - 1] + 1LL * a[i - 1] * a[i - 1];
        }
        vector<int> ans((int)query.size() / 2, 0);
        for (int i = 0; i < (int)query.size(); i += 2) {
            int l = query[i], r = query[i + 1];
            __int128 tmp = (sum[r] - sum[l - 1]) * (sum[r] - sum[l - 1]);
            tmp -= sum2[r] - sum2[l - 1];
            tmp /= 2;
            tmp %= 1000000007;
            ans[i/2] = tmp;
        }
        return ans;
    }
};
