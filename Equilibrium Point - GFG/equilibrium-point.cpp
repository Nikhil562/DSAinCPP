//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
   int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int sum[n];
        long long temp = 0;
        if(n==1) return a[0];
        for(int i = 0; i < n; i++){
            temp+=a[i];
            sum[i]=temp;
        }
        for(int i = 0; i < n; i++)
        {
            int ls=sum[i]-a[i];
            int rs=sum[n-1]-sum[i];
            if(ls==rs)
                return i + 1;
           
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends