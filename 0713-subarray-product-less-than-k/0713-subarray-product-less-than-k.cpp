class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,n=nums.size();
        int prod=1;
        int maxi=0;
        if(k<2) return 0;
        for(int j=0;j<n;j++){
            prod*=nums[j];
            while(prod>=k){
                prod/=nums[i];
                i++;
            }
              maxi+=j-i+1;
            
        }
        return maxi;
    }
};
