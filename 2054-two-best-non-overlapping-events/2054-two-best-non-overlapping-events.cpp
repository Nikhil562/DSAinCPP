class Solution {
public:
    
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // priority queue minheap --> to store endtime and values of the events
        sort(events.begin(),events.end()); // sort according to start time
        
        int result = 0;
        int maxval = 0; // maxvalue stores the maximum value of the values encountered so far and 
        // whose ending time is less than the start time of the current event
        for(int i=0; i<n; i++)
        {
            while(!pq.empty() && pq.top().first < events[i][0])
            {
                maxval = max(maxval,pq.top().second);
                pq.pop();
            }
            result = max(result, maxval + events[i][2]);
            pq.push({events[i][1],events[i][2]});
        }
        return result;
        
    }
};