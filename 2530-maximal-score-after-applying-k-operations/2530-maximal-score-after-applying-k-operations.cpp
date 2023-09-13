class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
         priority_queue<int> q;
        for (auto i : nums) q.push(i);
        long long score = 0;
        while (k--) {
            long long t = q.top();
            q.pop();
            score += t;
            q.push(ceil(t / 3.0)); // Corrected ceil function
        }
        return score;
    }
    
    // q.push(ceil((double)t/3))
};