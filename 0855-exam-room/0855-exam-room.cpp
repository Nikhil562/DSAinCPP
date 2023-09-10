class ExamRoom {
public:
    set<int> s;
    int size;
    ExamRoom(int n) {
        size=n;
    }
    
    int seat() {
        if(s.size()==0){
            s.insert(0);
            return 0;
        }
        else{
            int maxDis=*s.begin();
            auto  it1=s.begin();
            auto  it2=s.begin();
            int index=0;
            it2++;
            for(; it2!=s.end() ; it1++ ,it2++){
                int d=(*it2-*it1)/2;
                if(d>maxDis){
                    maxDis=d;
                    index=*it1+((*it2-*it1)/2);
                }
            }
            if(((size-1)-*it1)>maxDis) {
                index=size-1;
            }
            s.insert(index);
            return index;
        }
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */