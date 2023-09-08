class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> q;
        int n=heights.size();
        for(int i=0;i<n-1;i++){
            if(heights[i+1]<=heights[i]) continue;
            if(heights[i+1]>heights[i]) q.push(heights[i+1]-heights[i]);
            if(q.size()>ladders) bricks-=q.top(),q.pop();
            if(bricks<0) return i;
            
        }
        return n-1;
    }
};
// int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         int n = heights.size();
//         // use ladders at larger heights and bricks at smaller heights
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for(int i = 0; i < n-1; i++) {
//             if(heights[i + 1] > heights[i])
//                 pq.push(heights[i + 1] - heights[i]);
//             if(pq.size() > ladders) 
//                     bricks -= pq.top(), pq.pop();
//             if(bricks < 0)
//                 return i;
//         }
//         return n - 1;
//     }