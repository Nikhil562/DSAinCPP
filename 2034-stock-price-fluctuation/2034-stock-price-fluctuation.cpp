class StockPrice {
public:
    
    map<int,int> m;
    
    set<pair<int,int>> s;
    
    StockPrice() {
        s.clear();
        m.clear();
    }
    
    void update(int timestamp, int price) {
        if(m.find(timestamp) == m.end()) {
            s.insert({price, timestamp});
            m[timestamp] = price;
        } else {
            s.erase({m[timestamp], timestamp});
            s.insert({price, timestamp});
            m[timestamp] = price;
        }
    }
    
    int current() {
        return m[(*(m.rbegin())).first];
    }
    
    int maximum() {
        return (*s.rbegin()).first;
    }
    
    int minimum() {
        return (*s.begin()).first;
    }
};