class Solution {
public:
    int solve(int idx, vector<int>& dp, vector<int>& nums, int target){
        if(idx==nums.size()-1) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int res=INT_MIN;
        for(int i=idx+1; i<nums.size(); i++){
            if(nums[i]-nums[idx]<=target && nums[i]-nums[idx]>=-target){
                res=max(res,1+solve(i,dp,nums,target));
            }
        }
        
        return dp[idx]=res;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n,-1);
        
        int ans=solve(0,dp,nums,target);
        return ans<0 ? -1 : ans;
        
    }
};