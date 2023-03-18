class Solution {
public:
    
    
    //to remove el within or to unset use zor
    int longestNiceSubarray(vector<int>& nums) {
        
//         int n=nums.size();
//         int j=0;
//         int mx=0;
//         int num=0;
//         for(int i=0;i<n;i++){
//             while((num & nums[i])!=0){
//                 num^=nums[j++];
                
//             }
//             num|=nums[i];
//             mx=max(mx,j-i+1);
//         }
//         return mx;
        int num = 0;
        int j =0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            while ( (num & nums[i]) != 0) 
            {
               num^=nums[j++];       
            }  
             num|= nums[i];
            ans = max(ans,i-j+1);
        }
        return ans;

    }
};