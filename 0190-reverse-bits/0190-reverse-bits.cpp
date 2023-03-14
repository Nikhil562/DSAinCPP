class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int ans=0;
        for(int i=1;i<=32;i++){
            if(n&(1<<(i-1))){
                ans=ans|(1<<(32-i));
            }
        }
        return ans;
    }
};