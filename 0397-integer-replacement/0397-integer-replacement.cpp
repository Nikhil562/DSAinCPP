class Solution {
public:
   
    int fun(long long int n){
        if(n==1) return 0;
        int ans=0;
        if(n&1) ans=min(fun(n+1),fun(n-1))+1;
        else ans=1+fun(n/2);
        return ans;
    }
     int integerReplacement(int n) {
        return fun(n);
    }
    
    
};