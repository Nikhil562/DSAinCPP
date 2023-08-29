class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int tmpSum=0;
        int ans=0;
        int windSize=n-k;
        if(n==k) return sum;
        while(j<n){
            tmpSum+=nums[j];
            if(j-i+1==windSize){
                ans=max(ans,sum-tmpSum);
                tmpSum-=nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};

