//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%1000000007;
        a = a * a%1000000007;
        b >>= 1;
    }
    return res;
}
   	int Nth_term(int a, int r, int n){
   	    // Code here
   	    long long ans=a*binpow(r,n-1);
   	    return ans%1000000007;
   	    
   	    
   	}    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, r, n;
		cin >> a >> r >> n;
		Solution ob;
		int ans = ob.Nth_term(a, r, n);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends