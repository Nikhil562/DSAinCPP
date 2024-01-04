class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map<int, int>Map ;
        int ret = 0 ;
        for(auto x : nums)
            Map[x]++ ;
        for(auto [key, cn] : Map){
            if(cn == 1)
                return -1 ;
            if(cn % 3 == 0)
                ret += cn / 3 ;
            else 
                ret += cn / 3 + 1 ;
        }
        return ret ;
    }
};