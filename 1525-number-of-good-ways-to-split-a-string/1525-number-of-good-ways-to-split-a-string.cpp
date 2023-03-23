class Solution {
public:
    int numSplits(string s) {
        int n=s.size();
        int ans=0;
        unordered_map<char,int> mp1,mp2;
        for(auto i: s) mp1[i]++;
        for(int i=0;i<n;i++){
             mp2[s[i]]++;
            mp1[s[i]]--;
            if(mp1[s[i]]==0) mp1.erase(s[i]);
            if(mp1.size()==mp2.size()) ans++;
        }
        return ans;
    }
};
// class Solution {
// public:
//     int numSplits(string s) {
//         int ans=0;
//         unordered_map<int,int> mp1,mp2;
//         for(int i=0;i<s.size();i++)
//         {
//             mp1[s[i]]++;
//         }
//         for(int i=0;i<s.size();i++)
//         {
//              mp2[s[i]]++;
//              mp1[s[i]]--;
//              if(mp1[s[i]]==0)
//              {
//                  mp1.erase(s[i]);
//              }
//              if(mp1.size()==mp2.size())
//              {
//                  ans++;
//              }
//         }
//         return ans;
//     }
// };