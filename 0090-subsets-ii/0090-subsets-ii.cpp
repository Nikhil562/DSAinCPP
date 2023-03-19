class Solution {
public:
   vector<vector<int>> subsetsWithDup(vector<int>& nums){
    vector<vector<int>>Subsets; // final result
    sort(nums.begin(),nums.end());
    
    int n = nums.size();
    int subsets_count = (1<<n);  // Number of subsets --> 2^n
    
    set<vector<int>>unique; // for avoiding duplicate subsets
    
    for(int mask = 0;mask<subsets_count;mask++)
    {
        vector<int>subset;
        for(int i=0;i<n;i++){
            if((mask & (1<<i)) != 0) subset.push_back(nums[i]);
        }
        unique.insert(subset);
    }
    
    for (auto it = unique.begin();it != unique.end();it++) Subsets.push_back(*it);
    
    return Subsets;
}
};