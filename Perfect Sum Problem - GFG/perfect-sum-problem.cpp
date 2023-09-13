//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
    int mod = 1e9+7;
    
	int solve(int sum, int n, int arr[], vector<vector<int>>&dp){
	    if(n<0)return sum == 0;
	    if(dp[n][sum]!=-1)return dp[n][sum];
	    
        int pick = (sum-arr[n]>=0)?solve(sum-arr[n],n-1,arr,dp):0;
        int notPick = solve(sum,n-1,arr,dp);
        
        return dp[n][sum] = (pick+notPick)%mod;

	}
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
	    return solve(sum,n-1,arr,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends