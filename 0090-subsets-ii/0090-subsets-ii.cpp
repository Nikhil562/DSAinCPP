class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
   
   int n=nums.size();
   int t=1<<n;
 sort(nums.begin(),nums.end());
   vector<vector<int>> ans;
    set<vector<int>> s;
   for(int i=0;i<t;i++){
       vector<int> v;
       for(int j=0;j<n;j++){
           if(i&(1<<j)){
               v.push_back(nums[j]);
           }
       }
       s.insert(v);
   }
        for(auto i: s) ans.push_back(i);
        return ans;
}
};
