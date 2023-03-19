class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=queries.size();
        for(int i=1;i<arr.size();i++){
            arr[i]=arr[i-1]^arr[i];
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            int r=queries[i][1],l=queries[i][0];
            int k=arr[r];
            if(l>0){
                k^=arr[l-1];
            }
               ans.push_back(k);
        }
        return ans;
    }
};