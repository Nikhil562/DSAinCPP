class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        
        int l = 0, r = 0, val = mx, mx_len = 1;
        while(l < nums.size() && r < nums.size())
        {
            val &= nums[r];
            if(val < mx)
            {
                l++;
                if(l > r)
                    r++;
                val = mx;
            }
            else
            {
                mx_len = max(mx_len, r - l + 1);
                r++;
            }
        }
        return mx_len;
    }
};