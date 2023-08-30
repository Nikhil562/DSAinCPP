// Count the frequency of each characters. Those characters with frequency greater than N / 4 must be replaced. Find the minimum window which covers those characters that should be replaced.

// OJ: https://leetcode.com/problems/replace-the-substring-for-balanced-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int balancedString(string s) {
        int N = s.size(), ans = N, i = 0, j = 0, replace = 0;
        unordered_map<char, int> m;
        for (char c : s) m[c]++;
        for (auto &[c, cnt] : m) {
            if ((m[c] = max(0, cnt - N / 4)) > 0) ++replace;
        }
        if (replace == 0) return 0;
        while (j < N) {
            // replace -= --m[s[j++]] == 0;
            char currentChar = s[j];
            int currentFreq = --m[currentChar];
            // cout<<currentFreq<<endl;
            if (currentFreq == 0) replace--;
            j++;

            while (replace <= 0) {
                ans = min(ans, j - i);
                // replace += m[s[i]]++ == 0;
                char currentChar = s[i];
                int originalFreq = m[currentChar];
                if (originalFreq == 0) {
                 replace++;
                    }   
                m[currentChar]++;

                i++;
            }
        }
        return ans;
    }
};