class Solution 
{
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        int n=s.size();
        unordered_map<string,int> m;
        for(int x=0; x<=n-10; x++)
        {
            string str=s.substr(x,10);
            m[str]++;
        }
        vector<string> ans;
        for(auto it: m)
        {
            if(it.second>1) ans.push_back(it.first);
        }
        return ans;
    }
};