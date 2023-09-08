class Solution {
public:
    typedef pair<int,pair<int,int>> pr;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // priority_queue<pr,vector<pr>,greater<pr>> q;
        priority_queue<pair<int,pair<int,int>>>q;
        int n=nums1.size();
        // int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<nums2.size();j++){
                int sum=nums1[i]+nums2[j];
                if(q.size()<k){
                    q.push({sum,{nums1[i],nums2[j]}});
                    
                }
                else{
                    if(sum<q.top().first){
                        q.pop();
                        q.push({sum,{nums1[i],nums2[j]}});
                    }else break;
                }
                
            }
            
        }
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<int> res;
            res.push_back(q.top().second.first);
            res.push_back(q.top().second.second);
            q.pop();
            ans.push_back(res);
    }
        return ans;
    }
};
