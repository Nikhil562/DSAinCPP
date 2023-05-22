typedef pair<int,int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> v;
        for(auto i: nums) mp[i]++;
        priority_queue<pi,vector<pi>,greater<pi>> minh;
        for(auto i: mp){
            minh.push(make_pair(i.second,i.first));
            if(minh.size()>k) minh.pop();
            
        }
        while(!minh.empty()){
            v.push_back(minh.top().second);
            minh.pop();
        }
        return v;
    }
};