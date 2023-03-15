//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:    
    int swapBits(int x, int p1, int p2, int n)
    {
        unsigned a=(x>>p1)&((1U<<n)-1);
        unsigned b=(x>>p2)&((1U<<n)-1);
        unsigned c=a^b;
        c=(c<<p1)|(c<<p2);
        return x^c;
    }
};

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,p1,p2,n;
		cin>>x>>p1>>p2>>n;
		Solution obj;
		int res=obj.swapBits(x,p1,p2,n);
		printf("%d\n", res);
	}
    return 0;
}
// } Driver Code Ends