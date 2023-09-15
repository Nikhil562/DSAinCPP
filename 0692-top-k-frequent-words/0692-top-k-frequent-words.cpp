struct compare{
    bool operator()(const pair<int,string> s1,const pair<int,string> s2){
        if(s1.first == s2.first) return s1.second < s2.second;
        return s1.first > s2.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto x: words){
            m[x]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> q;
        for(auto x: m){
            q.push({x.second,x.first});
            if(q.size()>k) q.pop();
        }
        vector<string> ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        reverse(ans.begin(),ans.end());    
        return ans;
    }
};