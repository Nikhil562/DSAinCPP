class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int,int>> maxH;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >minH;
        
        int n=nums.size();
        int i=0,res=0;
        for(int j=0;j<n;j++){
            minH.push({nums[j],j});
            maxH.push({nums[j],j});
            
            while(!maxH.empty() && maxH.top().second<i) maxH.pop();
            while(!minH.empty() && minH.top().second<i) minH.pop();
            
            if(maxH.top().first-minH.top().first>limit) i++;
            
            res=max(j-i+1,res);
            
        }
        return res;
    }
};