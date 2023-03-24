class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans;
        int even=0,odd=0;
        int i=0;
        int m=0;
        while(n){
            m=n&1;
            if(m==1 && i%2==0) even++;
            if(m==1 && i&1) odd++;
            n=n>>1;
            i++;
        }
        ans.push_back(even);
        ans.push_back(odd);
        return ans;
        
        
    }
};