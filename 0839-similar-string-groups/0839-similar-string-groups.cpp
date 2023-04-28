class Solution {
private:
    bool similar(string s1, string s2){
        int diffChars=0;
        for(int i=0 ; i<s1.size() ;i++){
            if(s1[i]!=s2[i]){
                diffChars++;
            }
        }
        return(diffChars==0||diffChars==2);
    } 

    void dfs(int node , vector<int>&vis , vector<int>adj[]){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<int>adj[n];
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ;j++){
                if(similar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                ans++;
            }
        }
        return ans;
    }
};