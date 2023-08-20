class Solution {
public:

int dp[50000][3];
int fun(int i,int rem, vector<int>&a)
{
    if(i==a.size())
    {
        if(rem==0)
            return 0;
        return INT_MIN;
    }
    if(dp[i][rem]!=-1)
        return dp[i][rem];
    
    return dp[i][rem]=max(a[i]+fun(i+1,(rem+a[i])%3,a),fun(i+1,rem,a));
}
int maxSumDivThree(vector<int>& a) {
    int i,j,n=a.size();
    memset(dp,-1,sizeof(dp));
    
    return fun(0,0,a);
    
}
};