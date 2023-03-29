class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        int n=sat.size();
        int s=n-1;
        int total=0;
        for(int i=n-1;i>=0;i--){
            total+=sat[i];
            if(total<0) break;
            s--;
        }
        s++;
        int k=1;
        total=0;
        for(int i=s;i<n;i++){
            total+=(k++)*sat[i];
        }
        return total;
    }
};