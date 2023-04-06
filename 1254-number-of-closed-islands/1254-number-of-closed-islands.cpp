class Solution {
public:

    bool bfs(vector<vector<int>>&vis, int i, int j, vector<vector<int>>&grid){

        int n = grid.size(), m = grid[0].size();
        vis[i][j] = 1;
        queue<pair<int,int>>q;
        bool res=true;
        q.push({i,j});

        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newX = r+delrow[i];
                int newY = c+delcol[i];

            if(!(newX >= 0 && newX < n && newY >= 0 && newY < m)) {
				res = false;
			}

			if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 0 &&
               vis[newX][newY] == 0) {
				q.push({newX, newY});
				vis[newX][newY] = 1;
			}
            }
        }
        return res;
    }

    int closedIsland(vector<vector<int>>& grid) {
        // 0 is the land and 1 is water
        int n = grid.size(), m = grid[0].size();
        // cout << n << m;
        if(m<=2 || n<=2)
        {
            return 0;
        }

        vector<vector<int>> vis(n,vector<int>(m,0));

        int c=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && grid[i][j]==0){
                    if(bfs(vis,i,j,grid)==true){
                        c++;
                    }
                }
            }
        }

   
        return c;
    }
};