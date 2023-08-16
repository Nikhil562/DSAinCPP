class Solution {
public:
    int subsetSum(vector<int>&nums , int n, int target,vector<vector<int>>&dp){
        if(n==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0 || nums[0]==target) return 1;
            return 0;
        }
        if(dp[n][target]!=-1) return dp[n][target];
        int take=0;
        if(nums[n]<=target) take=subsetSum(nums,n-1,target-nums[n],dp);
        int nottake=subsetSum(nums,n-1,target,dp);
        return dp[n][target]=(take+nottake);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum-target<0) return 0;
        if((sum-target)&1) return 0;
        int tg=(sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(tg+1,-1));
        return subsetSum(nums,n-1,tg,dp);
    }
};