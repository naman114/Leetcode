class Solution:
    def dfs(self, grid: List[List[str]], r, c):
        rows = len(grid)
        cols = len(grid[0])
        
        if(r < 0 or r >= rows or c < 0 or c >= cols or grid[r][c] == "0"):
            return;
        
        grid[r][c] = "0"
        
        dxy = [-1, 0, 1, 0, -1]
        
        for i in range(4):
            tempr = r + dxy[i]
            tempc = c + dxy[i + 1]
            self.dfs(grid, tempr, tempc)
        
    def numIslands(self, grid: List[List[str]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        
        cnt = 0
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == "1":
                    cnt += 1
                    self.dfs(grid, i, j)
        
        return cnt
                    