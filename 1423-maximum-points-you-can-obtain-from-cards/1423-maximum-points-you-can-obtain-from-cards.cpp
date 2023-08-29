class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        
        for (auto iter : cardPoints) {
            sum += iter;
        }
        
        int i = 0;
        int j = 0;
        int temp_sum = 0;
        int ans = 0;
        int n = cardPoints.size();
       // cout << "Sum is " << sum << endl;
        
        if (k == n) return sum;

        while (j < n) {
            temp_sum += cardPoints[j];
            if (j-i+1 < n-k) {
                // do nothing
            } else if(j-i+1==n-k){
                // Reached window size
               // cout<< "temp_sum is " << temp_sum << endl;
                ans = max(ans, (sum - temp_sum));
                temp_sum -= cardPoints[i];
                i++;
            }
            j++;
        }
        
        return ans;
    }
};