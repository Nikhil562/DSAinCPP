class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> V;
        int m=*max_element(candies.begin(),candies.end());
        int c=candies.size();
        for(int i=0;i<c;i++){
            if((candies[i]+extraCandies)>=m) {V.push_back(true);}
            else V.push_back(false);
        }
        return V;
    }
};