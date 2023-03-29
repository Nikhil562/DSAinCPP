class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
       set<int> s;
        for(auto i: nums){
            s.insert(i);
            int rem,revNo=0;
            while(i){
                rem=i%10;
                revNo=revNo*10+rem;
                i/=10;
            }
            s.insert(revNo);
        }
        return s.size();
    }
};