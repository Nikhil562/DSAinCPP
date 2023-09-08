class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod=1e9+7;
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto i: nums) q.push(i);
        int n=nums.size();
        while(k--){
            int a=q.top();
            q.pop();
            q.push(a+1);
        }
        long long  prod=1;
        while(!q.empty()){
           prod=(prod*q.top())%mod;
            q.pop();
           // prod%=mod;
        }
        return prod;
    }
};
// class Solution {
// public:
//     int maximumProduct(vector<int>& nums, int k) {
//         long long ans = 1, mod = 1e9 + 7;
//         priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        
//         while(k--) {
//             int a = pq.top(); pq.pop();
//             pq.push(a + 1);
//         }
        
//         while(pq.size()) {
//             ans *= pq.top(); pq.pop();
//             ans %= mod;
//         }
//         return ans;
//     }
// };