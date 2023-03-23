class Solution {
public:
    int concatenatedBinary(int n) {
        int i=1;
        long long val=0;
        long long mod=1000000007;
        while(i<=n){
            val=((val<<(1+int(log2(i))))%mod +i)%mod;
            i++;
        }
        return val;
        
    }
};