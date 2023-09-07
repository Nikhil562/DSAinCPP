class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for(auto i: piles) q.push(i);
        while(k--){
            int t=q.top();
            q.pop();
            q.push(t-floor(t/2));
        }
        int sum=0;
        while(!q.empty()){
            sum+=q.top();
            q.pop();
    }
        return sum;
    }
};