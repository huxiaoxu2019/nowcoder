// https://ac.nowcoder.com/acm/contest/9475/B
// Topic: 二分搜索
class Solution {
public:
    bool check(int n, int m, vector<Interval>& is, long long d) {
        int nums = 1;
        long long now = is[0].start;
        for (int i = 0; i < m; ++i) {
            if (now + d > is[i].end) continue;
            now = max(now + d, (long long)is[i].start);
            int cnt = (is[i].end - now) / d + 1;
            nums += cnt;
            now = now + (cnt-1) * d;
        }
        return nums >= n;
    }
 
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param n int整型 玩偶数
     * @param m int整型 区间数
     * @param intervals Interval类vector 表示区间
     * @return int整型
     */
    int doll(int n, int m, vector<Interval>& intervals) {
        // write code here
        long long l = 0, h = INT_MAX, mid, ans = 0;
        sort(intervals.begin(), intervals.end(), [&](Interval& a, Interval& b) -> bool {
            return a.start < b.start;
        });
        while (l <= h) {
            mid = (l + h)/2;
            if (check(n, m, intervals, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};
