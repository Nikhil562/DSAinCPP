class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>ans;
        int count=0;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count+=mat[i][j];
            }
            pq.push({count,i});
            count=0;
        }
        while(k--){
            int a=pq.top().second;
            pq.pop();
            ans.push_back(a);
        }
        return ans;
    }
};