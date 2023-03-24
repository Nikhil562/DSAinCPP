class Solution {
public:
    bool hasAlternatingBits(int n) {
        int curr;
        int prev=!(n&1);
        while(n){
            curr=n&1;
            if(curr==prev) return false;
            n=n>>1;
            prev=curr;
        }
        return true;
        
    }
};