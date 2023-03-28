class Solution {
public:
    vector<int> divisors(int n){
        vector<int> ans;
        for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i * i != n) {
                ans.push_back(n / i);
            }
        }
    }
        if(ans.size()==4) return ans;
            return {};
    }
    int sumFourDivisors(vector<int>& nums) {
        int s=0;
        for(auto i: nums){
           vector<int> ans= divisors(i);
           if(ans.size()) s+=accumulate(ans.begin(),ans.end(),0);
           else continue;
        }
        return s;
    }
};