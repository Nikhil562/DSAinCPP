class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> ans;
        // for(int i=0;i<pow(2,n);i++){
        //     vector<int> v;
        //     for(int j=0;j<n;j++){
        //         if((1<<i)&j){
        //             v.push_back(nums[i]);
        //         }
        //     }
        //     ans.push_back(v);
        // }
        // return ans;
         int n = nums.size(); // n=3 -> 2^3 = 8
        vector<vector<int>> ans;
        for(int i=0;i<(1<<n);i++)
        {   
            vector<int>v;
            for(int j=0;j<n;j++)
            {   
                if((1<<j)&i) 
                    v.push_back(nums[j]); 
            }
            ans.push_back(v);
            
        }
        return ans;
    }
};