/*
TC: O(N^2)
SC: O(N^2)
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        int rows = m.size();
        int cols = m[0].size();
        
        int dp[rows][cols];
        memset(dp, 0, sizeof dp);
        
        for(int i = 0; i < cols; ++i) dp[0][i] = m[0][i] == '1' ? 1 : 0;
        for(int i = 0; i < rows; ++i) dp[i][0] = m[i][0] == '1' ? 1 : 0;

        for(int i = 1; i < rows; ++i){
            for(int j = 1; j < cols; ++j){
                if(m[i][j] == '1')
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                // cout<<dp[i][j]<<',';
                ans = max(ans, dp[i][j]);
            }
            // cout<<endl;
        }
        
        return ans*ans;
    }
};