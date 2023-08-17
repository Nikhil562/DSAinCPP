//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int arr[], int n){
        // Code here
    vector<int> v; // creating a vector for storing result 
    stack <int> s; // creating a stack for temp. hold the values from array
    for (int i=n-1;i>=0;i--){
      if(s.size() ==0) // when stack size is empty there is no element in stack return output as -1;
        v.push_back(-1);
      else if (s.size()>0 && s.top()>arr[i]) // when there is element in stack and stack top is greater then array element 
      {
        v.push_back(s.top()); // take stack top in the result vector 
      }
      else if (s.size()>0 && s.top()<=arr[i]) // when there is element in stack and that element is less then array element 
      {
        while(s.size()>0 && s.top()<=arr[i]) // upto when there is element and stack top is less then array's element delete the element from stack
        {
          s.pop(); // delete the element from stack
        }
        if (s.size()==0) // when stack became empty return -1
        {
          v.push_back(-1);
        }
        else
        {
          v.push_back(s.top()); // else push stack top in the vector 
        }
      }
      s.push(arr[i]); // push array in stack
    }
    
    reverse(v.begin(),v.end()); // while returning reverse the vector and return it.
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(v[i]==-1) ans.push_back(arr[i]);
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends