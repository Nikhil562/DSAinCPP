class SeatManager {
    set<int> Set;
public:
    SeatManager(int n) {
        for(int i = 1; i <= n; i++) {
            Set.insert(i);
        }
    }
    
    int reserve() {
        int seat = *Set.begin();
        Set.erase(Set.begin());
        return seat;
    }
    
    void unreserve(int seatNumber) {
        Set.insert(seatNumber);
    }
};