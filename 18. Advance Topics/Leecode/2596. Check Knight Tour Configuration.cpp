// This is a standard problem of BFS

class Solution {
public:
    int n,m;
    int count=0;
    int hor [8] = {2,2,1,-1,-2,-2,1,-1};
    int ver [8] = {1,-1,-2,-2,1,-1,2,2};

    bool isValid(int i,int j, vector<vector<int>>& grid)
    {
        if(i<n && i>=0 && j<m && j>=0 && grid[i][j]==count)
        {
            return true;
        }
        return false;
    }


    void dfs(vector<vector<int>>& grid , int i , int j)
    {
        
        for(int it=0;it<8;it++)
        {
            // we only move onto the index whose value is one more than current value and valid move
            if(isValid(i+hor[it],j+ver[it],grid))
            {
                count++;
                dfs(grid,i+hor[it],j+ver[it]);
                break;
                
            }
        }
        return ;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        count+=1;

        if(grid[0][0]!=0) return false;

        dfs(grid,0,0);

        return count==n*n;

        
    }
};