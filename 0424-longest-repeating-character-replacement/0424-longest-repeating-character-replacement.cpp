class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0;
        int maxLen=0,repeat=0;
        int n=s.size();
        unordered_map<char,int> mp;
        while(j<n){
            char el=s[j];
            mp[el]++;
            repeat=max(mp[el],repeat);
            while(j-i+1-repeat>k){
                mp[s[i]]--;
                i++;
            }
            maxLen=max(maxLen,j-i+1);
                        j++;

        }
        return maxLen;
    }
};
