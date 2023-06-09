//  this is a standard problem of Graphs as a Grid matrix
// solve it using BFS

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;
        while(!q.empty())
        {
            int siz = q.size();
            for(int i=0;i<siz;i++)
            {
                auto node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                if(x==n-1 && y==m-1)
                return ans+1;
                for(int j=min(grid[x][y]+y,m-1);j>y;j--)
                {
                    if(!vis[x][j])
                    {
                        q.push({x,j});
                        vis[x][j] = 1;
                    }
                }
                for(int j=min(grid[x][y]+x,n-1);j>x;j--)
                {
                    if(!vis[j][y])
                    {
                        q.push({j,y});
                        vis[j][y] = 1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};