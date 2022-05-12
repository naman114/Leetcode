class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c){
        int rows = grid.size(), cols = grid[0].size();
        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) return 0;
        
        grid[r][c] = 0;
        
        int dxy[5] = {-1, 0, 1, 0, -1};
        
        int ans = 1;
        
        for(int i = 0; i < 4; ++i){
            int tr = r + dxy[i];
            int tc = c + dxy[i + 1];
            ans += dfs(grid, tr, tc);    
        }
        
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        int ans = INT_MIN;
        
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] == 1){
                    ans = max(ans, dfs(grid, i, j));
                    cout<<ans<<endl;
                }
            }
        }
        
        return ans == INT_MIN ? 0 : ans;
    }
};