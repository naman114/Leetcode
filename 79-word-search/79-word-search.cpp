class Solution {
public:
    bool solve(vector<vector<char>>& board, int r, int c, string word, int idx) {
        int rows = board.size(), cols = board[0].size(), n = word.length();
        
        if(idx == n) return true;
        
        if(r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[idx]) return false;
        
        char original = board[r][c];
        board[r][c] = '$';
        
        int dxy[5] = {-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; ++i){
            int tr = r + dxy[i];
            int tc = c + dxy[i + 1];
            
            if(solve(board, tr, tc, word, idx + 1))
                return true;
        }
        
        board[r][c] = original;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size(), n = word.length();
        
        char start = word[0];
        
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(board[i][j] == start){
                    if(solve(board, i, j, word, 0))
                        return true;
                }
            }
        }
        
        return false;
    }
};