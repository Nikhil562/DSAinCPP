class Solution {
public:
     int arraySign(vector<int>& nums) {
        int c=0; //count the no. of negetive no. in the array
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) //if there is any 0 then product must be 0
                return 0;
            else if(nums[i]<0) //if less than 0
                c++;
        }
        if(c%2==0) //even no. of negetive integer's product will be positive
            return 1;
        return -1; // else negetive
    }
};