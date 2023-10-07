class Solution {
public:
    int halveArray(vector<int>& A) {
        priority_queue<double> pq;
        double sum = 0;
        int ans = 0;
        for (int n : A) {
            pq.push(n);
            sum += n;
        }
        double goal = sum / 2;
        while (sum > goal) {
            auto x = pq.top();
            pq.pop();
            sum -= x / 2;
            pq.push(x / 2);
            ++ans;
        }
        return ans;
    }
};