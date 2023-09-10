class FoodRatings {
public:
    struct comp{
        bool operator()(pair<int,string> a, pair<int,string> b) const {
            if(a.first>b.first) return 1;
            if(a.first<b.first) return 0;
            return (a.second<b.second);
        }
    };
    unordered_map<string,set<pair<int,string>,comp>> s;
    unordered_map<string,pair<string,int>> mp;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            mp[foods[i]]={cuisines[i],ratings[i]};
            s[cuisines[i]].insert({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string oldcusine=mp[food].first;
        int oldrating=mp[food].second;
        s[oldcusine].erase({oldrating,food});
        mp[food]={oldcusine,newRating};
        s[oldcusine].insert({newRating,food});
    }
    
    string highestRated(string cuisine) {
        return (*s[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */