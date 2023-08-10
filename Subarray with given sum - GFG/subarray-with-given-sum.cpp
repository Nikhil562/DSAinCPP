//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        // int i=0,j=0;
        // int sum=0;
        // while(j<n){
        //     sum+=arr[j];
        //     if(sum==s) {
        //         return {i+1,j+1};
        //     }
        //     while(sum>s){
        //         sum-=arr[i];
        //         i++;
        //     }
        //     j++;
        // }
        // return {i+1,j+1};
        int currSum = 0;
        int  start = 0;
        int end = 0;
        while (end < n ){
            currSum += arr[end];
            while (currSum > s ){
                currSum -= arr[start];
                start++;
            }
            if (currSum == s && start <= end){
                return {start+1, end+1};
            }
            end++;
            
        }

        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends