class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;
        for(auto i: s) mp[i]++;
        priority_queue<pair<char,int>> pq;
        for(auto i:mp) pq.push({i.first,i.second});
        string ans="";
        while(!pq.empty()){
            auto [firstch,firstfreq]=pq.top();
            pq.pop();
            for(int i=0;i<repeatLimit && firstfreq>0;i++){
                firstfreq--;
                ans+=firstch;
            }
            if(firstfreq>0 && pq.size()>0){
                auto [secch,secfreq]=pq.top();
                pq.pop();
                ans+=secch;
                secfreq--;
                if(secfreq>0) pq.push({secch,secfreq});
                pq.push({firstch,firstfreq});
            }
        }
        return ans;
    }
};