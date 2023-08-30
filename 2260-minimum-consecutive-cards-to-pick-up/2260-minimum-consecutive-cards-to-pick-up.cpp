class Solution {
public:
   int minimumCardPickup(vector<int>& cards) {
        int mn = INT_MAX ,sze = cards.size() , l = 0;
        unordered_map<int,int> m{}; 
        for(int i = 0 ; i < sze ; i++ ){
            m[cards[i]]++;
            while(m[cards[i]] > 1){mn = min(mn , i - l + 1); m[cards[l++]]--; }
        }
        return mn == INT_MAX ? -1 : mn  ; 
    }
};
 // int minimumCardPickup(vector<int>& cards) {
 //        int mn = INT_MAX ,sze = cards.size() , l = 0;
 //        unordered_map<int,int> m{}; 
 //        for(int i = 0 ; i < sze ; i++ ){
 //            m[cards[i]]++;
 //            while(m[cards[i]] > 1){mn = min(mn , i - l + 1); m[cards[l++]]--; }
 //        }
 //        return mn == INT_MAX ? -1 : mn  ; 
 //    }