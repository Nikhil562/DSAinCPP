class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        if(n==0) return 0;
        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        int mn=INT_MIN;
        while(j<n){
            mp[s[j]]++;
            // if(mp.size()>(j-i+1)) j++;
            if(mp.size()==(j-i+1)) {
                mn=max(mn,(j-i+1));
                j++;
            }
            else if(mp.size()<(j-i+1)){
                while(mp.size()<(j-i+1)) 
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }j++;
            }
        }return mn;
    }
};