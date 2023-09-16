class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        priority_queue<pair<int ,char>>pq;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        for(auto x:m)
        {
            pq.push({x.second,x.first});
        }
        string temp="";
        while(!pq.empty())
        {
            auto p=pq.top();
            
            while(p.first--)
            {
              temp+=p.second;
            }
            pq.pop();
            
        }
        return temp;
    }
};

