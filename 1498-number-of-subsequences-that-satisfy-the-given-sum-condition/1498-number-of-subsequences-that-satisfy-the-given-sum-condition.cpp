class Solution {
public:
    int help(int x,int y){
        if(y==1)return x;
        if(y==0)return 1;
        long long ans=1;
        if(y%2==0){
            ans=help(x,y/2)%1000000007;
            return (ans*ans)%1000000007;
        }else{
            return (x*help(x,y-1))%1000000007;
        }
        
    }
    int numSubseq(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        int ans=0;
        sort(nums.begin(),nums.end());
        while(s<=e){
            if(nums[s]+nums[e]<=target){
                ans+=help(2,e-s);
                cout<<e-s<<endl;
                ans%=1000000007;
                s++;
            }
            else e--;
        }
        return ans;
    }
};