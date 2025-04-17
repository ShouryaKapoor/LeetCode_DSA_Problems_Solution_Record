//[["1","0","1","1","0","1","1"]] -> ans=3
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) { //[["1"],["1"]]
        // DFS until all 1s are visited.
        int m = grid.size(), n = grid[0].size(), islands = 0; //m = 1, n = 2

        for(int i=0; i<m;i++)
        {
            for(int j=0; j<n;j++)
            {
                if(i >= m || j >= n) break;
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j, m, n);
                    islands++;
                }
            }
        }

        return islands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n)
    {
        if(grid[i][j] == '0') return;

        grid[i][j] = '0'; //visited

        if(i+1 < m) dfs(grid, i+1, j, m, n);
        if(j+1 < n) dfs(grid, i, j+1, m, n); 
        if(i-1 >= 0) dfs(grid, i-1, j, m, n); 
        if(j-1 >= 0) dfs(grid, i, j-1, m, n); 
    }
};