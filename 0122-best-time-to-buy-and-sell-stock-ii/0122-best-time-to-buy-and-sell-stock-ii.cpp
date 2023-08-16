class Solution {
public:
    int maxProfit(vector<int>&prices, int ind, int buy, int n,vector<vector<int>>&dp){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit;
        if(buy==0) profit=max(maxProfit(prices,ind+1,0,n,dp),-prices[ind]+maxProfit(prices,ind+1,1,n,dp));
        if(buy==1) profit=max(maxProfit(prices,ind+1,1,n,dp),prices[ind]+maxProfit(prices,ind+1,0,n,dp));
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return maxProfit(prices,0,0,n,dp);
    }
};