class LUPrefix {
public:
    
    set<int> s;
    
    LUPrefix(int n) {
        
        for(int i=1;i<=1e5;i++){
            s.insert(i);
        }
        
    }
    
    void upload(int video) {
        
        s.erase(video);
    }
    
    int longest() {
        
        
        int h = *s.begin();
        
        return h-1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);A
 * int param_2 = obj->longest();
 */