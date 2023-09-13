class comp{
    public:
    bool operator()(string &a,string &b)
    {
        if (a.size() == b.size()) {
                return a > b;
            }
            return a.size() > b.size();
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,comp> pq;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
            pq.pop();
        }
        return pq.top();
    }
};