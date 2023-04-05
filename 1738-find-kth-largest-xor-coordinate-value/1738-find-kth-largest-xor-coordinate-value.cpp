class Solution {
public:
    int kthLargestValue(vector<vector<int>>& v, int k) {
        int n=v.size();
        int m=v[0].size();
        vector<int>ans(n*m);
        ans.clear();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0 && i==0);
                else if(i==0)
                v[i][j]=v[i][j]^v[i][j-1];
                 else if(j==0)
                    v[i][j]=v[i][j]^v[i-1][j];
                else
                    v[i][j]=v[i][j]^(v[i-1][j]^v[i][j-1]^v[i-1][j-1]);
                ans.push_back(v[i][j]);
            }
            //cout<<endl;
        }
        sort(ans.begin(),ans.end(),greater<int>());
        
       
        return ans[k-1];
    }
};