class StockPrice {
public:
    set<pair<int,int>> s;  //{price ,-time}
    map<int,int> map; // -time : price
    
    StockPrice() {}
    
    void update(int time, int price) {
        if(map.find(-time)!= map.end()){
            s.erase({map[-time],-time});
        }
        map[-time]= price;
        s.insert({price,-time});
    }
    
    
    int current() {
        return map.begin()->second ;
    }
    
    
    int maximum() {
        return s.rbegin()->first;
    }
    
    
    int minimum() {
        return s.begin()->first;
    }
};