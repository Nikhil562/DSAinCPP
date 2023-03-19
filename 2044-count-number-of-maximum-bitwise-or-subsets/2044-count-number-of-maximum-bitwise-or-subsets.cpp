class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        int mxor=0;
        for(int i=0;i<n;i++){
            mxor|=nums[i];
        }
        int t=pow(2,n);
        for(int i=0;i<t;i++){
            int ror=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    ror|=nums[j];
                }
            }
            if(ror==mxor) c++;
        }
        return c;
    }
};