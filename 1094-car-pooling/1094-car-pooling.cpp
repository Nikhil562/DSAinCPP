class Solution {
public:
    typedef pair<int,int> pr;
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pr,vector<pr>,greater<pr>> q;
        for(int i=0;i<trips.size();i++){
            q.push({trips[i][1],trips[i][0]});
            q.push({trips[i][2],-trips[i][0]});
        }
        int sum=0;
        while(!q.empty()){
            sum+=q.top().second;
            q.pop();
            if(sum>capacity) return false;
        }
        return true;
    }
};