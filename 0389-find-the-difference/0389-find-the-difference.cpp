class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26,0);
        for(auto i:s) freq[i-'a']++;
        for(auto i:t) freq[i-'a']--;
        for(int i = 0; i < 26; i++) if(freq[i]) return (char)(i+'a');
        return '\0';
    }
};