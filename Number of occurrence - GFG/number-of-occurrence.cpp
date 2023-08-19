//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int FO(int arr[], int t, int n){
	    int l=0;
	    int h=n-1;
	    int ind=-1;
	    while(l<=h){
	        int mid=l+(h-l)/2;
	        if(arr[mid]==t) {
	            ind=mid;
	            h=mid-1;
	        }
	        else if(arr[mid]>t) h=mid-1;
	        else l=mid+1;
	    }
	    return ind;
	}
	int LO(int arr[], int t, int n){
	    int l=0;
	    int h=n-1;
	    int ind=-1;
	    while(l<=h){
	        int mid=l+(h-l)/2;
	        if(arr[mid]==t) {
	            ind=mid;
	           l=mid+1;
	        }
	        else if(arr[mid]>t) h=mid-1;
	        else l=mid+1;
	    }
	    return ind;
	}
	int count(int arr[], int n, int x) {
	    // code here
	  int fo=FO(arr,x,n);
	  int lo=LO(arr,x,n);
	  if(fo==-1 && lo==-1) return 0;
	  return (lo-fo+1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends