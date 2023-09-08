class Solution {
 public:
  int maxEvents(vector<vector<int>> &events) {
    sort(begin(events), end(events), [](auto &v1, auto &v2) { return v1[0] < v2[0]; });
    priority_queue<int, vector<int>, greater<int>> pq;  // min heap: stores end times by earliest
    int day = 1, i = 0, n = events.size(), ans = 0;     // i: event index
    while (i < n || !pq.empty()) {
      if (pq.empty()) {
        day = events[i][0];
      }
      while (i < n && events[i][0] == day) {
        pq.push(events[i++][1]);
      }
      pq.pop();  // attend the event that ends earliest
      ++ans;
      // clean up for next round
      ++day;
      while (!pq.empty() && pq.top() < day) {
        pq.pop();
      }
    }
    return ans;
  }
};