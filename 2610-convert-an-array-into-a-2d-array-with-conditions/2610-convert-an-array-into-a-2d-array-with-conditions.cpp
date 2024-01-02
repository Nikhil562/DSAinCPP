class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
           vector<vector<int>> ans;
        unordered_map<int, int> mp;

        // Count the occurrences of each element in nums
        for (auto num : nums) {
            mp[num]++;
        }

        // Iterate until the map is not empty
        while (!mp.empty()) {
            vector<int> row;
            vector<int> toRemove;  // Temporary vector to store elements to be removed

            // Iterate over the map and add elements to the row
            for (auto& entry : mp) {
                row.push_back(entry.first);
                entry.second--;  // Decrease the count of the current element

                if (entry.second == 0) {
                    toRemove.push_back(entry.first);  // Add elements to be removed
                }
            }

            // Remove elements with count 0
            for (auto num : toRemove) {
                mp.erase(num);
            }

            ans.push_back(row);
        }

        return ans;
    }
};