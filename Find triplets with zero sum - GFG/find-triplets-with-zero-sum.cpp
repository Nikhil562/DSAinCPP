//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
         if(n<=2)return 0;
        sort(arr,arr+n);int k=n-1;
        int sm=0;
       for(int i=1;i<n-1;i++){
           int s=0;
           int e=n-1;
           while(s<e){
               if(s!=e && s!=i && e!=i){
                  sm= arr[s]+arr[e]+arr[i];
                   if(sm==0)return 1;
                   if(sm<0){
                       s++;
                   }
                   else{
                       e--;
                   }
               }
               else break;
               
           }
           
       }
       return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends