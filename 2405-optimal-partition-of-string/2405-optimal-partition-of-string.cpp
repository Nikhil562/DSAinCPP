class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(mp[s[i]]>1){
                c++;
                mp.clear();
                i--;
            }
        }
        return ++c;
    }
};
