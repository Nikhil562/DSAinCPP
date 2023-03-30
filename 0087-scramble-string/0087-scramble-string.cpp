class Solution {
public:
    bool isScramble(string s1, string s2) {
        int sum1 = 0, sum2 = 0;
        int n = s1.size();
        if (n == 1) return s1[0] == s2[0];
        int p1 = -1, p2 = -1;
        for (int i = 0; i < n; i++) {
            sum1 += s1[i] * s1[i] - s2[i] * s2[i];
            sum2 += s1[i] * s1[i] - s2[n - 1 - i] * s2[n - 1 - i];
            if (sum1 == 0 && i != n-1) p1 = i;
            if (sum2 == 0 && i != n-1) p2 = i;
        }
        int a = 0, b = 0;
        if (p1 != -1) a = isScramble(s1.substr(0, p1 + 1), s2.substr(0, p1 + 1)) && isScramble(s1.substr(p1 + 1, n - p1 - 1 ), s2.substr(p1 + 1, n - p1 - 1));
        if (p2 != -1) b = isScramble(s1.substr(0, p2 + 1), s2.substr(n - p2 - 1, p2 + 1)) && isScramble(s1.substr(p2 + 1, n - p2 - 1), s2.substr(0, n - p2 - 1));
        return a || b;
    }
};