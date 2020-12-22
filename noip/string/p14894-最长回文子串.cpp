// https://ac.nowcoder.com/acm/problem/14894
// string manacher
//
// format: $#a#b#c#
// n = str.length();  
// len = n * 2 + 1;
// p[i] - 1 为 i 为中心的回文串的字符串长度
#include<bits/stdc++.h>
using namespace std;

const int maxn=200010;
char sa[maxn], sb[maxn], so[maxn];
int n, len, pa[maxn], pb[maxn];

void print_a(int *p) {
    for(int i=0;i<len;++i) {
        printf("p[%d]:%d ", i, p[i]);
    }
    printf("\n");
}

void change(char *s) {
    scanf("%s",so);
    s[0]='$';
    s[1]='#';
    int j=1;
    for (int i=0;i<n;++i) {
        s[++j] = so[i];
        s[++j] = '#';
    }
    s[++j]='\0';
}

void manacher(char *s, int *p) {
    change(s);
    int id = 1, mx = 0;
    for (int i = 1;i <= len; ++i) {
        if (mx > i) p[i] = min(p[2 * id - i], mx - i);
        else p[i] = 1;
        while (i - p[i] > 0 && s[i - p[i]] == s[i + p[i]]) ++p[i];
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
}

int solve() {
    int ans = 1;
    for(int i = 2; i <= len; i++) {
        int t = max(pa[i], pb[i - 2]);
        while (sa[i-t] == sb[i-2+t]) ++t;
        ans=max(ans,t);
    }
    return ans - 1;
}

int main() {
    scanf("%d", &n);
    len=2*n+1;
    manacher(sa, pa);
    manacher(sb, pb);
    printf("%d\n",solve());
    return 0;
}
