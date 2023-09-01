class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        if(n==0) return {0};
        while(n){
            int c=0;
            int t=n;
            while(t){
                c++;
                t=t&(t-1);
                t/=2;
            }
            ans.push_back(c);
            n--;
            if(n==0) ans.push_back(0);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};