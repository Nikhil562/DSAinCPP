class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int n=customers.size();
        int i=0,j=0;
        int sum=0;
        int maxSum=0;
        for(int i=0;i<n;i++){
            if(!grumpy[i]) sum+=customers[i];
        }
        while(j<n){
            if(grumpy[j]){
                sum+=customers[j];
            }
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                maxSum=max(maxSum,sum);
                if(grumpy[i]==1) sum-=customers[i];
                i++;
                j++;
            }
        }
        return maxSum;
    }
};