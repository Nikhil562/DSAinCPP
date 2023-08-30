class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int k = n/4;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int i = 0;
        int j = 0;
        int ans = 1e9;
        while(j<n){
            mp[s[j]]--;
            while(i<n && mp['W']<=k && mp['R']<=k && mp['E']<=k && mp['Q']<=k){
                // i am tring to find the freq of W R E Q outside the current window 
                //if all the frequency is less than <= k then we can replace the string to a suitable substring
                ans = min(ans,(j-i+1));
                mp[s[i]]++;//remove the calculation of the silding window when i shrink the window 
                i++;
            }
            j++;
        }
        return  ans;
    }
};