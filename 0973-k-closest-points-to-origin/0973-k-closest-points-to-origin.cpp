class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<int,pair<int,int>>> p;
        for(auto i: points){
            int a=i[0];
            int b=i[1];
            int s=a*a+b*b;
            p.push({s,{a,b}});
            if(p.size()>k) p.pop();
        }
        vector<vector<int>> ans;
        while(p.size()>0){
            ans.push_back({p.top().second.first,p.top().second.second});
            p.pop();
        }
        return ans;
    }
};