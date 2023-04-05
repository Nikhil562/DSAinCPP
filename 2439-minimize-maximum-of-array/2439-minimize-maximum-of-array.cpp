class Solution {
public:
    int n;
    
    bool possibleMax(vector<int>& ar, int m) {
        vector<long> nums(ar.begin(), ar.end());
        
        for(int i = n - 1; i > 0; i--) {
            if(nums[i] > m)
                nums[i - 1] += nums[i] - m;
        }
        
        return nums[0] <= m;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        n = nums.size();
        int l = 0, r = *max_element(nums.begin(), nums.end()), mid;
        
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(possibleMax(nums, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return l;
    }
};