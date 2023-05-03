class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_set<int> set1_tracker, set1, set2;
        for(auto e: nums1){
            set1_tracker.insert(e);
            set1.insert(e);
        }

        for(auto e: nums2){
            if(set1_tracker.find(e)==set1_tracker.end()){
                set2.insert(e);
            }
            else
                set1.erase(e);
        }

        vector<int> v1, v2;

        for(auto e: set1){
            v1.push_back(e);
        }

        for(auto e: set2){
            v2.push_back(e);
        }

        ans.push_back(v1);
        ans.push_back(v2);

        return ans;
    }
};