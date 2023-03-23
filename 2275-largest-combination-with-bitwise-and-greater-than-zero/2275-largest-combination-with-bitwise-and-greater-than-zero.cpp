class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();
        int max1=0;
        for(int i=0;i<32;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(candidates[j]&1<<i){
                    c++;
                }
            }
            max1=max(c,max1);
            
        }
        return max1;
    }
};