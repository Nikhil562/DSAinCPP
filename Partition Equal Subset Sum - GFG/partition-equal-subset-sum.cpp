//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool PESS(int Arr[], int n, int t, vector<vector<int>>&dp){
        if(t==0) return true;
        if(n==0) return Arr[0]==t;
        if(dp[n][t]!=-1) return dp[n][t];
        int nottake=PESS(Arr,n-1,t,dp);
        int take=false;
        if(Arr[n]<=t) take=PESS(Arr,n-1,t-Arr[n],dp);
        return dp[n][t]=take || nottake;
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        int t=sum/2;
        vector<vector<int>> dp(n,vector<int>(t+1,-1));
        
        if(sum%2==1) return 0;
        return PESS(arr,n-1,t,dp);

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends