#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     *
     * @param arr int整型vector
     * @return int整型
     */
    int Answerofjudge(vector<int>& arr) {
        // write code here
        sort(arr.begin(), arr.end());
        double m, a = 0;
        int n = arr.size();
        int p = (n - 1) / 2;
        if (n % 2 == 0) {
            m = (double)(arr[p] + arr[p + 1]) / 2;
        } else {
            m = arr[p];
        }
        for (int i = 0; i < n; ++i) {
            a += arr[i];
        }

        a /= n;
        cout<<"m:"<<m<<" a:"<<a<<endl;
        if (abs(m - a) < 1e-9) {
            return 0;
        } else {
            if (m > a) return 1;
            return -1;
        }
        return 0;
    }
};

int main() {
    auto s=new Solution();
    vector<int> a = {7,4,8,11};
    cout<<s->Answerofjudge(a)<<endl;
    return 0;
}
