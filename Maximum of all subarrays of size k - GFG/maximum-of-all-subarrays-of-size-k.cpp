//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *nums, int n, int k)
    {
        // your code here
        vector<int> output;
        int i=0;
        int j=0;
        list<int> l;
        if (k>n) // edge case
        {
            output.push_back(*max_element(l.begin(),l.end()));
            return output;
        }
          
        while(j<n)
        {
            if(l.empty()){ 
                l.push_back(nums[j]);   
            }
            else
            { 
                while(!l.empty() && l.back()<nums[j]) l.pop_back(); //jo A[j] hm push krna wala ha agr list k els usse chota ha to pop krdo 
                l.push_back(nums[j]);               
            }
            if(j-i+1<k)
                ++j;
            else if(j-i+1==k)
            {
                output.push_back(l.front());
                if(nums[i]==l.front())
                    l.pop_front();
                ++i;
                ++j;
            }
        }
        return output;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends