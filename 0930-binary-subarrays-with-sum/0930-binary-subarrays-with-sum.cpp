class Solution {
public:
    int atmost(vector<int>&nums , int goal){
        int i=0,j=0;
        int n=nums.size();
        int sum=0,ans=0;
        while(j<n){
            sum+=nums[j];
            while(sum>goal && i<=j){
                sum-=nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
            
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};