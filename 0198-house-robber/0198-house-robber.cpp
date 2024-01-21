class Solution {
public:
    int fun(vector<int>&nums, int n,vector<int>&dp){
        if(n==0) return nums[0];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick=nums[n]+fun(nums,n-2,dp);
        int not_pick=0+fun(nums,n-1,dp);
        return dp[n]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(nums,n-1,dp);
    }
};