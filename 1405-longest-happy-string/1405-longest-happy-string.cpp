class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result = "";

        while (!pq.empty()) {
            pair<int, char> first = pq.top();
            pq.pop();

            if (!result.empty() && result.back() == first.second) {
                if (pq.empty()) break;
                pair<int, char> second = pq.top();
                pq.pop();
                result += second.second;
                if (--second.first > 0) pq.push(second);
                pq.push(first);  // Push the first element back
            } else {
                int count = min(2, first.first);
                for (int i = 0; i < count; ++i) {
                    result += first.second;
                }
                if ((first.first -= count) > 0) pq.push(first);
            }
        }

        return result;
    }
};
