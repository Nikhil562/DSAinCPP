class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums2.size();i++)v.push_back({nums2[i],nums1[i]});
        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=v[i].second;
            pq.push(v[i].second);
        }
        long long ans=sum*v[k-1].first;
        for(int i=k;i<v.size();i++){
            sum-=pq.top();
            pq.pop();
            sum+=v[i].second;
            pq.push(v[i].second);
            ans=max(ans,sum*v[i].first);
        }
        return ans;
    }
};