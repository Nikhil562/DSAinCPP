class Solution {
public:
    int minScore(int n, vector<vector<int>>&v) {
    vector<vector<int>>adj[n+1];
     for(auto a :v){
          // yaha u->{v,distance }
           // v->{u,dist} undirected hai na isliye
            adj[a[0]].push_back({a[1],a[2]});
            adj[a[1]].push_back({a[0],a[2]});
        }
    // ad mere pass pura u->v,v->u with dis hai 
    vector<bool>vis(n+1,0);//pura node size ka bool lo or false kar do 
    queue<pair<int,int>>q;
    // que me first node dal so 
    q.push({1,100000});


    //ab queue me dal diya to true vi mark kar do 
    vis[1]=true;

    int ans=1e9;
    while(!q.empty())
    {
        int nodetonode=q.front().first;
        q.pop(); //queue ke aag wala nikal lo 
        //ab node mil gaya to ise delete vi kar do 
        // ans= min(ans,adj[nodetonode].second);

        //ab pura adj node ke neighbour ko find kar lo 

       for(auto i:adj[nodetonode])
       {
            ans=min(ans,i[1]);
            if(!vis[i[0]])
            {
                vis[i[0]]=1;
                q.push({i[0],i[1]});
            }
       }
    }
    return ans;
    }
};