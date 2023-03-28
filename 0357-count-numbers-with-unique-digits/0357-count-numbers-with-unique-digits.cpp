class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int ans=10;
        int c=9;
        int s=9;
        while(n-->1 && s){
            c*=(s--);
            ans+=c;
        }
        return ans;
    }
};