class LUPrefix {
public:
    int maxi=0;
    unordered_map<int,int> mp;
    LUPrefix(int n) {
        
    }
    
    void upload(int video) {
        
        mp[video]++;
        while(mp[maxi+1]>0) maxi++;
    }
    
    int longest() {
        return maxi;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */